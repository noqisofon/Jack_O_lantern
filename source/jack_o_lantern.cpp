#include "lantern/jack_o_lantern_compile_config.hxx"

#include "spaghetti/sph_types.hxx"
#include "spaghetti/memory.hxx"

#include "lantern/IDevice.hxx"
#include "lantern/DeviceType.hxx"
#include "lantern/DeviceCreationParameters.hxx"

#include "lantern/jack_o_lantern.hxx"

namespace lantern {
    JOL_API spaghetti::Shared<IDevice> createDevice( video::DriverType                  driver_type,
                                                     const geom::Size                  &window_size,
                                                     std::uint32_t                      bits,
                                                     bool                               fullscreen,
                                                     bool                               stencil_buffer,
                                                     bool                               vsync,
                                                     spaghetti::Shared<IEventReceiver> &receiver ) {
        DeviceCreationParameters p;

        p.driver_type = driver_type;
        p.window_size = window_size;
        p.bits = static_cast<std::uint8_t>( bits );
        p.fullscreen = fullscreen;
        p.stencil_buffer = stencil_buffer;
        p.vsync = vsync;
        p.event_receiver = receiver;

        return createDeviceEx( p );
    }

    JOL_API spaghetti::Shared<IDevice> createDevicecreateDeviceEx( const DeviceCreationParameters &parameters ) {
        switch ( parameters.device_type ) {
#ifdef JOL_COMPILE_WITH_WINDOWS_DEVICE
        case DeviceType::WINDOWS:
            return create_device_for_win32( parameters );
#endif  /* def JOL_COMPILE_WITH_WINDOWS_DEVICE */

#ifdef JOL_COMPILE_WITH_WINDOWS_CE_DEVICE
        case DeviceType::WINDOWS_CE:
            return create_device_for_win32_ce( parameters );
#endif  /* def JOL_COMPILE_WITH_WINDOWS_CE_DEVICE */

#ifdef JOL_COMPILE_WITH_OSX_DEVICE
        case DeviceType::MAC_OS_X:
            return create_device_for_mac_os_x( parameters );
#endif  /* def JOL_COMPILE_WITH_OSX_DEVICE */

#if defined(JOL_COMPILE_WITH_SDL_DEVICE) || defined(JOL_COMPILE_WITH_SDL2_DEVICE)
        case DeviceType::SDL:
            return create_device_for_sdl( parameters );
#endif  /* defined(JOL_COMPILE_WITH_SDL_DEVICE) || defined(JOL_COMPILE_WITH_SDL2_DEVICE) */

        default:
            return spaghetti::Shared<IDevice>();
        }
    }

#ifdef JOL_COMPILE_WITH_WINDOWS_DEVICE
    static spaghetti::Shared<IDevice> create_device_for_win32( const DeviceCreationParameters &parameters ) {
    }
#endif  /* def JOL_COMPILE_WITH_WINDOWS_DEVICE */

#ifdef JOL_COMPILE_WITH_WINDOWS_CE_DEVICE
    static spaghetti::Shared<IDevice>  create_device_for_win32_ce( const DeviceCreationParameters &parameters ) {
    }
#endif  /* def JOL_COMPILE_WITH_WINDOWS_CE_DEVICE */

#ifdef JOL_COMPILE_WITH_OSX_DEVICE
    static spaghetti::Shared<IDevice> create_device_for_mac_os_x( const DeviceCreationParameters &parameters ) {
    }
#endif  /* def JOL_COMPILE_WITH_OSX_DEVICE */

#if defined(JOL_COMPILE_WITH_SDL_DEVICE) || defined(JOL_COMPILE_WITH_SDL2_DEVICE)
    static spaghetti::Shared<IDevice>   create_device_for_sdl( const DeviceCreationParameters & parameters ) {
    }
#endif  /* defined(JOL_COMPILE_WITH_SDL_DEVICE) || defined(JOL_COMPILE_WITH_SDL2_DEVICE) */
    }
