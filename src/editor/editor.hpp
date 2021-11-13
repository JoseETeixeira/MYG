#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "linmath.h"


#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "../../third_party/glfw/deps/glad/gl.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
 
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif
 


namespace myg{

    static void error_callback(int error, const char* description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }
    
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    class Editor {

        private:
            GLFWwindow* window;

            int xpos,ypos,width,height;

            const char* glsl_version = "#version 130";

            bool show_demo_window = true;
            bool show_another_window = false;
            ImVec4 clear_color = ImVec4(0.07f,0.13f,0.17f,1.0f);

            void InitializeGLFW(bool fullscreen);

            void InitializeImGUI();

            void MainLoop();


        public:
            Editor();
            ~Editor();

    };
}
