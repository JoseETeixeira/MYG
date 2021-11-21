#include "png.h"
#include "file.h"
#include "../errors.h"

#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>

PNG::ReadHandle::ReadHandle() {
    png = png_create_read_struct(
        PNG_LIBPNG_VER_STRING, nullptr,
        [](png_structp, const char *) {
            throw ReasonError("internal libpng read error");
        },
        nullptr);
    if (!png)
        throw ReasonError("couldn't create libpng read struct");

    info = png_create_info_struct(png);
    if (!info)
        throw ReasonError("couldn't create PNG info struct");
}

PNG::ReadHandle::~ReadHandle() {
    png_destroy_read_struct(&png, &info, nullptr);
}

PNG::WriteHandle::WriteHandle() {
    png = png_create_write_struct(
        PNG_LIBPNG_VER_STRING, nullptr,
        [](png_structp, const char *) {
            throw ReasonError("internal libpng write error");
        },
        nullptr);
    if (!png)
        throw ReasonError("couldn't create libpng write struct");

    info = png_create_info_struct(png);
    if (!info)
        throw ReasonError("couldn't create PNG info struct");
}

PNG::WriteHandle::~WriteHandle() { png_destroy_write_struct(&png, &info); }

PNG::PNG(Vec size) : image_size(size) {
    rows = new uint8_t *[size.y];
    for (unsigned i = 0; i < size.y; i++)
        rows[i] = new uint8_t[size.x * 4];

    // fill with alpha
    for (unsigned i = 0; i < size.y; i++)
        std::memset(rows[i], 0, size.x*4);
}

PNG::~PNG() {
    if (!rows)
        return;
    for (unsigned i = 0; i < image_size.y; i++)
        delete[] rows[i];
    delete[] rows;
}

static bool dmi_check_sig(uint8_t *sig) {
    const uint8_t expected[] = {0x04, 0x44, 0x4d, 0x49};
    return std::equal(sig, sig + 4, expected);
}

void PNG::load(std::filesystem::path path) {
    FileHandle file(path.string().c_str(), "rb");

    uint8_t sig[8];
    fread(sig, 1, 8, file.file);
    if (dmi_check_sig(sig))
        throw ReasonError("old-style DMIs are not supported");
    else if (!png_check_sig(sig, 8))
        throw ReasonError("not a PNG file");

    ReadHandle handle;

    png_init_io(handle.png, file.file);
    png_set_sig_bytes(handle.png, 8);
    png_read_info(handle.png, handle.info);

    png_set_palette_to_rgb(handle.png);
    png_set_tRNS_to_alpha(handle.png);

    image_size = {png_get_image_width(handle.png, handle.info),
                  png_get_image_height(handle.png, handle.info)};

    rows = new uint8_t *[image_size.y];
    for (unsigned i = 0; i < image_size.y; i++)
        rows[i] = new uint8_t[image_size.x * 4];

    png_set_rows(handle.png, handle.info, rows);
    png_read_image(handle.png, rows);

    png_textp t;
    int num;
    png_get_text(handle.png, handle.info, &t, &num);

    if (num < 1)
        throw ReasonError("incorrect PNG text blocks");

    text = std::string(t->text);
}

void PNG::save(std::filesystem::path path) {
    FileHandle file(path.string().c_str(), "wb");
    WriteHandle handle;

    png_init_io(handle.png, file.file);

    png_set_IHDR(handle.png, handle.info, image_size.x, image_size.y, 8,
                 PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    std::string title = "Description";
    png_text t = {
        PNG_TEXT_COMPRESSION_zTXt,
        title.data(),
        text.data(),
        text.size(),
        0, nullptr,
    };

    png_set_text(handle.png, handle.info, &t, 1);
    png_write_info(handle.png, handle.info);

    png_write_image(handle.png, rows);
    png_write_end(handle.png, nullptr);
}

Image PNG::slice(Vec pos, Vec size) {
    Image ret;
    ret.size = size;
    ret.pixels.resize(size.x * size.y * 4);
    for (unsigned i = 0; i < size.y; i++) {
        std::copy_n(rows[i + pos.y] + pos.x * 4, size.x * 4,
                    ret.pixels.begin() + i * size.x * 4);
    }
    return ret;
}

void PNG::insert(Vec pos, Image img) {
    for (unsigned i = 0; i < img.size.y; i++) {
        auto p = img.pixels.begin() + i * 4 * img.size.x;
        std::copy_n(p, 4 * img.size.x, rows[i + pos.y] + pos.x * 4);
    }
}
