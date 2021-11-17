/**
 * José Eduardo da Silva Teixeira Junior 2021
 * 
 * The frames which are being displayed are the FRONT BUFFER, while the ones being loaded are the BACK BUFFER
 */

#include "editor.hpp"

#include "../../third_party/fonts/IconsFontAwesome5.h"


namespace MYG{
    


    float previous_x = 1920.0f;
    float previous_y= 1080.0f;

    void resize_window_callback(GLFWwindow *glfw_window, int x, int y)
    {
        if (x == 0 || y == 0)
        {
            return;
        }
        //spdlog::debug("Resizing window to {}x{}", x, y);
        glViewport(0, 0, x, y);

       
        if (x > 2500) {
            ImGui::GetStyle().ScaleAllSizes(1.0f / (previous_x / previous_y));
            ImGui::GetIO().FontGlobalScale = (1.0f / (previous_x / previous_y));

            ImGui::GetStyle().ScaleAllSizes(2.0f / (x / y));
            ImGui::GetIO().FontGlobalScale = 2.0f/ (x / y);
        }
            
        else {
            ImGui::GetStyle().ScaleAllSizes(2.0f / (previous_x / previous_y));
            ImGui::GetIO().FontGlobalScale = (2.0f / (previous_x / previous_y));

            ImGui::GetStyle().ScaleAllSizes(1.0f/ (x / y));
            ImGui::GetIO().FontGlobalScale = 1.0f / (x / y);
        }
           
 
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
            window = glfwCreateWindow(width, height, "M.Y.G Maker", glfwGetPrimaryMonitor(), NULL);
        else
            window = glfwCreateWindow(width, height, "M.Y.G Maker", NULL, NULL);
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
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
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

       

        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        codeInterface = new CodeEditorInterface(window,library,xpos,ypos,width,height);
        mapInterface = new MapEditorInterface(window,library,xpos,ypos,width,height);
        
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

            
            ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));

            ImGui::Begin("MYG Maker", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse);
            ImGui::SetWindowSize(ImVec2(width, height));


            ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_PassthruCentralNode;
            ImGuiID dockspaceID =ImGui::GetID("MainDockspace");
   
            ImGui::DockSpace(dockspaceID, ImVec2(0.0f, 0.0f), dockspaceFlags);

             if (ImGui::BeginMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {
                    if (ImGui::MenuItem("Save"))
                    {
                        auto textToSave = codeInterface->editor.GetText();
                        /// save text....
                    }
                    if (ImGui::MenuItem("Quit", "Alt-F4"))
                        break;
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Edit"))
                {
                    bool ro = codeInterface->editor.IsReadOnly();
                    if (ImGui::MenuItem("Read-only mode", nullptr, &ro))
                        codeInterface->editor.SetReadOnly(ro);
                    ImGui::Separator();

                    if (ImGui::MenuItem("Undo", "ALT-Backspace", nullptr, !ro && codeInterface->editor.CanUndo()))
                        codeInterface->editor.Undo();
                    if (ImGui::MenuItem("Redo", "Ctrl-Y", nullptr, !ro && codeInterface->editor.CanRedo()))
                        codeInterface->editor.Redo();

                    ImGui::Separator();

                    if (ImGui::MenuItem("Copy", "Ctrl-C", nullptr, codeInterface->editor.HasSelection()))
                       codeInterface->editor.Copy();
                    if (ImGui::MenuItem("Cut", "Ctrl-X", nullptr, !ro && codeInterface->editor.HasSelection()))
                        codeInterface->editor.Cut();
                    if (ImGui::MenuItem("Delete", "Del", nullptr, !ro && codeInterface->editor.HasSelection()))
                        codeInterface->editor.Delete();
                    if (ImGui::MenuItem("Paste", "Ctrl-V", nullptr, !ro && ImGui::GetClipboardText() != nullptr))
                        codeInterface->editor.Paste();

                    ImGui::Separator();

                    if (ImGui::MenuItem("Select all", nullptr, nullptr))
                       codeInterface-> editor.SetSelection(TextEditor::Coordinates(), TextEditor::Coordinates(codeInterface->editor.GetTotalLines(), 0));

                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("View"))
                {
                    if (ImGui::MenuItem("Dark palette"))
                        codeInterface->editor.SetPalette(TextEditor::GetDarkPalette());
                    if (ImGui::MenuItem("Light palette"))
                        codeInterface->editor.SetPalette(TextEditor::GetLightPalette());
                    if (ImGui::MenuItem("Retro blue palette"))
                        codeInterface->editor.SetPalette(TextEditor::GetRetroBluePalette());
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

           
            codeInterface->mainLoop();

            mapInterface->mainLoop();

    



            ImGui::End();

           
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
        delete codeInterface;
        delete mapInterface;
        //Delete the window before ending the program
        glfwDestroyWindow(window);
        //Terminate GLFW before ending
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }

    Editor::Editor(){
        library = new BYOND::Library();
        //We initialize GLFW with the default false value for fullscreen (editor does not go fullscreen)
        InitializeGLFW(false);
        InitializeImGUI();
        MainLoop();
    }



}

 

 
int main(void)
{
    MYG::Editor editor =  MYG::Editor();
    return 0;



   
}
 