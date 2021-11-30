#pragma once
#include "spdlog/spdlog.h"
#include "../dme/Dme.h"
#include "../DMI/DMI.h"
#include <vector>
#include <map>
#include <set>
#include "../utils/string_helper.h"
#include "../../../third_party/glfw/deps/glad/gl.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
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

                GLuint* getTexture(std::string icon_state, int dir, int frame){
                    if(!dmipath.empty() && dmipath!="null")
                       if(tree->icon_states->find(dmipath + "/" + icon_state) != tree->icon_states->end())
                          return tree->icon_states->at(dmipath+"/"+icon_state)->at(dir).at(frame);
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
            icons = new std::map<std::string, DMI*>();
            images = new std::map<std::string, boost::gil::rgba8_image_t*>();
            //all of the states of every item;
            icon_states = new std::map<std::string, std::vector<std::vector<GLuint*>>*>();

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
                if(icons->find(dmipath) != icons->end()){
                    dmi = icons->at(dmipath);
                }else{
                    dmi = new DMI();
                    spdlog::info(dmipath);
                    std::filesystem::path fsdmipath(dmipath);
                    dmi->load(fsdmipath);
                    icons->emplace(dmipath,dmi);
                }   
                
              
                

                namespace bg = boost::gil;
                bg::rgba8_image_t *image;
                if(images->find(dmipath) != images->end()){
                    image = images->at(dmipath);
                }else{
                    image = new bg::rgba8_image_t();
                    bg::read_image(dmipath, *image,bg::png_tag{});

                    //png_read_image(path, img);
                    images->emplace(dmipath,image);
                }

                for(auto iS : dmi->states){
                    std::string state_name = iS.name;
                    std::vector<std::vector<GLuint*>> *imagens;

                    if(icon_states->find(dmipath+"/"+state_name) != icon_states->end()){
                        imagens = icon_states->at(dmipath+"/"+state_name);
                    }else{
                        imagens = new std::vector<std::vector<GLuint*>>();
                        
                        int direcao = 0;
                        for(auto dir: iS.images){
                            imagens->push_back(std::vector<GLuint*>());
           
                            int fram = 0;
                            for(auto frame: dir){
                                
                                GLuint *texture = new GLuint();
                                bg::rgba8c_view_t subImage = bg::subimage_view(bg::view(*image), frame.pos.x, frame.pos.y, frame.size.x, frame.size.y);
                                unsigned _width = static_cast<int>(subImage.width());
                                unsigned _height = static_cast<int>(subImage.height());

                                typedef bg::rgba8_pixel_t pixel;

                                //auto view = gil::interleaved_view(
                                //  img.width(), img.height(), &*gil::view(img).pixels(), img.width() * sizeof pixel);

                                //auto view = gil::interleaved_view(
                                //  img.width(), img.height(), &*gil::view(img).pixels(), img.width() * sizeof pixel);

                                auto pixeldata = new pixel[_width * _height  * 4];  


                                auto dstView = bg::interleaved_view(
                                _width, _height, pixeldata,  4 * _width);

                                bg::copy_pixels(subImage, dstView);

                            // bg::write_view(state+"output.png", dstView,bg::png_tag{});
                                glGenTextures(1, texture);
                                glBindTexture(GL_TEXTURE_2D, *texture);

                                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);      

                                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
                                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); 
                                glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);


                                glTexImage2D(GL_TEXTURE_2D,     // Type of texture
                                                0,                 // Pyramid level (for mip-mapping) - 0 is the top level
                                                GL_RGBA,            // Internal colour format to convert to
                                                subImage.width(),          // Image width  i.e. 640 for Kinect in standard mode
                                                subImage.height(),          // Image height i.e. 480 for Kinect in standard mode
                                                0,                 // Border width in pixels (can either be 1 or 0)
                                                GL_RGBA, // Input image format (i.e. GL_RGB, GL_RGBA, GL_BGR etc.)
                                                GL_UNSIGNED_BYTE,  // Image data type
                                                reinterpret_cast<void*>(pixeldata));         // The actual image data itself
                                glGenerateMipmap(GL_TEXTURE_2D);
                                glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
                                glBindTexture(GL_TEXTURE_2D, *texture);

                                free(pixeldata);
                                imagens->at(direcao).push_back(texture);
                            }
                            direcao++;
                        }

                        icon_states->emplace(dmipath+"/"+state_name,imagens);
                    }

                   

                }
                
            }
 
            TreeItem *it = new TreeItem(this,object,dmipath);
            items->emplace(object->type,it);
        


            for(auto subtype: *object->directSubtypes){
                generate_items(environment,environment->items->at(subtype));
            }

           // free(images);
            //free(icons);
            

            
        }

        private:
            BYOND::dme::Dme* environment;
            std::map<std::string,TreeItem*> *items;
            std::vector<TreeItem*> *instances;
            std::map<std::string,DMI*> *icons;
            std::map<std::string,boost::gil::rgba8_image_t*> *images;
            //all of the states of every item;
            std::map<std::string,std::vector<std::vector<GLuint*>>*> *icon_states;

        


    };

   

};