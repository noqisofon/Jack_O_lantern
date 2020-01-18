#pragma once

namespace lantern {

    /*!
     *
     */
    enum class EventType {
        GUI_EVENT = 0,

        MOUSE_INPUT_EVENT,

        KEY_INPUT_EVENT,

        JOYSTICK_INPUT_EVENT,

        LOG_TEXT_EVENT,

        USER_EVENT,

        FORCE_32_BIT = 0x7ffffffff
    };

    /*!
     * イベント
     */
    struct Event {
        virtual ~Event() {}

        /*!
         * レシーバーのイベントタイプを返します。
         */
        virtual EventType getType() const = 0;
    };

    /*!
     *
     */
    enum class MouseButtonStateMask {
        LEFT    = 0x01,
        RIGHT   = 0x02,
        MIDDLE  = 0x04,

        EXTRA1  = 0x08,
        EXTRA2  = 0x10,

        FORCE_32_BIT = 0x7ffffffff
    };

    /*!
     *
     */
    struct MouseInputEvent : public Event {
        /*!
         *
         */
        virtual EventType getType() const { return EventType::MOUSE_INPUT_EVENT; }

        std::int32_t  x;
        std::int32_t  y;

        float         wheel;

        bool          shift : 1;

        bool          control : 1;

        std::uint32_t button_states;

        MouseInputEventType mouse_input;

        /*!
         *
         */
        bool isLeftPressed()   const { return 0 != ( button_states & MouseButtonStateMask::LEFT ); }

        /*!
         *
         */
        bool isMiddlePressed() const { return 0 != ( button_states & MouseButtonStateMask::MIDDLE ); }

        /*!
         *
         */
        bool isRightPressed()  const { return 0 != ( button_states & MouseButtonStateMask::RIGHT ); }
    };

    /*!
     *
     */
    class IEventReceiver {
     public:
        /*!
         *
         */
        virtual ~IEventReceiver() {}

     public:
        /*!
         *
         */
        virtual bool onEvent(const Event &an_event) = 0;
    };
}
