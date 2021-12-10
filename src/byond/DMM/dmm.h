

// DMM loader - Where you will get confused by all the regex.
#pragma once
#include "Location.h"
#include "../tree/ByondTree.h"
#include <string>
#include <map>
#include <vector>
#include <filesystem>
#include <set>
#include <fstream>
#include <sstream>
#include "../utils/string_helper.h"
#include "../utils/string_builder.h"
#include "../utils/exception_helper.h"
#include "spdlog/spdlog.h"
#include <regex>
#include <boost/config.hpp>
#include <iostream>
#include <cctype>

#include <boost/bimap.hpp>
#include <ctime>


#include "spdlog/spdlog.h"
#include <algorithm>



namespace BYOND::dmm{

class DMM {

	

	public:
		class TileInstance;
		// Parser shit goes here.
		bool isCommenting = false;
		int parenthesisDepth = 0;
		int stringDepth = 0;
		int stringExpDepth = 0;
		int parenthesesDepth = 0;
		int arrayDepth[50];
		
		int minX = 1;
		int minY = 1;
		int minZ = 1;
		int maxX = 1;
		int maxY = 1;
		int maxZ = 1;
		
		int keyLen = 0;
		boost::bimap<std::string, TileInstance*> *instances = new boost::bimap<std::string, TileInstance*>();
		std::map<BYOND::dmm::Location*, std::string> *map = new std::map<Location*, std::string>();
		std::vector<std::string> *unusedKeys = new std::vector<std::string>();
		
		BYOND::tree::Tree *objTree;
		
		std::filesystem::path* file;
		
		std::string relPath = "";
		
		float storedViewportX = 0;
		float storedViewportY = 0;
		int storedViewportZoom = 32;


	//BEGIN TILE INSTANCE
	class TileInstance {

	private:
		std::vector<BYOND::tree::Tree::TreeItem *> *cachedSorted;
		BYOND::tree::Tree::TreeItem *cachedArea = nullptr;
		BYOND::dmm::DMM *dmm;

	public:
		std::vector<BYOND::tree::Tree::TreeItem *> *objs;
		int refCount = 0;
		
		TileInstance(std::vector<BYOND::tree::Tree::TreeItem *> *objs, BYOND::dmm::DMM* dmm):objs(objs),dmm(dmm){
			
		}
		
		static TileInstance* fromString(std::string s, BYOND::tree::Tree *objTree, BYOND::dmm::DMM* dmm) {
			// This regex matches modified types: /blah/blah{a = "b"; c = 23}
			try {
				std::smatch m;
				std::regex_search(s,m,std::regex("[\\w/]+(?:\\{(?:\"(?:\\\\\"|[^\"])*?\"|[^\\}])*?\\})?(?=,|$)"));
				std::vector<BYOND::tree::Tree::TreeItem *> *objs = new std::vector<BYOND::tree::Tree::TreeItem *>();
				if(m.size() > 0){
					for(int i = 0; i< m.size(); i++){
						objs->push_back(ModifiedType::fromString(m[i].str(), objTree,dmm));
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
				sb->append(obj->toString());
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
	};


class ModifiedType : public BYOND::tree::Tree::TreeItem {

    public:

        std::map<std::string, std::string> *vars;
        std::string parentType;
        BYOND::tree::Tree::TreeItem* parent;
        BYOND::dmm::DMM *dmm;

        ModifiedType(BYOND::tree::Tree *tree,BYOND::dme::Dme::DmeItem *item,std::map<std::string, std::string> *vars, std::string parentType,BYOND::dmm::DMM *dmm, std::string dmipath = "null"):vars(vars), dmm(dmm), TreeItem(tree,item,dmipath){
            this->parentType = parentType;
            this->parent = tree->getItem(parentType);
        }

        
        static BYOND::tree::Tree::TreeItem* fromString(std::string s, BYOND::tree::Tree *objtree, BYOND::dmm::DMM *dmm) {
            if(s.find("{")==std::string::npos)
                return objtree->getItem(s);
            // This will match the type path (/blah/blah) and the var list (a = "b"; c = 123)
            std::smatch m;
            std::regex_search(s,m,std::regex("([\\w/]+)\\{(.*)\\}"));
            if(!m.empty()) {
                std::map<std::string,std::string> *vars = new std::map<std::string,std::string>();
                // This will match variable key-val
                std::smatch varmatcher;
                std::string v = m[2].str();
                std::regex_search(v,varmatcher,std::regex("([\\w]+) ?= ?((?:\"(?:\\\\\"|[^\"])*\"|[^;])*)(?:$|;)"));
                for(int i = 0; i < varmatcher.size(); i++){
                    vars->emplace(varmatcher[i+1].str(),varmatcher[i+2].str());
                }
                
                ModifiedType *mt = new ModifiedType(objtree,objtree->getDMEItem(v),vars, m[1].str(),dmm,objtree->getItem(v)->dmipath);
               
			   	mt->parent = objtree->getItem(m[1].str());
				if(dmm->instances->left.find(mt->toString())!= dmm->instances->left.end()) {
					mt = (ModifiedType*) dmm->instances->left.at(mt->toString());
				} else {
					typedef boost::bimap< std::string, TileInstance* > results_bimap;
                    typedef results_bimap::value_type position;
					BYOND::dmm::DMM::TileInstance *ti = TileInstance::fromString(mt->toString(),objtree,dmm);
					//spdlog::info ("CREATED TILE INSTANCE: {}",ti->toString());
					dmm->instances->insert(position(dmm->getKeyForInstance(ti),ti));
					
				}

                if(mt->parent != nullptr) {
                    TileInstance *ti = TileInstance::fromString(m[2].str(),objtree,dmm);
                    typedef boost::bimap< std::string, TileInstance* > results_bimap;
                    typedef results_bimap::value_type position;
                    dmm->instances->insert(position(dmm->getKeyForInstance(ti),ti));
                
                }
               
                return mt;
            }
            return nullptr;
        }
        
        static ModifiedType* deriveFrom(BYOND::tree::Tree::TreeItem* i,BYOND::dmm::DMM *dmm) {
            
            ModifiedType *p = (ModifiedType*)i;
            ModifiedType *mt = new ModifiedType(p->tree,p->tree->getDMEItem(p->type),p->getAllVars(), p->type,dmm, p->tree->getItem(i->type)->dmipath);
            mt->parent = p->parent;
            return mt;
          
        }
        
        
        
        std::string getVar(std::string key) {
            if(vars->find(key)  != vars->end())
                return vars->at(key);
            if(parent != nullptr)
                return parent->getVar(key);
            return "null";
        }
        
        std::string toString() {
            StringBuilder *out = new StringBuilder(parentType);
            out->append('{');
            bool isFirst = true;
            for(std::pair<std::string,std::string> e : *vars) {
                if(isFirst)
                    isFirst = false;
                else
                    out->append("; ");
                out->append(e.first);
                out->append(" = ");
                out->append(e.second);
            }
            out->append('}');
            return out->toString();
        }
        
        
        size_t hashCode() {
            std::hash<std::string> hasher;
            size_t hash = hasher(toString());
            return hash;
        }
        
        bool equals(BYOND::tree::Tree::TreeItem* other) {
            if(other == this)
                return true;
            if(other->toString() == toString())
                return true;
            return false;
        }

        std::string typeString() {
            return parentType;
        }
        
        bool istype(std::string path) {
            if(this->type == path)
                return true;
            if(parent != nullptr)
                return parent->istype(path);
            return false;
        }
        
        /*
        public boolean viewVariables(FastDMM editor) {
            final JDialog dialog = new JDialog(editor, "View Variables", true);
            
            final ModifiedTypeTableModel model = new ModifiedTypeTableModel(this);
            JTable table = new JTable(model);
            table.setFillsViewportHeight(true);
            table.setDefaultRenderer(Object.class, new ModifiedTypeRenderer(model));
            dialog.getContentPane().add(new JScrollPane(table), BorderLayout.CENTER);
            
            JPanel bottomPanel = new JPanel(new BorderLayout());
            dialog.getContentPane().add(bottomPanel, BorderLayout.SOUTH);
            
            JButton okButton = new JButton("OK");
            okButton.addActionListener(e -> {
                model.doReturnTrue = true;
                dialog.setVisible(false);
            });
            bottomPanel.add(okButton, BorderLayout.WEST);
            
            JButton cancelButton = new JButton("Cancel");
            cancelButton.addActionListener(e -> dialog.setVisible(false));
            bottomPanel.add(cancelButton, BorderLayout.EAST);
            
            dialog.setLocationRelativeTo(editor);
            dialog.setSize(400, 450);
            dialog.setPreferredSize(dialog.getSize());
            dialog.setVisible(true);
            
            return model.doReturnTrue;
        }*/
    };


		char change_case (char c) {
			if (std::isupper(c)) 
				return std::tolower(c); 
			else
				return std::toupper(c); 
		}

		std::string flip_case(std::string s){
			std::string ans = "";
			for(char i : s){
				ans += change_case(i);
			}
			return ans;
		}
		

		
		DMM(std::filesystem::path* file, BYOND::tree::Tree* objTree) {
			this->file = file;
			this->objTree = objTree;

			relPath = file->relative_path().string();
			
			if(!std::filesystem::exists(file->string())) {
				
				std::vector<std::string> *unusedKeysSet = new std::vector<std::string> ();
				generateKeys(keyLen, "", unusedKeysSet);
				unusedKeys = new std::vector<std::string>(*unusedKeysSet);
				
				keyLen = 1;
				
				return;
			}

			spdlog::info("Reading map file: {}",file->string());
			std::ifstream br(file->string());

			std::string line;
			std::string runOn = "";
			std::vector<std::string> *unusedKeysSet = new std::vector<std::string>();
			
			std::map<std::string, std::string> *substitutions = new std::map<std::string, std::string>();


			unsigned mark = 0;
			while (std::getline(br, line))
			{
				line = StringHelper::trim(line);
				std::smatch p;
				std::regex_search(line,p,std::regex("\\((\\d*) ?, ?(\\d*) ?, ?(\\d*) ?\\) ?= ?\\{\""));
				if(!p.empty()) {
					//br.seekg(mark);
					break;
				}
				//mark = 100;
				//br.seekg(mark);
				line = stripComments(line);
				line = runOn + line;
				if(!StringHelper::trim(line).empty()) {
					if(StringHelper::endsWith(line,"\\")) {
						line = line.substr(0, line.length() - 1);
						runOn = line;
					} else if(parenthesisDepth > 0) {
						runOn = line;
					} else {
						runOn = "";
						std::smatch m;
						std::regex_search(line,m,std::regex("\"([a-zA-Z]*)\" ?= ?\\((.+)\\)"));
						if (!m.empty()) {
							TileInstance* ti = TileInstance::fromString(m[2].str(), objTree, this);
							//spdlog::info("Current tile instance: {}", ti->toString());

							typedef boost::bimap< std::string, TileInstance* > results_bimap;
							typedef results_bimap::value_type position;

							// Handle cases where DM put in duplicate instances.
							if (instances->right.find(ti) != instances->right.end()) {
								substitutions->emplace(m[1].str(), instances->right.at(ti));
								continue;
							}
							instances->insert(position(m[1].str(), TileInstance::fromString(m[2].str(), objTree, this)));
							//spdlog::info("Instance key {}",m[1].str());
							if (keyLen == 0) {
								keyLen = StringHelper::trim(m[1].str()).length();
								// Generate all the instance ID's
								generateKeys(keyLen, "", unusedKeysSet);
							}

							std::erase_if(*unusedKeysSet, [&](const auto& val) {
								return val == m[1].str();
							});
							
							
						}
					}
				}
			}
			unusedKeys->insert(unusedKeys->end(),unusedKeysSet->begin(),unusedKeysSet->end());
			
			std::map<Location*, std::string> *reverseMap = new std::map<Location*, std::string>();
			
			int partX = -1;
			int partY = -1;
			int partZ = -1;
			int cursorX = 0;
			int cursorY = 0;
			br.seekg(0);
			while (std::getline(br, line)) {
				line = StringHelper::trim(line);
				if(partX == -1) {
					std::smatch m;
					std::regex_search(line,m,std::regex("\\((\\d*) ?, ?(\\d*) ?, ?(\\d*) ?\\) ?= ?\\{\""));
					if(!m.empty()) {
						partX = stoi(m[1].str());
						partY = stoi(m[2].str());
						partZ = stoi(m[3].str());
						cursorX = 0;
						cursorY = 0;
					}
					continue;
				}
				std::smatch ma;
				std::regex_search(line,ma,std::regex("\"}"));
				if(!ma.empty()) {
					partX = -1;
					partY = -1;
					partZ = -1;
					continue;
				}
				for(int i = 0; i < line.length(); i += keyLen) {
					Location *loc = new Location(cursorX + partX, cursorY + partY, partZ) ;
					if(loc->z == 1)
						spdlog::info("CURRENT LOC: {} ,{}, {}", std::to_string(loc->x),std::to_string(loc->y),std::to_string(loc->z));
					std::string key = line.substr(i, keyLen);
					//spdlog::info("KEY: {}",key);
					if(substitutions->find(key) != substitutions->end())
						key = substitutions->at(key);
					reverseMap->emplace(loc, key);
					
					if(loc->x > maxX) {
						maxX = loc->x;
					}
					if(loc->y > maxY) {
						maxY = loc->y;
					}
					if(loc->z > maxZ) {
						maxZ = loc->z;
					}
					if(loc->x < minX) {
						minX = loc->x;
					}
					if(loc->y < minY) {
						minY = loc->y;
					}
					if(loc->z < minZ) {
						minZ = loc->z;
					}
					
					cursorX++;
				}
				cursorX = 0;
				cursorY += 1;
			}
			
			br.close();
			for(auto entry : *reverseMap) {
				putMap(new Location(entry.first->x, entry.first->y, entry.first->z), entry.second);
			}
			
			
		}
		
		void putMap(Location* l, std::string key) {
			if(map->find(l) != map->end()){
				std::string oldKey = map->at(l);
				if(!oldKey.empty()) {
					TileInstance *i = instances->left.at(oldKey);
					if (i != nullptr) {
						i->refCount--;
					}
				}
			}
				
			if(instances->left.find(key) != instances->left.end()) {
				TileInstance *i = instances->left.at(key);
				if(i != nullptr)
					i->refCount++;
				map->emplace(l, key);
			}
		}

		
		void save() {
			if(!std::filesystem::exists(file->string())) {
				std::ofstream f;
				try {
					f = std::ofstream(file->string());
				} catch (IOException e) {
					spdlog::error(e.what());
				}
				std::vector<std::string> *instancesList = new std::vector<std::string> ();
				for(auto ent : instances->left) {
					if(ent.second->refCount <= 0)
						continue;
					instancesList->push_back("\"" + ent.first + "\" = (" + (ent.second->toString()) + ")");
				}
				std::sort(instancesList->begin(), instancesList->end(),[&](std::string a, std::string b){
					if(flip_case(a) == flip_case(b)){
						for(auto instance : *instancesList){
							f << "\n";
						}
					}
					return strcmp(a.c_str(),b.c_str());
				});

				f << "\n";
			
			
				// Save normally
				for(int z = minZ; z <= maxZ; z++) {
					f << ("(1,1," + std::to_string(z) + ") = {\"");
					for(int y = maxY; y >= minY; y--) {
						for(int x = minX; x <= maxX; x++) {
							f << (map->at(new Location(x, y, z)));
						}
						f << "\n";
					}
					f << "\"}\n";
					f << "\n";
				}
			
				f.close();
			}
		}
		
		
		
		std::string getKeyForInstance(TileInstance* ti) {
			if(instances->right.find(ti) != instances->right.end()) {
				return instances->right.at(ti);
			}
			if(unusedKeys->size() == 0)
				expandKeys();
			if(unusedKeys->size() > 0) {
				srand((unsigned int) time (NULL));
				// Picking a key randomly reduces chances of merge conflicts, especially if this map editor is used a lot over time.
				// And we all know how much of a pain *those* are.
				std::string key = unusedKeys->at(rand()%unusedKeys->size());
				for(auto it = unusedKeys->begin(); it!= unusedKeys->end(); ++it){
					if(*it == key){
						unusedKeys->erase(it);
					}
				}
				// Assign the instance
				typedef boost::bimap< std::string, TileInstance* > results_bimap;
				typedef results_bimap::value_type position;
				instances->insert(position(key, ti));
				// Return the key
				return key;
			}
			return "";
		}
		
		void generateKeys(int length, std::string prefix, std::vector<std::string> *set) {
			if(length <= 0) {
				set->push_back(prefix);
				return;
			}
			for(char c = 'a'; c <= 'z'; c++) {
				generateKeys(length - 1, prefix + c, set);
			}
			for(char c = 'A'; c <= 'Z'; c++) {
				generateKeys(length - 1, prefix + c, set);
			}
		}
		
		// All warranties on merge conflicts and diff size are now void if you call this method.
		void expandKeys() {
			keyLen++;
			std::vector<std::string> *unusedKeysSet = new std::vector<std::string>();
			generateKeys(keyLen, "", unusedKeysSet);
			std::vector<std::string> *newUnusedKeys = new std::vector<std::string>(*unusedKeysSet);
			boost::bimap<std::string, TileInstance*> *newInstances = new boost::bimap<std::string, TileInstance*>();
			std::map<Location*, std::string> *newMap = new std::map<Location*, std::string>();
			std::map<std::string, std::string> *substitutions = new std::map<std::string, std::string>();
			for(auto instance : *instances) {
				srand((unsigned int) time (NULL));
				std::string newKey = newUnusedKeys->at(rand()%newUnusedKeys->size());
				for(auto it = newUnusedKeys->begin(); it != newUnusedKeys->end(); ++it){
					if(*it == newKey){
						newUnusedKeys->erase(it);
					}
				}
				
				substitutions->emplace(instance.left, newKey);
				typedef boost::bimap< std::string, TileInstance* > results_bimap;
				typedef results_bimap::value_type position;
				newInstances->insert(position(newKey, instance.right));
			}
			for(std::pair<Location*, std::string> mapInst : *map) {
				newMap->emplace(mapInst.first, substitutions->at(mapInst.second));
			}
			
			instances = newInstances;
			map = newMap;
			unusedKeys = newUnusedKeys;
		}
		
		void setSize(int nMinX, int nMinY, int nMinZ, int nMaxX, int nMaxY, int nMaxZ) {
			minX = nMinX;
			minY = nMinY;
			minZ = nMinZ;
			maxX = nMaxX;
			maxY = nMaxY;
			maxZ = nMaxZ;
			
			BYOND::tree::Tree::TreeItem *world = objTree->getItem("/world");
			if(world == nullptr)
				return;
			
			TileInstance *ti = TileInstance::fromString(world->getVar("turf") + ", " + world->getVar("area"), objTree, this);
			std::string defaultInst = getKeyForInstance(ti);
			
			std::set<Location*> *toRemove = new std::set<Location*> ();
			for(std::pair<Location*, std::string> mapInst : *map) {
				Location *l = mapInst.first;
				// In range? Don't remove then!
				if(l->x >= minX && l->x <= maxX && l->y >= minY && l->y <= maxY && l->z >= minZ && l->z <= maxZ)
					continue;
				instances->left.at(mapInst.second)->refCount--;
				toRemove->emplace(mapInst.first);
			}
			for(Location *l : *toRemove) {
				map->erase(l);
			}
			
			for(int x = minX; x <= maxX; x++) {
				for(int y = minY; y <= maxY; y++) {
					for(int z = minZ; z <= maxZ; z++) {
						Location *l = new Location(x, y, z);
						if(map->find(l) == map->end())
							putMap(l, defaultInst);
					}
				}
			}
		}
		
		std::string stripComments(std::string s)
		{
			StringBuilder *o = new StringBuilder();
			for(int i = 0; i < s.length(); i++) {
				char pC = ' ';
				if(i - 1 >= 0){
					pC = s[i - 1];
				}
					
				char ppC = ' ';
				if(i - 2 >= 0){
					ppC = s[i - 2];
				}
					
				char c = s[i];
				char nC = ' ';
				if(i + 1 < s.length()){
					nC = s[i + 1];
				}
					
				if(!isCommenting) {
					if(c == '/' && nC == '/' && stringDepth == 0){
						break;
					}
					if(c == '/' && nC == '*' && stringDepth == 0) {
						isCommenting = true;
						continue;
					}
					if(c == '"' && (pC != '\\' || ppC == '\\') && stringDepth != stringExpDepth) {
						stringDepth--;
					} else if(c == '"' && stringDepth == stringExpDepth) {
						stringDepth++;
					}
					if(c == '[' && stringDepth == stringExpDepth){
						arrayDepth[stringExpDepth]++;
					}else if(c == '[' && (pC != '\\' || ppC == '\\') && stringDepth != stringExpDepth){
						stringExpDepth++;
					}
					if(c == ']' && arrayDepth[stringExpDepth] != 0){
						arrayDepth[stringExpDepth]--;
					}else if(c == ']' && stringDepth > 0 && stringDepth == stringExpDepth){
						stringExpDepth--;
					}
					if(c == '(' && stringDepth == stringExpDepth){
						parenthesisDepth++;
					}
					if(c == ')' && stringDepth == stringExpDepth){
						parenthesisDepth--;
					}
					o->append(c);	
					
				}
				else {
					if(c == '*' && nC == '/') {
						isCommenting = false;
						i++;
					}
				}
					
			}
			return o->toString();
		}
		
		
	};


};
