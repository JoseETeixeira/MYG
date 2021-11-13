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
 
    if (!glfwInit())
        exit(EXIT_FAILURE);
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    int xpos,ypos,width,height;
    glfwGetMonitorWorkarea	(glfwGetPrimaryMonitor(), &xpos, &ypos, &width,&height );
 
    window = glfwCreateWindow(width, height, "M.Y.G Editor", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    
    gladLoadGL(glfwGetProcAddress);


    glViewport(0,0,width,height);    

    while(!glfwWindowShouldClose(window)){
        //We process the window events
        glfwPollEvents();
    }


 
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
 