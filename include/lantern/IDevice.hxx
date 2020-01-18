#pragma once

#include "spaghetti/sph_types.hxx"
#include "spaghetti/memory.hxx"
#include "spaghetti/ILogger.hxx"

#include "lantern/IEventReceiver.hxx"
#include "lantern/gui/Environment.hxx"
#include "lantern/gui/ICursorControl.hxx"
#include "lantern/scene/ISceneManager.hxx"
#include "lantern/video/IVideoDriver.hxx"

namespace spaghetti {
    class ILogger;
}

namespace lantern {
    class IEventReceiver;
    
    namespace scene {
        class ISceneManager;
    }

    namespace gui {
        class ICursorControl;
        class IEnvironment;
    }
}

namespace lantern {

    /*!
     * Jack O Lantern デバイス。
     *
     * `createDevice()` または `createDeviceEx()` で作成できます。
     * これは Jack O Lantern の最も重要なクラスです。
     * 
     */
    class IDevice {
     public:
        /*!
         * デバイスを実行します。
         *
         * また、`ITimer::tick()` を呼び出して仮想タイマーをインクリメントします。
         * これを防ぐには `ITimer::stop()` を呼び出します。
         * こんな風に使用します:
         * 
         * \code
         * while ( device->run() ) {
         *     // draw everything here
         * }
         * \endcode
         */
        virtual bool run() = 0;

        /*!
         *
         */
        virtual void yield() = 0;

        /*!
         *
         */
        virtual void sleep(std::uint32_t milliseconds, bool pause_timer = false) = 0;

        /*! @{ */

        /*!
         *
         */
        virtual spaghetti::Shared<video::IVideoDriver> getVideoDriver() = 0;

        /*!
         *
         */
        virtual spaghetti::Shared<gui::IEnvironment> getGuiEnvironment() = 0;

        /*!
         *
         */
        virtual spaghetti::Shared<scene::ISceneManager> getSceneManager() = 0;

        /*!
         *
         */
        virtual spaghetti::Shared<gui::ICursorControl> getCursorControl() = 0;

        /*!
         *
         */
        virtual spaghetti::Shared<spaghetti::ILogger> getLogger() = 0;

        /*!
         *
         */
        virtual spaghetti::Shared<IEventReceiver> getEventReceiver() = 0;

        /*! @} */

        /*!  @{ */

        /*!
         *
         */
        virtual void setCaption() = 0;

        /*!
         *
         */
        virtual void minimizeWindow() = 0;

        /*!
         *
         */
        virtual void maximizeWindow() = 0;

        /*!
         *
         */
        virtual void restoreWindow() = 0;

        /*! @} */
    };
    
}
