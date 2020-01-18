#pragma once

#include "spaghetti/sph_types.hxx"

namespace lantern {
    namespace video {
        /*!
         *
         */
        enum class ColorFormat {
            A1R5G5B5 = 0,
            R5G5B5,
            R5G6B5,
            R8G8B8,
            A8R8G8B8,

            UNKNOWN
        };

        /*!
         *
         */
        inline std::int16_t rgba16( std::uint32_t red, std::uint32_t  green, std::uint32_t blue, std::uint32_t alpha = 0xFF ) {
            return static_cast<std::int16_t>(
                ( alpha & 0x80 ) << 8 |
                ( red   & 0xF8 ) << 7 |
                ( green & 0xF8 ) << 2 |
                ( blue  & 0xF8 ) << 3
                );
        }

        /*!
         *
         */
        inline std::int16_t rgb16(std::uint32_t red, std::uint32_t  green, std::uint32_t blue) {
            return rgba16( red, green, blue );
        }

        /*!
         *
         */
        inline std::int16_t rgb16_from_16(std::int16_t red, std::int16_t green, std::int16_t blue) {
            return ( 0x8000 |
                     (  red  & 0x1F ) << 10 |
                     ( green & 0x1F ) <<  5 |
                     ( blue  & 0x1F )
            );
        }

        /*!
         *
         */
        template <class _T>
        struct color {
            /*!
             *
             */
            color() {}
            /*!
             *
             */
            color( _T alpha, _T red, _T green, _T blue ) : alpha( alpha ), red( red ), green( green ), blue( blue ) {}

            /*!
             *
             */
            void assign( _T alpha, _T red, _T green, _T blue ) {
                this->alpha = alpha;
                this->red = red;
                this->green = green;
                this->blue = blue;
            }

            _T alpha;
            _T red;
            _T green;
            _T blue;
        };

        using Color = color<std::uint8_t>;
        using ColorF = color<float>;
    }    // end namespace video
}    // end namespace lantern
