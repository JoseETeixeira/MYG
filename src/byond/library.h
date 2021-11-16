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
        ObjectTree* tree;
            
    public:
        void openDME(std::string filepath) {
            tree = new ObjectTree();
            parser = new ObjectTreeParser(tree);
            // PARSE TREE
            try {
                parser->parseDME(filepath);
                //spdlog::info("Tree dump: {}", tree->get(".")->path);
            }
            catch (const std::runtime_error& ex) {
                spdlog::error(ex.what());
                tree = nullptr;

            }
        }

              

     


    };
};
#endif