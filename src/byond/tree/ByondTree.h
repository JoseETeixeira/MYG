#pragma once
#include "spdlog/spdlog.h"
#include "../dme/Dme.h"
#include "../DMI/DMI.h"
#include "Icon.h"
#include <vector>
#include <map>
#include <set>
#include "../utils/string_helper.h"

#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>
#include <boost/gil/extension/numeric/sampler.hpp>
#include <boost/gil/extension/numeric/resample.hpp>

// I need this bugfix to compile against libpng 1.5, your mileage may vary
#define int_p_NULL (int*)NULL
// done with the fix


namespace BYOND::tree {

    class Tree{
        public:

            class TreeItem{

            private:
                //The DME item this relates to
                BYOND::dme::Dme::DmeItem *item;
                Tree *tree;
                std::string dmipath;
                std::string name;
                

                
                


            public:
                std::set<std::string> *directSubtypes;

                TreeItem(Tree *tree,BYOND::dme::Dme::DmeItem *item, std::string dmipath = "null"):tree(tree),item(item){
                    this->dmipath = dmipath;
                    this->name = item->type.substr(item->type.find_last_of("/"),item->type.length());
                    this->directSubtypes = item->directSubtypes;
                }

                GLuint* getTexture(std::string icon_state, int dir = 0, int frame = 0){
                    if(!dmipath.empty() && dmipath!="null")
                       if(tree->icons->find(item->getVar("icon") ) != tree->icons->end())
                          return tree->icons->at(item->getVar("icon"))->getIconState(icon_state,dir,frame);
                    return nullptr;
                }

                std::string getName(){
                    return this->name;
                }

                std::string getIconState(){
                    return this->item->getVar("icon_state");
                }

                std::string getVar(std::string var){
                    return this->item->getVar(var);
                }
                
                

                


                

                


            };

        Tree(BYOND::dme::Dme *environment,std::string root = "/atom"):environment(environment){
            BYOND::dme::Dme::DmeItem *atom = environment->items->at(root);
 
            items = new std::map<std::string, TreeItem*>();
            instances = new std::vector<TreeItem*>();
            icons = new std::map<std::string, Icon*>();

            TreeItem* it = new TreeItem(this, atom, "null");
            items->emplace(atom->type, it);

            for(auto item : *atom->directSubtypes){
                spdlog::info(item);

                generate_items(environment,environment->items->at(item));
                

            }
        }

        TreeItem* getItem(std::string rootPath){
            if(items->find(rootPath) != items->end())
                return items->at(rootPath);
            return nullptr;
        }

        void generate_items(BYOND::dme::Dme *environment,BYOND::dme::Dme::DmeItem *object){

            //TODO: EMPLACE ITEM AFTER GENERATING
            DMI  *dmi;
            std::string icon = "null";
            std::string icon_state = "null";
            std::string dmipath = "null";
            icon = object->getVar("icon");
            spdlog::info(icon);
            if(icon != "null" && !icon.empty()){
                 
                #if defined(WIN32)
                    dmipath= environment->fileDir + environment->absoluteRootPath + StringHelper::ReplaceAll(icon,"/","\\").substr(1, StringHelper::ReplaceAll(icon, "/", "\\").length()-2);
                #else if defined(LINUX)
                    dmipath = environment->fileDir + environment->absoluteRootPath + StringHelper::ReplaceAll(icon,"\\","/").substr(1, StringHelper::ReplaceAll(icon, "\\","/").length()-2);
                #endif
                
                Icon *ico = new Icon(icon,dmipath);
                icons->emplace(icon,ico);

                
            }

            TreeItem *it = new TreeItem(this,object,dmipath);
            items->emplace(object->type,it);
        


            for(auto subtype: *object->directSubtypes){
                generate_items(environment,environment->items->at(subtype));
            }
 

            
        }

        private:
            BYOND::dme::Dme* environment;
            std::map<std::string,TreeItem*> *items;
            std::vector<TreeItem*> *instances;
            std::map<std::string,Icon*> *icons;

        


    };

   

};