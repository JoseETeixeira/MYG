/**
 * José Eduardo da Silva Teixeira Junior 2021
 * 
 * The frames which are being displayed are the FRONT BUFFER, while the ones being loaded are the BACK BUFFER
 */

#include "editor.hpp"
 

 
static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
 
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
 
int main(void)
{
    GLFWwindow* window;

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


    int xpos,ypos,width,height;

    //Get the primary monitor work area
    glfwGetMonitorWorkarea	(glfwGetPrimaryMonitor(), &xpos, &ypos, &width,&height );
 
    //Create a GLFW window object with the size of the monitor work area, named M.Y.G Editor
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


    //Main while loop
    while(!glfwWindowShouldClose(window)){
        //We process the window events
        glfwPollEvents();
    }


    //Delete the window before ending the program
    glfwDestroyWindow(window);
    //Terminate GLFW before ending
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
 