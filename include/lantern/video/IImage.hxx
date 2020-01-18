#pragma once

#include "spaghetti/memory.hxx"

#include "lantern/geom/dimension2d.hxx"
#include "lantern/geom/position2d.hxx"
#include "lantern/geom/rect.hxx"
#include "lantern/video/color.hxx"

namespace lantern {
    namespace video {
        /*!
         *
         */
        class IImage {
        public:
           /*!
            *
            */
            virtual void *lock() = 0;

            /*!
             *
             */
            virtual void unlock() = 0;

            /*!
             *
             */
            virtual const geom::Size &getDimension() const = 0;

            /*!
             *
             */
            virtual std::uint32_t getBitsPerPixel() const = 0;

            /*!
             *
             */
            virtual std::uint32_t getBytesPerPixel() const = 0;

            /*!
             *
             */
            virtual std::uint32_t getImageDataSizeInBytes() const = 0;

            /*!
             *
             */
            virtual Color pixelAt( std::uint32_t x, std::uint32_t y ) const = 0;

            /*!
             *
             */
            virtual void pixelAtPut( std::uint32_t x, std::uint32_t y,
                                     const Color &color,
                                     bool blend = false ) = 0;

            /*!
             *
             */
            virtual ColorFormat getColorFormat() const = 0;

            /*!
             *
             */
            virtual std::uint32_t getRedMask() const = 0;

            /*!
             *
             */
            virtual std::uint32_t getGreenMask() const = 0;

            /*!
             *
             */
            virtual std::uint32_t getBlueMask() const = 0;

            /*!
             *
             */
            virtual std::uint32_t getAlphaMask() const = 0;

            /*!
             *
             */
            virtual std::uint32_t getPitch() const = 0;

            /*!
             *
             */
            virtual void copyToScaling( const spaghetti::Shared<IImage> &target ) = 0;
            /*!
             *
             */
            virtual void copyToScaling( void *target,
                                        std::uint32_t width, std::uint32_t height,
                                        ColorFormat format = ColorFormat::A8R8G8B8,
                                        std::uint32_t pitch = 0 ) = 0;

            /*!
             *
             */
            virtual void copyTo( const spaghetti::Shared<IImage> &target, const geom::Point &position = { 0,0 } ) = 0;
            /*!
             *
             */
            virtual void copyTo( const spaghetti::Shared<IImage> &target,
                                 const geom::Point &position,
                                 const geom::Rect &source_rect,
                                 const geom::Rect &clip_rect = {} ) = 0;

            /*!
             *
             */
            virtual void copyToScalingBoxFilter( const spaghetti::Shared<IImage> &target,
                                                 std::int32_t bias,
                                                 bool blend = false ) = 0;

             /*!
              *
              */
            virtual void fill( const Color &color ) = 0;

            /*!
             *
             */
            static std::uint32_t getBitsPerPixelFromFormat( const ColorFormat format ) {
                switch ( format ) {
                case ColorFormat::A1R5G5B5:
                    return 16;
                    
                case ColorFormat::R5G5B5:
                    return 16;
                    
                case ColorFormat::R8G8B8:
                    return 24;
                    
                case ColorFormat::A8R8G8B8:
                    return 32;

                default:
                    return 0;
                }
            }

            /*!
             *
             */
            static bool isRenderTargetOnlyFormat(const ColorFormat format) {
                switch ( format ) {
                case ColorFormat::A1R5G5B5:
                case ColorFormat::R5G5B5:
                case ColorFormat::R8G8B8:
                case ColorFormat::A8R8G8B8:
                    return true;

                default:
                    return false;
                }
            }
        };
    }    // end namespace video
}    // end namespace lantern
