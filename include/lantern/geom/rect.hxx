#pragma once

#include "spaghetti/sph_types.hxx"

namespace lantern {
    namespace geom {
        /*!
         *
         */
        template <class _Integer, class _UInteger>
        struct rect {
            _Integer x;
            _Integer y;
            _UInteger width;
            _UInteger height;
        };

        using Rect = rect<std::int32_t, std::uint32_t>;
    }    // end namespace geom
}    // end namespace lantern