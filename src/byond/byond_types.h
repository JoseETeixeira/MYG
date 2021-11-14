#include <string>

namespace BYOND {
class ByondTypes {

public:

    const std::string  null = "null"; // remember to change NULL to null everywhere

    /** Holder to store all variables with global scope. */
    const std::string   GLOBAL = "GLOBAL";

    const std::string    DATUM = "/datum";
    const std::string    WORLD = "/world";
    const std::string    CLIENT = "/client";
    const std::string    LIST = "/list";
    const std::string    SAVEFILE = "/savefile";

    const std::string    ATOM = "/atom";
    const std::string    ATOM_MOVABLE = "/atom/movable";

    const std::string    AREA = "/area";
    const std::string    TURF = "/turf";
    const std::string    OBJ = "/obj";
    const std::string    MOB = "/mob";

    ByondTypes();
};
};