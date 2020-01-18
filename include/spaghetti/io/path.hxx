#pragma once

#include <filesystem>

namespace spaghetti {
    namespace io {

#if __cplusplus >= 201703L

        // filesystem は C++17 以降なので…
        using path = std::filesystem::path;
#else


        /*!
         *
         */
        class path {
        };

        
#endif  /* __cplusplus > 199717L */

    }   // end namespace io
}   // end namespace spaghetti
