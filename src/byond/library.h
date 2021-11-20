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
#include "../editor/source_navigation/tree/DME_Tree_Model.h"




namespace BYOND{
    
    class Library {


    private:
        std::string currentDME = "";
        bool done = false;
        BYOND::DME_Parser *parser;
        MYG::DME_Tree_Tree_Model *treeModel;
        
            
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
                parser = new BYOND::DME_Parser(&p);

                spdlog::info("Parser created");

                treeModel = new MYG::DME_Tree_Tree_Model(parser->tree);
                spdlog::info("Tree model listener created");

                parser->parseDME();

                spdlog::info("Parsing done");

                done = true;

            }
        }

        MYG::DME_Tree_Tree_Model *getTree(){
            return this->treeModel;
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