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

   

    void mainLoop(){

           

            ImGui::Begin("Map Editor", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
            ImGui::SetWindowSize(ImVec2(width*0.8, height*0.8), ImGuiCond_FirstUseEver);
            

            ImGui::End();

          

    }

    




};

};


#endif