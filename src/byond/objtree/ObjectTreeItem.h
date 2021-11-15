#pragma once

#include "ObjInstance.h"
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include "../stringhelper.h"
#include "../vectorhelper.h"

namespace BYOND
{

	class ObjectTreeItem : public ObjInstance, public ListModel<ObjInstance*>
	{
	public:
		virtual ~ObjectTreeItem()
		{
			delete parent;
		}

		ObjectTreeItem(ObjectTreeItem *parent, const std::string &path)
		{
			path = StringHelper::trim(path);
			this->path = path;
			this->parent = parent;
			vars.emplace(L"type", path);
			if (parent != nullptr)
			{
				parent->subtypes.push_back(this);
				vars.emplace(L"parentType", parent->path);
			}
			instances.push_back(this);
		}

		ObjectTreeItem(const std::string &path)
		{
			this->path = path;
			vars.emplace(L"type", path);
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
				vars.emplace(key, L"null");
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
			return L"";
		}

		virtual std::unordered_map<std::string, std::string> getAllVars()
		{
			std::unordered_map<std::string, std::string> allVars = std::map<std::string, std::string>();
			if (parent != nullptr)
			{
				allVars.putAll(parent->getAllVars());
			}
			allVars.putAll(vars);
			return allVars;
		}

		std::string path = L"";
		std::vector<ObjectTreeItem*> subtypes;
		ObjectTreeItem *parent = nullptr;
		std::unordered_map<std::string, std::string> vars = std::map<std::string, std::string>();
		std::vector<ObjInstance*> instances;

		virtual void addInstance(ObjInstance *instance)
		{
			if (std::find(instances.begin(), instances.end(), instance) != instances.end())
			{
				return;
			}
			instances.push_back(instance);
//JAVA TO C++ CONVERTER TODO TASK: The 'Compare' parameter of std::sort produces a boolean value, while the Java Comparator parameter produces a tri-state result:
//ORIGINAL LINE: java.util.Collections.sort(instances, (o1, o2) ->
			std::sort(instances.begin(), instances.end(), [&] (o1, o2)
			{
			if (dynamic_cast<ObjectTreeItem*>(o1) != nullptr)
			{
				return -1;
			}
			if (dynamic_cast<ObjectTreeItem*>(o2) != nullptr)
			{
				return 1;
			}
			return o1->toString().compareToIgnoreCase(o2->toString());
			});
			int index = VectorHelper::indexOf(instances, instance);
			ListDataEvent *event = new ListDataEvent(this, ListDataEvent::INTERVAL_ADDED, index, index);
			for (auto l : listeners)
			{
				l->intervalAdded(event);
			}

//JAVA TO C++ CONVERTER TODO TASK: A 'delete event' statement was not added since event was passed to a method or constructor. Handle memory management manually.
		}

		virtual void removeInstance(ObjInstance *instance)
		{
			int index = VectorHelper::indexOf(instances, instance);
			if (index == -1)
			{
				return;
			}
//JAVA TO C++ CONVERTER TODO TASK: The Java Collection 'remove(Object)' method is not converted:
			instances.remove(instance);
			ListDataEvent *event = new ListDataEvent(this, ListDataEvent::INTERVAL_REMOVED, index, index);
			for (auto l : listeners)
			{
				l->intervalRemoved(event);
			}

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

	private:
		std::unordered_set<ListDataListener*> listeners = std::unordered_set<ListDataListener*>();

	public:
		void addListDataListener(ListDataListener *arg0) override
		{
			listeners.insert(arg0);
		}

		ObjInstance *getElementAt(int arg0) override
		{
			// TODO Auto-generated method stub
			return instances[arg0];
		}

		int getSize() override
		{
			// TODO Auto-generated method stub
			return instances.size();
		}

		void removeListDataListener(ListDataListener *arg0) override
		{
			listeners.remove(arg0);
		}

	};


}
