#include "imgui_file_browser.h"
#include "../fonts/IconsFontAwesome5.h"
#include <limits>
#include <functional>
#include "imgui.h"

using namespace imgui_ext;

static void get_files_in_path(const fs::path& path, std::vector<file>& files) {
    files.clear();

    if (path.has_parent_path()) {
        std::string separator = " ";
        std::string pathdirectory = ICON_FA_ARROW_ALT_CIRCLE_UP + separator + "...";
        files.push_back({
            pathdirectory,
            path.parent_path()
        });
    }

    for (const fs::directory_entry& dirEntry : fs::directory_iterator(path)) {
        const fs::path& dirPath = dirEntry.path();
        std::string separator = " ";
        if(std::filesystem::is_directory(dirEntry)){
            std::string pathdirectory = ICON_FA_FOLDER + separator + dirPath.filename().string();
            files.push_back({
                pathdirectory,
                dirPath
            });
        }
        else if(dirEntry.path().string().rfind(".dm")!= std::string::npos ){
            std::string pathdirectory = ICON_FA_FILE_ALT + separator + dirPath.filename().string();
            files.push_back({
                pathdirectory,
                dirPath
            });
        }

        else if(dirEntry.path().string().rfind(".dmi")!= std::string::npos ){
            std::string pathdirectory = ICON_FA_FILE_IMAGE + separator + dirPath.filename().string();
            files.push_back({
                pathdirectory,
                dirPath
            });
        }

        else if(dirEntry.path().string().rfind(".dme")!= std::string::npos ){
            std::string pathdirectory = ICON_FA_GLOBE + separator + dirPath.filename().string();
            files.push_back({
                pathdirectory,
                dirPath
            });
        }

        else{
            std::string pathdirectory = ICON_FA_FILE + separator + dirPath.filename().string();
            files.push_back({
                pathdirectory,
                dirPath
            });
        }

    }
}

static const int clamp_size_t_to_int(const size_t data) {
    static const int max_int = std::numeric_limits<int>::max();
    return static_cast<int>(data > max_int ? max_int : data);
}

static bool vector_file_items_getter(void* data, int idx, const char** out_text) {
    const std::vector<file>* v = reinterpret_cast<std::vector<file>*>(data);
    const int elementCount = clamp_size_t_to_int(v->size());
    if (idx < 0 || idx >= elementCount) return false;
    *out_text = v->at(idx).alias.data();
    return true;
}

inline static constexpr int modal_flags =
    ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoCollapse |
    ImGuiWindowFlags_NoScrollbar |
    ImGuiWindowFlags_AlwaysAutoResize;

file_browser::file_browser(const char* title) :
    m_title(title),
    m_oldVisibility(false),
    m_selection(0),
    m_currentPath(fs::current_path()),
    m_currentPathIsDir(true) {
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontDefault();

    // merge in icons from Font Awesome
    static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
    ImFontConfig icons_config; icons_config.MergeMode = true; icons_config.PixelSnapH = true;
    io.Fonts->AddFontFromFileTTF(FONT_ICON_FILE_NAME_FAS, 16.0f, &icons_config, icons_ranges );
    io.Fonts->Build();

}

// Will return true if file selected.
const bool file_browser::render(const bool isVisible, std::string& outPath) {
    bool result = false;

    if (m_oldVisibility != isVisible) {
        m_oldVisibility  = isVisible;
        //Visiblity has changed.

        if (isVisible) {
            //Only run when the visibility state changes to visible.

            //Reset the path to the initial path.
            m_currentPath = fs::current_path();
            m_currentPathIsDir = true;

            //Update paths based on current path
            get_files_in_path(m_currentPath, m_filesInScope);

        }

    }

    bool isOpen = true;
    if (ImGui::Begin(m_title, &isOpen)) {

        if (ImGui::ListBox("##", &m_selection, vector_file_items_getter, &m_filesInScope, m_filesInScope.size(), 30)) {

            //Update current path to the selected list item.
            m_currentPath = m_filesInScope[m_selection].path;
            m_currentPathIsDir = fs::is_directory(m_currentPath);

            //If the selection is a directory, repopulate the list with the contents of that directory.
            if (m_currentPathIsDir) {

                get_files_in_path(m_currentPath, m_filesInScope);
            }else{
                if (ImGui::IsItemClicked() || ImGui::IsItemFocused()){
                    outPath = m_currentPath.string();
                    result = true;
                }

            }


        }

        //Auto resize text wrap to popup width.

        ImGui::TextWrapped(m_currentPath.string().data());


        ImGui::End();

    }


    return result;
}
