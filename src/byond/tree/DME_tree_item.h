#ifndef _DME_TREE_ITEM_H
#define _DME_TREE_ITEM_H
#include <string>
#include <unordered_map>
#include <optional>
#include <algorithm>
#include <functional>
#include <set>
#pragma once

#include "../utils/string_helper.h"

namespace BYOND{

class DME_Tree_Item{

	public:
		DME_Tree_Item *parent;
		std::string name;

		std::unordered_map<std::string, std::string> vars = std::unordered_map<std::string, std::string>();
		std::vector<DME_Tree_Item*> *children = new std::vector<DME_Tree_Item*>();

	
	public:
		virtual ~DME_Tree_Item()
		{
			delete parent;
			delete children;
		}

        void add(std::vector<DME_Tree_Item*>& v, DME_Tree_Item* elem) {
         
            // add room at the end:
            v.push_back(elem);
            // find the position for the element
            std::sort(v.begin(),v.end(),[&](const DME_Tree_Item *obj1, const DME_Tree_Item *obj2){
                return obj1->name.compare(obj2->name);
            });
        };


        /**
		 * Creates a new object node with the given name and parent.
		 * Automatically adds itself to the parent's child list.
		 * @param parent
		 * @param name
		 */
		DME_Tree_Item(DME_Tree_Item *parent, const std::string &name)
		{
			this->parent = parent;
			this->name = name;

			if (parent != nullptr)
			{
				parent->children->push_back(this);
				std::sort(parent->children->begin(),parent->children->end(),[&](const DME_Tree_Item *obj1, const DME_Tree_Item *obj2){
                	return obj1->name.compare(obj2->name);
            	});
			}
		}

		virtual void setVar(const std::string &name, const std::string &value)
		{
			vars.emplace(name, value);
		}

		virtual std::string getVar(const std::string &name)
		{
			if (vars.find(name) != vars.end())
			{
				return vars[name];
			}
			else
			{
				if (parent == nullptr)
				{
					return "";
				}
				return parent->getVar(name);
			}
		}

		/**
		 * @return The parent of this {@code DME_Tree_Item}
		 */
		virtual DME_Tree_Item *getParent()
		{
			return parent;
		}

		/**
		 * Returns {@code true} if {@code potentialParent} is anywhere in the parent hierarchy of this node.
		 */
		virtual bool isParent(DME_Tree_Item *potentialParent)
		{
			return parent != nullptr && (parent == (potentialParent) || parent->isParent(potentialParent));
		}

		virtual std::string getName()
		{
			return name;
		}

		virtual std::vector<DME_Tree_Item*> getChildren()
		{
			return *children;
		}

		DME_Tree_Item* getChild(const std::string &name)
		{
           
            for(auto child : *children){
                if(child->name.compare(name) == 0){
                    return child;
                }
            }
        
            return nullptr;
		}

		/**
		 * Gives the full path of this DME_Tree_Item with slashes separating the nodes
		 */
		virtual std::string toString()
		{
			std::vector<std::string> path;
			DME_Tree_Item *currentParent = parent;
			while (currentParent != nullptr)
			{
				path.push_back(currentParent->name);
				currentParent = currentParent->parent;
			}
            std::string s;
            for (std::vector<std::string>::const_iterator i = path.begin(); i != path.end(); ++i)
                s += *i;

			return s + "/";
		}

		int compareTo(DME_Tree_Item *o) 
		{
			return StringHelper::toLower(name).compare(StringHelper::toLower(o->name));
		}
	};


};




#endif