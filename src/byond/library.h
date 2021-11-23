
#ifndef _BYOND_LIBRARY_H
#define _BYOND_LIBRARY_H

#pragma once

#include "spdlog/spdlog.h"
#include <filesystem>
#include <iostream>
#include <sstream>
#include <fstream>
#include "parser/DME_parser.h"
#include "tree/DME_tree.h"
#include "../editor/source_navigation/tree/DME_Tree_Model.h"
#include <thread>




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
               

                std::thread t([this, filepath]{
                    std::ifstream dmeFile(filepath);
                    std::filesystem::path p = filepath;
                    BYOND::DME_Parser *parser = new BYOND::DME_Parser(&p);
                    treeModel = new MYG::DME_Tree_Tree_Model(parser->tree);
                    spdlog::info("Tree model listener created");
                    parser->parseDME();
                    //parser->tree->completeTree();
                    this->parser = parser;
                    
                });

                t.join();
                

                spdlog::info("Parsing done");

                done = true;

            }
        }

        MYG::DME_Tree_Tree_Model *getTree(){
            return this->treeModel;
        }

        DME_Tree *getMainTree(){
            return this->parser->tree;
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