#pragma once

#include <memory>

namespace spaghetti {
    template <class _Type> using Unique = std::unique_ptr<_Type>;

    template <class _Type> using Shared = std::shared_ptr<_Type>;

    template <class _Com_Interface>
    struct com_deleter {
        constexpr com_delete() noexcept = default;
        template <_Other_Com_Interface>
        com_delete( com_delete<_Other_Com_Interface> &other ) noexcept {
        }
        ~com_delete() = default;

        void operator ()( _Com_Interface *ptr ) const {
            ptr->Release();
        }
    };

    template <class _Com_Interface> using ComUnique = std::unique_ptr<_Com_Interface, com_deleter<_Com_Interface>>;

    template <class _Com_Interface> using ComShared = std::shared_ptr<_Com_Interface, com_deleter<_Com_Interface>>;
}