#pragma once

#include "spaghetti/memory.hxx"
#include "spaghetti/io/path.hxx"

#include "lantern/video/IImage.hxx"

namespace spaghetti {
    namespace io {
        class IReadFile;
    }   // end namespace io
}   // end namespace spaghetti

namespace lantern {
    namespace video {
        namespace io {
            /*!
             *
             */
            class IImageLoader {
             public:
                /*!
                 * 指定されたファイル名がロードできる拡張子なら真を返します。
                 * 
                 * \param filename ファイル名
                 *
                 * \return ロードできる拡張子なら真。
                 */
                virtual bool isALoadableFileExtension(const spaghetti::io::path filename) = 0;

                /*!
                 *
                 */
                virtual bool isALoadableFileFormat(spaghetti::Shared<spaghetti::io::IReadFile> &file) = 0;

                /*!
                 *
                 */
                virtual spaghetti::Unique<IImage> loadImage(spaghetti::Shared<spaghetti::io::IReadFile> &file) = 0;
            };
        }   // end namespace io
    }   // end namespace video
}   // end namespace lantern
