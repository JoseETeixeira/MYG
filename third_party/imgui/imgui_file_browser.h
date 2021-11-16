#pragma once

#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

namespace imgui_ext {

    struct file {
        std::string alias;
        fs::path path;
    };

    class file_browser final {

        static const int flags;

        const char* m_title;

        bool m_oldVisibility;

        int m_selection;

        fs::path m_currentPath;
        bool m_currentPathIsDir;

        std::vector<file> m_filesInScope;

    public:

        file_browser(const char* title);

        const bool render(const bool isVisible, std::string& outPath);

    };

};
