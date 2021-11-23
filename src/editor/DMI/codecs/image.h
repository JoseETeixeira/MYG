#pragma once

#include <cstdint>
#include <vector>


struct Vec {
    unsigned x, y;
};

struct Image {
    Vec size;
    Vec pos;
    std::vector<uint8_t> pixels;
};
