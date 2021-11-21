#include "dmi.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <sstream>
#include "codecs/image.h"
#include "codecs/png.h"
#include "errors.h"


#if defined(WIN32)  || defined (_WIN32)
    #pragma comment(lib, "libwebp.lib")
#else
/* Do linux stuff */
#endif

#include "codecs/webp.h"
#include "errors.h"

namespace fs = std::filesystem;

void DMI::load(fs::path fname) {
    name = fname.stem().string();
    PNG png;
    png.load(fname);

    std::string data = png.text;
    load_states(data);

    unsigned index = 0;
    for (auto &s : states) {
        s.load(png, width, height, index);
    }
}

void DMI::save(fs::path fname) {
    unsigned num = 0;
    for (auto &s : states)
        num += s.dirs * s.frames;

    unsigned size = std::ceil(std::sqrt(num));
    PNG png{{size * width, size * height}};

    unsigned index = 0;
    for (auto &s : states) {
        s.save(png, index);
    }

    png.text = gen_states();
    png.save(fname);
}

static std::string getline(std::istream &input, char delim) {
    std::string s;
    std::getline(input, s, delim);
    return s;
}

void DMI::load_states(std::string data) {
    std::istringstream dmi_str{data};
    if (getline(dmi_str, '\n') != "# BEGIN DMI")
        throw ReasonError{"no DMI metadata"};

    getline(dmi_str, '=');
    dmi_str >> version;

    if (dmi_str.fail())
        throw ReasonError{"bad version/size header"};

    auto s = getline(dmi_str, '\n');
    size_t pos = dmi_str.tellg();
    if (getline(dmi_str, '=') != "\twidth ") {
        width = 32;
        height = 32;
        dmi_str.seekg(pos);
    } else {
        dmi_str >> width;
        getline(dmi_str, '=');
        dmi_str >> height;
        getline(dmi_str, '\n');
    }

    if (version != 4.0)
        throw VersionError(version, 4.0);

    while (getline(dmi_str, '"') == "state = ") {
        std::string name = getline(dmi_str, '"');
        if (name == "")
            name = "default";
        states.emplace_back(name);
        DMI::State &cur = states[states.size() - 1];

        while (isspace(dmi_str.peek())) {
            while (isspace(dmi_str.peek()))
                dmi_str.get();

            std::string property = getline(dmi_str, ' ');
            getline(dmi_str, '=');

            if (property == "dirs") {
                dmi_str >> cur.dirs;
            } else if (property == "frames") {
                dmi_str >> cur.frames;
            } else if (property == "delay") {
                do {
                    dmi_str >> cur.delays.emplace_back();
                } while (dmi_str.peek() == ',' && dmi_str.get());
            } else if (property == "loop") {
                dmi_str >> cur.loop;
            } else if (property == "rewind") {
            } else if (property == "hotspot") {
            } else if (property == "movement") {
            } else {
                std::cerr << " " << property << "\n";
                throw ReasonError{"unknown DMI property encountered"};
            }

            getline(dmi_str, '\n');
        }
    }
}

std::string DMI::gen_states() {
    std::ostringstream dmi_str;

    dmi_str << "# BEGIN DMI\n";

    dmi_str << "version = " << version << "\n";
    dmi_str << "\twidth = " << width << "\n";
    dmi_str << "\theight = " << height << "\n";

    for (auto &s : states) {
        if (s.name == "default")
            dmi_str << "state = \"\"\n";
        else
            dmi_str << "state = \"" << s.name << "\"\n";

        dmi_str << "\tdirs = " << s.dirs << "\n";
        dmi_str << "\tframes = " << s.frames << "\n";

        if (s.frames > 1) {
            dmi_str << "\tdelay = ";
            bool first = true;
            for (auto d : s.delays) {
                if (!first) {
                    dmi_str << ",";
                }
                dmi_str << d;
                first = false;
            }
            dmi_str << "\n";

            if (s.loop)
                dmi_str << "\tloop = " << s.loop << "\n";
        }
    }

    dmi_str << "# END DMI\n";

    return dmi_str.str();
}

DMI::State::State(std::string name) : name(name) {}

void DMI::State::load(PNG &png, unsigned width, unsigned height,
                      unsigned &index) {
    images.resize(dirs);
    for (unsigned i = 0; i < dirs; i++)
        images[i].resize(frames);

    for (unsigned f = 0; f < frames; f++) {
        for (unsigned d = 0; d < dirs; d++) {
            unsigned x = (index * width) % png.image_size.x;
            unsigned y = (index / (png.image_size.x / width)) * height;
            images[d][f] = png.slice({x, y}, {width, height});
            index++;
        }
    }
}

void DMI::State::save(PNG &png, unsigned &index) {
    auto size = images[0][0].size;

    for (unsigned f = 0; f < frames; f++) {
        for (unsigned d = 0; d < dirs; d++) {
            unsigned x = (index * size.x) % png.image_size.x;
            unsigned y = (index / (png.image_size.x / size.x)) * size.y;
            png.insert({x, y}, images[d][f]);
            index++;
        }
    }
}

void DMI::split(fs::path path,
                std::function<void(int, int, std::string)> callback) {
    fs::create_directory(path);
    int i = 1;
    int total = states.size();
    for (auto &s : states) {
        callback(total, i, s.name);
        s.split(path / s.name);
        i++;
    }
}

const char *DMI::State::dirname(unsigned d) {
    switch (d) {
    case 0:
        return "down";
    case 1:
        return "up";
    case 2:
        return "right";
    case 3:
        return "left";
    case 4:
        return "downright";
    case 5:
        return "downleft";
    case 6:
        return "upright";
    case 7:
        return "upleft";
    default:
        throw ReasonError("unknown direction");
    }
}

void DMI::State::split(fs::path path) {
    if (dirs == 1) {
        write_frames(0, path);
        return;
    }

    fs::create_directory(path);
    for (unsigned d = 0; d < dirs; d++) {
        write_frames(d, path / dirname(d));
    }
}

void DMI::State::write_frames(unsigned int dir, std::filesystem::path path) {
    WebP webp{images[dir], delays, loop};
    webp.save(path.replace_extension("webp"));
}

Vec DMI::State::size() const { return images[0][0].size; }

int DMI::State::dirnum(const std::string name) {
    if (name == "down")
        return 0;
    else if (name == "up")
        return 1;
    else if (name == "right")
        return 2;
    else if (name == "left")
        return 3;
    else if (name == "downright")
        return 4;
    else if (name == "downleft")
        return 5;
    else if (name == "upright")
        return 6;
    else if (name == "upleft")
        return 7;
    else
        throw ReasonError("unknown direction name");
}

void DMI::State::reduplicate() {
    frames = 0;
    for (auto &d : images)
        frames = std::max(frames, (unsigned)d.size());

    for (auto &d : images) {
        if (d.size() < frames) {
            for (unsigned i = 0; i < d.size() - frames; i++)
                d.push_back(d[0]);
        }
    }
}

void DMI::State::join(std::filesystem::path path) {
    if (fs::is_directory(path)) {
        images.resize(8);
        unsigned total = 0;
        for (auto &p : fs::directory_iterator(path)) {
            WebP webp;
            webp.load(p.path());
            images[dirnum(p.path().stem().string())] = webp.frames;
            delays = webp.delays;
            loop = webp.loops;
            total++;
        }
        images.resize(total);
    } else {
        dirs = 1;
        WebP webp;
        webp.load(path);
        images.push_back(webp.frames);
        delays = webp.delays;
        loop = webp.loops;
    }

    dirs = images.size();
    reduplicate();
}

void DMI::join(
    std::filesystem::path path,
    std::function<void(int total, int i, std::string name)> callback) {
    unsigned total = 0;
    for (auto &p : fs::directory_iterator(path))
        (void)p, total++;

    unsigned i = 0;
    for (auto &p : fs::directory_iterator(path)) {
        auto &state = states.emplace_back(p.path().stem().string());
        state.join(p);
        callback(total, i++, state.name);
    }

    width = states[0].size().x;
    height = states[0].size().y;
}
