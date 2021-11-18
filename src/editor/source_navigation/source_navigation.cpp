#include "source_navigation.h"
#include <sstream>

namespace MYG{

    SourceNavigationInterface::SourceNavigationInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height):
    window(window), library(library),xpos(xpos),ypos(ypos),width(width),height(height)
    {
       fileBrowser = new imgui_ext::file_browser("File Explorer");


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

        if (ImGui::BeginTabItem("Object Explorer", &objectExplorerOpen, ImGuiTabItemFlags_None))
        {

            

                BYOND::ObjectTree *tree = library->getTree();
                int i =0;
                for(auto item : tree->items){
                    
                    if (ImGui::TreeNode((void*)(intptr_t)i, "%s",item.first.c_str()))
                    {
                        for (auto var : item.second->instances)
                        {
                        
                            ImGui::Text(item.second->path.c_str());
                            //ImGui::SameLine();
                            //if (ImGui::SmallButton("button")) {}
                            ImGui::TreePop();
                        }
                        
                    }
                    i++;
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