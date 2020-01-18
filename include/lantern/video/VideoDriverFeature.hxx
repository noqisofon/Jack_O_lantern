#pragma once

namespace lantern {
    namespace video {
        /*!
         *
         */
        enum class VideoDriverFeature {
            RENDER_TO_TARGET = 0,
            HARDWARE_TL,
            MULTIEXTURE,
            BLINEAR_FILETER,
            MIP_MAP,
            
        };
    }   // end namespace video
}   // end namespace lantern
