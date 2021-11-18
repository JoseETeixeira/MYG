#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include "imgui.h"
#include "../../byond/objtree/ObjectTree.h"
#include "../../byond/library.h"
#include "../../byond/stringhelper.h"
#include "../../../third_party/fonts/IconsFontAwesome5.h"
#include <limits>
#include <functional>


namespace MYG {


    class ObjectExplorer  {

        static const int flags;

        const char* m_title;

        bool m_oldVisibility;

        int m_selection;

        BYOND::Library *library;
        ImVec4 textColor = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);


    public:

        ObjectExplorer(const char* title,BYOND::Library* library);

        void RenderTree(BYOND::ObjectTree * tree, ImVec4 &TextCol0,int indentspace);

        const bool render(bool &isVisible);

    };

};
