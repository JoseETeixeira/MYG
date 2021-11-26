#ifndef _DME_TREE_H
#define _DME_TREE_H
#include <string>
#include <unordered_map>
#include <vector>
#include <filesystem>
#include <optional>
#include <map>
#include <regex>
#include "../utils/string_helper.h"
#include "spdlog/spdlog.h"
#pragma once
#include "DME_tree_item.h"
#include "DME_tree_listener.h"




namespace BYOND{

    class DME_Tree{

	public:

       	std::vector<std::filesystem::path*> fileDirs;
		std::unordered_map<std::string, std::string> macros;
		std::unordered_map<std::string, DME_Tree_Item*> pathCache;
		
		// Catch-all for other stuff
	private:


		
		DME_Tree_Item* rootNode = new DME_Tree_Item(nullptr, "");

		DME_Tree_Item *datum = new DME_Tree_Item(rootNode, "datum");

		DME_Tree_Item *atom = new DME_Tree_Item(datum, "atom");

		DME_Tree_Item *movable = new DME_Tree_Item(atom, "movable");

		DME_Tree_Item *area = new DME_Tree_Item(atom, "area");

		DME_Tree_Item *turf = new DME_Tree_Item(atom, "turf");

		DME_Tree_Item *obj = new DME_Tree_Item(movable, "obj");

		DME_Tree_Item *mob = new DME_Tree_Item(movable, "mob");

		DME_Tree_Item *world = new DME_Tree_Item(datum, "world");

		int icon_size = 0;
		
		std::vector<DME_Tree_Item*> createdNodes;

		// endregion

		

		std::vector<DME_Tree_Listener*> listeners = std::vector<DME_Tree_Listener*>();

	public:
		virtual ~DME_Tree()
		{
			delete rootNode;
			delete datum;
			delete atom;
			delete movable;
			delete area;
			delete turf;
			delete obj;
			delete mob;
			delete world;
		}

		DME_Tree()
		{
			InitializeInstanceFields();
			fileDirs = std::vector<std::filesystem::path*>();
			macros = std::unordered_map<std::string, std::string>();
			pathCache = std::unordered_map<std::string, DME_Tree_Item*>();
		}

        std::vector<std::string> split(const std::string& s, const  char* seperator)
		{
			std::vector<std::string> output;

			std::string::size_type prev_pos = 0, pos = 0;

			while ((pos = s.find(seperator, pos)) != std::string::npos)
			{
				std::string substring(s.substr(prev_pos, pos - prev_pos));

				output.push_back(substring);

				prev_pos = ++pos;
			}

			output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

			return output;
		}

		virtual DME_Tree_Item *getOrCreateDME_Tree_Item(const std::string &path)
		{
			std::string trimmedPath = StringHelper::trim(path);

			DME_Tree_Item *current;
			if ((current = pathCache[trimmedPath]) != nullptr)
			{
				return current;
			}

			//TODO: fix split path
			//spdlog::info("TIMMED PATH: {}",trimmedPath);
			std::vector<std::string> splitPath = split(trimmedPath,"/");

			int startIndex = 0;

			if (splitPath[0].empty())
			{
				startIndex++;
			}

			//spdlog::info("SPLIT PATH SIZE: {}",splitPath.size());

			if (splitPath.size() > startIndex)
			{
				DME_Tree_Item *currentNode;

				std::string startNodeName = splitPath[startIndex];

				spdlog::info("START NODE NAME: {}",startNodeName);

				if (startNodeName == "datum" || startNodeName == "/datum")
				{
						currentNode = datum;
				}

				else if (startNodeName == "atom" || startNodeName == "/atom")
				{
						currentNode = atom;
				}

				else if (startNodeName == "area" || startNodeName == "/area")
				{
						currentNode = area;
				}

				else if (startNodeName == "turf" || startNodeName == "/turf")
				{
						currentNode = turf;
				}

				else if (startNodeName == "obj" || startNodeName == "/obj")
				{
						currentNode = obj;
				}

				else if (startNodeName == "mob" || startNodeName == "/mob")
				{
						currentNode = mob;
				}
				else
				{
					bool found = false;
					for (auto i : createdNodes) {
						if (i->name == startNodeName) {
							found = true;
							currentNode = i;
						}
					}
					if (!found) {
						DME_Tree_Item* item = new DME_Tree_Item(datum, startNodeName);
						createdNodes.push_back(item);

						// INICIO MODS
						/*
						DME_Tree_Item *tmp = item;
						if(tmp->getVar("icon").empty() || tmp->getVar("icon") == "null"){
							while(tmp->parent!= datum){
								if(!tmp->parent->getVar("icon").empty() && tmp->parent->getVar("icon") != "null"){
									
									break;
									
								}
								tmp = tmp->parent;
							}
							item->setVar("icon",tmp->parent->getVar("icon"));
						}
						tmp = item;
						if(tmp->getVar("icon_state").empty() || tmp->getVar("icon_state") == "null"){
							while(tmp->parent!= datum){
								if(!tmp->parent->getVar("icon_state").empty() && tmp->parent->getVar("icon_state") != "null"){
									break;
								}
								tmp = tmp->parent;
							}
							item->setVar("icon_state",tmp->parent->getVar("icon_state"));
						}
						*/
						//FIM MODS
						currentNode = item;
						for (auto listener : listeners) {
							listener->onNodeAdded(item);
						}
					}
						
				}

				startIndex++;

				for (int i = startIndex; i < splitPath.size(); i++)
				{
					// Iterates through the path, getting or creating children as it goes.
					// Remember, DME_Tree_Item::new automatically adds the new node to its parent
					DME_Tree_Item* optNode = currentNode->getChild(splitPath[i]);
					if (optNode != nullptr)
					{
						currentNode = optNode;
					}
					else
					{
						DME_Tree_Item *newNode = new DME_Tree_Item(currentNode, splitPath[i]);
                        for(auto listener : listeners){
                            listener->onNodeAdded(newNode);
                        }
						
					}
				}

				return currentNode;
			}
			else
			{
				return datum;
			}
		}

		virtual void addFileDir(std::filesystem::path *path)
		{
			fileDirs.push_back(path);
		}

		virtual DME_Tree_Item *getRootNode()
		{
			return datum;
		}

		virtual DME_Tree_Item *getAtomNode()
		{
			return atom;
		}

		virtual void addListener(DME_Tree_Listener *listener)
		{
			listeners.push_back(listener);
		}

		virtual void addMacro(const std::string &name, const std::string &val)
		{
			macros.emplace(name, val);
		}

		virtual void removeMacro(const std::string &name)
		{
			macros.erase(name);
		}

		virtual bool isMacro(const std::string &macro)
		{
			return macros.find(macro) != macros.end();
		}

		virtual std::string getMacro(const std::string &macro)
		{
			return macros[macro];
		}




		virtual void completeTree()
		{
			// Clear children and parse expressions
			spdlog::info("Globals");

			DME_Tree_Item *global = rootNode;

			spdlog::info("Got global");


			spdlog::info("Assigning parents/children");
			// Assign parents/children
			for (auto &i : pathCache)
			{
				if (i.second != nullptr) {
					//spdlog::info("{}",i.first);
					DME_Tree_Item* parent = i.second->parent;
					if (parent != nullptr)
					{
						i.second->parent = parent;
						parent->children->push_back(i.second);
						for(auto var: i.second->parent->vars){
							bool found = false;
							for(auto child_var : i.second->vars){
								if(child_var.first == var.first){
									if(child_var.second == StringHelper::trim("null")){
										i.second->setVar(child_var.first,var.second);
										found = true;
									}
								}
							}	
							if(!found){
								i.second->setVar(var.first,var.second);
							}	
						}
					}
					else {
						spdlog::info("Empty Parent type: FIRST {}, SECOND {}", i.first, i.second->name);
					}
				}
				else {
					spdlog::error("Second is nullptr {}. Building...", i.first);

					
						DME_Tree_Item *item = getOrCreateDME_Tree_Item(i.first);
						for(auto var: item->parent->vars){
							bool found = false;
							for(auto child_var : item->vars){
								if(child_var.first == var.first){
									if(child_var.second == StringHelper::trim("null")){
										item->setVar(child_var.first,var.second);
										found = true;
									}
								}
							}	
							if(!found){
								item->setVar(var.first,var.second);
							}		
						}
				
				}
			// Sort children

			


				std::stringstream intValue(world->getVar("icon_size"));
				int number = 0;
				intValue >> number;
				icon_size = number;
			}
		}

	private:
		void InitializeInstanceFields()
		{
			datum->setVar("tag", "null");
			atom->setVar("alpha", "255");
			atom->setVar("appearance_flags", "0");
			atom->setVar("blend_mode", "0");
			atom->setVar("color", "null");
			atom->setVar("density", "0");
			atom->setVar("desc", "null");
			atom->setVar("dir", "2");
			atom->setVar("gender", "\"neuter\"");
			atom->setVar("icon", "null");
			atom->setVar("icon_state", "null");
			atom->setVar("infra_luminosity", "0");
			atom->setVar("invisibility", "0");
			atom->setVar("layer", "1");
			atom->setVar("luminosity", "0");
			atom->setVar("maptext", "null");
			atom->setVar("maptext_width", "32");
			atom->setVar("maptext_height", "32");
			atom->setVar("maptext_x", "0");
			atom->setVar("maptext_y", "0");
			atom->setVar("mouse_drag_pointer", "0");
			atom->setVar("mouse_drop_pointer", "1");
			atom->setVar("mouse_drop_zone", "0");
			atom->setVar("mouse_opacity", "1");
			atom->setVar("mouse_over_pointer", "0");
			atom->setVar("name", "null");
			atom->setVar("opacity", "0");
			atom->setVar("overlays", "list()");
			atom->setVar("override", "0");
			atom->setVar("pixel_x", "0");
			atom->setVar("pixel_y", "0");
			atom->setVar("pixel_z", "0");
			atom->setVar("plane", "0");
			atom->setVar("suffix", "null");
			atom->setVar("transform", "null");
			atom->setVar("underlays", "list()");
			atom->setVar("verbs", "list()");
			movable->setVar("animate_movement", "1");
			movable->setVar("bound_x", "0");
			movable->setVar("bound_y", "0");
			movable->setVar("bound_width", "32");
			movable->setVar("bound_height", "32");
			movable->setVar("glide_size", "0");
			movable->setVar("screen_loc", "null");
			movable->setVar("step_size", "32");
			movable->setVar("step_x", "0");
			movable->setVar("step_y", "0");
			area->setVar("layer", "1");
			area->setVar("luminosity", "1");
			turf->setVar("layer", "2");
			obj->setVar("layer", "3");
			mob->setVar("ckey", "null");
			mob->setVar("density", "1");
			mob->setVar("key", "null");
			mob->setVar("layer", "4");
			mob->setVar("see_in_dark", "2");
			mob->setVar("see_infrared", "0");
			mob->setVar("see_invisible", "0");
			mob->setVar("sight", "0");
			world->setVar("turf", "/turf");
			world->setVar("mob", "/mob");
			world->setVar("area", "/area");
			world->setVar("icon_size", "32");

		}

    };

};


#endif