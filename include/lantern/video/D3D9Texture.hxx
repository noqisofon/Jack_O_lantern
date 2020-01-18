#pragma once


#ifdef JOL_COMPILE_WITH_DIRECT3D_9

#   include "lantern/video/ITexture.hxx"
#   include "lantern/video/IImage.hxx"

#   include <d3d9.h>


namespace lantern {

    namespace video {


        class D3D9Driver;
        class D3DDepthSurface;


        /*!
         *
         */
        class D3D9Texture : public ITexture {
        };

        
    }    // end namespace video

}    // end namespace lantern


#endif  /* def JOL_COMPILE_WITH_DIRECT3D_9 */
