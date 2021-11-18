#include "source_navigation.h"
#include <sstream>


namespace MYG{

    SourceNavigationInterface::SourceNavigationInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height):
    window(window), library(library),xpos(xpos),ypos(ypos),width(width),height(height)
    {
       fileBrowser = new imgui_ext::file_browser("File Explorer");
       objects = new ObjectExplorer("Object Explorer",this->library);
        textColor = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);

    }

   
    void SourceNavigationInterface::mainLoop(){
        
        static ImGuiTabBarFlags tab_bar_flags =   ImGuiTabBarFlags_None;
        ImGui::BeginTabBar("MYG Explorer",tab_bar_flags);
        

        if (ImGui::BeginTabItem("File Explorer", &fileExplorerOpen, ImGuiTabItemFlags_None))
        {
            
            if (fileBrowser->render(fileExplorerOpen, path)) {
                // The "path" string will hold a valid file path here.
                fileToEdit = path;

                std::stringstream p;
                p << path;
                std::string spath = p.str();
                if(StringHelper::endsWith(spath,".dme")){
                    library->openDME(spath);
                }


            }
            ImGui::EndTabItem();
        }

        bool shouldOpen = library->isDone();
        if (ImGui::BeginTabItem("Object Explorer", &shouldOpen, ImGuiTabItemFlags_None))
        {
            
            if (objects->render(shouldOpen)) {
               
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