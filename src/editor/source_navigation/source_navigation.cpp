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

    

    void SourceNavigationInterface::RenderObjectTree(MYG::DefaultMutableTreeNode<BYOND::DME_Tree_Item *>  *root, int &i,int &selection_mask,int &node_clicked){
        
            

            if(!root->data.empty()){
               
                ImGui::Indent();
                ImGuiTreeNodeFlags node_flags = ((selection_mask == i) ? ImGuiTreeNodeFlags_Selected : 0);
                bool opened = ImGui::TreeNodeEx((void*)(intptr_t)(i), node_flags, "%s", root->data.c_str());
                if (ImGui::IsItemClicked()) 
                        node_clicked = (i);
                if (opened)
                {
                    if(root->children.size() > 0){
                         for (auto item : root->children) {
                            //spdlog::info(item->getChildren().size());

                            i++;
                            RenderObjectTree(item, i, selection_mask, node_clicked);
                            



                        }
                    }
                   
                    ImGui::TreePop();
                }
                
                    
               
                ImGui::Unindent();
            }

           
        
        
       
    }

        std::string printTree(MYG::DefaultMutableTreeNode<BYOND::DME_Tree_Item *>  *node){
            std::string tree = "{";
            tree += node->data;
            spdlog::info("Node: {}",node->data);
            for(MYG::DefaultMutableTreeNode<BYOND::DME_Tree_Item *> * child : node->children){
                tree += printTree(child);
            }
            tree += "}";
            return tree;
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
        static int selection_mask = 0;
        if(ImGui::BeginTabItem("Objects", &shouldOpen, ImGuiTabItemFlags_None)){
            int i = 0;
            int node_clicked = -1;
            DME_Tree_Tree_Model *tree = library->getTree();
            //spdlog::info(printTree(tree->getRoot()));

            RenderObjectTree(tree->getRoot()->children[1],i,selection_mask,node_clicked);
            if (node_clicked != -1)
            {
                /**
                 *  if (ImGui::GetIO().KeyCtrl)
                    selection_mask ^= (1 << node_clicked);  // CTRL+click to toggle
                * 
                */
                selection_mask = node_clicked;   // Click to single-select
            }

                     
    

         ImGui::EndTabItem();
        }
        
        
        ImGui::EndTabBar();
        ImGui::End();

    }

};