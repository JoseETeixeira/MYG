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

    

    void SourceNavigationInterface::RenderObjectTree(BYOND::DME_Tree_Item*  root, int &i,int &selection_mask,int &node_clicked){
        
        if(!root->getName().empty()){
            ImGui::Indent();

            ImGuiTreeNodeFlags node_flags = ((selection_mask & (1 << (i))) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnDoubleClick;
            bool opened = ImGui::TreeNodeEx((void*)(intptr_t)(i), node_flags, "%s", root->getName().c_str());
            if (ImGui::IsItemClicked()) 
                    node_clicked = (i);
            if (opened)
            {
                ImGui::Text(root->getName().c_str());
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
            if(root->getChildren().size() > 0){
                
                for(auto item : root->getChildren()){
                //spdlog::info(item->getChildren().size());

                if(!item->getName().empty()){
                     if(item->getChildren().size() == 0){
                    ImGui::Indent();
                    ImGuiTreeNodeFlags node_flags = ((selection_mask & (1 << (i))) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnDoubleClick;
                    bool opened = ImGui::TreeNodeEx((void*)(intptr_t)(i), node_flags, "%s", item->getName().c_str());
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
                    ImGui::Unindent();
                }else{
                    RenderObjectTree(item,i,selection_mask,node_clicked);
                }
                
                }else{
                    RenderObjectTree(item,i,selection_mask,node_clicked);
                }

               
            
            }
        
                

            }
            ImGui::Unindent();
        }else{
            
        if(root->getChildren().size() > 0){
               
             for(auto item : root->getChildren()){
            //spdlog::info(item->getChildren().size());

           if(!item->getName().empty()){
                     if(item->getChildren().size() == 0){
                    ImGui::Indent();
                    ImGuiTreeNodeFlags node_flags = ((selection_mask & (1 << (i))) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnDoubleClick;
                    bool opened = ImGui::TreeNodeEx((void*)(intptr_t)(i), node_flags, "%s", item->getName().c_str());
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
                    ImGui::Unindent();
                }else{
                    RenderObjectTree(item,i,selection_mask,node_clicked);
                }
                
                }else{
                    RenderObjectTree(item,i,selection_mask,node_clicked);
                }
            
           
        }
       
            

        }

        }
        
       
    }

    void printTree(BYOND::DME_Tree_Item *root ){
        spdlog::info("Printing: {}",root->getName());
        for(auto child : root->getChildren()){
            spdlog::info(child->getName());
            printTree(child);
        }
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
            int i = 0;
            int node_clicked = -1;
            BYOND::DME_Tree *tree = library->getTree();
            BYOND::DME_Tree_Item *root = tree->rootNode;
            printTree(root);
            //spdlog::info(root_children.size());

            RenderObjectTree(root,i,selection_mask,node_clicked);
                     
    

         ImGui::EndTabItem();
        }
        
        
        ImGui::EndTabBar();
        ImGui::End();

    }

};