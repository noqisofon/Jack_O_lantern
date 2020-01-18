#pragma once

#include "spaghetti/memory.hxx"
#include "spaghetti/io/path.hxx"

#include "lantern/video/IImage.hxx"

namespace spaghetti {
    namespace io {
        class IWriteFile;
    }   // end namespace io
}   // end namespace spaghetti

namespace lantern {
    namespace video {
        namespace io {
            /*!
             *
             */
            class IImageWriter {
            public:
               /*!
                *
                */
                virtual bool isAWriteableFileExtension( const spaghetti::io::path filename ) const = 0;

                /*!
                 *
                 */
                virtual bool writeImage( spaghetti::Shared<spaghetti::io::IWriteFile> &file,
                                         spaghetti::Shared<IImage> &image,
                                         std::uint32_t param = 0 ) const = 0;
            };
        }   // end namespace io
    }   // end namespace video
}   // end namespace lantern