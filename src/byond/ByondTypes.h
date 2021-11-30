#pragma once
#include <string>

namespace BYOND{
    
    class ByondTypes {

        public:
            static inline std::string NULLS = "null"; // FROM NULL

            /** Holder to store all variables with global scope. */
            static inline std::string GLOBAL = "GLOBAL";

            static inline std::string DATUM = "/datum";
            static inline std::string WORLD = "/world";
            static inline std::string CLIENT = "/client";
            static inline std::string LIST = "/list";
            static inline std::string SAVEFILE = "/savefile";

            static inline std::string ATOM = "/atom";
            static inline std::string ATOM_MOVABLE = "/atom/movable";

            static inline std::string AREA = "/area";
            static inline std::string TURF = "/turf";
            static inline std::string OBJ = "/obj";
            static inline std::string MOB = "/mob";

            ByondTypes() {}
    };
}

