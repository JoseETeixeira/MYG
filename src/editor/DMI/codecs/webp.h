#pragma once
#if defined(WIN32)  || defined (_WIN32)
    #pragma comment(lib, "libwebp.lib")
    #pragma comment(lib, "libwebpmux.lib")
    #pragma comment(lib, "libwebpdemux.lib")
#else
/* Do linux stuff */
#endif

#include <filesystem>
#include <vector>
#include "../../deps/libwebp/include/webp/demux.h"

#include "image.h"

class WebP {
public:
    WebP() = default;
    WebP(std::vector<Image> frames, std::vector<float> delays, unsigned loops);

    void save(std::filesystem::path path);
    void load(std::filesystem::path path);

    std::vector<Image> frames;
    std::vector<float> delays;
    unsigned loops;

protected:
    struct DecoderHandle {
        DecoderHandle(WebPData *data, WebPAnimDecoderOptions *opts);
        ~DecoderHandle();

        WebPAnimDecoder *d;
    };
};
