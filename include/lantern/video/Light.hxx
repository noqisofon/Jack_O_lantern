#pragma once

#include "lantern/video/color.hxx"

namespace lantern {
    namespace video {
        enum class LightType {
            POINT,
            SPOT,
            DRECTIONAL,

            COUNT
        };

        const char *const LIGHT_TYPE_NAMES[] = {
            "Point",
            "Spot",
            "Directional",

            0
        };

        /*!
         *
         */
        struct Light {
            /*!
             *
             */
            Light() : ambient_color( 0.0f, 0.0f, 0.0f ), diffuse_color( 1.0f, 1.0f, 1.0f ) {}

            ColorF ambient_color;
            ColorF diffuse_color;
        };
    }    // end namespace video
}    // end namespace latern