#include "file.h"

#include "../errors.h"

FileHandle::FileHandle(const char *fname, const char *mode) {
    file = fopen(fname, mode);
    if (!file)
        throw ReasonError("error opening file for reading");
}

FileHandle::~FileHandle() { fclose(file); }
