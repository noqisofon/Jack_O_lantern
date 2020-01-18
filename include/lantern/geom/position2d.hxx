#pragma once

#include "spaghetti/sph_types.hxx"


namespace lantern {

    namespace geom {


        /*!
         *
         */
        template <class _T>
        struct position2d {
            _T x;
            _T y;
        };


        using Point     = position2d<std::int32_t>;
        using PointF    = position2d<float>;


    }    // end namespace geom

}    // end namespace lantern