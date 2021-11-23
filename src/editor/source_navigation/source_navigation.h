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
#include "../../byond/tree/DME_tree.h"
#include "../../byond/tree/DME_tree_item.h"
#include "../../byond/library.h"
#include "../../byond/utils/string_helper.h"
#include "tree/DME_Tree_Model.h"
#include "tree/DME_Tree_Node.h"
#include "imgui_file_browser.h"
#include "../DMI/DMI.h"
#include <filesystem>
#include <map>

namespace MYG{

class SourceNavigationInterface{

private:
   
   
    BYOND::Library* library;
    GLFWwindow* window;
    int xpos,ypos,width,height;
    ImVec4 clear_color = ImVec4(0.07f,0.13f,0.17f,1.0f);
    imgui_ext::file_browser *fileBrowser;
    std::string path;
    std::map<std::string,DMI*> *icons = new std::map<std::string,DMI*>();
    std::string dmePath = "";

    bool fileExplorerOpen = true;

public:
    std::string fileToEdit = "";
    ImVec4 textColor;

    SourceNavigationInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height);
    void RenderObjectTree(MYG::DefaultMutableTreeNode<BYOND::DME_Tree_Item *> *items, int &i,int &selection_mask,int &node_clicked);
    static void drawIcon(DMI* dmi,std::string &path);
    void RenderIcon(std::string &dmePath,DME_Tree_Tree_Model *tree, MYG::DefaultMutableTreeNode<BYOND::DME_Tree_Item *>  *root);

    void mainLoop();

    




};

};


#endif