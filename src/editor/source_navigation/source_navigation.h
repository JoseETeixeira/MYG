#ifndef _SOURCE_NAVIGATION_H
#define _SOURCE_NAVIGATION_H

#pragma once

#include "../../../third_party/glfw/deps/glad/gl.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "TextEditor.h"
#include "imgui_file_browser.h"
#include "../../byond/objtree/ObjectTree.h"
#include "../../byond/library.h"
#include "../../byond/stringhelper.h"
#include "object_tree.h"
#include "imgui_file_browser.h"


namespace MYG{

class BYOND::Library;
class ObjectExplorer;

class SourceNavigationInterface{

private:
   
   
    BYOND::Library* library;
    GLFWwindow* window;
    int xpos,ypos,width,height;
    ImVec4 clear_color = ImVec4(0.07f,0.13f,0.17f,1.0f);
    imgui_ext::file_browser *fileBrowser;
    ObjectExplorer *objects;
    std::string path;

    bool fileExplorerOpen = true;
    bool objectExplorerOpen = false;

public:
    std::string fileToEdit = "";
    ImVec4 textColor;

    SourceNavigationInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height);
   

    void mainLoop();

    




};

};


#endif