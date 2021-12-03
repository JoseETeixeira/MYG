

// DMM loader - Where you will get confused by all the regex.
#pragma once
#include "Location.h"
#include "TileInstance.h"
#include "../tree/ModifiedType.h"
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


namespace BYOND::dmm{

class DMM {

	public:
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
		boost::bimap<std::string, BYOND::dmm::TileInstance*> *instances = new boost::bimap<std::string, BYOND::dmm::TileInstance*>();
		std::map<Location*, std::string> *map = new std::map<Location*, std::string>();
		std::vector<std::string> *unusedKeys = new std::vector<std::string>();
		
		BYOND::tree::Tree *objTree;
		
		std::filesystem::path* file;
		
		std::string relPath = "";
		
		float storedViewportX = 0;
		float storedViewportY = 0;
		int storedViewportZoom = 32;

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
					br.seekg(mark);
					break;
				}
				mark = 100;
				br.seekg(mark);
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
						if(!m.empty()) {
							BYOND::dmm::TileInstance *ti = BYOND::dmm::TileInstance::fromString(m[2].str(), objTree, this);

							typedef boost::bimap< std::string, BYOND::dmm::TileInstance* > results_bimap;
    						typedef results_bimap::value_type position;
							
							// Handle cases where DM put in duplicate instances.
							if(instances->right.find(ti) != instances->right.end()) {
								substitutions->emplace(m[1].str(), instances->right.at(ti));
								continue;
							}
							instances->insert(position(m[1].str(), BYOND::dmm::TileInstance::fromString(m[2].str(), objTree, this)));
							if(keyLen == 0) {
								keyLen = m[1].str().length();
								// Generate all the instance ID's
								generateKeys(keyLen, "", unusedKeysSet);
							}
							for(auto it = unusedKeysSet->begin(); it!= unusedKeysSet->end(); ++it){
								if(*it == m[1].str()){
									unusedKeysSet->erase(it);
								}
							}
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
				std::smatch m;
				std::regex_search(line,m,std::regex("\"}"));
				if(!m.empty()) {
					partX = -1;
					partY = -1;
					partZ = -1;
					continue;
				}
				for(int i = 0; i < line.length(); i += keyLen) {
					Location *loc = new Location(cursorX + partX, cursorY + partY, partZ) ;
					std::string key = line.substr(i, i+keyLen);
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
			
			for(std::pair<Location*, std::string> entry : *reverseMap) {
				putMap(new Location(entry.first->x, maxY+minY-entry.first->y, entry.first->z), entry.second);
			}
		}
		
		void putMap(Location* l, std::string key) {
			putMap(l, key);
		}
		
		void putMap(Location *l, std::string key) {
			std::string oldKey = map->at(l);
			if(!oldKey.empty()) {
				BYOND::dmm::TileInstance *i = instances->left.at(oldKey);
				if (i != nullptr) {
					i->refCount--;
				}
			}
			if(instances->left.find(key) != instances->left.end()) {
				BYOND::dmm::TileInstance *i = instances->left.at(key);
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
		
		
		
		std::string getKeyForInstance(BYOND::dmm::TileInstance* ti) {
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
				typedef boost::bimap< std::string, BYOND::dmm::TileInstance* > results_bimap;
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
			boost::bimap<std::string, BYOND::dmm::TileInstance*> *newInstances = new boost::bimap<std::string, BYOND::dmm::TileInstance*>();
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
				typedef boost::bimap< std::string, BYOND::dmm::TileInstance* > results_bimap;
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
