#ifndef _SOURCE_NAVIGATION_H
#define _SOURCE_NAVIGATION_H

#pragma once

#include "../../../third_party/glfw/deps/glad/gl.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "TextEditor.h"
#include "imgui_file_browser.h"
#include "../../byond/library.h"
#include "../../byond/stringhelper.h"
#include "imgui_file_browser.h"


namespace MYG{

class SourceNavigationInterface{

private:
   
   
    BYOND::Library* library;
    GLFWwindow* window;
    int xpos,ypos,width,height;
    ImVec4 clear_color = ImVec4(0.07f,0.13f,0.17f,1.0f);
    imgui_ext::file_browser *fileBrowser;
    std::string path;

    bool fileExplorerOpen = true;
    bool objectExplorerOpen = false;

public:
    std::string fileToEdit = "";

    SourceNavigationInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height):
    window(window), library(library),xpos(xpos),ypos(ypos),width(width),height(height)
    {
       fileBrowser = new imgui_ext::file_browser("File Explorer");


    }

   

    void mainLoop(){

            static ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_AutoSelectNewTabs | ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyResizeDown;
            ImGui::BeginTabBar("MYG Explorer",tab_bar_flags);
            

           if (ImGui::BeginTabItem("File Explorer", &fileExplorerOpen, ImGuiTabItemFlags_None))
            {
                fileExplorerOpen = true;
                objectExplorerOpen = false;
                if (fileBrowser->render(true, path)) {
                    // The "path" string will hold a valid file path here.
                    fileToEdit = path;

                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Object Explorer", &objectExplorerOpen, ImGuiTabItemFlags_None))
            {
                fileExplorerOpen = false;
                objectExplorerOpen = true;
                
                if (ImGui::TreeNode("Basic trees"))
                {
                    for (int i = 0; i < 5; i++)
                    {

                        if (ImGui::TreeNode((void*)(intptr_t)i, "Child %d", i))
                        {
                            ImGui::Text("blah blah");
                            ImGui::SameLine();
                            if (ImGui::SmallButton("button")) {}
                            ImGui::TreePop();
                        }
                    }
                }


                ImGui::EndTabItem();
            }


            //FILE AND OBJECT BROWSER
            
            
            ImGui::EndTabBar();


            ImGui::Begin("Map Editor", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
            ImGui::SetWindowSize(ImVec2(width*0.8, height*0.8), ImGuiCond_FirstUseEver);
            

            ImGui::End();

          

    }

    




};

};


#endif