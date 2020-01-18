#pragma once

#include "lantern/DeviceType.hxx"
#include "lantern/video/DriverType.hxx"
#include "lantern/geom/dimension2d.hxx"

namespace lantern {
    /*!
     *
     */
    struct DeviceCreationParameters {

        /*!
         *
         */
        DeviceCreationParameters() :
            device_type( DeviceType::BEST ),
            driver_type( video::DriverType::BURNINGS_VIDEO ),
            geom::Size( { 800, 600 } ),
            bits( 16 ),
            z_buffer_bits( 16 ),
            fullscreen( false ),
            window_resizable( false ),
            stencil_buffer( false ),
            vsync( false )
            anti_alias(0),
            handle_srgb( false ),
            receiver(0),
            window_id(0)
            {}
        
        DeviceType                         device_type;
        video::DriverType                  driver_type;
        geom::Size                         window_size;
        std::uint32_t                      bits;
        std::uint32_t                      z_buffer_bits;
        bool                               fullscreen;
        bool                               window_resizable;
        bool                               stencil_buffer;
        bool                               vsync;
        std::uint8_t                       anti_alias;
        bool                               handle_srgb;
        spaghetti::Shared<IEventReceiver>  receiver;

        void                              *window_id;
    };
}
