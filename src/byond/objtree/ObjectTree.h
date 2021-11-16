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
		static inline std::wstring macroRegex = L"([\\d\\.]+)[ \\t]*(\\+|\\-)[ \\t]*([\\d\\.]+)";
	
		std::unordered_map<std::wstring, ObjectTreeItem*> items = std::unordered_map<std::wstring, ObjectTreeItem*>();
		std::wstring dmePath;

		// List of all FILE_DIR definitions.
		// Linked list because it only really gets used for iteration and I'm too lazy to estimate the directory count
		// So it doesn't reallocate the array a billion times.
		std::list<std::filesystem::path *> fileDirs = std::list<std::filesystem::path*>();

		//Node<ObjectTreeItem> root = Node<ObjectTreeItem>(ObjectTreeItem(nullptr,""));

		int icon_size = 0;


		ObjectTree()
		{
			// Default datums

			ObjectTreeItem *datum = new ObjectTreeItem(nullptr, L"/datum");
			datum->setVar(L"tag",L"null");
			addItem(datum);

			ObjectTreeItem *atom = new ObjectTreeItem(datum, L"/atom");
			atom->setVar(L"alpha", L"255");
			atom->setVar(L"appearance_flags", L"0");
			atom->setVar(L"blend_mode", L"0");
			atom->setVar(L"color", L"nul");
			atom->setVar(L"density", L"0");
			atom->setVar(L"desc", L"nul");
			atom->setVar(L"dir", L"2");
			atom->setVar(L"gender", L"neuter");
			atom->setVar(L"icon", L"nul");
			atom->setVar(L"icon_state", L"nul");
			atom->setVar(L"infra_luminosity", L"0");
			atom->setVar(L"invisibility", L"0");
			atom->setVar(L"layer", L"1");
			atom->setVar(L"luminosity", L"0");
			atom->setVar(L"maptext", L"nul");
			atom->setVar(L"maptext_width", L"32");
			atom->setVar(L"maptext_height", L"32");
			atom->setVar(L"maptext_x", L"0");
			atom->setVar(L"maptext_y", L"0");
			atom->setVar(L"mouse_drag_pointer", L"0");
			atom->setVar(L"mouse_drop_pointer", L"1");
			atom->setVar(L"mouse_drop_zone", L"0");
			atom->setVar(L"mouse_opacity", L"1");
			atom->setVar(L"mouse_over_pointer", L"0");
			atom->setVar(L"name", L"nul");
			atom->setVar(L"opacity", L"0");
			atom->setVar(L"overlays", L"list()");
			atom->setVar(L"override", L"0");
			atom->setVar(L"pixel_x", L"0");
			atom->setVar(L"pixel_y", L"0");
			atom->setVar(L"pixel_z", L"0");
			atom->setVar(L"plane", L"0");
			atom->setVar(L"suffix", L"nul");
			atom->setVar(L"transform", L"nul");
			atom->setVar(L"underlays", L"list()");
			atom->setVar(L"verbs", L"list()");
			addItem(atom);

			ObjectTreeItem *movable = new ObjectTreeItem(atom, L"/atom/movable");
			movable->setVar(L"animate_movement", L"1");
			movable->setVar(L"bound_x", L"0");
			movable->setVar(L"bound_y", L"0");
			movable->setVar(L"bound_width", L"32");
			movable->setVar(L"bound_height", L"32");
			movable->setVar(L"glide_size", L"0");
			movable->setVar(L"screen_loc", L"nul");
			movable->setVar(L"step_size", L"32");
			movable->setVar(L"step_x", L"0");
			movable->setVar(L"step_y", L"0");
			addItem(movable);

			ObjectTreeItem *area = new ObjectTreeItem(atom, L"/area");
			area->setVar(L"layer", L"1");
			area->setVar(L"luminosity", L"1");
			addItem(area);

			ObjectTreeItem *turf = new ObjectTreeItem(atom, L"/turf");
			turf->setVar(L"layer", L"2");
			addItem(turf);

			ObjectTreeItem *obj = new ObjectTreeItem(movable, L"/obj");
			obj->setVar(L"layer", L"3");
			addItem(obj);

			ObjectTreeItem *mob = new ObjectTreeItem(movable, L"/mob");
			mob->setVar(L"ckey", L"nul");
			mob->setVar(L"density", L"1");
			mob->setVar(L"key", L"nul");
			mob->setVar(L"layer", L"4");
			mob->setVar(L"see_in_dark", L"2");
			mob->setVar(L"see_infrared", L"0");
			mob->setVar(L"see_invisible", L"0");
			mob->setVar(L"sight", L"0");
			addItem(mob);

			ObjectTreeItem *world = new ObjectTreeItem(datum, L"/world");
			world->setVar(L"turf", L"/turf");
			world->setVar(L"mob", L"/mob");
			world->setVar(L"area", L"/area");
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

		virtual ObjectTreeItem* getOrCreate(const std::wstring &path)
		{
			if (items.find(path) != items.end())
			{
				return items[path];
			}

			std::wstring parentPath;
			if ((int)path.find(L"/") != (int)path.rfind(L"/"))
			{
				parentPath = path.substr(0, (int)path.rfind(L"/"));
			}
			else
			{
				parentPath = L"/datum";
			}
			ObjectTreeItem *parentItem = getOrCreate(parentPath);
			ObjectTreeItem item(parentItem, path);
			items.emplace(path, &item);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete item' statement was not added since item was passed to a method or constructor. Handle memory management manually.
			return &item;
		}

		virtual ObjectTreeItem *get(const std::wstring &path)
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

				std::stringstream itemp;
				itemp << item.second->path.c_str();
				spdlog::info(itemp.str());
				for (auto var : item.second->vars)
				{
					std::stringstream f ;
					f << var.first.c_str();
					std::stringstream  s ;
					s << var.second.c_str();
					spdlog::info("\t" + f.str() + " = " + s.str());
				}
			}
		}

		virtual ObjectTreeItem *getGlobal()
		{
			return items[L""];
		}

		std::wstring ReplaceAll(std::wstring str, const std::wstring& from, const std::wstring& to) {
			size_t start_pos = 0;
			while ((start_pos = str.find(from, start_pos)) != std::wstring::npos) {
				str.replace(start_pos, from.length(), to);
				start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
			}
			return str;
		}

		int searchsubtypes(std::vector<ObjectTreeItem*> subtypes, ObjectTreeItem* arg) {
			int i = 0;
			for (ObjectTreeItem* type : subtypes) {
				if (type == arg)
					return i;
				i++;
			}
			return -1;
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
					std::wstring val = e.second;
					std::wstring origVal = L"";
					try
					{
					while (origVal != val)
					{
						origVal = val;
						// Trust me, this is the fastest way to parse the macros.
						std::wsmatch m;
						std::wstringstream outVal;
						std::regex_search(val, m, std::wregex(L"(?<![\\d\\w\"/])\\w+(?![\\d\\w\"/])"));
						for (int i =0; i< m.size(); i++)
						{
							if (global->vars.find(m.str(i)) != global->vars.end())
							{
								std::wstring s = outVal.str();
								std::wstring varsAtI = global->vars.at(m.str(i));
								s = ReplaceAll(s, varsAtI,L"");
								//std::replace(s.begin(), s.end(),s,varsAtI );
								outVal.str(s);
							}
							else
							{
								std::wstring s = outVal.str();
								std::wstring varsAtI = m.str(i);
								s = ReplaceAll(s, varsAtI, L"");
								//std::replace(s.begin(), s.end(),s, m.str(i));
								outVal.str(s);
							}
						}
						val = outVal.str();

						// Parse additions/subtractions.
						std::regex_search(val, m, std::wregex(macroRegex));
						outVal = std::wstringstream();
						for (int i =0; i< m.size(); i++)
						{
							std::wstring expr = m.str(i+2);
							// If group1 or group3 is a period then this is definitely not a macro and just an eager match.
							// Didn't feel like fixing the regex above. So this is a temporary fix. -Rockdtben
							if(expr == L"+"){
								if (m.str(i+1) != L"." && m.str(i+3) != L".")
									{
										std::wstring s = outVal.str();
										std::wstring varsAtI = std::to_wstring(std::stof(m.str(i + 1)) + std::stof(m.str(i + 3)));
										s = ReplaceAll(s, varsAtI, L"");
										outVal.str(s);
									}
							}else if(expr == L"-"){
								if (m.str(i+1) != L"." && m.str(i+3) != L".")
									{
										std::wstring s = outVal.str();
										std::wstring varsAtI = std::to_wstring(std::stof(m.str(i + 1)) - std::stof(m.str(i + 3)));
										s = ReplaceAll(s, varsAtI, L"");
										outVal.str(s);
									}
							}
								
						}
						val = outVal.str();

						// Parse parentheses
						std::regex_search(val, m, std::wregex(L"\\(([\\d\\.]+)\\)"));
						outVal = std::wstringstream();
						for (int i =0; i< m.size(); i++)
						{
							std::wstring s = outVal.str();
							std::wstring varsAtI = m.str(i+1);
							s = ReplaceAll(s, varsAtI, L"");
								
								outVal.str(s);
						}
						val = outVal.str();
					}
					}
					catch (const OutOfMemoryError &ex)
					{
						std::stringstream ff;
						std::stringstream ss;
						std::stringstream ppp;
						ff << e.first.c_str();
						ss << e.second.c_str();
						ppp << i.second->typeString().c_str();
						spdlog::error("OUT OF MEMORY PROCESSING ITEM " + ppp.str() + " VAR " + ff.str() + " = " + ss.str());
					}

					i.second->setVar(e.first, val);
				}
			}
			// Assign parents/children
			for (auto i : items)
			{
				ObjectTreeItem *parent = get(i.second->getVar(L"parentType"));
				if (parent != nullptr)
				{
					i.second->parent = parent;
					parent->subtypes.push_back(i.second);
				}
			}
			// Sort children
			/*
			for (auto i : items)
			{
				std::sort(i.second->subtypes.begin(), i.second->subtypes.end(),[&] (ObjectTreeItem *arg0, ObjectTreeItem *arg1)
				{
				 std::strcmp(arg0->path.c_str(),arg1->path.c_str());
				});
			}
			*/
			

			try
			{
				icon_size = std::stoi(get(L"/world")->getVar(L"icon_size"));
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
					return get(L"/area");
				case 1:
					return get(L"/mob");
				case 2:
					return get(L"/obj");
				case 3:
					return get(L"/turf");
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
				if (item->path == L"/area")
				{
					return 0;
				}
//ORIGINAL LINE: case "/mob":
				else if (item->path == L"/mob")
				{
					return 1;
				}
//ORIGINAL LINE: case "/obj":
				else if (item->path == L"/obj")
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
				if (searchsubtypes(subtypes, std::any_cast<ObjectTreeItem*>(arg1)) != -1)
					return searchsubtypes(subtypes, std::any_cast<ObjectTreeItem*>(arg1));
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


		virtual std::wstring toString()
		{
			return dmePath;
		}

		/**
		 * Gets a file name, taking the project's FILE_DIR into account.
		 * @param fileName The relative name of the file, which should be found with FILE_DIR definitions.
		 * @return The relative file path from the root project folder (folder with the opened code file).
		 * @exception FileNotFoundException Thrown if the file name could not be resolved.
		 */
		virtual std::wstring filePath(const std::wstring &filePath)
		{
			std::wstringstream ss;
			for (std::filesystem::path* path : fileDirs)
			{
				std::filesystem::path newPath = (path->relative_path()).append(filePath);
				std::filesystem::path rootPath = path->root_path();
				
				ss << newPath.relative_path();
				// Ding ding ding we got a winner!
				if (std::filesystem::exists(newPath) && newPath.has_filename())
				{
					
					return ss.str();
				}
			}
			std::stringstream error;
			error << filePath.c_str();
			spdlog::error("File not found: {}",error.str());
		}
	};

}
