#include "imgui_file_browser.h"
#include "../fonts/IconsFontAwesome5.h"
#include <limits>
#include <functional>
#include "imgui.h"

using namespace imgui_ext;

static void get_files_in_path(const fs::path& path, std::vector<file>& files) {
    files.clear();

    if (path.has_parent_path()) {
        files.push_back({
            "..",
            path.parent_path()
        });
    }

    for (const fs::directory_entry& dirEntry : fs::directory_iterator(path)) {
        const fs::path& dirPath = dirEntry.path();
        files.push_back({
            dirPath.filename().string(),
            dirPath
        });
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
    io.Fonts->AddFontFromFileTTF("third_party/imgui/fa-solid-900.ttf", 16.0f, &icons_config, icons_ranges );
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

        static int selection_mask = (1 << 2);
        int node_clicked = -1;
       std::function<void(const std::filesystem::path &, unsigned int, unsigned int &)> functor = [&](
                const std::filesystem::path &path,
                unsigned int depth, unsigned int &idx) {
                for (auto p : m_filesInScope) {
                    ImGuiTreeNodeFlags node_flags =
                        ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick |
                        ((selection_mask & (1 << idx)) ? ImGuiTreeNodeFlags_Selected : 0);
                    if (std::filesystem::is_directory(p.path)) {
                        using namespace std::string_literals;
                        std::string s = ICON_FA_FOLDER + " "s + p.path.filename().string().c_str();
                        if (ImGui::TreeNodeEx((void *)(intptr_t)idx, node_flags, "%s", s.c_str())) {
                            if (ImGui::IsItemClicked() || ImGui::IsItemFocused())
                                node_clicked = idx;
                            functor(p.path, depth + 1, ++idx);
                            ImGui::TreePop();
                        }
                    } else {
                        node_flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
                        if (depth > 0) {
                            ImGui::Indent();
                        }
                        ImGui::TreeNodeEx((void *)(intptr_t)idx, node_flags, "%s",
                                          p.path.filename().string().c_str());
                        if (ImGui::IsItemClicked() || ImGui::IsItemFocused())
                            node_clicked = idx;
                        if (depth > 0) {
                            ImGui::Unindent();
                        }
                    }
                    ++idx;
                }
                depth -= 1;
            };
            unsigned int idx = 0u;
            functor(std::filesystem::current_path(), 0u, idx);
            if (node_clicked != -1) {
                // Update selection state. Process outside of tree loop to avoid visual inconsistencies during the clicking-frame.
                if (ImGui::GetIO().KeyCtrl)
                    selection_mask ^= (1 << node_clicked);          // CTRL+click to toggle
                else //if (!(selection_mask & (1 << node_clicked))) // Depending on selection behavior you want, this commented bit preserve selection when clicking on item that is part of the selection
                    selection_mask = (1 << node_clicked);           // Click to single-select
            }





    return result;
}
