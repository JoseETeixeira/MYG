#pragma once

#include "ObjectTreeItem.h"
#include <string>
#include <unordered_map>
#include <list>
#include <any>
#include "node.hpp"
#include "../exceptionhelper.h"
#include "../stringbuilder.h"
#include "../vectorhelper.h"
#include "../tangible_filesystem.h"

namespace BYOND
{
	static const std::wstring macroRegex = L"([\\d\\.]+)[ \\t]*(\\+|\\-)[ \\t]*([\\d\\.]+)";

	class ObjectTree : public Node<ObjectTreeItem>
	{
	public:
	
		std::unordered_map<std::wstring, ObjectTreeItem*> items = std::unordered_map<std::wstring, ObjectTreeItem*>();
		std::string dmePath;

		// List of all FILE_DIR definitions.
		// Linked list because it only really gets used for iteration and I'm too lazy to estimate the directory count
		// So it doesn't reallocate the array a billion times.
		std::list<std::filesystem::path*> fileDirs = std::list<std::filesystem::path*>();

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
			atom->setVar(L"color", L"null");
			atom->setVar(L"density", L"0");
			atom->setVar(L"desc", L"null");
			atom->setVar(L"dir", L"2");
			atom->setVar(L"gender", L"neuter");
			atom->setVar(L"icon", L"null");
			atom->setVar(L"icon_state", L"null");
			atom->setVar(L"infra_luminosity", L"0");
			atom->setVar(L"invisibility", L"0");
			atom->setVar(L"layer", L"1");
			atom->setVar(L"luminosity", L"0");
			atom->setVar(L"maptext", L"null");
			atom->setVar(L"maptext_width", L"32");
			atom->setVar(L"maptext_height", L"32");
			atom->setVar(L"maptext_x", L"0");
			atom->setVar(L"maptext_y", L"0");
			atom->setVar(L"mouse_drag_pointer", L"0");
			atom->setVar(L"mouse_drop_pointer", L"1");
			atom->setVar(L"mouse_drop_zone", L"0");
			atom->setVar(L"mouse_opacity", L"1");
			atom->setVar(L"mouse_over_pointer", L"0");
			atom->setVar(L"name", L"null");
			atom->setVar(L"opacity", L"0");
			atom->setVar(L"overlays", L"list()");
			atom->setVar(L"override", L"0");
			atom->setVar(L"pixel_x", L"0");
			atom->setVar(L"pixel_y", L"0");
			atom->setVar(L"pixel_z", L"0");
			atom->setVar(L"plane", L"0");
			atom->setVar(L"suffix", L"null");
			atom->setVar(L"transform", L"null");
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
			movable->setVar(L"screen_loc", L"null");
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
			mob->setVar(L"ckey", L"null");
			mob->setVar(L"density", L"1");
			mob->setVar(L"key", L"null");
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

			// Empty path, this will be resolved as project root by filePath.
			fileDirs.push_back( &std::filesystem::path(L""));

			delete world;
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
			if ((int)path.find(L"/") != (int)path.rfind(L"/"))
			{
				parentPath = path.substr(0, (int)path.rfind(L"/"));
			}
			else
			{
				parentPath = L"/datum";
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

		virtual void dumpTree(PrintStream *ps)
		{
			for (auto item : items)
			{
				ps->println(item->second.path);
				for (Entry<std::string, std::string> *var : *item->second.vars.entrySet())
				{
					ps->println(L"\t" + var.first + L" = " + var.second);
				}
			}
		}

		virtual ObjectTreeItem *getGlobal()
		{
			return items[L""];
		}


		virtual void completeTree()
		{
			// Clear children and parse expressions

			ObjectTreeItem *global = getGlobal();

			System::gc();

			for (auto i : items)
			{
				i->second.subtypes->clear();

				for (Entry<std::string, std::string> *e : *i->second.vars.entrySet())
				{
					std::string val = e.second;
					std::string origVal = L"";
					try
					{
					while (origVal != val)
					{
						origVal = val;
						// Trust me, this is the fastest way to parse the macros.
						Matcher *m = Pattern::compile(L"(?<![\\d\\w\"/])\\w+(?![\\d\\w\"/])").matcher(val);
						StringBuilder *outVal = new StringBuilder();
						while (m->find())
						{
							if (global->vars.find(m->group(0)) != global->vars.end())
							{
								m->appendReplacement(outVal, global->vars[m->group(0)]);
							}
							else
							{
								m->appendReplacement(outVal, m->group(0));
							}
						}
						m->appendTail(outVal);
						val = outVal->toString();

						// Parse additions/subtractions.
						m = Pattern::compile(macroRegex).matcher(val);
						outVal = new StringBuilder();
						while (m->find())
						{
							switch (m->group(2))
							{
								// If group1 or group3 is a period then this is definitely not a macro and just an eager match.
								// Didn't feel like fixing the regex above. So this is a temporary fix. -Rockdtben
								case L"+":
									if (!m->group(1).equals(L".") && !m->group(3).equals(L"."))
									{
										m->appendReplacement(outVal, (static_cast<Float>(m->group(1)) + static_cast<Float>(m->group(3))) + L"");
									}
									break;
								case L"-":
									if (!m->group(1).equals(L".") && !m->group(3).equals(L"."))
									{
										m->appendReplacement(outVal, (static_cast<Float>(m->group(1)) - static_cast<Float>(m->group(3))) + L"");
									}
									break;
							}
						}
						m->appendTail(outVal);
						val = outVal->toString();

						// Parse parentheses
						m = Pattern::compile(L"\\(([\\d\\.]+)\\)").matcher(val);
						outVal = new StringBuilder();
						while (m->find())
						{
							m->appendReplacement(outVal, m->group(1));
						}
						m->appendTail(outVal);
						val = outVal->toString();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete outVal' statement was not added since outVal was passed to a method or constructor. Handle memory management manually.
					}
					}
					catch (const OutOfMemoryError &ex)
					{
						System::err::println(L"OUT OF MEMORY PROCESSING ITEM " + i->second.typeString() + L" VAR " + e.first + L" = " + e.second);
						throw ex;
					}

					i->second.setVar(e.first, val);
				}
			}
			System::gc();
			// Assign parents/children
			for (auto i : items)
			{
				ObjectTreeItem *parent = get(i->second.getVar(L"parentType"));
				if (parent != nullptr)
				{
					i->second->parent = parent;
					parent->subtypes.push_back(i->second);
				}
			}
			System::gc();
			// Sort children
			for (auto i : items)
			{
				i->second.subtypes.sort([&] (arg0, arg1)
				{
				arg0::path::compareToIgnoreCase(arg1::path);
				});
			}

			try
			{
				icon_size = std::stoi(get(L"/world")->getVar(L"icon_size"));
			}
			catch (const NumberFormatException &e)
			{
				icon_size = 32;
			}
		}

		void addTreeModelListener(TreeModelListener *arg0) override
		{
			// We don't change.
		}

		std::any getChild(std::any arg0, int arg1) override
		{
			if (obj::type() == typeid(com::github::tgstation::fastdmm::objtree::ObjectTree) && std::any_cast<com::github::tgstation::fastdmm::objtree::ObjectTree>(obj) == this)
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

		int getChildCount(std::any arg0) override
		{
			if (obj::type() == typeid(com::github::tgstation::fastdmm::objtree::ObjectTree) && std::any_cast<com::github::tgstation::fastdmm::objtree::ObjectTree>(obj) == this)
			{
				return 4;
			}
			if (arg0.type() == typeid(ObjectTreeItem))
			{
				return (std::any_cast<ObjectTreeItem*>(arg0)).subtypes->size();
			}
			return 0;
		}

		int getIndexOfChild(std::any arg0, std::any arg1) override
		{
			if (!(arg1.type() == typeid(ObjectTreeItem)))
			{
				return 0;
			}
			ObjectTreeItem *item = std::any_cast<ObjectTreeItem*>(arg1);
			if (obj::type() == typeid(com::github::tgstation::fastdmm::objtree::ObjectTree) && std::any_cast<com::github::tgstation::fastdmm::objtree::ObjectTree>(obj) == this)
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
				return VectorHelper::indexOf((std::any_cast<ObjectTreeItem*>(arg0)).subtypes, arg1);
			}
			return 0;
		}

		std::any getRoot() override
		{
			return this;
		}

		bool isLeaf(std::any arg0) override
		{
			if (obj::type() == typeid(com::github::tgstation::fastdmm::objtree::ObjectTree) && std::any_cast<com::github::tgstation::fastdmm::objtree::ObjectTree>(obj) == this)
			{
				return false;
			}
			if (arg0.type() == typeid(ObjectTreeItem))
			{
				return (std::any_cast<ObjectTreeItem*>(arg0)).subtypes::empty();
			}
			return true;
		}

		void removeTreeModelListener(TreeModelListener *arg0) override
		{
			// We don't change
		}

		void valueForPathChanged(TreePath *arg0, std::any arg1) override
		{
			// Nope
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
			for (auto path : fileDirs)
			{
				Path *newPath = path->resolve(filePath);
				Path *rootPath = Paths->get(dmePath).getParent();
				File *newFile = rootPath->resolve(newPath).toFile();

				// Ding ding ding we got a winner!
				if (newFile->exists() && newFile->canRead())
				{
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'toString':
					return newPath->toString();
				}
			}
			throw FileNotFoundException();
		}
	};

}
