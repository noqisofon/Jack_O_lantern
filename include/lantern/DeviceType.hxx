#pragma once

namespace lantern {
    /*!
     * \enum DeviceType
     * Jack_O_Lantern Engine がサポートする様々なデバイスタイプ。
     */
    enum class DeviceType {
        BEST,
        CONSOLE,
        FRAME_BUFFER,
        MAC_OS_X,
        SDL,
        WINDOWS,
        WINDOWS_CE,
        X11
    };
}