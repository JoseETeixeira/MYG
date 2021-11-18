#include "source_navigation.h"
#include <sstream>


namespace MYG{

    SourceNavigationInterface::SourceNavigationInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height):
    window(window), library(library),xpos(xpos),ypos(ypos),width(width),height(height)
    {
       fileBrowser = new imgui_ext::file_browser("File Explorer");
        textColor = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);

    }

   
    void SourceNavigationInterface::mainLoop(){
        
        static ImGuiTabBarFlags tab_bar_flags =   ImGuiTabBarFlags_None;
        ImGui::Begin("MYG Explorer");

        ImGui::BeginTabBar("##",tab_bar_flags);
        

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
        static int selection_mask = 0x02;
        if(ImGui::BeginTabItem("Objects", &shouldOpen, ImGuiTabItemFlags_None)){
            if (ImGui::TreeNodeEx("Root", ImGuiTreeNodeFlags_Selected, "Non-leaf node"))
        {   
                ImGui::Indent();
                ImGui::Text("Leaf Node");

                    int node_clicked = -1;
                    for (int i = 0; i < 5; i++)
                    {
                        ImGuiTreeNodeFlags node_flags = ((selection_mask & (1 << i)) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnDoubleClick;
                        bool opened = ImGui::TreeNodeEx((void*)(intptr_t)i, node_flags, "Selectable Child %d", i);
                        if (ImGui::IsItemClicked()) 
                            node_clicked = i;
                        if (opened)
                        {
                            ImGui::Text("blah blah");
                            ImGui::TreePop();
                        }
                    }
                    if (node_clicked != -1)
                    {
                        // Update selection state. Process outside of tree loop to avoid visual inconsistencies during the clicking-frame.
                        if (ImGui::GetIO().KeyCtrl)
                            selection_mask ^= (1 << node_clicked);  // CTRL+click to toggle
                        else
                            selection_mask = (1 << node_clicked);   // Click to single-select
                    }
                
                ImGui::Unindent();
                ImGui::TreePop();
            //ImGui::TreePop();
        }
    

         ImGui::EndTabItem();
        }
        
        
        ImGui::EndTabBar();
        ImGui::End();

    }

};