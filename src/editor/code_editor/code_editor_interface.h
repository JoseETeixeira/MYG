#ifndef _CODE_EDITOR_INTERFACE_H
#define _CODE_EDITOR_INTERFACE_H

#pragma once

#include "../../../third_party/glfw/deps/glad/gl.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "TextEditor.h"
#include "imgui_file_browser.h"
#include "../../byond/library.h"
#include "../../byond/stringhelper.h"



namespace MYG{

class CodeEditorInterface{

private:
   
    std::string fileToEdit = "";
    BYOND::Library *library;
    GLFWwindow* window;
    

public:
    
    imgui_ext::file_browser *fileBrowser;
    TextEditor editor;
    int xpos,ypos,width,height;
    ImVec4 clear_color = ImVec4(0.07f,0.13f,0.17f,1.0f);
   
    CodeEditorInterface( GLFWwindow* window,BYOND::Library *library,int xpos,int ypos,int width,int height):
    window(window), library(library),xpos(xpos),ypos(ypos),width(width),height(height)
    {
        auto lang = TextEditor::LanguageDefinition::DM();

        
        editor.SetLanguageDefinition(lang);

        //editor.SetPalette(TextEditor::GetLightPalette());

        // error markers
        //TextEditor::ErrorMarkers markers;
        //markers.insert(std::make_pair<int, std::string>(6, "Example error here:\nInclude file not found: \"TextEditor.h\""));
        //markers.insert(std::make_pair<int, std::string>(41, "Another example error"));
        //editor.SetErrorMarkers(markers);

        // "breakpoint" markers
        //TextEditor::Breakpoints bpts;
        //bpts.insert(24);
        //bpts.insert(47);
        //editor.SetBreakpoints(bpts);
        fileBrowser = new imgui_ext::file_browser("File Explorer");


    }

    void setEditorFile(std::string fileToEdit){
         {
            std::stringstream w;
            w << fileToEdit.c_str();
            if(StringHelper::endsWith(w.str(), ".dme")){
                
                library->openDME(w.str());
            }
            std::ifstream t(fileToEdit);
            if (t.good())
            {
                std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
                editor.SetText(str);
            }
        }
    }

    void mainLoop(){

           

            auto cpos = editor.GetCursorPosition();

            ImGui::Begin("File Explorer");
            

            // Had to use this awkward approach to get the menu item to open the pop-up modal.


            //FILE AND OBJECT BROWSER
            std::string path;
            if (fileBrowser->render(true, path)) {
                // The "path" string will hold a valid file path here.
                fileToEdit = path;
                setEditorFile(fileToEdit.c_str());

            }
            ImGui::End();

            ImGui::Begin("DM Editor", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
            ImGui::SetWindowSize(ImVec2(width*0.8, height*0.8), ImGuiCond_FirstUseEver);
            

            ImGui::Text("%6d/%-6d %6d lines  | %s | %s | %s | %s", cpos.mLine + 1, cpos.mColumn + 1, editor.GetTotalLines(),
                editor.IsOverwrite() ? "Ovr" : "Ins",
                editor.CanUndo() ? "*" : " ",
                editor.GetLanguageDefinition().mName.c_str(), fileToEdit.c_str());

            editor.Render("TextEditor");
            ImGui::End();

          

    }

    




};

};


#endif