/**
 * José Eduardo da Silva Teixeira Junior 2021
 * 
 * The frames which are being displayed are the FRONT BUFFER, while the ones being loaded are the BACK BUFFER
 */

#include "editor.hpp"


namespace myg{
    
    void resize_window_callback(GLFWwindow *glfw_window, int x, int y)
    {
        if (x == 0 || y == 0)
        {
            return;
        }
        //spdlog::debug("Resizing window to {}x{}", x, y);
        glViewport(0, 0, x, y);


        ImGui::GetStyle().ScaleAllSizes(1.0 / (x/y));
        ImGui::GetIO().FontGlobalScale = 1.0 / (x / y);

    }


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

        glfwSetWindowSizeCallback(window, resize_window_callback);
    }

    void Editor::InitializeImGUI(){
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);

        // Load Fonts
        // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
        // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
        // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
        // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
        // - Read 'docs/FONTS.md' for more instructions and details.
        // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
        //io.Fonts->AddFontDefault();
        //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
        //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
        //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
        //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
        //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
        //IM_ASSERT(font != NULL);

        // Our state
        bool show_demo_window = true;
        bool show_another_window = false;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    }


    void Editor::MainLoop(){
        //Main while loop
        while(!glfwWindowShouldClose(window)){
            // Poll and handle events (inputs, window resize, etc.)
            // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
            // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
            // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
            // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
            glfwPollEvents();

            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
            if (show_demo_window)
                ImGui::ShowDemoWindow(&show_demo_window);

            // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
            {
                static float f = 0.0f;
                static int counter = 0;

                ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

                ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
                ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
                ImGui::Checkbox("Another Window", &show_another_window);

                ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

                if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                    counter++;
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);

                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                ImGui::End();
            }

            // 3. Show another simple window.
            if (show_another_window)
            {
                ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
                ImGui::Text("Hello from another window!");
                if (ImGui::Button("Close Me"))
                    show_another_window = false;
                ImGui::End();
            }

            // Rendering
            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
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
        InitializeImGUI();
        MainLoop();
    }



}

 

 
int main(void)
{
    myg::Editor editor =  myg::Editor();
    return 0;



   
}
 