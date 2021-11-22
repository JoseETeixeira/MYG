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

    void SourceNavigationInterface::drawIcon(DMI* icon,std::string path){
        Image img;
        bool found = false;
       
        for(auto state : icon->states){
            if(StringHelper::trim(state.name) == StringHelper::trim(path)){
                img = state.images[0][0];
                found = true;
                break;
            }
        }
        if(!found){
            img = icon->states[0].images[0][0];
        }
        
          
            


        GLuint texture;
        
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);


        // Setup filtering parameters for display
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); 

        // Upload pixels into texture
        #if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
                glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        #endif
        // build our texture mipmaps
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.size.x, img.size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.pixels.data());




        ImGui::Image((void*)(intptr_t)texture, ImVec2(32,32));
    }
    

    void SourceNavigationInterface::RenderObjectTree(MYG::DefaultMutableTreeNode<BYOND::DME_Tree_Item *>  *root, int &i,int &selection_mask,int &node_clicked){
        if(!root->data->name.empty()){
               
                ImGui::Indent();
                ImGuiTreeNodeFlags node_flags = ((selection_mask == i) ? ImGuiTreeNodeFlags_Selected : 0);
                
                DMI  *dmi = new DMI();
                std::string dmipath;
                #if defined(WIN32)
                    dmipath= dmePath + "\\" + StringHelper::ReplaceAll(root->data->getVar("icon"),"/","\\").substr(1, StringHelper::ReplaceAll(root->data->getVar("icon"), "/", "\\").length()-2);
                #else if defined(LINUX)
                    dmipath = dmePath + "/" + StringHelper::ReplaceAll(root->data->getVar("icon"),"\\","/").substr(1, StringHelper::ReplaceAll(root->data->getVar("icon"), "\\","/").length()-2);
                #endif
                spdlog::info(dmipath);

                if(!root->data->getVar("icon").empty() && root->data->getVar("icon") != "null" ){
                    
                    spdlog::info(dmipath);
                    std::filesystem::path fsdmipath(dmipath);
                    dmi->load(fsdmipath);
                    if(!root->data->getVar("icon_state").empty()){
                         if(dmi->states.size()>0){
                             bool found = false;
                            for(auto state : dmi->states){
                                if(state.name == root->data->getVar("icon_state")){
                                    found = true;
                                    drawIcon(dmi,root->data->getVar("icon_state"));
                                }
                            }
                            if(!found){
                                drawIcon(dmi,root->data->getVar("icon_state"));
                            }
                        }
                    }
                }
               
                bool opened = ImGui::TreeNodeEx((void*)(intptr_t)(i), node_flags, "%s", root->data->name.c_str());
 
                spdlog::info(root->data->getVar("icon_state"));
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
                    }else{
                        drawIcon(dmi,root->data->getVar("icon_state"));
                        ImGui::Text(root->data->name.c_str());
                    }
                   
                    ImGui::TreePop();
                }
                
                    
               
                ImGui::Unindent();
            }

        
                
    }

        std::string printTree(MYG::DefaultMutableTreeNode<BYOND::DME_Tree_Item *>  *node){
            std::string tree = "{";
            tree += node->data->name;
            spdlog::info("Node: {}",node->data->name);
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
            DME_Tree_Tree_Model *tree = library->getTree();
            //spdlog::info(printTree(tree->getRoot()));
            //int child_index = 0;
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