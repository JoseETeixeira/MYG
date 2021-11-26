#pragma once
#include <string>
#include "../../../third_party/json/json.hpp"
#include "../ByondTypes.h"
#include "../ByondVarWrapper.h"
#include "spdlog/spdlog.h"
#include <map>
#include <vector>
#include <fstream>
#include <optional>
#include <set>

using json = nlohmann::json;

namespace BYOND{

     class DmeJsonMerger {

        private:

            static inline std::string TEXT_TYPE = "{text}";

            static inline std::string MACROS_KEY = "macroses";
            static inline std::string DEF_KEY = "definitions";

            static inline std::string TYPE_PROP = "type";
            static inline std::string PARENT_PROP = "parent";
            static inline std::string SUBTYPES_PROP = "subtypes";
            static inline std::string VARS_PROP = "vars";

        public:
            static void merge(std::string &json, Dme* dme) {
                auto jsonObject = json::parse(json);

                auto subPart = jsonObject[MACROS_KEY];
                if (subPart != NULL) {
                    addMacrossesToDme(subPart.object(), dme);
                }

                subPart = jsonObject[DEF_KEY];
                if (subPart != NULL) {
                    addDefinitionsToDme(subPart.array(), dme);
                }
            }
        private:

            static void addMacrossesToDme(json macroses, Dme* dme) {
                for (json::iterator member = macroses.begin(); member != macroses.end(); ++member) {
                    auto name = member.key();
                    auto value = member.value();
                    if(value.is_number()){
                        dme->addMacros(name,getNumberFromValue<double>(value));
                            
                    }else{
                        auto valueString = value.dump();
                        if (StringHelper::startsWith(valueString,TEXT_TYPE)) {
                            dme->addMacrosText(name, valueString.substr(TEXT_TYPE.length()));
                        } else {
                            dme->addMacros(name, valueString);
                        }
                    }
                }
               
            }

            static std::string const BoolToString(bool b)
            {
            return b ? "true" : "false";
            }

            static void addDefinitionsToDme(std::vector<json> definitions,  Dme* dme) {
                for (auto definition : definitions) {
                    auto defObject = definition.object();

                    auto type = defObject[TYPE_PROP].dump();
                    auto parent = defObject[PARENT_PROP];
                    auto subtypes = defObject[SUBTYPES_PROP];
                    auto vars = defObject[VARS_PROP].object();

                    auto item = dme->getItemOrCreate(type);

                    if (parent != nullptr) {
                        item->parentPath = parent.dump();
                    }

                    if (subtypes != nullptr) {
                        for (auto subtype : subtypes.array()) {
                            item->addToAllSubtype(subtype.dump());
                            item->addDirectSubtype(subtype.dump());
                        }
                    }

                    if (vars != nullptr) {
                        for (json::iterator member = vars.begin(); member != vars.end(); ++member) {
                            auto name = member.key();
                            auto value = member.value();

                            if (value.empty()) {
                                item->setEmptyVar(name);
                            } else if (value.is_number()) {
                                item->setVar(name, getNumberFromValue<double>(value));
                            } else if (value.is_string()) {
                                std::string valueString = value;
                                if (StringHelper::startsWith(valueString,TEXT_TYPE)) {
                                    item->setVarText(name, valueString.substr(TEXT_TYPE.length()));
                                } else {
                                    item->setVar(name, valueString);
                                }
                            } else if (value.is_boolean()) {
                                item->setVar(name, BoolToString((bool)value));
                            } else {
                                spdlog::error("Unknown type of variable found in JSON. Name: " + name + ", value: " + value.dump());
                            }
                        }
                    }
                }
            }

            template<class T>
            static T getNumberFromValue(json value) {
                double doubleNum = stod(value.dump());
                long longNum = (long) doubleNum;
                if (longNum == doubleNum) {
                    return longNum;
                } else {
                    return doubleNum;
                }
            }
        public:

            DmeJsonMerger() {}
    };

    
    class Dme {
    
        
    
    public:
        std::string absoluteRootPath;

        std::map<std::string, std::string> *macroses = new std::map<std::string, std::string>();
        std::map<std::string, DmeItem *> *items = new std::map<std::string, DmeItem *>();

        std::vector<std::string> *includedFiles = new std::vector<std::string>();
        std::vector<std::string> *mapFiles = new std::vector<std::string>();

        std::map<std::string, std::string> *getMacroses(){
            return macroses;
        }

        void mergeWithJson(std::ifstream &jsonFile) {
            try {
                //get length of file
                jsonFile.seekg(0, std::ios::end);
                size_t length = jsonFile.tellg();
                jsonFile.seekg(0, std::ios::beg);

                char *buffer;

                //read file
                jsonFile.read(buffer, length);
                std::string buffer_s(buffer);
                mergeWithJson(buffer_s);

                free(buffer);
            } catch (IOException e) {
                spdlog::error(e.what());
            }
        }

        void mergeWithJson(std::string& json) {
            DmeJsonMerger::merge(json, this);
        }

        void mergeWithJson(std::string& is) {
            try {
               
                mergeWithJson(is);
            } catch (IOException e) {
                spdlog::error(e.what());
            }
        }

        ///////////////// Macros

        void addMacros(std::string name, std::string value) {
            macroses->emplace(name, value);
        }


        void addMacros(std::string name, int value) {
            std::stringstream os; 
            os << value;
            macroses->emplace(name, os.str());
        }

        void addMacros(std::string name, double value) {
            std::stringstream os; 
            os << value;
            macroses->emplace(name, os.str());
        }

        void addMacros(std::string name, float value) {
            std::stringstream os; 
            os << value;
            macroses->emplace(name, os.str());
        }

        void addMacros(std::string name, bool value) {
            std::stringstream os; 
            os << value;
            macroses->emplace(name, os.str());
        }

        void addMacrosText(std::string name, std::string value) {
            macroses->emplace(name, '"' + value + '"');
        }


        void addMacrosFilePath(std::string name, std::string value) {
            macroses->emplace(name, "'" + value + "'");
        }

        std::string getMacros(std::string name) {
            return ByondVarWrapper::rawValue(macroses->at(name));
        }

        std::string getMacrosText(std::string name) {
            return ByondVarWrapper::optionalText(macroses->at(name)).value();
        }

        std::optional<std::string> getMacrosTextSafe(std::string name) {
            return ByondVarWrapper::optionalText(macroses->at(name));
        }

        std::string getMacrosFilePath(std::string name) {
            return ByondVarWrapper::optionalFilePath(macroses->at(name)).value();
        }

        std::optional<std::string> getMacrosFilePathSafe(std::string name) {
            return ByondVarWrapper::optionalFilePath(macroses->at(name));
        }

        int getMacrosInt(std::string name) {
            return ByondVarWrapper::optionalInt(macroses->at(name)).value();
        }

        std::optional<int> getMacrosIntSafe(std::string name) {
            return ByondVarWrapper::optionalInt(macroses->at(name));
        }

        double getMacrosDouble(std::string name) {
            return ByondVarWrapper::optionalDouble(macroses->at(name)).value();
        }

        std::optional<double> getMacrosDoubleSafe(std::string name) {
            return ByondVarWrapper::optionalDouble(macroses->at(name));
        }

        bool getMacrosBool(std::string name) {
            return getMacrosBoolSafe(name).value();
        }

        std::optional<bool> getMacrosBoolSafe(std::string name) {
            return ByondVarWrapper::optionalBoolean(macroses->at(name));
        }

        ///////////////// Included / Map files

        void addIncludedFile(std::string filePath) {
            includedFiles->push_back(filePath);
        }

        void addMapFile(std::string filePath) {
            mapFiles->push_back(filePath);
        }

        ///////////////// Item

        void addItem(DmeItem *item) {
            items->emplace(item->getType(), item);
        }

        DmeItem* getItemOrCreate(std::string type) {
            if(items->find(type) != items->end()){
                return items->at(type);
            }else{
                DmeItem* item = new DmeItem(type,this);
                items->emplace(type,item);
                //TODO: Notify listeners
                return item;
            }
        }

        DmeItem* getItem(std::string type) {
            return items->at(type);
        }

        ///////////////// Global vars

        std::map<std::string, std::string> getGlobalVars() {
            return *items->at(ByondTypes::GLOBAL)->vars;
        }

        std::string getGlobalVar(std::string name) {
            return ByondVarWrapper::rawValue(getGlobalVars().at(name));
        }

        std::string getGlobalVarText(std::string name) {
            return ByondVarWrapper::optionalText(getGlobalVars().at(name)).value();
        }

        std::optional<std::string> getGlobalVarTextSafe(std::string name) {
            return ByondVarWrapper::optionalText(getGlobalVars().at(name));
        }

        std::string getGlobalFilePath(std::string name) {
            return ByondVarWrapper::optionalFilePath(getGlobalVars().at(name)).value();
        }

        std::optional<std::string> getGlobalFilePathSafe(std::string name) {
            return ByondVarWrapper::optionalFilePath(getGlobalVars().at(name));
        }

        int getGlobalVarInt(std::string name) {
            return ByondVarWrapper::optionalInt(getGlobalVars().at(name)).value();
        }

        std::optional<int> getGlobalVarIntSafe(std::string name) {
            return ByondVarWrapper::optionalInt(getGlobalVars().at(name));
        }

        double getGlobalVarDouble(std::string name) {
            return ByondVarWrapper::optionalDouble(getGlobalVars().at(name)).value();
        }

        std::optional<double> getGlobalVarDoubleSafe(std::string name) {
            return ByondVarWrapper::optionalDouble(getGlobalVars().at(name));
        }

        bool getGlobalVarBool(std::string name) {
            return getGlobalVarBoolSafe(name).value();
        }

        std::optional<bool> getGlobalVarBoolSafe(std::string name) {
            return ByondVarWrapper::optionalBoolean(getGlobalVars().at(name));
        }
    };





    class DmeItem {

    private:
        Dme *environment;


    public:

        std::string type;
        std::string parentPath = "";

        bool varsLookedUp = false;

        std::map<std::string, std::string> *vars = new std::map<std::string, std::string>();
        std::set<std::string> *directSubtypes = new std::set<std::string> ();
        std::set<std::string> *allSubtypes = new std::set<std::string>() ;

        bool varsLookedUp(){
            return varsLookedUp;
        }

        void varsLookedUp(bool value){
            varsLookedUp = value;
        }

        std::string getType(){
            return type;
        }

        std::string parentPath(){
            return parentPath;
        }

        DmeItem(std::string type,Dme *environment):type(type),environment(environment) {
        }

        ///////////////// Types / Subtypes

        void addToAllSubtype(DmeItem* item) {
            allSubtypes->emplace(item->getType());
        }

        void addToAllSubtype(std::string subtypePath) {
            allSubtypes->emplace(subtypePath);
        }

        void addDirectSubtype(DmeItem* item) {
            directSubtypes->emplace(item->getType());
        }

        void addDirectSubtype(std::string subtypePath) {
            directSubtypes->emplace(subtypePath);
        }

        bool isType(std::string typeToCompare) {
            bool isEqualTypes = type.compare(typeToCompare) == 0;
            if (!isEqualTypes) {
                DmeItem *itemToCompare = environment->getItem(typeToCompare);
                isEqualTypes = (itemToCompare != nullptr && itemToCompare->allSubtypes->find(type) != itemToCompare->allSubtypes->end());
            }
            return isEqualTypes;
        }

        bool isType(DmeItem* item) {
            return isType(item->getType());
        }

        ///////////////// Variables

        void setVar(std::string name, std::string  value) {
            vars->emplace(name, value);
        }

        void setVarText(std::string  name, std::string value) {
            vars->emplace(name, '"' + value + '"');
        }

        void setVarFilePath(std::string  name, std::string  value) {
            vars->emplace(name, "'" + value + "'");
        }

        void setVar(std::string  name, int value) {
            std::stringstream os;
            os << value;
            vars->emplace(name, os.str());
        }

        void setVar(std::string  name, double value) {
            std::stringstream os;
            os << value;
            vars->emplace(name, os.str());
        }

        void setVar(std::string  name, bool value) {
            std::stringstream os;
            os << value;
            vars->emplace(name, os.str());
        }

        void setEmptyVar(std::string name) {
            vars->emplace(name, ByondTypes::NULLS);
        }

        std::map<std::string, std::string> getAllVars() {
            if (!varsLookedUp && !parentPath.empty()) {
                std::map<std::string, std::string>  *varsMap = new std::map<std::string, std::string>();
                lookUpVars(varsMap, environment->getItem(parentPath));
                varsLookedUp = true;
                return *varsMap;
            }
            return *vars;
        }

        std::string getVar(std::string name) {
            return ByondVarWrapper::rawValue(lookupVar(name));
        }

        std::string getVarText(std::string name) {
            return getVarTextSafe(name).value();
        }

        std::optional<std::string> getVarTextSafe(std::string name) {
            return ByondVarWrapper::optionalText(lookupVar(name));
        }

        std::string getVarFilePath(std::string name) {
            return getVarFilePathSafe(name).value();
        }

        std::optional<std::string> getVarFilePathSafe(std::string name) {
            return ByondVarWrapper::optionalFilePath(lookupVar(name));
        }

        int getVarInt(std::string name) {
            return getVarIntSafe(name).value();
        }

        std::optional<int>  getVarIntSafe(std::string name) {
            return ByondVarWrapper::optionalInt(lookupVar(name));
        }

        double getVarDouble(std::string name) {
            return getVarDoubleSafe(name).value();
        }

        std::optional<double> getVarDoubleSafe(std::string name) {
            return ByondVarWrapper::optionalDouble(lookupVar(name));
        }

        bool getVarBool(std::string name) {
            return getVarBoolSafe(name).value();
        }

        std::optional<bool> getVarBoolSafe(std::string name) {
            return ByondVarWrapper::optionalBoolean(lookupVar(name));
        }
    private:

        std::string lookupVar(std::string  name) {
            if (vars->find(name) != vars->end() || parentPath.empty()) {
                return vars->at(name);
            }
            std::string parentVarVal = environment->getItem(parentPath)->lookupVar(name);
            vars->emplace(name, parentVarVal);
            return parentVarVal;
        }

        void lookUpVars(std::map<std::string, std::string> *varsMap, DmeItem* parent) {
            if (parent != nullptr) {
                for(auto var : parent->getAllVars() ){
                    if(varsMap->find(var.first) == varsMap->end()){
                        varsMap->emplace(var.first,var.second);
                    }
                }
                if (!parent->varsLookedUp && !parent->parentPath.empty()) {
                    lookUpVars(varsMap, environment->getItem(parent->parentPath));
                }
            }
        }
    }; 
}