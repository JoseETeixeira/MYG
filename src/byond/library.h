
#ifndef _BYOND_LIBRARY_H
#define _BYOND_LIBRARY_H

#pragma once

#include "spdlog/spdlog.h"
#include <filesystem>
#include <iostream>
#include <sstream>
#include <fstream>
#include "dme/parser/DmeParser.h"

#include <thread>




namespace BYOND{
    
    class Library {


    private:
        std::string currentDME = "";
        bool done = false;
        BYOND::dme::parser::DmeParser *parser;
            
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
                    BYOND::dme::parser::DmeParser *parser = new   BYOND::dme::parser::DmeParser();
                    parser->parse(p);
                    this->parser = parser;
                    
                });

                t.join();
                

                spdlog::info("Parsing done");

                done = true;

            }
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