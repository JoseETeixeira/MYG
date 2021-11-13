/**
 * José Eduardo da Silva Teixeira Junior 2021
 * 
 * The frames which are being displayed are the FRONT BUFFER, while the ones being loaded are the BACK BUFFER
 */

#include "editor.hpp"


namespace myg{

    void Editor::InitializeGLFW(bool fullscreen){

        glfwSetErrorCallback(error_callback);


        //Initialize GLFW
        if (!glfwInit())
            exit(EXIT_FAILURE);
    
        // Tell GLFW what version of OpenGL we are using
        // In this case we are using OpenGL 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        //Tell GLFW we are using the CORE profile
        //So that means we only have the modern functions
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    

        //Get the primary monitor work area
        glfwGetMonitorWorkarea	(glfwGetPrimaryMonitor(), &xpos, &ypos, &width,&height );
        //Create a GLFW window object with the size of the monitor work area, named M.Y.G Editor
        if(fullscreen)
            window = glfwCreateWindow(width, height, "M.Y.G Editor", glfwGetPrimaryMonitor(), NULL);
        else
            window = glfwCreateWindow(width, height, "M.Y.G Editor", NULL, NULL);
        //Error check if the window fails to create
        if (!window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        // Introduce the window into the current context
        glfwMakeContextCurrent(window);
        
        //Load GLAD so it configures OpenGL
        gladLoadGL(glfwGetProcAddress);

        //Specify the viewport of OpenGL in the Window
        //In this case the viewport goes from x = 0, y = 0, to x = monitor_work_area_width, y = monitor_work_area_height
        glViewport(0,0,width,height);    


        //Specify the color of the background
        glClearColor(0.07f,0.13f,0.17f,1.0f);
        //Clean the buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT);

        //Swap the back buffer with the front buffer
        glfwSwapBuffers(window);
    }


    void Editor::MainLoop(){
        //Main while loop
        while(!glfwWindowShouldClose(window)){
            //We process the window events
            glfwPollEvents();
        }
    }

    Editor::~Editor(){
        //Delete the window before ending the program
        glfwDestroyWindow(window);
        //Terminate GLFW before ending
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }

    Editor::Editor(){
        //We initialize GLFW with the default false value for fullscreen (editor does not go fullscreen)
        InitializeGLFW(false);
        MainLoop();
    }



}

 

 
int main(void)
{
    myg::Editor editor =  myg::Editor();
    return 0;



   
}
 