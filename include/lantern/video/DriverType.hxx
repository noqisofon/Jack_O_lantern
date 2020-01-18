#pragma once

namespace lantern {
    namespace video {
        /*!
         *
         */
        enum class DriverType {
            NULL,
            SOFTWARE,
            BURNINGSVIDEO,
            DIRECT3D8,
            DIRECT3D9,
            DIRECT3D10,
            DIRECT3D11,
            DIRECT3D12,
            OPENGL,

            COUNT
        };
    }   // end namespace video
}   // end namespace lantern