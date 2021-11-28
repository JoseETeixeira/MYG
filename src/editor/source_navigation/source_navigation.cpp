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

        for(auto sta : icon->states){
            //spdlog::info("current state: {}",state.name);
            if(sta.name.find(state) != std::string::npos ||  sta.name.find(state.substr(1,state.length()-2)) != std::string::npos){
                img = sta.images[0][0];
                found = true;
                spdlog::info("found!");
                break;
            }
        }
        
        if(!found){
            img = icon->states[0].images[0][0];
        }
        
        if( !std::is_empty<Image>::value){
            
            
            namespace bg = boost::gil;
            bg::rgba8_image_t *imagem;
            if(images.find(path) != images.end()){
                imagem = images.at(path);
            }else{
                imagem = new bg::rgba8_image_t();
                bg::read_image(path, *imagem,bg::png_tag{});

                //png_read_image(path, img);
                images.emplace(path,imagem);
            }

            GLuint *texture;
            
            std::string icon_state = path+state;
            if(icon_states.find(icon_state) != icon_states.end()){
                texture = icon_states.at(icon_state);
            }else{
                texture = new GLuint();
                bg::rgba8c_view_t subImage = bg::subimage_view(bg::view(*imagem), img.pos.x, img.pos.y, img.size.x, img.size.y);

                //bg::write_view("output.png", subImage,bg::png_tag{});

                    unsigned _width = static_cast<int>(subImage.width());
                    unsigned _height = static_cast<int>(subImage.height());

                    typedef bg::rgba8_pixel_t pixel;

                    //auto view = gil::interleaved_view(
                    //  img.width(), img.height(), &*gil::view(img).pixels(), img.width() * sizeof pixel);

                    //auto view = gil::interleaved_view(
                    //  img.width(), img.height(), &*gil::view(img).pixels(), img.width() * sizeof pixel);

                    auto pixeldata = new pixel[_width * _height  * 4];  


                    auto dstView = bg::interleaved_view(
                    _width, _height, pixeldata,  4 * _width);

                    bg::copy_pixels(subImage, dstView);

                // bg::write_view(state+"output.png", dstView,bg::png_tag{});
                    glGenTextures(1, texture);
                    glBindTexture(GL_TEXTURE_2D, *texture);

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
                    glBindTexture(GL_TEXTURE_2D, *texture);

                    free(pixeldata);
                    //png_read_image(path, img);
                    icon_states.emplace(icon_state,texture);
                }

            

            
            
        

            ImGui::Image((void*)(intptr_t)*texture, ImVec2(32,32));
        }
        
       
    }
    
 

    void SourceNavigationInterface::SubRenderObject(std::string name, BYOND::dme::Dme::DmeItem* object, std::map<std::string, BYOND::dme::Dme::DmeItem*>* items, int& i, int& selection_mask, int& node_clicked,BYOND::dme::Dme *tree) {
             ImGui::Indent();
            ImGuiTreeNodeFlags node_flags = ((selection_mask == i) ? ImGuiTreeNodeFlags_Selected : 0);
            DMI  *dmi;
            std::string icon = "null";
            std::string icon_state = "null";
            icon = object->getVar("icon");
            spdlog::info(icon);
            if(icon != "null"){
                 std::string dmipath;
                #if defined(WIN32)
                    dmipath= tree->fileDir + tree->absoluteRootPath + StringHelper::ReplaceAll(icon,"/","\\").substr(1, StringHelper::ReplaceAll(icon, "/", "\\").length()-2);
                #else if defined(LINUX)
                    dmipath = tree->fileDir + tree->absoluteRootPath + StringHelper::ReplaceAll(icon,"\\","/").substr(1, StringHelper::ReplaceAll(icon, "\\","/").length()-2);
                #endif
                if(icons->find(dmipath) != icons->end()){
                    dmi = icons->at(dmipath);
                }else{
                    dmi = new DMI();
                    spdlog::info(dmipath);
                    std::filesystem::path fsdmipath(dmipath);
                    dmi->load(fsdmipath);
                    icons->emplace(dmipath,dmi);
                }   
                
              
                icon_state = object->getVar("icon_state");
                drawIcon(dmi,icon_state,dmipath);
            }
           
            //RenderIcon(dmePath,library->getTree(), root);
            
                bool opened = ImGui::TreeNodeEx((void*)(intptr_t)(i), node_flags, "%s", name.c_str());

                if (ImGui::IsItemClicked())
                    node_clicked = (i);
                if (opened)
                {

            


                    for (auto item : *object->directSubtypes) {
                        i++;
                        SubRenderObject(item, items->at(item), items, i, selection_mask, node_clicked,tree);
                        
                    }

     


                    
                    ImGui::TreePop();
                }
           
           
            ImGui::Unindent();
    }
   

    void SourceNavigationInterface::RenderObjectTree(std::map<std::string,BYOND::dme::Dme::DmeItem *> *items, int &i,int &selection_mask,int &node_clicked,BYOND::dme::Dme *tree){

        //ATOM
        BYOND::dme::Dme::DmeItem *atom = items->at("/atom");

        for(auto item : *atom->directSubtypes){
            spdlog::info(item);
            SubRenderObject(item, items->at(item), items, i, selection_mask, node_clicked,tree);
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

            
            BYOND::dme::Dme *tree = library->DME;
            //spdlog::info(printTree(tree->getRoot()));
            //int child_index = 0;
            std::map<std::string,BYOND::dme::Dme::DmeItem *> *items = tree->items;
            RenderObjectTree(items,i,selection_mask,node_clicked, tree);
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