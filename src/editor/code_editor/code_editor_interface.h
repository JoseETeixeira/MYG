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




namespace MYG{

class CodeEditorInterface{

private:
   
    std::string fileToEdit = "";
    GLFWwindow* window;
    

public:
    
   
    TextEditor editor;
    std::string currentFile = "";
    int xpos,ypos,width,height;
    ImVec4 clear_color = ImVec4(0.07f,0.13f,0.17f,1.0f);
   
    CodeEditorInterface( GLFWwindow* window,int xpos,int ypos,int width,int height):
    window(window),xpos(xpos),ypos(ypos),width(width),height(height)
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
        


    }

    void setEditorFile(std::string fileToEdit){
         {
             if(currentFile != fileToEdit){
                 currentFile = fileToEdit;
                std::ifstream t(fileToEdit);
                if (t.good())
                {
                    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
                    editor.SetText(str);
                }
             }
            /*std::stringstream w;
            w << fileToEdit.c_str();
            if(StringHelper::endsWith(w.str(), ".dme")){
                
                library->openDME(w.str());
            }*/
            
        }
    }

    void mainLoop(){

           

            
            std::string name = "DM Editor";
            if (!fileToEdit.empty()) {
                name = fileToEdit;
           }

            ImGui::Begin(name.c_str(), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
            ImGui::SetWindowSize(ImVec2(width*0.8, height*0.6));
            
            auto cpos = editor.GetCursorPosition();
            ImGui::Text("%6d/%-6d %6d lines  | %s | %s | %s | %s", cpos.mLine + 1, cpos.mColumn + 1, editor.GetTotalLines(),
                editor.IsOverwrite() ? "Ovr" : "Ins",
                editor.CanUndo() ? "*" : " ",
                editor.GetLanguageDefinition().mName.c_str(), fileToEdit.c_str());

            editor.Render("DM Editor");
            ImGui::End();

          

    }

    




};

};


#endif