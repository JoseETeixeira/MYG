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
			//delete parent;
		}


		ObjectTreeItem(ObjectTreeItem *parent, const std::string &p):
			parent(parent)
		{
			path = StringHelper::trim(p);
			this->path = p;
			this->parent = parent;
			vars.emplace("type", path);
			std::string pp = p.c_str();
			std::stringstream ppp;
			ppp << pp.c_str();
			spdlog::info(path);
			if (parent != nullptr)
			{
				parent->subtypes.push_back(this); 
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
			
			vars.try_emplace(key, value);
			
			
		
		}

		virtual void setVar(const std::string &key)
		{
			if (vars.find(key) == vars.end())
			{
				vars.try_emplace(key, "null");
			}
		}

		virtual std::string getVar(const std::string &key) 
		{
			std::string ret = "";
			try{
				if(key == "parentType"){
					if(parent != nullptr)
						return parent->path;
					return "";
				}
				if(!key.empty()){
					if(!vars.empty()){
						std::string current_value = vars.at(key);
						if(!current_value.empty()){
							return current_value;
						}
					}
					
					if(parent != nullptr)
						return parent->getVar(key);
				}else{
					return "";
				}
				
				
			}catch(...){
				spdlog::error("getVar problem at var {}",key);
				return "";
			}
			

			
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

		std::string path = "" ;
		std::vector<ObjectTreeItem*> subtypes;
		ObjectTreeItem *parent = nullptr;
		std::unordered_map<std::string, std::string> vars = std::unordered_map<std::string, std::string>();
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
