#include "file.h"

#include "../errors.h"
#include "spdlog/spdlog.h"
#include <stdio.h>
#include "../../../byond/utils/string_helper.h"
#include <sys/stat.h>

inline bool exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

FileHandle::FileHandle(const char *fname, const char *mode) {
    spdlog::info(fname);
    if(StringHelper::endsWith(fname,"null")){
        spdlog::error("null file passed");
    }
    else{
        if(exists(fname)){
            file = fopen(fname, mode);
        }
        
        else{
            spdlog::error("file does not exist : {}",fname);
            file = nullptr;
        }
            
    }
   
}

FileHandle::~FileHandle() { fclose(file); }
