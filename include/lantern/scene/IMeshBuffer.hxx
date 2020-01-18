#pragma once

#include "lantern/video/Material.hxx"

namespace lantern {
    namespace scene {
        /*!
         *
         */
        class IMeshBuffer {
        public:
           /*!
            *
            */
            virtual const video::Material &getMaterial() const = 0;
        };
    }   // end namespace scene
}   // end namespace lantern