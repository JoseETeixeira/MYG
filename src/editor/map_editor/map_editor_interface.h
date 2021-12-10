#ifndef _MAP_EDITOR_INTERFACE_H
#define _MAP_EDITOR_INTERFACE_H

#pragma once

#include "../../../third_party/glfw/deps/glad/gl.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <library.h>
#include <utils/string_helper.h>
#include <DMM/Location.h>






namespace MYG{

class MapEditorInterface{

private:
   
    std::string fileToEdit = "";
    BYOND::Library* library;
    GLFWwindow* window;
    int xpos,ypos,width,height;
    ImVec4 clear_color = ImVec4(0.07f,0.13f,0.17f,1.0f);

    

public:
   
    MapEditorInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height):
    window(window), library(library),xpos(xpos),ypos(ypos),width(width),height(height)
    {
   

    }

       void drawTiles (int z) { //our function to draw the tiles
        for(auto mi : *library->dmm->map){
            if(mi.first->z == z){
                ImVec2 p =  ImVec2(ImGui::GetItemRectMin().x + mi.first->x*32,ImGui::GetItemRectMin().y +  mi.first->y*32);
                std::string instanceKey = mi.second;
                //spdlog::info ("LOOKING FOR: {}, {}, {}",std::to_string(mi.first->x),std::to_string(mi.first->y),std::to_string(mi.first->z));
                if(library->dmm->instances->left.find(instanceKey) != library->dmm->instances->left.end()){
                    BYOND::dmm::DMM::TileInstance *ti = library->dmm->instances->left.at(instanceKey);
                    for(auto obj: *ti->objs){

                        std::thread t([this,obj,p]{
                        
                        ImGui::GetWindowDrawList()->AddImage((void*)*obj->getTexture(obj->getIconState()), p, ImVec2(p.x+32, p.y+32), ImVec2(0,0), ImVec2(1,1)); 
                        });
                        t.join();
                    }
                }else //otherwise
                {
                    
                    spdlog::info("LOC NOT FOUND {} {} {}",std::to_string(mi.first->x),std::to_string(mi.first->y),std::to_string(mi.first->z));
                    ImVec2 p =  ImVec2(ImGui::GetItemRectMin().x + mi.first->x*32,ImGui::GetItemRectMin().y + mi.first->y*32);
                    ImGui::GetWindowDrawList()->AddImage((void*)*library->tree->getItem("/turf")->getTexture("2_2"), p, ImVec2(p.x+32, p.y+32), ImVec2(0,0), ImVec2(1,1)); 

                    
                
                }
            }
            
            
        }
    }


    void draw(bool shouldOpen) {    
        if(shouldOpen){
            // clear (has to be done at the beginning)    
          
            std::thread t([this]{
                   drawTiles(1); 
                    
            });

            t.join();
            //draw our tiles

            //for(auto tileObject : *library->dmm->map){
              //  spdlog::info(std::to_string(tileObject.first->x) +"/"+ std::to_string(tileObject.first->y) +"/"+ std::to_string(tileObject.first->z));
           // }
   
        }
        
    }
    

    void mainLoop(){

           

            ImGui::Begin("Map Editor", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
            ImGui::SetWindowSize(ImVec2(width*0.8, height*0.8), ImGuiCond_FirstUseEver);
            
            bool shouldOpen = library->isMapOpen();
            static int selection_mask = 0;
            


            draw(shouldOpen);
               

                        
        


            ImGui::End();

          

    }

    




};

};


#endif