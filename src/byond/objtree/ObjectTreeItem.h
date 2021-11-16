#include "ObjInstance.h"
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <list>
#include "spdlog/spdlog.h"
#include "../stringhelper.h"
#include "../vectorhelper.h"
#pragma once



namespace BYOND
{

	class ObjectTreeItem : public ObjInstance
	{
	public:
		~ObjectTreeItem()
		{
			delete parent;
		}


		ObjectTreeItem(ObjectTreeItem *parent, const std::wstring &p):
			parent(parent)
		{
			path = StringHelper::trim(p);
			this->path = p;
			this->parent = parent;
			vars.emplace(L"type", path);
			std::wstring pp = p.c_str();
			std::stringstream ppp;
			ppp << pp.c_str();
			spdlog::info(ppp.str());
			if (parent != nullptr)
			{
				parent->subtypes.push_back(this);
			}
			instances.push_back(this);
		}

		ObjectTreeItem(const std::wstring &path)
		{
			this->path = path;
			vars.emplace(L"type", path);
			instances.push_back(this);
		}

		bool istype(const std::wstring &path) override
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

		virtual void setVar(const std::wstring &key, const std::wstring &value)
		{
			vars.emplace(key, value);
		}

		virtual void setVar(const std::wstring &key)
		{
			if (vars.find(key) == vars.end())
			{
				vars.emplace(key, L"null");
			}
		}

		std::wstring getVar(const std::wstring &key) override
		{
			if (vars.find(key) != vars.end())
			{
				return vars[key];
			}
			if (parent != nullptr)
			{
				return parent->getVar(key);
			}
			return L"";
		}

		virtual std::unordered_map<std::wstring, std::wstring> getAllVars()
		{
			std::unordered_map<std::wstring, std::wstring> allVars = std::unordered_map<std::wstring, std::wstring>();
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

		std::wstring path = L"" ;
		std::vector<ObjectTreeItem*> subtypes;
		ObjectTreeItem *parent = nullptr;
		std::unordered_map<std::wstring, std::wstring> vars = std::unordered_map<std::wstring, std::wstring>();
		std::vector<ObjectTreeItem*> instances;

		virtual void addInstance(ObjectTreeItem *instance)
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
			return o1->toStringTGM().compare(o2->toStringTGM());
			});

//JAVA TO C++ CONVERTER TODO TASK: A 'delete event' statement was not added since event was passed to a method or constructor. Handle memory management manually.
		}

		virtual void removeInstance(ObjectTreeItem *instance)
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

		virtual std::wstring parentlessName()
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

		std::wstring typeString() override
		{
			return path;
		}

		virtual std::wstring toString()
		{
			return path;
		}

		std::wstring toStringTGM() override
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
