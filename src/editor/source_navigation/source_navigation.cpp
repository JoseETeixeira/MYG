#include "source_navigation.h"
#include <sstream>
#include "spdlog/spdlog.h"


namespace MYG{

    SourceNavigationInterface::SourceNavigationInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height):
    window(window), library(library),xpos(xpos),ypos(ypos),width(width),height(height)
    {
       fileBrowser = new imgui_ext::file_browser("File Explorer");
        textColor = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);

    }

    /*

    void SourceNavigationInterface::RenderObjectTree(std::vector<BYOND::ObjectTreeItem*> subtypes, int &i,int &selection_mask,int &node_clicked){
        ImGui::Indent();
        for(auto item : subtypes){
            

            if(item->subtypes.size() == 0){
                
                ImGuiTreeNodeFlags node_flags = ((selection_mask & (1 << (i))) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnDoubleClick;
                bool opened = ImGui::TreeNodeEx((void*)(intptr_t)(i), node_flags, "%s", item->path.c_str());
                if (ImGui::IsItemClicked()) 
                    node_clicked = (i);
                if (opened)
                {
                    ImGui::Text("blah blah");
                    ImGui::TreePop();
                }
                
                if (node_clicked != -1)
                {
                    // Update selection state. Process outside of tree loop to avoid visual inconsistencies during the clicking-frame.
                    if (ImGui::GetIO().KeyCtrl)
                        selection_mask ^= (1 << node_clicked);  // CTRL+click to toggle
                    else
                        selection_mask = (1 << node_clicked);   // Click to single-select
                }
                i++;
            }else{
                //Recursive
                if(item->parent != nullptr && item->parent->path.find(item->path) != std::string::npos){
                    RenderObjectTree(item->subtypes,i,selection_mask,node_clicked);
                    
                    i++;
                }
                
            }

        }
        ImGui::Unindent();
    }
    */
   
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
        
        /*

        bool shouldOpen = library->isDone();
        static int selection_mask = 0x02;
        if(ImGui::BeginTabItem("Objects", &shouldOpen, ImGuiTabItemFlags_None)){
            int i = 0;
            int node_clicked = -1;
            

            if (ImGui::TreeNodeEx("Area", ImGuiTreeNodeFlags_Selected, "/area"))
            {   
 
                
                RenderObjectTree(library->getTree()->get("/area")->subtypes,i,selection_mask,node_clicked);
                

                
                ImGui::TreePop();
            }

            if (ImGui::TreeNodeEx("Datum", ImGuiTreeNodeFlags_Selected, "/datum"))
            {   
 
                
                RenderObjectTree(library->getTree()->get("/datum")->subtypes,i,selection_mask,node_clicked);
                

                
                ImGui::TreePop();
            }


            if (ImGui::TreeNodeEx("Mobs", ImGuiTreeNodeFlags_Selected, "/mob"))
            {   
 
                
                RenderObjectTree(library->getTree()->get("/mob")->subtypes,i,selection_mask,node_clicked);
                

                
                ImGui::TreePop();
            }

            if (ImGui::TreeNodeEx("Obj", ImGuiTreeNodeFlags_Selected, "/obj"))
            {   
 
                
                RenderObjectTree(library->getTree()->get("/obj")->subtypes,i,selection_mask,node_clicked);
                

                
                ImGui::TreePop();
            }

            if (ImGui::TreeNodeEx("Turf", ImGuiTreeNodeFlags_Selected, "/turf"))
            {   
 
                
                RenderObjectTree(library->getTree()->get("/turf")->subtypes,i,selection_mask,node_clicked);
                

                
                ImGui::TreePop();
            }

            for(auto item: library->getTree()->items){
                if(!item.first.empty() && (item.second->parent == nullptr || (item.second->parent->path.empty()) || item.second->parent->path == "/" )){
                    if (ImGui::TreeNodeEx(item.second->path.c_str(), ImGuiTreeNodeFlags_Selected, item.second->path.c_str()))
                        {   
            
                            
                            RenderObjectTree(item.second->subtypes,i,selection_mask,node_clicked);
                            

                            
                            ImGui::TreePop();
                        }
                }
            }
        
            
    

         ImGui::EndTabItem();
        }
        */
        
        ImGui::EndTabBar();
        ImGui::End();

    }

};