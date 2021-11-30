#pragma once

#include <cstdint>
#include <vector>
#include <cstring>




struct Vec {
    unsigned x, y;
};

class Image {
public:
    Vec size;
    Vec pos;
    std::vector<uint8_t> pixels;

    
    Image(){};
};
