#pragma once

#include "spaghetti/memory.hxx"

#include "lantern/video/io/IImageLoader.hxx"
#include "lantern/video/io/IImageWriter.hxx"
#include "lantern/video/Light.hxx"
#include "lantern/video/MaterialRenderer.hxx"
#include "lantern/video/IVideoDriver.hxx"

#include <list>

namespace lantern {
    namespace video {
        /*!
         *
         */
        class AbstractVideoDriver : public IVideoDriver {
        protected:
            std::list<spaghetti::Shared<io::IImageLoader>>  surface_loaders;
            std::list<spaghetti::Shared<io::IImageWriter>>  surface_writer;
            std::list<Light>                                lights;
            std::list<MaterialRenderer>                     material_renderers;
        };
    }    // end namespace video
}    // end namespace lantern