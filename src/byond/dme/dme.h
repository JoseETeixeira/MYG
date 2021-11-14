#ifndef _DME_H
#define _DME_H


#include <string>
#include <optional>
#include <map>
#include <set>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include "var_wrapper.h"
#include "byond_types.h"
#include <spdlog/spdlog.h>
#include "json.hpp"



namespace BYOND {




class Dme {

class DmeItem {


    public:
        std::string parentPath;
        std::string type;
        Dme *environment;

        DmeItem(){}

        ///////////////// Types / Subtypes

        void addToAllSubtype(DmeItem item) {
            allSubtypes.insert(item.type);
        }

        void addToAllSubtype(std::string subtypePath) {
            allSubtypes.insert(subtypePath);
        }

        void addDirectSubtype(DmeItem item) {
            directSubtypes.insert(item.type);
        }

        void addDirectSubtype(std::string subtypePath) {
            directSubtypes.insert(subtypePath);
        }

        bool isType(std::string typeToCompare) {
            bool isEqualTypes = type.compare(typeToCompare) == 0;
            return isEqualTypes;
        }

        bool isType(DmeItem* item) {
            return isType(item->type);
        }

        ///////////////// Variables

        void setVar(std::string name, std::string value) {
            vars.insert(std::pair(name, value));
        }

        void setVarText(std::string name, std::string value) {
            vars.insert(std::pair(name, '"' + value + '"'));
        }

        void setVarFilePath(std::string name, std::string value) {
            vars.insert(std::pair(name, "'" + value + "'"));
        }

        void setVar(std::string name, double value) {
            std::ostringstream  ss;
            std::string val;
            ss << value;
            val =  ss.str();
            vars.insert(std::pair(name, val));
        }

        void setVar(std::string name, long value) {
            std::ostringstream  ss;
            std::string val;
            ss << value;
            val =  ss.str();
            vars.insert(std::pair(name, val));
        }

        void setVar(std::string name, int value) {
            std::ostringstream  ss;
            std::string val;
            ss << value;
            val =  ss.str();
            vars.insert(std::pair(name, val));
        }

        void setEmptyVar(std::string name) {
            vars.insert(std::pair(name, ByondTypes::null));
        }

        std::map<std::string, std::string> getAllVars() {
            if (!varsLookedUp && !parentPath.empty()) {
                std::map<std::string, std::string> varsMap = std::map<std::string, std::string>();
                lookUpVars(varsMap, this);
                for (auto var : varsMap) {
                    if (vars.find(var.first) != vars.end()) {
                        vars.insert(var);
                    }
                }
                varsLookedUp = true;
            }
            return vars;
        }

        std::string getVar(std::string name) {
            return VarWrapper::rawValue(lookupVar(name));
        }

        std::string getVarText(std::string name) {
            return getVarTextSafe(name).value();
        }

        std::optional<std::string> getVarTextSafe(std::string name) {
            return VarWrapper::optionalText(lookupVar(name));
        }

        std::string getVarFilePath(std::string name) {
            return getVarFilePathSafe(name).value();
        }

        std::optional<std::string> getVarFilePathSafe(std::string name) {
            return VarWrapper::optionalFilePath(lookupVar(name));
        }

        int getVarInt(std::string name) {
            return getVarIntSafe(name).value();
        }

        std::optional<int> getVarIntSafe(std::string name) {
            return VarWrapper::optionalInt(lookupVar(name));
        }

        double getVarDouble(std::string name) {
            return getVarDoubleSafe(name).value();
        }

        std::optional<double> getVarDoubleSafe(std::string name) {
            return VarWrapper::optionalDouble(lookupVar(name));
        }

        bool getVarBool(std::string name) {
            return getVarBoolSafe(name).value();
        }

        std::optional<bool> getVarBoolSafe(std::string name) {
            return VarWrapper::optionalBoolean(lookupVar(name));
        }

    private:





        std::map<std::string, std::string> vars = {};
        std::set<std::string> directSubtypes = {};
        std::set<std::string> allSubtypes = {};

        bool varsLookedUp = false;

        std::string lookupVar(std::string name) {
            if (vars.count(name) == 1 || parentPath.empty()) {
                return vars.at(name);
            }
            std::string parentVarVal = environment->getItem(parentPath).lookupVar(name);
            vars.insert(std::pair(name, parentVarVal));
            return parentVarVal;
        }

        void lookUpVars(std::map<std::string, std::string>& varsMap, DmeItem* parent) {
            if (parent != nullptr) {
                for (auto var : parent->vars) {
                    if (varsMap.find(var.first) != varsMap.end()) {
                        varsMap.insert(var);
                    }
                }
                if (!parent->varsLookedUp && !parent->parentPath.empty()) {
                    DmeItem item = environment->getItem(parentPath);
                    lookUpVars(varsMap, &item);
                }
            }
        }
    };

    class DmeJsonMerger {

    private:
        static inline  std::string TEXT_TYPE = "{text}";

        static inline  std::string MACROS_KEY = "macroses";
        static inline  std::string DEF_KEY = "definitions";

        static inline  std::string TYPE_PROP = "type";
        static inline  std::string PARENT_PROP = "parent";
        static inline  std::string SUBTYPES_PROP = "subtypes";
        static inline  std::string VARS_PROP = "vars";

    public:
        void merge(std::string& json, Dme& dme) {
            nlohmann::json json_parser;
            nlohmann::json jsonObject = json_parser.parse(json);

            auto& macros = jsonObject[jsonObject.find(MACROS_KEY).key()];
            addMacrossesToDme(macros, dme);


            auto& keys= jsonObject[jsonObject.find(DEF_KEY).key()];

            addDefinitionsToDme(keys, dme);
        }

        static void addMacrossesToDme(nlohmann::json macroses, Dme& dme) {
            nlohmann::json json_parser;
            for (const auto& member : macroses.array()) {
                auto& name = macroses.find(member).key();
                auto& value = macroses.find(member).value();
                if (value.is_number()) {
                
                        double value = getNumberFromValue(value);
                        std::ostringstream  ss;
                        std::string val;
                        ss << value;
                        val =  ss.str();
                        dme.addMacros(name, val);
                   
                   
                   
                    
                }
                else {
                    std::string valueString = value;
                    if (valueString.rfind(TEXT_TYPE, 0) == 0) {
                        dme.addMacrosText(name, valueString.substr(TEXT_TYPE.length()));
                    }
                    else {
                        dme.addMacros(name, valueString);
                    }
                }
            }
        }

        static void addDefinitionsToDme(nlohmann::json definitions, Dme dme) {
            for (auto& definition : definitions.items()) {
                nlohmann::json defObject = definition;

                std::string type = static_cast<std::string>(defObject[TYPE_PROP]);
                std::string parent = defObject[PARENT_PROP];
                nlohmann::json subtypes = defObject[SUBTYPES_PROP];
                nlohmann::json vars = defObject[VARS_PROP];

                DmeItem item = dme.getItemOrCreate(type);

                if (!parent.empty()) {
                    item.parentPath = parent;
                }

                if (subtypes != NULL) {
                    for (auto& subtype : subtypes.items()) {
                        item.addToAllSubtype(static_cast<std::string>(subtype.value()));
                        item.addDirectSubtype(static_cast<std::string>(subtype.value()));
                    }
                }

                if (vars != NULL) {
                    for (auto& var : vars.items()) {
                        auto& name = var.key();
                        auto& value = var.value();

                        if (value.is_null()) {
                            item.setEmptyVar(name);
                        }
                        else if (value.is_number()) {
                            double value = getNumberFromValue(value);
                            item.setVar(name,value );
                        }

                     
                        else if (value.type() == nlohmann::detail::value_t::string) {
                            std::string valueString = value;
                            if (valueString.rfind(TEXT_TYPE, 0) == 0) {
                                item.setVarText(name, valueString.substr(TEXT_TYPE.length()));
                            }
                            else {
                                item.setVar(name, valueString);
                            }
                        }
                        else if (value.type() == nlohmann::detail::value_t::boolean) {
                            item.setVar(name, std::to_string((bool)value));
                        }
                        else {
                            spdlog::error("Error merging with JSON: {} {}", name, value);
                        }
                    }
                }
            }
        }

        static double getNumberFromValue(double value) {
            return (double) value;
           
        }



        DmeJsonMerger() {};
    };
    

public:

    std::string absoluteRootPath;

    std::map<std::string, std::string> macroses ;
    std::map<std::string, DmeItem> items;

    std::list<std::string> includedFiles ;
    std::list<std::string> mapFiles;

    Dme() {};

     
     void mergeWithJson(std::ifstream jsonFile) {
        try {
            std::string buffer((std::istreambuf_iterator<char>(jsonFile)),
            std::istreambuf_iterator<char>());
            mergeWithJson(buffer);
        } catch (...) {
            spdlog::error("Error merging with JSON: {}",1);
        }
    }

    void mergeWithJson(std::string json) {
        DmeJsonMerger merger;
        merger.merge(json, *this);
        spdlog::info(json);
    }


    /*
    public void mergeWithJson(final InputStream is) {
        val bis = new BufferedInputStream(is);
        try (val buf = new ByteArrayOutputStream()) {
            int result;
            while ((result = bis.read()) != -1) {
                byte b = (byte) result;
                buf.write(b);
            }
            mergeWithJson(buf.toString());
        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
    }
    */

    ///////////////// Macros

    void addMacros(std::string name, std::string value) {
        macroses.insert(std::pair(name, value));
    }
    
    void addMacros(std::string name, double value) {
        std::ostringstream  ss;
        std::string val;
        ss << value;
        macroses.insert(std::pair(name, val));
    }

  

    void addMacrosText(std::string name, std::string value) {
        macroses.insert(std::pair(name, '"' + value + '"'));
    }

    void addMacrosFilePath(std::string name, std::string value) {
        macroses.insert(std::pair(name, "'" + value + "'"));
    }

    std::string getMacros(std::string name) {
        return VarWrapper::rawValue(macroses.at(name));
    }

    std::string getMacrosText(std::string name) {
        return VarWrapper::optionalText(macroses.at(name)).value();
    }

    std::optional<std::string> getMacrosTextSafe(std::string name) {
        return VarWrapper::optionalText(macroses.at(name));
    }

    std::string getMacrosFilePath(std::string name) {
        return VarWrapper::optionalFilePath(macroses.at(name)).value();
    }

    std::optional<std::string> getMacrosFilePathSafe(std::string name) {
        return VarWrapper::optionalFilePath(macroses.at(name));
    }

    int getMacrosInt(std::string name) {
        return VarWrapper::optionalInt(macroses.at(name)).value();
    }

    std::optional<int> getMacrosIntSafe(std::string name) {
        return VarWrapper::optionalInt(macroses.at(name));
    }

    double getMacrosDouble(std::string name) {
        return VarWrapper::optionalDouble(macroses.at(name)).value();
    }

    std::optional<double> getMacrosDoubleSafe(std::string name) {
        return VarWrapper::optionalDouble(macroses.at(name));
    }

    bool getMacrosBool(std::string name) {
        return getMacrosBoolSafe(name).value();
    }

    std::optional<bool> getMacrosBoolSafe(std::string name) {
        return VarWrapper::optionalBoolean(macroses.at(name));
    }

    ///////////////// Included / Map files

    void addIncludedFile(std::string filePath) {
        includedFiles.push_front(filePath);
    }

    void addMapFile(std::string filePath) {
        includedFiles.push_front(filePath);
    }

    ///////////////// Item

    void addItem(DmeItem item) {
        items.insert(std::pair(item.type, item));
    }

    DmeItem getItemOrCreate(std::string type) {
        DmeItem item;
        item.type = type;
        item.environment = this;
        items.insert(std::pair(type, item));
        return item;
    }

    DmeItem getItem(std::string type) {
        return items.at(type);
    }


    ///////////////// Global vars

    std::map<std::string, std::string> getGlobalVars() {
        return items.at(ByondTypes::GLOBAL).getAllVars();
    }

    std::string getGlobalVar(std::string name) {
        return VarWrapper::rawValue(getGlobalVars().at(name));
    }

    std::string getGlobalVarText(std::string name) {
        return VarWrapper::optionalText(getGlobalVars().at(name)).value();
    }

    std::optional<std::string> getGlobalVarTextSafe(std::string name) {
        return VarWrapper::optionalText(getGlobalVars().at(name));
    }

    std::string getGlobalFilePath(std::string name) {
        return VarWrapper::optionalFilePath(getGlobalVars().at(name)).value();
    }

    std::optional<std::string> getGlobalFilePathSafe(std::string name) {
        return VarWrapper::optionalFilePath(getGlobalVars().at(name));
    }

    int getGlobalVarInt(std::string name) {
        return VarWrapper::optionalInt(getGlobalVars().at(name)).value();
    }

    std::optional<int> getGlobalVarIntSafe(std::string name) {
        return VarWrapper::optionalInt(getGlobalVars().at(name));
    }

    double getGlobalVarDouble(std::string name) {
        return VarWrapper::optionalDouble(getGlobalVars().at(name)).value();
    }

    std::optional<double> getGlobalVarDoubleSafe(std::string name) {
        return VarWrapper::optionalDouble(getGlobalVars().at(name));
    }

    bool getGlobalVarBool(std::string name) {
        return getGlobalVarBoolSafe(name).value();
    }

    std::optional<bool> getGlobalVarBoolSafe(std::string name) {
        return VarWrapper::optionalBoolean(getGlobalVars().at(name));
    }

  
};



};

#endif