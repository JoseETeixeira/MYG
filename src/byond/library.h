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
        ObjectTreeParser* parser;
            
    public:
        void openDME(std::string filepath) {
            parser = new ObjectTreeParser();
            // PARSE TREE
          
            parser->parseDME(filepath);
            spdlog::info("Tree size: {}", parser->tree->items.size());
            parser->tree->completeTree();
                //tree->completeTree();
                //spdlog::info("Tree dump: {}", tree->get(".")->path);
            
            
        }

              

     


    };
};
#endif