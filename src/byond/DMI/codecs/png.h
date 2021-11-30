#pragma once


#if defined(WIN32)
    #include "../../deps/libpng/png.h"
    #include "../../deps/zlib-1.2.11/zlib.h"
#else if defined(LINUX)
    #include <zlib.h>
    #include <png.h>
#endif

#include <cstdio>
#include <filesystem>
#include <fstream>

#include "image.h"

class PNG {
public:
    PNG() = default;
    PNG(Vec size);
    PNG(const PNG &) = delete;
    PNG &operator=(const PNG &) = delete;
    ~PNG();

    void load(std::filesystem::path path);
    Image slice(Vec pos, Vec size);

    void save(std::filesystem::path path);
    void insert(Vec pos, Image img);

    Vec image_size;
    std::string text;

protected:
    class ReadHandle {
    public:
        ReadHandle();
        ~ReadHandle();

        png_structp png;
        png_infop info;
    };

    class WriteHandle {
    public:
        WriteHandle();
        ~WriteHandle();

        png_structp png;
        png_infop info;
    };

    uint8_t **rows = nullptr;
};
