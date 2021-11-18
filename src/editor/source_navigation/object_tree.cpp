#include "object_tree.h"


namespace MYG{

inline static constexpr int modal_flags =
    ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoCollapse |
    ImGuiWindowFlags_NoScrollbar |
    ImGuiWindowFlags_AlwaysAutoResize;

ObjectExplorer::ObjectExplorer(const char* title,BYOND::Library* library) :
    m_title(title),
    library(library),
    m_oldVisibility(false),
    m_selection(0) {
        
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontDefault();

    // merge in icons from Font Awesome
    static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
    ImFontConfig icons_config; icons_config.MergeMode = true; icons_config.PixelSnapH = true;
    io.Fonts->AddFontFromFileTTF(FONT_ICON_FILE_NAME_FAS, 16.0f, &icons_config, icons_ranges );
    io.Fonts->Build();

}



 void DrawModelTree(BYOND::ObjectTreeItem * item, ImVec4 &TextCol0,int indentspace){
        	ImGui::Indent(indentspace);
			
			size_t n = item->subtypes.size();

			if (n == 0)
			{
				ImGui::AlignTextToFramePadding();
				ImGui::Indent(indentspace-8);
				ImGui::TextColored(TextCol0, "%s", item->path.c_str());
				ImGui::Unindent(indentspace-8);
			}
			else
			{
				if (ImGui::TreeNode(item->path.c_str()))
				{

					for (size_t i = 0; i < n; ++i)
					{
						DrawModelTree(item->subtypes[i], TextCol0, indentspace-3);
					}

					ImGui::TreePop();
				}
			}

			ImGui::Unindent(indentspace);
    }

    void ObjectExplorer::RenderTree(BYOND::ObjectTree * tree, ImVec4 &TextCol0,int indentspace)
   {
		
			ImGui::Indent(indentspace);
			
            if(tree != nullptr){
                int n = tree->getAbsoluteChildCount(tree->get("/area"));

                if (n == 0)
                {
                    ImGui::AlignTextToFramePadding();
                    ImGui::Indent(indentspace-8);
                    ImGui::TextColored(TextCol0, "%s", tree->dmePath.c_str());
                    ImGui::Unindent(indentspace-8);
                }
                else
                {
                    if (ImGui::TreeNode(tree->dmePath.c_str()))
                    {

                        for (auto item: tree->items)
                        {
                            DrawModelTree(item.second, TextCol0, indentspace-3);
                        }

                        ImGui::TreePop();
                    }
                }
            }
			

			ImGui::Unindent(indentspace);
    }



// Will return true if file selected.
const bool ObjectExplorer::render(bool& isVisible) {
    bool result = false;

    if (m_oldVisibility != isVisible) {
        m_oldVisibility  = isVisible;
        //Visiblity has changed.

        if (isVisible) {
           
             if (ImGui::Begin("File Explorer"))
            {
                RenderTree(library->getTree(),textColor,13);

                ImGui::End();
            }
        }

    }

   


    return result;
}


};

