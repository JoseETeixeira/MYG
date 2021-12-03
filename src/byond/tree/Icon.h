#pragma once
#include "../DMI/DMI.h"
#include "spdlog/spdlog.h"
#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>
#include <boost/gil/extension/numeric/sampler.hpp>
#include <boost/gil/extension/numeric/resample.hpp>
#include "../../../third_party/glfw/deps/glad/gl.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

// I need this bugfix to compile against libpng 1.5, your mileage may vary
#define int_p_NULL (int*)NULL
// done with the fix


namespace BYOND::tree {

    class Icon {
        public:

            GLuint* getIconState(std::string state, int dir =0, int frame=0){
                if(state != "null"){
                    //spdlog::info("Looking for {}",state);
                    for(auto iS : icon->states){
                        //spdlog::info("Current state {}",iS.name);
                        if(iS.name.find(state) != std::string::npos || iS.name.find(state.substr(1,state.length()-2)) != std::string::npos){
                            //spdlog::info("found");
                            return icon_states->at(iS.name)->at(dir)->at(frame);
                        }
                    }
                }

                
                return icon_states->at(icon->states[0].name)->at(0)->at(0);
            }
            


            std::string name;

            Icon(std::string name, std::string dmipath): name(name){
                icon = new DMI();
                std::filesystem::path fsdmipath(dmipath);
                icon->load(fsdmipath);

                namespace bg = boost::gil;
                image = new bg::rgba8_image_t();
                bg::read_and_convert_image(dmipath, *image,bg::png_tag{});
                icon_states = new std::map<std::string,std::vector<std::vector<GLuint*>*>*>();
                int state = 0;
                for(auto iS : icon->states){
                    int direcao = 0;
                    std::vector<std::vector<GLuint*>*> *directions = new std::vector<std::vector<GLuint*>*>();
                    for(auto dir: iS.images){
                        int fram = 0;
                        std::vector<GLuint*> *frames = new std::vector<GLuint*>();
                        for(auto frame: dir){
                            
                            GLuint *texture = new GLuint();
                            bg::rgba8c_view_t subImage = bg::subimage_view(bg::view(*image), frame.pos.x, frame.pos.y, frame.size.x, frame.size.y);
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
                            frames->push_back(texture);
                            fram++;
                        }
                        directions->push_back(frames);
                        direcao++;
                    }
                    icon_states->emplace(iS.name,directions);
                    state++;
                }
                free(image);

            }    

        private:
            DMI* icon;
            boost::gil::rgba8_image_t *image;
            //all of the states of every item;
            std::map<std::string,std::vector<std::vector<GLuint*>*>*> *icon_states;
    };

};