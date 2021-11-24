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
    Vec image_size;
    Vec pos;
    std::vector<uint8_t> pixels;
    uint8_t **rows;
    Image(){};
    Image(uint8_t **r,Vec is):image_size(is),rows(r){
    };
};
