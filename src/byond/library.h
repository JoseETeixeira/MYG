#include "spdlog/spdlog.h"
#include <filesystem>
#include <iostream>
#include <sstream>
#include <fstream>
#ifndef _BYOND_LIBRARY_H
#define _BYOND_LIBRARY_H

#pragma once


#include "parser/DME_parser.h"
#include "tree/DME_tree.h"




namespace BYOND{
    
    class Library {


    private:
        std::string currentDME = "";
        bool done = false;
        BYOND::DME_Parser *parser;
        
            
    public:
    
        Library(){};

        /**
         * @brief Opens the DME file passed if it's different from the current one and parses it
         * 
         * @param filepath 
         */
        void openDME(std::string filepath) {
            spdlog::info("Opening DME");

            if(filepath != currentDME){
                //TODO: Do parse
                std::ifstream dmeFile(filepath);
                std::filesystem::path p = filepath;
                parser = new BYOND::DME_Parser(&dmeFile,&p);

                spdlog::info("Parser created");

                parser->parseSynchronously();

                spdlog::info("Parsing done");

                done = true;

            }
        }

        DME_Tree *getTree(){
            return parser->tree;
        }

        std::unordered_map<std::string, DME_Tree_Item*> getTreeItems(DME_Tree *tree){
            return tree->pathCache;
        }

        /**
         * @brief informs if the current DME file has finished being parsed
         * 
         * @return true 
         * @return false 
         */
        bool isDone(){
            
            return done == true;
        }

       



              

     


    };
};
#endif