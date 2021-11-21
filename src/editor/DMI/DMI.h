#pragma once

#include <cstdio>
#include <filesystem>
#include <functional>
#include <string>
#include <vector>

#include "codecs/image.h"
#include "codecs/png.h"
#include "errors.h"

class DMI {
public:
    class State {
    public:
        State(std::string name);

        void load(PNG &png, unsigned width, unsigned height, unsigned &index);
        void split(std::filesystem::path path);

        void save(PNG &png, unsigned &index);
        void join(std::filesystem::path path);

        std::string name;
        unsigned dirs = 1;
        unsigned frames = 1;
        unsigned loop = 0;
        std::vector<float> delays;

        Vec size() const;

    protected:
        static const char *dirname(unsigned d);
        static int dirnum(const std::string name);

        void write_frames(unsigned dir, std::filesystem::path path);
        void reduplicate();

        std::vector<std::vector<Image>> images;
    };

    void load(std::filesystem::path fname);
    void split(std::filesystem::path path,std::function<void(int total, int i, std::string name)> callback);

    void save(std::filesystem::path fname);
    void join(std::filesystem::path path,
                     std::function<void(int total, int i, std::string name)> callback);

    std::string name;
    float version = 4.0;
    unsigned width, height;
    std::vector<State> states;

protected:
    void load_states(std::string data);
    std::string gen_states();
};
