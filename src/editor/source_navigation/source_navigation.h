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
#include <library.h>
#include <dme/Dme.h>
#include <tree/ByondTree.h>
#include <utils/string_helper.h>
#include "imgui_file_browser.h"
#include <filesystem>
#include <map>

#include <boost/bimap.hpp>
#include <boost/config.hpp>



// done with the fix



namespace MYG{

class SourceNavigationInterface{

private:
   
   
    BYOND::Library* library;
    GLFWwindow* window;
    int xpos,ypos,width,height;
    ImVec4 clear_color = ImVec4(0.07f,0.13f,0.17f,1.0f);
    imgui_ext::file_browser *fileBrowser;
    std::string path;

    std::string dmePath = "";


    bool fileExplorerOpen = true;

public:
    std::string fileToEdit = "";
    ImVec4 textColor;

    SourceNavigationInterface( GLFWwindow* window,BYOND::Library* library,int xpos,int ypos,int width,int height);
    void RenderObjectTree(BYOND::tree::Tree* tree, int &i,int &selection_mask,int &node_clicked);
    void SubRenderObject(BYOND::tree::Tree* tree,BYOND::tree::Tree::TreeItem* item, int& i, int& selection_mask, int& node_clicked);
    //void RenderIcon(std::string &dmePath,DME_Tree_Tree_Model *tree, MYG::DefaultMutableTreeNode<BYOND::DME_Tree_Item *>  *root);

    void mainLoop();

    




};

};


#endif