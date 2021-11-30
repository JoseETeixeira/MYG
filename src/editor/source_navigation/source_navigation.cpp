#include "source_navigation.h"
#include <sstream>
#include "spdlog/spdlog.h"
#include <type_traits>



namespace MYG{

    SourceNavigationInterface::SourceNavigationInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height):
    window(window), library(library),xpos(xpos),ypos(ypos),width(width),height(height)
    {
       fileBrowser = new imgui_ext::file_browser("File Explorer");
        textColor = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);

    }
 

    void SourceNavigationInterface::SubRenderObject(BYOND::tree::Tree* tree, BYOND::tree::Tree::TreeItem* item, int& i, int& selection_mask, int& node_clicked) {
            ImGui::Indent();
            ImGuiTreeNodeFlags node_flags = ((selection_mask == i) ? ImGuiTreeNodeFlags_Selected : 0);
            if(item->getVar("icon")!="null" && item->getVar("icon_state")!="null")
                if(item->getTexture(item->getVar("icon_state"), 0, 0) != nullptr)
                    ImGui::Image((void*)(intptr_t)*item->getTexture(item->getVar("icon_state"),0,0), ImVec2(32,32));
            //RenderIcon(dmePath,library->getTree(), root);

            
                bool opened = ImGui::TreeNodeEx((void*)(intptr_t)(i), node_flags, "%s", item->getName().c_str());

                if (ImGui::IsItemClicked())
                    node_clicked = (i);
                if (opened)
                {

            


                    for (auto item : *item->directSubtypes) {
                        i++;
                        SubRenderObject(tree, tree->getItem(item), i, selection_mask, node_clicked);
                        
                    }

     


                    
                    ImGui::TreePop();
                }
           
           
            ImGui::Unindent();
    }
   

    void SourceNavigationInterface::RenderObjectTree(BYOND::tree::Tree* tree, int &i,int &selection_mask,int &node_clicked){

        //ATOM
        BYOND::tree::Tree::TreeItem *atom = tree->getItem("/atom");

        for(auto item : *atom->directSubtypes){
            spdlog::info(item);
            SubRenderObject(tree,tree->getItem(item), i, selection_mask, node_clicked);
            i++;
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
                    #if defined(WIN32)
                        dmePath = spath.substr(0, spath.find_last_of("\\"));
                    #else if defined(LINUX)
                        dmePath = spath.substr(0, spath.find_last_of("/"));
                    #endif
                   
                }


            }
            ImGui::EndTabItem();
        }
        

        
        

        bool shouldOpen = library->isDone();
        static int selection_mask = 0;
        if(ImGui::BeginTabItem("Objects", &shouldOpen, ImGuiTabItemFlags_None)){
            int i = 0;
            int node_clicked = -1;

            
            BYOND::tree::Tree *tree = library->tree;
            //spdlog::info(printTree(tree->getRoot()));
            //int child_index = 0;
            RenderObjectTree(tree,i,selection_mask,node_clicked);
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