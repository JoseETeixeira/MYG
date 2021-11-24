#include "source_navigation.h"
#include <sstream>
#include "spdlog/spdlog.h"
#include <type_traits>
#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>
#include <boost/gil/extension/numeric/sampler.hpp>
#include <boost/gil/extension/numeric/resample.hpp>


namespace MYG{

    SourceNavigationInterface::SourceNavigationInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height):
    window(window), library(library),xpos(xpos),ypos(ypos),width(width),height(height)
    {
       fileBrowser = new imgui_ext::file_browser("File Explorer");
        textColor = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);

    }

    void SourceNavigationInterface::drawIcon(DMI* icon,std::string& state,std::string& path){
        Image img;
        bool found = false;
        spdlog::info("Searching for {}",state);
        if(state == "null"){
            img = icon->states[0].images[0][0];
        }
        else{
            for(auto state : icon->states){
                //spdlog::info("current state: {}",state.name);
                if(state.name.find(state.name) != std::string::npos ||  state.name.find(state.name.substr(0,state.name.length()-1)) != std::string::npos){
                    img = state.images[0][0];
                    found = true;
                    spdlog::info("found!");
                    break;
                }
            }
        }
        if(!found){
            img = icon->states[0].images[0][0];
        }
        
        if( !std::is_empty<Image>::value){
            
            GLuint texture = 0; 
            namespace bg = boost::gil;
            bg::rgba8_image_t imagem;
            if(images.find(path) != images.end()){
                imagem = images.at(path);
            }else{
                
                bg::read_and_convert_image(path, imagem,bg::png_tag{});

                //png_read_image(path, img);
                images.emplace(path,imagem);
            }
            bg::rgba8c_view_t subImage = bg::subimage_view(bg::view(imagem), img.pos.x * img.size.x, img.pos.y * img.size.y, img.size.x, img.size.y);

            //bg::write_view("output.png", subImage,bg::png_tag{});

            unsigned _width = static_cast<int>(subImage.width());
            unsigned _height = static_cast<int>(subImage.height());

            typedef decltype(imagem)::value_type pixel;

            //auto view = gil::interleaved_view(
            //  img.width(), img.height(), &*gil::view(img).pixels(), img.width() * sizeof pixel);

            //auto view = gil::interleaved_view(
            //  img.width(), img.height(), &*gil::view(img).pixels(), img.width() * sizeof pixel);

            auto pixeldata = new pixel[_width * _height  * 4];  


            auto dstView = bg::interleaved_view(
              _width, _height, pixeldata,  4 * _width);

             bg::copy_pixels(subImage, dstView);

           // bg::write_view(state+"output.png", dstView,bg::png_tag{});

            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);      

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); 
            glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);


            glTexImage2D(GL_TEXTURE_2D,     // Type of texture
                            0,                 // Pyramid level (for mip-mapping) - 0 is the top level
                            GL_RGBA,            // Internal colour format to convert to
                            subImage.width(),          // Image width  i.e. 640 for Kinect in standard mode
                            subImage.height(),          // Image height i.e. 480 for Kinect in standard mode
                            0,                 // Border width in pixels (can either be 1 or 0)
                            GL_RGBA, // Input image format (i.e. GL_RGB, GL_RGBA, GL_BGR etc.)
                            GL_UNSIGNED_BYTE,  // Image data type
                            reinterpret_cast<void*>(pixeldata));         // The actual image data itself
            glGenerateMipmap(GL_TEXTURE_2D);
            glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
            glBindTexture(GL_TEXTURE_2D, texture);

            free(pixeldata);


           
           


            


            ImGui::Image((void*)(intptr_t)texture, ImVec2(32,32));
        }
        
       
    }
    

    void SourceNavigationInterface::RenderIcon(std::string &dmePath,DME_Tree_Tree_Model *tree, MYG::DefaultMutableTreeNode<BYOND::DME_Tree_Item *>  *root){
        DMI  *dmi;
        std::string icon = "null";
        std::string icon_state = "null";
        //spdlog::info("Root name: {}",root->data->name);
        if(root->data->getVar("icon_state") != "null" && (root->data->getVar("icon") == "null")){
            spdlog::info("{} HAS ICON_STATE ONLY",root->data->name);
        }
        else if(root->data->getVar("icon_state") == "null" && (root->data->getVar("icon") != "null")){
            spdlog::info("{} HAS ICON ONLY",root->data->name);
            std::string dmipath;
            #if defined(WIN32)
                dmipath= dmePath + "\\" + StringHelper::ReplaceAll(root->data->getVar("icon"),"/","\\").substr(1, StringHelper::ReplaceAll(root->data->getVar("icon"), "/", "\\").length()-2);
            #else if defined(LINUX)
                dmipath = dmePath + "/" + StringHelper::ReplaceAll(root->data->getVar("icon"),"\\","/").substr(1, StringHelper::ReplaceAll(root->data->getVar("icon"), "\\","/").length()-2);
            #endif
            if(dmipath.find(".dmi") == std::string::npos){
                dmipath += ".dmi";
            }
            if(icons->find(root->data->getVar("icon")) != icons->end()){
                dmi = icons->at(root->data->getVar("icon"));
            }else{
                dmi = new DMI();
                icons->emplace(root->data->getVar("icon"),dmi);
            }
            
            //spdlog::info(dmipath);
            std::filesystem::path fsdmipath(dmipath);
            dmi->load(fsdmipath);
            drawIcon(dmi,icon_state,dmipath);
        }
        else if(root->data->getVar("icon_state") == "null" && (root->data->getVar("icon") == "null")){
            spdlog::info("{} HAS NOTHING",root->data->name);
        }
        else if(root->data->getVar("icon_state") != "null" && (root->data->getVar("icon") != "null")){
            spdlog::info("{} HAS EVERYTHING",root->data->name);
            std::string dmipath;
            #if defined(WIN32)
                dmipath= dmePath + "\\" + StringHelper::ReplaceAll(root->data->getVar("icon"),"/","\\").substr(1, StringHelper::ReplaceAll(root->data->getVar("icon"), "/", "\\").length()-2);
            #else if defined(LINUX)
                dmipath = dmePath + "/" + StringHelper::ReplaceAll(root->data->getVar("icon"),"\\","/").substr(1, StringHelper::ReplaceAll(root->data->getVar("icon"), "\\","/").length()-2);
            #endif
            if(dmipath.find(".dmi") == std::string::npos){
                dmipath += ".dmi";
            }
            if(icons->find(dmipath) != icons->end()){
                dmi = icons->at(root->data->getVar("icon"));
            }else{
                dmi = new DMI();
                icons->emplace(root->data->getVar("icon"),dmi);
            }
            
            //spdlog::info(dmipath);
            std::filesystem::path fsdmipath(dmipath);
            dmi->load(fsdmipath);
            icon_state = root->data->getVar("icon_state");
            drawIcon(dmi,icon_state,dmipath);
        }
        /*
        //set turf icon if none is found
        if(root->data->name == "turf"){
            icon = root->data->getVar("icon");
            spdlog::info(icon);
            root->data->setVar("icon","'Turfs/general/grass_and_dirt.dmi'");
            root->data->setVar("icon_state","2_2");
            icon = root->data->getVar("icon");
            std::string dmipath;
            #if defined(WIN32)
                dmipath= dmePath + "\\" + StringHelper::ReplaceAll(icon,"/","\\").substr(1, StringHelper::ReplaceAll(icon, "/", "\\").length()-2);
            #else if defined(LINUX)
                dmipath = dmePath + "/" + StringHelper::ReplaceAll(icon,"\\","/").substr(1, StringHelper::ReplaceAll(icon, "\\","/").length()-2);
            #endif
            if(icons->find(dmipath) != icons->end()){
                dmi = icons->at(dmipath);
            }else{
                dmi = new DMI();
                icons->emplace(dmipath,dmi);
            }
            
            spdlog::info(dmipath);
            std::filesystem::path fsdmipath(dmipath);
            dmi->load(fsdmipath);
            icon_state = root->data->getVar("icon_state");
            drawIcon(dmi,icon_state);
        }*/
       
    }

    void SourceNavigationInterface::RenderObjectTree(MYG::DefaultMutableTreeNode<BYOND::DME_Tree_Item *>  *root, int &i,int &selection_mask,int &node_clicked){
        if(!root->data->name.empty()){
               
                ImGui::Indent();
                ImGuiTreeNodeFlags node_flags = ((selection_mask == i) ? ImGuiTreeNodeFlags_Selected : 0);
                
                RenderIcon(dmePath,library->getTree(), root);
               
                bool opened = ImGui::TreeNodeEx((void*)(intptr_t)(i), node_flags, "%s", root->data->name.c_str());
 
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
                       // drawIcon(dmi,root->data->getVar("icon_state"));
                        //RenderIcon(dmePath,library->getTree(),root,&icons);
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