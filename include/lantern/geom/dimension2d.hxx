#pragma once

#include "spaghetti/sph_types.hxx"


namespace lantern {

    namespace geom {


        template <class _T>
        class vector2d;


        /*!
         *
         */
        template <class _T>
        struct dimension2d {
         public:
            /*!
             *
             */
            dimension2d() : width( 0 ), height( 0 ) {}
            /*!
             *
             */
            dimension2d(const _T& width, const _T& height) : width( width ), height( height ) {}
            /*!
             *
             */
            template <class _U>
            explicit dimension2d(const dimension2d<_U>& other) : width( static_cast<_T>( other.width ) ), height( static_cast<_T>( other.height ) ) {}

         public:
            /*!
             *
             */
            template <class _U>
            dimension2d<_T> operator = (const dimension2d<_U>& other) {
                this->width  = static_cast<_T>( other.width );
                this->height = static_cast<_T>( other.height );

                return *this;
            }
            
            /*!
             *
             */
            dimension2d<_T> operator +=(const dimension2d<_T>& other) {
                width  += other.width;
                height += other.height;

                return *this;
            }
            
            /*!
             *
             */
            dimension2d<_T> operator +(const dimension2d<_T>& other) {
                return {
                    width  + other.width,
                    height + other.height
                };
            }
            
            /*!
             *
             */
            dimension2d<_T> operator -=(const dimension2d<_T>& other) {
                width  -= other.width;
                height -= other.height;

                return *this;
            }
            
            /*!
             *
             */
            dimension2d<_T> operator -(const dimension2d<_T>& other) {
                return {
                    width  - other.width,
                    height - other.height
                };
            }

            /*!
             *
             */
            void assign(_T width, _T height) {
                this->width  = width;
                this->height = height;
            }
            
            /*!
             *
             */
            _T getArea() const { return width * height; }

         public:
            _T    width;
            _T    height;
        };


        using Size  = dimension2d<std::uint32_t>;
        using SizeF = dimension2d<float>;


    }    // end namespace geom

}    // end namespace lantern
