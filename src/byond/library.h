#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "spdlog/spdlog.h" 
#include <thread>
#include <mutex>
#ifndef _BYOND_LIBRARY_H
#define _BYOND_LIBRARY_H

#pragma once

#include "objtree/ObjectTreeParser.h"

namespace BYOND{
    
    class Library {


    private:
        ObjectTreeParser parser;
            
    public:
        void openDME(std::string filepath)
               
            
            // PARSE TREE
            try {
                parser.parseDME(filepath);
                parser.tree->completeTree();
            }
            catch (const std::runtime_error& ex) {
                spdlog::error(ex.what());
                parser.tree = nullptr;

            }
              

     


    };
};
#endif