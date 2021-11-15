#include "ObjInstance.h"
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <list>
#include "../stringhelper.h"
#include "../vectorhelper.h"
#pragma once



namespace BYOND
{

	class ObjectTreeItem : public ObjInstance, public std::list<ObjInstance*>
	{
	public:
		virtual ~ObjectTreeItem()
		{
			delete parent;
		}


		ObjectTreeItem(ObjectTreeItem *parent, const std::string &p)
		{
			path = StringHelper::trim(p.c_str());
			this->path = p;
			this->parent = parent;
			vars.emplace("type", path);
			if (parent != nullptr)
			{
				parent->subtypes.push_back(this);
				vars.emplace("parentType", parent->path);
			}
			instances.push_back(this);
		}

		ObjectTreeItem(const std::string &path)
		{
			this->path = path;
			vars.emplace("type", path);
			instances.push_back(this);
		}

		bool istype(const std::string &path) override
		{
			if (this->path == path)
			{
				return true;
			}
			if (parent != nullptr)
			{
				return parent->istype(path);
			}
			return false;
		}

		virtual void setVar(const std::string &key, const std::string &value)
		{
			vars.emplace(key, value);
		}

		virtual void setVar(const std::string &key)
		{
			if (vars.find(key) == vars.end())
			{
				vars.emplace(key, "null");
			}
		}

		std::string getVar(const std::string &key) override
		{
			if (vars.find(key) != vars.end())
			{
				return vars[key];
			}
			if (parent != nullptr)
			{
				return parent->getVar(key);
			}
			return "";
		}

		virtual std::unordered_map<std::string, std::string> getAllVars()
		{
			std::unordered_map<std::string, std::string> allVars = std::unordered_map<std::string, std::string>();
			if (parent != nullptr)
			{
				for(auto &var : parent->getAllVars()){
					allVars.insert(var);
				}
			}
			for(auto &var : vars){
				allVars.insert(var);
			}
			return allVars;
		}

		std::string path = "";
		std::vector<ObjectTreeItem*> subtypes;
		ObjectTreeItem *parent = nullptr;
		std::unordered_map<std::string, std::string> vars = std::unordered_map<std::string, std::string>();
		std::vector<ObjInstance*> instances;

		virtual void addInstance(ObjInstance *instance)
		{
			if (std::find(instances.begin(), instances.end(), instance) != instances.end())
			{
				return;
			}
			instances.push_back(instance);

			std::sort(instances.begin(), instances.end(), [&] (ObjInstance *o1, ObjInstance* o2){
			if (o1 != nullptr)
			{
				return -1;
			}
			if (o2!= nullptr)
			{
				return 1;
			}
			return strcmp(o1->toStringTGM().c_str(),o2->toStringTGM().c_str());
			});

//JAVA TO C++ CONVERTER TODO TASK: A 'delete event' statement was not added since event was passed to a method or constructor. Handle memory management manually.
		}

		virtual void removeInstance(ObjInstance *instance)
		{
			auto found = std::find(instances.begin(), instances.end(), instance);
			if ( found == instances.end())
			{
				return;
			}
//JAVA TO C++ CONVERTER TODO TASK: The Java Collection 'remove(Object)' method is not converted:
			instances.erase(found);
			
//JAVA TO C++ CONVERTER TODO TASK: A 'delete event' statement was not added since event was passed to a method or constructor. Handle memory management manually.
		}

		virtual std::string parentlessName()
		{
			if (StringHelper::startsWith(path, parent->path))
			{
				return path.substr(parent->path.length());
			}
			else
			{
				return path;
			}
		}

		std::string typeString() override
		{
			return path;
		}

		virtual std::string toString()
		{
			return path;
		}

		std::string toStringTGM() override
		{
			return path;
		}


	public:

		ObjInstance* getElementAt(int arg0) 
		{
			// TODO Auto-generated method stub
			return instances[arg0];
		}

		int size()
		{
			// TODO Auto-generated method stub
			return instances.size();
		}


	};


}
