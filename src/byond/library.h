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

    public:
        std::ifstream *dme;
    private:
        ObjectTreeParser *outerInstance;

        private:
            class ThreadAnonymousInnerClass: public std::thread
            {
            private:
                ObjectTreeParser *outerInstance;

                static void BodyWrapper(ThreadAnonymousInnerClass* instance) {
                    try {
                       ObjectTreeParser *parser = new ObjectTreeParser();
                        parser->parseDME(instance->outerInstance->dme);
                        parser->tree->completeTree();
                        instance->outerInstance->tree = parser->tree;
                    } 
                    catch (const std::runtime_error &ex){
                        spdlog::error(ex.what());
                        instance->outerInstance->tree = nullptr;

                    
                    } //exception
                    std::lock_guard<std::mutex> lock(instance->joinMutex);
                    instance->done = true;
                    instance->join();
                } //BodyWrapper

                std::thread thread;
                std::condition_variable stateEvent, joinEvent;
                std::mutex stateMutex, joinMutex;
                bool done = false; // protected by joinMutex, joinEvent

            public:
                virtual ~ThreadAnonymousInnerClass()
                {
                    delete outerInstance;
                }

                ThreadAnonymousInnerClass(ObjectTreeParser *outerInstance) : outerInstance(outerInstance)
                {
                }

                void run()
                {
                    std::thread tmp(BodyWrapper, this);
                    thread.swap(tmp);
                    thread.detach();
                }
            };
            
    public:
        void openDME(std::string filepath)
            {
                std::ifstream fc(filepath, std::ios::binary );
               
                outerInstance->dme = std::filesystem::path(filepath); 
                dme = &fc;
            
                // PARSE TREE
                ThreadAnonymousInnerClass tempVar(this->outerInstance);
                (&tempVar)->run();
              

            }


    };
};
#endif