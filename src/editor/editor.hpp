#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "linmath.h"


#pragma once
#include "../../third_party/glfw/deps/glad/gl.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
 

 


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

            void InitializeGLFW(bool fullscreen);

            void MainLoop();


        public:
            Editor();
            ~Editor();

    };
}
