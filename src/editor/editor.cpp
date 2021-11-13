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


        ImGui::GetStyle().ScaleAllSizes(2.0 / (x/y));
        ImGui::GetIO().FontGlobalScale = 2.0 / (x / y);

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
        resize_window_callback(window, width, height);
    }


    void Editor::MainLoop(){
        //Main while loop
        ///////////////////////////////////////////////////////////////////////
        // TEXT EDITOR SAMPLE
        TextEditor editor;
        auto lang = TextEditor::LanguageDefinition::CPlusPlus();

        // set your own known preprocessor symbols...
        static const char* ppnames[] = { "NULL", "PM_REMOVE",
            "ZeroMemory", "DXGI_SWAP_EFFECT_DISCARD", "D3D_FEATURE_LEVEL", "D3D_DRIVER_TYPE_HARDWARE", "WINAPI","D3D11_SDK_VERSION", "assert" };
        // ... and their corresponding values
        static const char* ppvalues[] = { 
            "#define NULL ((void*)0)", 
            "#define PM_REMOVE (0x0001)",
            "Microsoft's own memory zapper function\n(which is a macro actually)\nvoid ZeroMemory(\n\t[in] PVOID  Destination,\n\t[in] SIZE_T Length\n); ", 
            "enum DXGI_SWAP_EFFECT::DXGI_SWAP_EFFECT_DISCARD = 0", 
            "enum D3D_FEATURE_LEVEL", 
            "enum D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE  = ( D3D_DRIVER_TYPE_UNKNOWN + 1 )",
            "#define WINAPI __stdcall",
            "#define D3D11_SDK_VERSION (7)",
            " #define assert(expression) (void)(                                                  \n"
            "    (!!(expression)) ||                                                              \n"
            "    (_wassert(_CRT_WIDE(#expression), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \n"
            " )"
            };

        for (int i = 0; i < sizeof(ppnames) / sizeof(ppnames[0]); ++i)
        {
            TextEditor::Identifier id;
            id.mDeclaration = ppvalues[i];
            lang.mPreprocIdentifiers.insert(std::make_pair(std::string(ppnames[i]), id));
        }

        // set your own identifiers
        static const char* identifiers[] = {
            "HWND", "HRESULT", "LPRESULT","D3D11_RENDER_TARGET_VIEW_DESC", "DXGI_SWAP_CHAIN_DESC","MSG","LRESULT","WPARAM", "LPARAM","UINT","LPVOID",
            "ID3D11Device", "ID3D11DeviceContext", "ID3D11Buffer", "ID3D11Buffer", "ID3D10Blob", "ID3D11VertexShader", "ID3D11InputLayout", "ID3D11Buffer",
            "ID3D10Blob", "ID3D11PixelShader", "ID3D11SamplerState", "ID3D11ShaderResourceView", "ID3D11RasterizerState", "ID3D11BlendState", "ID3D11DepthStencilState",
            "IDXGISwapChain", "ID3D11RenderTargetView", "ID3D11Texture2D", "TextEditor" };
        static const char* idecls[] = 
        {
            "typedef HWND_* HWND", "typedef long HRESULT", "typedef long* LPRESULT", "struct D3D11_RENDER_TARGET_VIEW_DESC", "struct DXGI_SWAP_CHAIN_DESC",
            "typedef tagMSG MSG\n * Message structure","typedef LONG_PTR LRESULT","WPARAM", "LPARAM","UINT","LPVOID",
            "ID3D11Device", "ID3D11DeviceContext", "ID3D11Buffer", "ID3D11Buffer", "ID3D10Blob", "ID3D11VertexShader", "ID3D11InputLayout", "ID3D11Buffer",
            "ID3D10Blob", "ID3D11PixelShader", "ID3D11SamplerState", "ID3D11ShaderResourceView", "ID3D11RasterizerState", "ID3D11BlendState", "ID3D11DepthStencilState",
            "IDXGISwapChain", "ID3D11RenderTargetView", "ID3D11Texture2D", "class TextEditor" };
        for (int i = 0; i < sizeof(identifiers) / sizeof(identifiers[0]); ++i)
        {
            TextEditor::Identifier id;
            id.mDeclaration = std::string(idecls[i]);
            lang.mIdentifiers.insert(std::make_pair(std::string(identifiers[i]), id));
        }
        editor.SetLanguageDefinition(lang);
        //editor.SetPalette(TextEditor::GetLightPalette());

        // error markers
        TextEditor::ErrorMarkers markers;
        markers.insert(std::make_pair<int, std::string>(6, "Example error here:\nInclude file not found: \"TextEditor.h\""));
        markers.insert(std::make_pair<int, std::string>(41, "Another example error"));
        editor.SetErrorMarkers(markers);

        // "breakpoint" markers
        //TextEditor::Breakpoints bpts;
        //bpts.insert(24);
        //bpts.insert(47);
        //editor.SetBreakpoints(bpts);

        static const char* fileToEdit = "ImGuiColorTextEdit/TextEditor.cpp";
        //	static const char* fileToEdit = "test.cpp";

        {
            std::ifstream t(fileToEdit);
            if (t.good())
            {
                std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
                editor.SetText(str);
            }
        }

        // Main loop
    
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

            if (ImGui::BeginMainMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {
                    if (ImGui::MenuItem("Save"))
                    {
                        auto textToSave = editor.GetText();
                        /// save text....
                    }
                    if (ImGui::MenuItem("Quit", "Alt-F4"))
                        break;
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Edit"))
                {
                    bool ro = editor.IsReadOnly();
                    if (ImGui::MenuItem("Read-only mode", nullptr, &ro))
                        editor.SetReadOnly(ro);
                    ImGui::Separator();

                    if (ImGui::MenuItem("Undo", "ALT-Backspace", nullptr, !ro && editor.CanUndo()))
                        editor.Undo();
                    if (ImGui::MenuItem("Redo", "Ctrl-Y", nullptr, !ro && editor.CanRedo()))
                        editor.Redo();

                    ImGui::Separator();

                    if (ImGui::MenuItem("Copy", "Ctrl-C", nullptr, editor.HasSelection()))
                        editor.Copy();
                    if (ImGui::MenuItem("Cut", "Ctrl-X", nullptr, !ro && editor.HasSelection()))
                        editor.Cut();
                    if (ImGui::MenuItem("Delete", "Del", nullptr, !ro && editor.HasSelection()))
                        editor.Delete();
                    if (ImGui::MenuItem("Paste", "Ctrl-V", nullptr, !ro && ImGui::GetClipboardText() != nullptr))
                        editor.Paste();

                    ImGui::Separator();

                    if (ImGui::MenuItem("Select all", nullptr, nullptr))
                        editor.SetSelection(TextEditor::Coordinates(), TextEditor::Coordinates(editor.GetTotalLines(), 0));

                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("View"))
                {
                    if (ImGui::MenuItem("Dark palette"))
                        editor.SetPalette(TextEditor::GetDarkPalette());
                    if (ImGui::MenuItem("Light palette"))
                        editor.SetPalette(TextEditor::GetLightPalette());
                    if (ImGui::MenuItem("Retro blue palette"))
                        editor.SetPalette(TextEditor::GetRetroBluePalette());
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }

            auto cpos = editor.GetCursorPosition();
            ImGui::Begin("DM Editor", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
            ImGui::SetWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
            

            ImGui::Text("%6d/%-6d %6d lines  | %s | %s | %s | %s", cpos.mLine + 1, cpos.mColumn + 1, editor.GetTotalLines(),
                editor.IsOverwrite() ? "Ovr" : "Ins",
                editor.CanUndo() ? "*" : " ",
                editor.GetLanguageDefinition().mName.c_str(), fileToEdit);

            editor.Render("TextEditor");
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
 