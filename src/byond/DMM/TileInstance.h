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

namespace BYOND::dmm{

	class TileInstance {

	private:
		std::vector<BYOND::tree::Tree::TreeItem *> *cachedSorted;
		BYOND::tree::Tree::TreeItem *cachedArea = nullptr;

	public:
		std::vector<BYOND::tree::Tree::TreeItem *> *objs;
		int refCount = 0;
		
		TileInstance(std::vector<BYOND::tree::Tree::TreeItem *> *objs):objs(objs){
			
		}
		
		static TileInstance* fromString(std::string s, BYOND::tree::Tree *objTree, DMM dmm) {
			// This regex matches modified types: /blah/blah{a = "b"; c = 23}
			try {
				std::smatch m;
				std::regex_search(s,m,std::regex("[\\w/]+(?:\\{(?:\"(?:\\\\\"|[^\"])*?\"|[^\\}])*?\\})?(?=,|$)"));
				std::vector<BYOND::tree::Tree::TreeItem *> *objs = new std::vector<BYOND::tree::Tree::TreeItem *>();
				if(m.size() > 0){
					for(int i = 0; i< m.size(); i++){
						objs->push_back(BYOND::tree::ModifiedType::fromString(m[i].str(), objTree, dmm));
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
		std::string addObject(BYOND::tree::Tree::TreeItem * obj) {
			TileInstance* ti = new TileInstance(new std::vector<BYOND::tree::Tree::TreeItem *>(*objs), dmm);
			if(obj->istype("/area")) {
				for(int i = 0; i < ti->objs->size(); i++) {
					BYOND::tree::Tree::TreeItem *cobj = ti->objs->at(i);
					if(cobj->istype("/area"))
						ti->objs->erase(i);
				}
			}
			if(obj->istype("/turf")) {
				
				for(int i = 0; i < ti->objs->size(); i++) {
					BYOND::tree::Tree::TreeItem *cobj = ti->objs->at(i);
					if(cobj->istype("/turf"))
						ti->objs->erase(i);
				}
				
			}
			ti->objs->push_back(obj);
			ti->sortObjs();
			return dmm->getKeyForInstance(ti);
		}
		
		// Removes the bottom-most occurence of the obj.
		public String removeObject(ObjInstance obj) {
			TileInstance ti = new TileInstance(new ArrayList<>(objs), dmm);
			ObjectTreeItem replacement = null;
			if(obj.istype("/area"))
				replacement = dmm.objTree.get(dmm.objTree.get("/world").getVar("area"));
			else if(obj.istype("/turf")) {
				int turfcount = 0;
				for(ObjInstance i : ti.objs)
					if(i.istype("/turf"))
						turfcount++;
				if(turfcount <= 1)
					replacement = dmm.objTree.get(dmm.objTree.get("/world").getVar("turf"));
			}
			if(replacement != null)
				ti.objs.set(ti.objs.indexOf(obj), replacement);
			else
				ti.objs.remove(obj);
			return dmm.getKeyForInstance(ti);
		}
		
		public String removeObjectOrSubtypes(ObjInstance obj) {
			TileInstance ti = new TileInstance(new ArrayList<>(objs), dmm);
			ObjectTreeItem replacement = null;
			if(obj.istype("/area"))
				replacement = dmm.objTree.get(dmm.objTree.get("/world").getVar("area"));
			else if(obj.istype("/turf")) {
				int turfcount = 0;
				for(ObjInstance i : ti.objs)
					if(i.istype("/turf"))
						turfcount++;
				if(turfcount <= 1)
					replacement = dmm.objTree.get(dmm.objTree.get("/world").getVar("turf"));
			}
			ObjInstance toDel = null;
			for(ObjInstance obj2 : ti.objs) {
				if(obj2 == obj || obj2.istype(obj.toString())) {
					toDel = obj2;
					break;
				}	
			}
			if(toDel == null)
				return dmm.getKeyForInstance(this);
			if(replacement != null)
				ti.objs.set(ti.objs.indexOf(toDel), replacement);
			else
				ti.objs.remove(toDel);
			return dmm.getKeyForInstance(ti);
		}
		
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
		}
		
		public String moveObjToTop(ObjInstance obj) {
			TileInstance ti = new TileInstance(new ArrayList<>(objs), dmm);
			ti.objs.remove(obj);
			ti.objs.add(obj);
			ti.sortObjs();
			return dmm.getKeyForInstance(ti);
		}
		
		public String moveObjToBottom(ObjInstance obj) {
			TileInstance ti = new TileInstance(new ArrayList<>(objs), dmm);
			ti.objs.remove(obj);
			ti.objs.add(0, obj);
			ti.sortObjs();
			return dmm.getKeyForInstance(ti);
		}
		
		// Replaces the bottom-most occurence of the obj. 
		public String replaceObject(ObjInstance objA, ObjInstance objB) {
			TileInstance ti = new TileInstance(new ArrayList<>(objs), dmm);
			ti.objs.set(ti.objs.indexOf(objA), objB);
			return dmm.getKeyForInstance(ti);
		}
		
		public int hashCode() {
			return toString().hashCode();
		}
		
		public boolean equals(Object other) {
			if(!(other instanceof TileInstance))
				return false;
			if(other == this)
				return true;
			if(other.toString().equals(toString()))
				return true;
			return false;
		}
	}

};

