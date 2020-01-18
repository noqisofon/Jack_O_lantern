#pragma once

#include "lantern/geom/dimension2d.hxx"
#include "lantern/video/color.hxx"
#include "lantern/video/DriverType.hxx"

namespace lantern {
    namespace video {
        /*!
         *
         */
        enum class TextureLockMode {
            READ_WRITE,
            READ_ONLY,
            WRITE_ONLY
        };

        /*!
         *
         */
        class ITexture {
        public:
           /*!
            *
            */
            ITexture( const io::Path &name ) : named_path( name ) {
            }

        public:
           /*!
            *
            */
            virtual void *lock( TextureLockMode mode = TextureLockMode::READ_WRITE, std::uint32_t mipmap_level = 0 ) = 0;

            /*!
             *
             */
            virtual void unlock() = 0;

            /*!
             *
             */
            virtual const geom::Size &getOriginalSize() const = 0;

            /*!
             *
             */
            virtual const geom::Size &getSize() const = 0;

            /*!
             *
             */
            virtual DriverType getDriverType() const = 0;

            /*!
             *
             */
            virtual ColorFormat getColorFormat() const = 0;

            /*!
             *
             */
            virtual std::uint32_t getPitch() const = 0;

            /*!
             *
             */
            virtual bool hasMipmaps() const { return false; }
        };
    }   // end namespace video
}    // end namespace lantern