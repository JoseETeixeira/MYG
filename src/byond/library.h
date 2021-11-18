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
#include "objtree/ObjectTree.h"

namespace BYOND{
    
    class Library {


    private:
        ObjectTreeParser* parser;
        std::string currentDME = "";
        bool done = false;
        
            
    public:
    
        void openDME(std::string filepath) {

            if(currentDME != filepath ){
                delete parser;

                currentDME = filepath;
                parser = new ObjectTreeParser();
                // PARSE TREE
            
                parser->parseDME(filepath);
                //spdlog::info("Tree size: {}", parser->tree->items.size());
                parser->tree->completeTree();
                done = true;

            }
            
            // parser->tree->dumpTree();
                //tree->completeTree();
                //spdlog::info("Tree dump: {}", tree->get(".")->path);
            
            
        }

        bool isDone(){
            return done == true;
        }

        ObjectTree* getTree(){
            if(parser !=nullptr ){
                if(parser->tree != nullptr){
                    return parser->tree;
                }
                else{
                    spdlog::error("Parser tree not loaded");
                    return nullptr;
                }
            }else{
                spdlog::error("No DME file loaded");
                return nullptr;
            }
        }



              

     


    };
};
#endif