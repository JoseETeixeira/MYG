#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <spdlog/spdlog.h>
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
        void InneropenDME(std::ifstream filetoopen)
            {
                
                dme = &filetoopen;
                // PARSE TREE
                ThreadAnonymousInnerClass tempVar(outerInstance);
                (&tempVar)->run();
            }

        private:
            class ThreadAnonymousInnerClass 
            {
            private:
                ObjectTreeParser *outerInstance;

                static void BodyWrapper(ThreadAnonymousInnerClass* instance) {
                    try {
                       ObjectTreeParser *parser = new ObjectTreeParser();
                        parser->modalParent = outerInstance;
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
                    instance->joinEvent.notify_all();
                    instance->Terminated();
                } //BodyWrapper

                std::thread thread;
                std::condition_variable stateEvent, joinEvent;
                std::mutex stateMutex, joinMutex;
                Action state = Action::wakeup; // protected by statusMutex, statusEvent
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
                {
                    InneropenDME(fc);
                }

            }


    };
};
#endif