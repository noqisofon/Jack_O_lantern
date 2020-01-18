#include "lantern/jack_o_lantern_compile_config.h"

#ifdef JOL_COMPILE_WITH_DIRECT3D_9

#   include "lantern/video/D3D9Texture.hxx"

#   include "spaghetti/memory.hxx"
#   include "spaghetti/io/Path.hxx"
#   include "spaghetti/os/Printer.hxx"

#   include <d3dx9tex.h>


namespace lantern {

    namespace video {

        D3D9Texture::D3D9Texture(spaghetti::Shared<D3D9Driver>&         driver,
                                 const code::dimension2d<std::uint32_t> size,
                                 const spaghetti::io::Path&             name,
                                 const ColorFormat                      format)
            : ITexture( name ), Texture( 0 ),
              rtt_surface( 0 ), driver( driver ), depth_surface( 0 ), 
              texuture_size( size ), image_size( size ), pitch( 0 ), color_format( ColorFormat::UNKNOWN ),
              has_mipmaps( false ), hardware_mipmaps( false ), is_render_target( true )
        {
#   ifdef _DEBUG
            setDebugName( "D3D9Texture" );
#   endif  /* def _DEBUG */

            this->device = this->driver->getDevice();
            // device も spaghetti::Shared<?> なので必要なさそう。
            // if ( this->device ) {
            //     this->device->retain();
            // }

            this->createRenderTarget( format );
        }

        D3D9Texture::D3D9Texture(spaghetti::Shared<IImage>&             image,
                                 spaghetti::Shared<D3D9Driver>&         driver,
                                 std::uint32_t                          flags,
                                 const spaghetti::io::Path&             name,
                                 void                                  *mipmap_data)
            : ITexture( name ), Texture( 0 ),
              rtt_surface( 0 ), driver( driver ), depth_surface( 0 ), 
              texuture_size( 0, 0 ), image_size( 0, 0 ), pitch( 0 ), color_format( ColorFormat::UNKNOWN ),
              has_mipmaps( false ), hardware_mipmaps( false ), is_render_target( false )
        {
#   ifdef _DEBUG
            setDebugName( "D3D9Texture" );
#   endif  /* def _DEBUG */

            this->has_mipmaps = this->driver->getTextureCreationFlag( TextureCreationFlag::CREATE_MIPMAPS );

            this->device = this->driver->getDevice();
            // device も spaghetti::Shared<?> なので必要なさそう。
            // if ( this->device ) {
            //     this->device->retain();
            // }

            if ( image ) {
                if ( this->createTecture( flags, image ) ) {
                    if ( this->copyTexture( image ) ) {
                        this->regenerateMipmapLevels( mipmap_data );
                    }
                } else {
                    spaghetti::os::Printer::warning( "Could not create DIRECT3D9 Texture." );
                }
            }
        }

        D3D9Texture::~D3D9Texture() {
            // 多分 release() とかしなくても良さそう。
            // if ( this->texture ) {
            //     this->texture->release();
            // }

            // if ( this->rtt_surface ) {
            //     this->rtt_surface->release();
            // }

            if ( this->depth_surface ) {
                if ( this->depth_surface->drop() ) {
                    this->driver->removeDepthSurface( this->depth_surface );
                }
            }

            // if ( this->driver ) {
            //     this->driver->release();
            // }
        }

        void D3D9Texture::createRenderTarget(const ColorFormat format) {
            if ( ! this->driver->queryFeature( VideoDriverFeature::TEXTURE_NPOT ) ) {
                if ( this->texture_size != this->image_size ) {
                    spaghetti::os::Printer::info( "RenderTarget size has to be power of two" );
                }
            }
            this->texture_size = this->texture_size.getOptiomalSize( ! this->driver->queryFeature( VideoDriverFeature::TEXTURE_NPOT ),
                                                                     ! this->driver->queryFeature( VideoDriverFeature::TEXTURE_NSQUARE ),
                                                                     true,
                                                                     this->driver.caps.max_texture_width );

            D3DFORMAT d3d_format = this->driver->getD3DColorFormat();

            if ( this->color_format == ColorFormat::UNKNOWN ) {
                this->color_format = this->driver->getColorFormat();
                this->setPitch( d3d_format );

                if ( format != ColorFormat::UNKNOWN ) {
                    this->color_format = format;

                    d3d_format = this->driver->getD3DFormatFromColorFormat( format );
                    this->setPitch( d3d_format );
                }
            } else {
                d3d_format = this->driver->getD3DFormatFromColorFormat( format );
            }

            HRESULT hr = this->device->createTexture( this->texture_size.width,
                                                      this->texture_size.height,
                                                      1,
                                                      D3DUSAGE_RENDERTARGET,
                                                      d3d_format,
                                                      D3DPOOL_DEFAULT,
                                                      this->texture.get(),
                                                      NULL );

            if ( FAILED(hr) ) {
                switch ( hr ) {
                case D3DERR_INVALIDCALL:
                    spaghetti::os::Printer::log( "Could not create render target texture", "Invalid Call" );
                    break;

                case D3DERR_OUTOFVIDEOMEMORY:
                    spaghetti::os::Printer::log( "Could not create render target texture", "Out of Video Memory" );
                    break;

                case E_OUTOFMEMORY:
                    spaghetti::os::Printer::log( "Could not create render target texture", "Out of Memory" );
                    break;

                default:
                    spaghetti::os::Printer::log( "Could not create render target texture" );
                    break;
                }
            }
        }

        bool D3D9Texture::createMipmaps(std::uint32_t level) {
            if ( level == 0 ) {
                return true;
            }

            if ( this->hardware_mipmaps && this->texture ) {
                this->texture->GenerateMipSubLevels();

                return true;
            }

            spaghetti::ComUnique<IDirect3DSurface9> upper_surface;
            spaghetti::ComUnique<IDirect3DSurface9> lower_surface;
            {
                HRESULT hr = 0;

                hr = this->texture->GetSurfaceLevel( level - 1, upper_surface.get() );
                if ( FAILED(hr) || !upper_surface ) {
                    spaghetti::os::Printer::warning( "Could not get upper surface level for mipmap generation" );

                    return false;
                }

                hr = this->texture->GetSurfaceLevel( level, lower_surface.get() );
                if ( FAILED(hr) || !lower_surface ) {
                    spaghetti::os::Printer::warning( "Could not get lower surface level for mipmap generation" );

                    return false;
                }
            }

            D3DSURFACE_DESC upper_desc, lower_desc;
            {
                upper_surface->GetDesc( &upper_desc );
                lower_surface->GetDesc( &lower_desc );
            }

            D3DLOCKED_RECT upper_locked_rect, lower_locked_rect;            
            {
                if ( FAILED( upper_surface->LockRect( &upper_locked_rect, NULL, 0 ) ) ) {
                    spaghetti::os::Printer::warning( "Could not lock upper texture for mipmap generation" );

                    return false;
                }

                if ( FAILED( lower_surface->LockRect( &lower_locked_rect, NULL, 0 ) ) ) {
                    upper_surface->UnlockRect();

                    spaghetti::os::Printer::warning( "Could not lock lower texture for mipmap generation" );

                    return false;
                }
            }
        }

    }    // end namespace video

}    // end namespace lantern



#endif  /* def JOL_COMPILE_WITH_DIRECT3D_9 */
