#pragma once

#include <cstdio>

class FileHandle {
public:
    FileHandle(const char *fname, const char *mode);
    ~FileHandle();

    FILE *file;
};
