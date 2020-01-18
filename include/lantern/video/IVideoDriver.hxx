#pragma once

#include "spaghetti/io/path.hxx"
#include "spaghetti/memory.hxx"
#include "spaghetti/sph_types.hxx"

#include "lantern/geom/dimension2d.hxx"
#include "lantern/geom/matrix4.hxx"
#include "lantern/geom/position2d.hxx"
#include "lantern/geom/rect.hxx"
#include "lantern/scene/IMeshBuffer.hxx"
#include "lantern/video/color.hxx"
#include "lantern/video/IImage.hxx"
#include "lantern/video/ITexture.hxx"
#include "lantern/video/VideoDriverFeature.hxx"

namespace lantern {
    namespace io {
        class AttributeReadWriteOptions;
        class IAttributes;
        class IReadFile;
        class IWriteFile;
    }

    namespace scene {
        class IMesh;
        class IMeshBuffer;
        class IMeshManipulator;
        class ISceneNode;
    }

    namespace video {
        class IGPUProgramingServices;
        class IImageLoader;
        class IImageWriter;
        class IMaterialRenderer;
        class Light;
        class Vertex2TCoords;
        class Vertex3D;

        enum class TransformationState {
            VIEW = 0,
            WORLD,
            PROJECTION,

            TEXTURE_0,

            TEXTURE_1,

            TEXTURE_2,

            TEXTURE_3,
        };

        /*!
         *
         */
        class IVideoDriver {
        public:
           /*!
            *
            */
            virtual bool beginScene(
                bool                             back_buffer = true,
                bool                             z_buffer = true,
                Color                            color              = { 255, 0, 0 },
                const ExposedVideoData          &video_data         = ExposedVideoData(),
                spaghetti::Shared<geom::Rect>   &source_rect        = spaghetti::Shared<geom::Rect>()
            ) = 0;

            /*!
             *
             */
            virtual bool endScene() = 0;

            /*!
             *
             */
            virtual bool queryFeature( VideoDriverFeature feature ) const = 0;

            /*!
             *
             */
            virtual bool toggleFeature( VideoDriverFeature feature, bool flag = true ) = 0;

            /*!
             *
             */
            virtual const spaghetti::Shared<core::IAttributes> &getDriverAttributes() const = 0;

            /*!
             *
             */
            virtual bool checkDriverReset() = 0;

            /*!
             *
             */
            virtual void setTransform( TransformationState state, const geom::Matrix4 &mat ) = 0;

            /*!
             *
             */
            virtual const geom::Matrix4 &getTransform( TransformationState state ) const = 0;

            /*!
             *
             */
            virtual std::size_t getImageLoaderCount() const = 0;

            /*!
             *
             */
            virtual spaghetti::Shared<IImageLoader> imageLoadersAt( std::uint32_t index ) = 0;

            /*!
             *
             */
            virtual std::size_t getImageWriterCount() const = 0;

            /*!
             *
             */
            virtual spaghetti::Shared<IImageWriter> imageWritersAt( std::uint32_t index ) = 0;

            /*!
             *
             */
            virtual void setMaterial( const Material &material ) = 0;

            /*!
             *
             */
            virtual const Material &getMaterial() const = 0;

            /*!
             *
             */
            virtual spaghetti::Shared<ITexture> texturesNamedAt( const spaghetti::io::path &filename ) = 0;
            /*!
             *
             */
            virtual spaghetti::Shared<ITexture> texturesNamedAt( const io::IReadFile &file ) = 0;

            /*!
             *
             */
            virtual spaghetti::Shared<ITexture> texturesAt( std::uint32_t index ) = 0;

            /*!
             *
             */
            virtual std::size_t getTextureCount() const = 0;

            /*!
             *
             */
            virtual void renameTexture( spaghetti::Shared<ITexture> &a_texture, const spaghetti::io::path &new_name ) = 0;

            /*!
             *
             */
            virtual spaghetti::Shared<ITexture> addTexture(
                const geom::Size &size,
                const spaghetti::io::path &name,
                ColorFormat          format = ColorFormat::A8R8G8B8
            ) = 0;

            /*!
             *
             */
            virtual spaghetti::Shared<ITexture> addTexture(
                const spaghetti::io::path              &name,
                spaghetti::Shared<IImage>   &image,
                void                        *mipmap_data = 0
            ) = 0;

            /*!
             *
             */
            virtual void removeTexture( spaghetti::Shared<ITexture> &texture ) = 0;

            /*!
             *
             */
            virtual void removeAllTextures() = 0;

            /*!
             *
             */
            virtual void removeHadwareBuffer( const spaghetti::Shared<scene::IMeshBuffer> &mesh_buffer ) = 0;

            /*!
             *
             */
            virtual void removeAllHadwareBuffers() = 0;

            /*!
             *
             */
            virtual void addOcclusionQuery( spaghetti::Shared<scene::ISceneNode> &node ) = 0;
            /*!
             *
             */
            virtual void addOcclusionQuery(
                spaghetti::Shared<scene::ISceneNode> &node,
                const spaghetti::Shared<scene::IMesh> &mesh
            ) = 0;

            /*!
             *
             */
            virtual void removeOcclusionQuery( spaghetti::Shared<scene::ISceneNode> &node ) = 0;

            /*!
             *
             */
            virtual void removeAllOcclusionQueries() = 0;

            /*!
             *
             */
            virtual void runOcclusionQuery( spaghetti::Shared<scene::ISceneNode> &node, bool visible = false ) = 0;

            /*!
             *
             */
            virtual void runAllOcclusionQueries( bool visible = false ) = 0;

            /*!
             *
             */
            virtual void updateOcclusionQuery( spaghetti::Shared<scene::ISceneNode> &node, bool block = true ) = 0;

            /*!
             *
             */
            virtual void updateAllOcclusionQueries( bool block = true ) = 0;

            /*!
             *
             */
            virtual std::uint32_t getOcclusionQueryResult( spaghetti::Shared<scene::ISceneNode> &node ) const = 0;

            /*!
             *
             */
            virtual void makeColorKeyTexture(
                spaghetti::Shared<video::ITexture> &texture,
                Color                                color,
                bool                                 zero_texels = false
            ) const = 0;
            /*!
             *
             */
            virtual void makeColorKeyTexture(
                spaghetti::Shared<video::ITexture> &texture,
                geom::Point                         color_key_pixel_position,
                bool                                zero_texels = false
            ) const = 0;
        };
    }    // end namespace video
}    // end namespace lantern