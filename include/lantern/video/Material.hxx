#pragma once

#include "lantern/video/color.hxx"

namespace lantern {
    namespace video {
        /*!
         *
         */
        struct Material {

            Color ambient_color;
            Color diffuse_color;
            Color emissive_color;
            Color specular_color;
            
        };
    }   // end namespace video
}   // end namespace lantern
