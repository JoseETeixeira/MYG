#include "ObjectTreeItem.h"
#include <string>
#include <unordered_map>
#include <list>
#include <any>
#include <regex>
#include "node.hpp"
#include <sstream>
#include <algorithm>
#include "../exceptionhelper.h"
#include "../stringbuilder.h"
#include "../vectorhelper.h"
#include "../tangible_filesystem.h"
#include "spdlog/spdlog.h"
#pragma once



namespace BYOND
{
	

	class ObjectTree 
	{
	public:
		static inline std::string macroRegex = "([\\d\\.]+)[ \\t]*(\\+|\\-)[ \\t]*([\\d\\.]+)";
	
		std::unordered_map<std::string, ObjectTreeItem*> items = std::unordered_map<std::string, ObjectTreeItem*>();
		std::string dmePath;

		// List of all FILE_DIR definitions.
		// Linked list because it only really gets used for iteration and I'm too lazy to estimate the directory count
		// So it doesn't reallocate the array a billion times.
		std::list<std::filesystem::path *> fileDirs = std::list<std::filesystem::path*>();

		//Node<ObjectTreeItem> root = Node<ObjectTreeItem>(ObjectTreeItem(nullptr,""));

		int icon_size = 0;


		ObjectTree()
		{
			// Default datums

			ObjectTreeItem *datum = new ObjectTreeItem(nullptr, "/datum");
			datum->setVar("tag","null");
			addItem(datum);

			ObjectTreeItem *atom = new ObjectTreeItem(datum, "/atom");
			atom->setVar("alpha", "255");
			atom->setVar("appearance_flags", "0");
			atom->setVar("blend_mode", "0");
			atom->setVar("color", "nul");
			atom->setVar("density", "0");
			atom->setVar("desc", "nul");
			atom->setVar("dir", "2");
			atom->setVar("gender", "neuter");
			atom->setVar("icon", "nul");
			atom->setVar("icon_state", "nul");
			atom->setVar("infra_luminosity", "0");
			atom->setVar("invisibility", "0");
			atom->setVar("layer", "1");
			atom->setVar("luminosity", "0");
			atom->setVar("maptext", "nul");
			atom->setVar("maptext_width", "32");
			atom->setVar("maptext_height", "32");
			atom->setVar("maptext_x", "0");
			atom->setVar("maptext_y", "0");
			atom->setVar("mouse_drag_pointer", "0");
			atom->setVar("mouse_drop_pointer", "1");
			atom->setVar("mouse_drop_zone", "0");
			atom->setVar("mouse_opacity", "1");
			atom->setVar("mouse_over_pointer", "0");
			atom->setVar("name", "nul");
			atom->setVar("opacity", "0");
			atom->setVar("overlays", "list()");
			atom->setVar("override", "0");
			atom->setVar("pixel_x", "0");
			atom->setVar("pixel_y", "0");
			atom->setVar("pixel_z", "0");
			atom->setVar("plane", "0");
			atom->setVar("suffix", "nul");
			atom->setVar("transform", "nul");
			atom->setVar("underlays", "list()");
			atom->setVar("verbs", "list()");
			addItem(atom);

			ObjectTreeItem *movable = new ObjectTreeItem(atom, "/atom/movable");
			movable->setVar("animate_movement", "1");
			movable->setVar("bound_x", "0");
			movable->setVar("bound_y", "0");
			movable->setVar("bound_width", "32");
			movable->setVar("bound_height", "32");
			movable->setVar("glide_size", "0");
			movable->setVar("screen_loc", "nul");
			movable->setVar("step_size", "32");
			movable->setVar("step_x", "0");
			movable->setVar("step_y", "0");
			addItem(movable);

			ObjectTreeItem *area = new ObjectTreeItem(atom, "/area");
			area->setVar("layer", "1");
			area->setVar("luminosity", "1");
			addItem(area);

			ObjectTreeItem *turf = new ObjectTreeItem(atom, "/turf");
			turf->setVar("layer", "2");
			addItem(turf);

			ObjectTreeItem *obj = new ObjectTreeItem(movable, "/obj");
			obj->setVar("layer", "3");
			addItem(obj);

			ObjectTreeItem *mob = new ObjectTreeItem(movable, "/mob");
			mob->setVar("ckey", "nul");
			mob->setVar("density", "1");
			mob->setVar("key", "nul");
			mob->setVar("layer", "4");
			mob->setVar("see_in_dark", "2");
			mob->setVar("see_infrared", "0");
			mob->setVar("see_invisible", "0");
			mob->setVar("sight", "0");
			addItem(mob);

			ObjectTreeItem *world = new ObjectTreeItem(datum, "/world");
			world->setVar("turf", "/turf");
			world->setVar("mob", "/mob");
			world->setVar("area", "/area");
			addItem(world);

			// Empty path, this will be resolved as project root by filePath.
			fileDirs.push_back(new std::filesystem::path(""));

			//delete world;
//JAVA TO C++ CONVERTER TODO TASK: A 'delete mob' statement was not added since mob was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete obj' statement was not added since obj was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete turf' statement was not added since turf was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete area' statement was not added since area was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete movable' statement was not added since movable was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete atom' statement was not added since atom was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete datum' statement was not added since datum was passed to a method or constructor. Handle memory management manually.
		}

		virtual ObjectTreeItem *getOrCreate(const std::string &path)
		{
			if (items.find(path) != items.end())
			{
				return items[path];
			}

			std::string parentPath;
			if ((int)path.find("/") != (int)path.rfind("/"))
			{
				parentPath = path.substr(0, (int)path.rfind("/"));
			}
			else
			{
				parentPath = "/datum";
			}
			ObjectTreeItem *parentItem = getOrCreate(parentPath);
			ObjectTreeItem *item = new ObjectTreeItem(parentItem, path);
			items.emplace(path, item);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete item' statement was not added since item was passed to a method or constructor. Handle memory management manually.
			return item;
		}

		virtual ObjectTreeItem *get(const std::string &path)
		{
			if (items.find(path) != items.end())
			{
				return items[path];
			}
			else
			{
				return nullptr;
			}
		}

		virtual void addItem(ObjectTreeItem *item)
		{
			items.emplace(item->path, item);
		}

		virtual void dumpTree()
		{
			for (auto item : items)
			{

				spdlog::info(item.second->path);
				for (auto var : item.second->vars)
				{
					spdlog::info("\t" + var.first + " = " + var.second);
				}
			}
		}

		virtual ObjectTreeItem *getGlobal()
		{
			return items[""];
		}


		virtual void completeTree()
		{
			// Clear children and parse expressions

			ObjectTreeItem *global = getGlobal();


			for (auto i : items)
			{
				i.second->subtypes.clear();

				for (auto e : i.second->vars)
				{
					std::string val = e.second;
					std::string origVal = "";
					try
					{
					while (origVal != val)
					{
						origVal = val;
						// Trust me, this is the fastest way to parse the macros.
						std::smatch m;
						std::stringstream outVal;
						std::regex_search(val, m, std::regex("(?<![\\d\\w\"/])\\w+(?![\\d\\w\"/])"));
						for (int i =0; i< m.size(); i++)
						{
							if (global->vars.find(m.str(i)) != global->vars.end())
							{
								std::string s = outVal.str();
								std::replace(s.begin(), s.end(),s, global->vars.at(m.str(i)));
								outVal.str(s);
							}
							else
							{
								std::string s = outVal.str();
								std::replace(s.begin(), s.end(),s, m.str(i));
								outVal.str(s);
							}
						}
						val = outVal.str();

						// Parse additions/subtractions.
						std::regex_search(val, m, std::regex(macroRegex));
						outVal = std::stringstream();
						for (int i =0; i< m.size(); i++)
						{
							std::string expr = m.str(i+2);
							// If group1 or group3 is a period then this is definitely not a macro and just an eager match.
							// Didn't feel like fixing the regex above. So this is a temporary fix. -Rockdtben
							if(expr == "+"){
								if (m.str(i+1) != "." && m.str(i+3) != ".")
									{
										std::string s = outVal.str();
										std::replace(s.begin(), s.end(), s, std::to_string(std::stof(m.str(i+1)) + std::stof(m.str(i+3))));
										outVal.str(s);
									}
							}else if(expr == "-"){
								if (m.str(i+1) != "." && m.str(i+3) != ".")
									{
										std::string s = outVal.str();
										std::replace(s.begin(), s.end(), s, std::to_string(std::stof(m.str(i+1)) - std::stof(m.str(i+3))));
										outVal.str(s);
									}
							}
								
						}
						val = outVal.str();

						// Parse parentheses
						std::regex_search(val, m, std::regex("\\(([\\d\\.]+)\\)"));
						outVal = std::stringstream();
						for (int i =0; i< m.size(); i++)
						{
							std::string s = outVal.str();
								std::replace(s.begin(), s.end(), s, m.str(i+1));
								outVal.str(s);
						}
						val = outVal.str();
					}
					}
					catch (const OutOfMemoryError &ex)
					{
						spdlog::error("OUT OF MEMORY PROCESSING ITEM " + i.second->typeString() + " VAR " + e.first + " = " + e.second);
					}

					i.second->setVar(e.first, val);
				}
			}
			// Assign parents/children
			for (auto i : items)
			{
				ObjectTreeItem *parent = get(i.second->getVar("parentType"));
				if (parent != nullptr)
				{
					i.second->parent = parent;
					parent->subtypes.push_back(i.second);
				}
			}
			// Sort children
			for (auto i : items)
			{
				std::sort(i.second->subtypes.begin(), i.second->subtypes.end(),[&] (ObjectTreeItem *arg0, ObjectTreeItem *arg1)
				{
				 std::strcmp(arg0->path.c_str(),arg1->path.c_str());
				});
			}

			try
			{
				icon_size = std::stoi(get("/world")->getVar("icon_size"));
			}
			catch (const NumberFormatException &e)
			{
				icon_size = 32;
			}
		}

	
		std::any getChild(std::any arg0, int arg1) 
		{
			if (arg0.type() == typeid(ObjectTree) && std::any_cast<ObjectTree *>(arg0) == this)
			{
				switch (arg1)
				{
				case 0:
					return get("/area");
				case 1:
					return get("/mob");
				case 2:
					return get("/obj");
				case 3:
					return get("/turf");
				}
			}
			else if (arg0.type() == typeid(ObjectTreeItem))
			{
				ObjectTreeItem *item = std::any_cast<ObjectTreeItem*>(arg0);
				return item->subtypes[arg1];
			}
			return std::any();
		}

		int getChildCount(std::any arg0) 
		{
			if (arg0.type() == typeid(ObjectTree) && std::any_cast<ObjectTree *>(arg0) == this)
			{
				return 4;
			}
			if (arg0.type() == typeid(ObjectTreeItem))
			{
				return (std::any_cast<ObjectTreeItem*>(arg0))->subtypes.size();
			}
			return 0;
		}

		int getIndexOfChild(std::any arg0, std::any arg1) 
		{
			if (!(arg1.type() == typeid(ObjectTreeItem)))
			{
				return 0;
			}
			ObjectTreeItem *item = std::any_cast<ObjectTreeItem*>(arg1);
			if (arg1.type() == typeid(BYOND::ObjectTree) && std::any_cast<ObjectTree *>(arg1) == this)
			{
//JAVA TO C++ CONVERTER NOTE: The following 'switch' operated on a string and was converted to C++ 'if-else' logic:
//				switch(item.path)
//ORIGINAL LINE: case "/area":
				if (item->path == "/area")
				{
					return 0;
				}
//ORIGINAL LINE: case "/mob":
				else if (item->path == "/mob")
				{
					return 1;
				}
//ORIGINAL LINE: case "/obj":
				else if (item->path == "/obj")
				{
					return 2;
				}
				else
				{
					return 3;
				}
			}
			if (arg0.type() == typeid(ObjectTreeItem))
			{
				std::vector<ObjectTreeItem*> subtypes = std::any_cast<ObjectTreeItem*>(arg0)->subtypes;
				std::vector<ObjectTreeItem*>::iterator it = std::find(subtypes.begin(), subtypes.end(), arg1);
				if (it != subtypes.end())
					return std::distance(subtypes.begin(), it);
				else
					return -1;
			}
			return 0;
		}

		std::any getRoot() 
		{
			return this;
		}

		bool isLeaf(std::any arg0) 
		{
			if (arg0.type() == typeid(ObjectTree) && std::any_cast<ObjectTree*>(arg0) == this)
			{
				return false;
			}
			if (arg0.type() == typeid(ObjectTreeItem))
			{
				return (std::any_cast<ObjectTreeItem*>(arg0))->subtypes.empty();
			}
			return true;
		}


		virtual std::string toString()
		{
			return dmePath;
		}

		/**
		 * Gets a file name, taking the project's FILE_DIR into account.
		 * @param fileName The relative name of the file, which should be found with FILE_DIR definitions.
		 * @return The relative file path from the root project folder (folder with the opened code file).
		 * @exception FileNotFoundException Thrown if the file name could not be resolved.
		 */
		virtual std::string filePath(const std::string &filePath)
		{
			std::stringstream ss;
			for (std::filesystem::path* path : fileDirs)
			{
				std::filesystem::path newPath = (path->relative_path()).append(filePath);
				std::filesystem::path rootPath = path->root_path();

				
				ss << newPath.relative_path();
				// Ding ding ding we got a winner!
				if (newPath.has_filename())
				{
					
					return ss.str();
				}
			}
			spdlog::error("File not found: {}",ss.str());
		}
	};

}
