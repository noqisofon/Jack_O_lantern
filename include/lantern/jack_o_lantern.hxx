#pragma once

namespace lantern {

    /*!
     *
     */
    JOL_API spaghetti::Shared<IDevice> createDevice( video::DriverType                  driver_type,
                                                     const geom::Size                  &window_size,
                                                     std::uint32_t                      bits,
                                                     bool                               fullscreen,
                                                     bool                               stencil_buffer,
                                                     bool                               vsync,
                                                     spaghetti::Shared<IEventReceiver> &receiver );

    /*!
     *
     */
    JOL_API spaghetti::Shared<IDevice> createDevicecreateDeviceEx( const DeviceCreationParameters &parameters );
}
