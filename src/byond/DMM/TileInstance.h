#pragma once
#include "../tree/ByondTree.h"
#include <vector>
#include <string>
#include <regex>
#include "../tree/ModifiedType.h"
#include "../utils/exception_helper.h"
#include "../utils/string_builder.h"
#include "../utils/string_helper.h"
#include "spdlog/spdlog.h"
#include <algorithm>
#include <map>

namespace BYOND::dmm{

	class TileInstance {

	private:
		std::vector<BYOND::tree::Tree::TreeItem *> *cachedSorted;
		BYOND::tree::Tree::TreeItem *cachedArea = nullptr;
		DMM *dmm;

	public:
		std::vector<BYOND::tree::Tree::TreeItem *> *objs;
		int refCount = 0;
		
		TileInstance(std::vector<BYOND::tree::Tree::TreeItem *> *objs, DMM* dmm):objs(objs),dmm(dmm){
			
		}
		
		static TileInstance* fromString(std::string s, BYOND::tree::Tree *objTree, DMM* dmm) {
			// This regex matches modified types: /blah/blah{a = "b"; c = 23}
			try {
				std::smatch m;
				std::regex_search(s,m,std::regex("[\\w/]+(?:\\{(?:\"(?:\\\\\"|[^\"])*?\"|[^\\}])*?\\})?(?=,|$)"));
				std::vector<BYOND::tree::Tree::TreeItem *> *objs = new std::vector<BYOND::tree::Tree::TreeItem *>();
				if(m.size() > 0){
					for(int i = 0; i< m.size(); i++){
						objs->push_back(BYOND::tree::ModifiedType::fromString(m[i].str(), objTree,dmm));
					}
				}
				return new TileInstance(objs, dmm);
			} catch(StackOverflowError e) {
				spdlog::error("Stack overflow. Stack {}",s);
				return nullptr;
			}
		}
		
		std::string toString() {
			StringBuilder *sb = new StringBuilder();
			bool isFirst = true;
			for(BYOND::tree::Tree::TreeItem *obj : *objs) {
				if(isFirst)
					isFirst = false;
				else
					sb->append(",");
				sb->append(obj);
			}
			return sb->toString();
		}
		
		template <typename T> int sgn(T val) {
			return (T(0) < val) - (val < T(0));
		}
				
		
		std::vector<BYOND::tree::Tree::TreeItem *>* getLayerSorted() {
			if(cachedSorted == nullptr) {
				cachedSorted = new std::vector<BYOND::tree::Tree::TreeItem *>(*objs);
				std::sort(cachedSorted->begin(), cachedSorted->end(),[&](BYOND::tree::Tree::TreeItem *a,BYOND::tree::Tree::TreeItem *b){
					try {
						float layerA = stof(a->getVar("plane"));
						float layerB = stof(b->getVar("plane"));
						if(layerA == layerB) {
							layerA = stof(a->getVar("layer"));
							layerB = stof(b->getVar("layer"));
						}
						if(layerA == layerB) {
							// Sort by type
							if(StringHelper::startsWith(a->type,"/turf"))
								layerA = 1;
							if(StringHelper::startsWith(a->type,"/obj"))
								layerA = 2;
							if(StringHelper::startsWith(a->type,"/mob"))
								layerA = 3;
							if(StringHelper::startsWith(a->type,"/area"))
								layerA = 4;
							if(StringHelper::startsWith(b->type,"/turf"))
								layerB = 1;
							if(StringHelper::startsWith(b->type,"/obj"))
								layerB = 2;
							if(StringHelper::startsWith(b->type,"/mob"))
								layerB = 3;
							if(StringHelper::startsWith(b->type,"/area"))
								layerB = 4;
						}
						return (int)sgn(layerA - layerB);
					} catch (NumberFormatException e) {
						if(a != nullptr && b != nullptr) {
							spdlog::error("Error with layers " + a->getVar("layer") + ", " + b->getVar("layer"));
						}
						return 0;
					}
				});
				
			}
			return cachedSorted;
		}
		
		
		BYOND::tree::Tree::TreeItem* getArea() {
			if(cachedArea == nullptr) {
				for(BYOND::tree::Tree::TreeItem *i : *objs) {
					if(i == nullptr)
						continue;
					if(i->type == "/area")
						cachedArea = i;
				}
			}
			return cachedArea;
		}
		
		void sortObjs() {
			// Sort the object list in the order 
			std::sort(objs->begin(), objs->end(),[&](BYOND::tree::Tree::TreeItem *a,BYOND::tree::Tree::TreeItem *b){
				int iA = 0;
				int iB = 0;
				if(a->istype("/obj"))
					iA = 1;
				else if(a->istype("/mob"))
					iA = 2;
				else if(a->istype("/turf"))
					iA = 3;
				else if(a->istype("/area"))
					iA = 4;
				if(b->istype("/obj"))
					iB = 1;
				else if(b->istype("/mob"))
					iB = 2;
				else if(b->istype("/turf"))
					iB = 3;
				else if(b->istype("/area"))
					iB = 4;
				return iA < iB ? -1 : (iA == iB ? 0 : 1);
			});
		
		}

		
		
		// Modification functions. They do not modify the tile instance, they return the key pointing to the modified instance.
		std::string addObject(BYOND::tree::Tree::TreeItem *obj) {
			TileInstance* ti = new TileInstance(new std::vector<BYOND::tree::Tree::TreeItem *>(*objs),dmm);
			if(obj->istype("/area")) {
				for(auto i = ti->objs->begin(); i != ti->objs->end(); ++i) {
					BYOND::tree::Tree::TreeItem *cobj = *i;
					if(cobj->istype("/area"))
						ti->objs->erase(i);
				}
			}
			if(obj->istype("/turf")) {
				
				for(auto i = ti->objs->begin(); i != ti->objs->end(); ++i) {
					BYOND::tree::Tree::TreeItem *cobj = *i;
					if(cobj->istype("/turf"))
						ti->objs->erase(i);
				}
				
			}
			ti->objs->push_back(obj);
			ti->sortObjs();
			return dmm->getKeyForInstance(ti);
		}
		
		// Removes the bottom-most occurence of the obj.
		std::string removeObject(BYOND::tree::Tree::TreeItem * obj) {
			TileInstance* ti = new TileInstance(new std::vector<BYOND::tree::Tree::TreeItem *>(*objs),dmm);
			BYOND::tree::Tree::TreeItem *replacement = nullptr;
			if(obj->istype("/area"))
				replacement = obj->tree->getItem(obj->tree->getItem("/world")->getVar("area"));
			else if(obj->istype("/turf")) {
				int turfcount = 0;
				for(BYOND::tree::Tree::TreeItem *i : *ti->objs)
					if(i->istype("/turf"))
						turfcount++;
				if(turfcount <= 1)
					replacement = obj->tree->getItem(obj->tree->getItem("/world")->getVar("turf"));
			}
			if(replacement != nullptr)
				for(auto it = ti->objs->begin(); it!=ti->objs->end(); ++it){
					if (*it == obj){
						ti->objs->emplace(it, replacement);
					}
				}
				
			else
				for(auto it = ti->objs->begin(); it!=ti->objs->end(); ++it){
					if (*it == obj){
						ti->objs->erase(it);
					}
				}
				
			return dmm->getKeyForInstance(ti);
		}
		
		std::string removeObjectOrSubtypes(BYOND::tree::Tree::TreeItem *obj) {
			TileInstance* ti = new TileInstance(new std::vector<BYOND::tree::Tree::TreeItem *>(*objs),dmm);
			BYOND::tree::Tree::TreeItem *replacement = nullptr;
			if(obj->istype("/area"))
				replacement = obj->tree->getItem(obj->tree->getItem("/world")->getVar("area"));
			else if(obj->istype("/turf")) {
				int turfcount = 0;
				for(BYOND::tree::Tree::TreeItem *i : *ti->objs)
					if(i->istype("/turf"))
						turfcount++;
				if(turfcount <= 1)
					replacement = obj->tree->getItem(obj->tree->getItem("/world")->getVar("turf"));
			}
			BYOND::tree::Tree::TreeItem *toDel = nullptr;
			for(BYOND::tree::Tree::TreeItem *obj2 : *ti->objs) {
				if(obj2 == obj || obj2->istype(obj->toString())) {
					toDel = obj2;
					break;
				}	
			}
			if(toDel == nullptr)
				return dmm->getKeyForInstance(this);
			if(replacement != nullptr)
				for(auto it = ti->objs->begin(); it!=ti->objs->end(); ++it){
						if (*it == toDel){
							ti->objs->emplace(it,replacement);
						}
					}
			else
				for(auto it = ti->objs->begin(); it!=ti->objs->end(); ++it){
					if (*it == toDel){
						ti->objs->erase(it);
					}
				}
			return dmm->getKeyForInstance(ti);
		}
		
		/*
		public String deleteAllInFilter(FastDMM editor) {
			TileInstance ti = new TileInstance(new ArrayList<>(), dmm);
			boolean hasTurf = false;
			boolean hasArea = false;
			for(ObjInstance obj : objs) {
				if(!editor.inFilter(obj)) {
					ti.objs.add(obj);
					if(obj.istype("/turf"))
						hasTurf = true;
					if(obj.istype("/area"))
						hasArea = true;
				}
			}
			if(!hasTurf)
				ti.objs.add(dmm.objTree.get(dmm.objTree.get("/world").getVar("turf")));
			if(!hasArea)
				ti.objs.add(dmm.objTree.get(dmm.objTree.get("/world").getVar("area")));
			ti.sortObjs();
			return dmm.getKeyForInstance(ti);
		}*/
		
		std::string moveObjToTop(BYOND::tree::Tree::TreeItem *obj) {
			TileInstance* ti = new TileInstance(new std::vector<BYOND::tree::Tree::TreeItem *>(*objs),dmm);
			for(auto it = ti->objs->begin(); it!=ti->objs->end(); ++it){
				if (*it == obj){
					ti->objs->erase(it);
				}
			}
			ti->objs->push_back(obj);
			ti->sortObjs();
			return dmm->getKeyForInstance(ti);
		}
		
		std::string moveObjToBottom(BYOND::tree::Tree::TreeItem * obj) {
			TileInstance* ti = new TileInstance(new std::vector<BYOND::tree::Tree::TreeItem *>(*objs),dmm);
			for(auto it = ti->objs->begin(); it!=ti->objs->end(); ++it){
				if (*it == obj){
					ti->objs->erase(it);
				}
			}
			ti->objs->emplace(objs->begin(), obj);
			ti->sortObjs();
			return dmm->getKeyForInstance(ti);
		}
		
		// Replaces the bottom-most occurence of the obj. 
		std::string replaceObject(BYOND::tree::Tree::TreeItem *objA, BYOND::tree::Tree::TreeItem *objB) {
			TileInstance* ti = new TileInstance(new std::vector<BYOND::tree::Tree::TreeItem *>(*objs),dmm);
			for(auto it = ti->objs->begin(); it!=ti->objs->end(); ++it){
				if (*it == objA){
					ti->objs->emplace(it,objB);
				}
			}
			return dmm->getKeyForInstance(ti);
		}
		
		int hashCode() {
			std::hash<std::string> hasher;
			return hasher(toString());
		}
		
		bool equals(TileInstance* other) {
			if(other == this)
				return true;
			if(other->toString() == toString())
				return true;
			return false;
		}
	}

};

