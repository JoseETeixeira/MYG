#pragma once
#include "../DMM/dmm.h"
#include "ObjInstance.h"
#include "ObjectTree.h"
#include <string>
#include <map>
#include "../utils/string_builder.h"
#include <regex>

namespace BYOND::tree
{

    class ModifiedType : public ObjInstance {

    public:

        std::map<std::string, std::string> *vars;
        std::string parentType;
        ObjInstance* parent;

        ModifiedType(std::map<std::string,std::string> *vars, std::string parentType):vars(vars) {
            this.parentType = parentType;
        }
        
        static ObjInstance* fromString(std::string s, ObjectTree *objtree) {
            if(!s.contains("{"))
                return objtree->get(s);
            // This will match the type path (/blah/blah) and the var list (a = "b"; c = 123)
            std::smatch m;
            std::regex_search(s,m,std::regex("([\\w/]+)\\{(.*)\\}"));
            if(!m.empty()) {
                std::map<std::string,std::string> *vars = new std::map<std::string,std::string>();
                // This will match variable key-val
                std::smatch varmatcher;
                std::regex_search(m[2].str(),varmatcher,std::regex("([\\w]+) ?= ?((?:\"(?:\\\\\"|[^\"])*\"|[^;])*)(?:$|;)"));
                for(int i = 0; i < varmatcher.size(); i++){
                    vars->emplace(varmatcher[i+1].str(),varmatcher[i+2].str());
                }
                
                ModifiedType *mt = new ModifiedType(vars, m[1].str());
                mt->parent = objtree->get(m[1].str());
               
                if(mt->parent != nullptr) {
                    mt->parent->addInstance(mt);
                }
               
                return mt;
            }
            return nullptr;
        }
        
        static ModifiedType* deriveFrom(ObjInstance* i) {
            
            ModifiedType *p = (ModifiedType)i;
            ModifiedType *mt = new ModifiedType(p->vars, p->type);
            mt->parent = p->parent;
            return mt;
          
        }
        
        
        
        std::string getVar(std::string key) {
            if(vars->find(key)  != vars->end())
                return vars->at(key);
            if(parent != nullptr)
                return parent->getVar(key);
            return "null";
        }
        
        std::string toString() {
            StringBuilder *out = new StringBuilder(parentType);
            out->append('{');
            bool isFirst = true;
            for(std::pair<std::string,std::string> e : *vars) {
                if(isFirst)
                    isFirst = false;
                else
                    out->append("; ");
                out->append(e.first);
                out->append(" = ");
                out->append(e.second);
            }
            out->append('}');
            return out->toString();
        }
        
        
        size_t hashCode() {
            std::hash<std::string> hasher;
            size_t hash = hasher(toString());
            return hash;
        }
        
        bool equals(ObjInstance* other) {
            if(other == this)
                return true;
            if(other->toString() == toString())
                return true;
            return false;
        }

        std::string typeString() {
            return parentType;
        }
        
        bool istype(std::string path) {
            if(this.type == path)
                return true;
            if(parent != nullptr)
                return parent->istype(path);
            return false;
        }
        
        /*
        public boolean viewVariables(FastDMM editor) {
            final JDialog dialog = new JDialog(editor, "View Variables", true);
            
            final ModifiedTypeTableModel model = new ModifiedTypeTableModel(this);
            JTable table = new JTable(model);
            table.setFillsViewportHeight(true);
            table.setDefaultRenderer(Object.class, new ModifiedTypeRenderer(model));
            dialog.getContentPane().add(new JScrollPane(table), BorderLayout.CENTER);
            
            JPanel bottomPanel = new JPanel(new BorderLayout());
            dialog.getContentPane().add(bottomPanel, BorderLayout.SOUTH);
            
            JButton okButton = new JButton("OK");
            okButton.addActionListener(e -> {
                model.doReturnTrue = true;
                dialog.setVisible(false);
            });
            bottomPanel.add(okButton, BorderLayout.WEST);
            
            JButton cancelButton = new JButton("Cancel");
            cancelButton.addActionListener(e -> dialog.setVisible(false));
            bottomPanel.add(cancelButton, BorderLayout.EAST);
            
            dialog.setLocationRelativeTo(editor);
            dialog.setSize(400, 450);
            dialog.setPreferredSize(dialog.getSize());
            dialog.setVisible(true);
            
            return model.doReturnTrue;
        }*/
    };


};