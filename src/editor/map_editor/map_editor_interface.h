#ifndef _MAP_EDITOR_INTERFACE_H
#define _MAP_EDITOR_INTERFACE_H

#pragma once

#include "../../../third_party/glfw/deps/glad/gl.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "../../byond/library.h"
#include "../../byond/utils/string_helper.h"
#include "../../byond/DMM/Location.h"



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
        for (int i = library->dmm->minX; i < library->dmm->maxX; i+=32) //loop through the height of the map
        {
            for (int j = library->dmm->minY; j < library->dmm->maxY; j+=32) //loop through the width of the map
            {
                BYOND::dmm::Location *loc = new BYOND::dmm::Location(i,j,z);
                if (library->dmm->map->find(loc) == library->dmm->map->end()) //if the map at this position contains a 0
                {
                    ImGui::GetWindowDrawList()->AddImage((void *)*library->tree->getItem("/turf")->getTexture("null"), ImVec2(ImGui::GetItemRectMin().x + i,ImGui::GetItemRectMin().y + j),ImVec2(i, j), ImVec2(0, 0), ImVec2(1, 1));
                }    
                else //otherwise
                {
                    std::string instanceKey = library->dmm->map->at(loc);
                    BYOND::dmm::DMM::TileInstance *ti = library->dmm->instances->left.at(instanceKey);
                    for(auto obj: *ti->objs){
                        ImGui::GetWindowDrawList()->AddImage( (void *) *obj->getTexture(obj->getIconState()), ImVec2(ImGui::GetItemRectMin().x + i,ImGui::GetItemRectMin().y + j),ImVec2(i, j), ImVec2(0, 0), ImVec2(1, 1));           
                    }
                    //getKeyForInstance
                   
                }

            } //end first loop
        } //end second loop
    }


    void draw(bool shouldOpen) {    
        if(shouldOpen){
            // clear (has to be done at the beginning)    
          

            drawTiles(1); //draw our tiles
   
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