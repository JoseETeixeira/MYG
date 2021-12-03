
#ifndef _BYOND_LIBRARY_H
#define _BYOND_LIBRARY_H

#pragma once

#include "spdlog/spdlog.h"
#include <filesystem>
#include <iostream>
#include <sstream>
#include <fstream>
#include "dme/parser/DmeParser.h"
#include "tree/ByondTree.h"
#include <thread>
#include "DMM/dmm.h"
#include <string>



namespace BYOND{
    
    class Library {


    private:
        std::string currentDME = "";
        bool done = false;
        
            
    public:

        BYOND::dme::Dme *DME;
        BYOND::tree::Tree *tree;
        BYOND::dmm::DMM *dmm;

        ~Library(){
            free(DME);
            free(tree);
        }

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
                    BYOND::dme::parser::DmeParser *parser = new   BYOND::dme::parser::DmeParser();
                    
                    this->DME = parser->parse(p);
                    
                });

                t.join();
                
                this->tree = new BYOND::tree::Tree(this->DME);

                spdlog::info("Parsing done");

                done = true;

            }
        }

        void openMap(std::filesystem::path *p){
            dmm = new BYOND::dmm::DMM(p,this->tree);
            spdlog::info(std::to_string(dmm->maxX));
            spdlog::info(std::to_string(dmm->maxY));
            spdlog::info(std::to_string(dmm->maxZ));
            spdlog::info(std::to_string(dmm->instances->size()));
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