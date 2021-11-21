#pragma once

#include <cstdint>
#include <vector>

struct Vec {
    unsigned x, y;
};

struct Image {
    Vec size;
    std::vector<uint8_t> pixels;
};
