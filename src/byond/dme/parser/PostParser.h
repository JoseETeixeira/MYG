#pragma once

#include <regex>
#include <vector>
#include <map>
#include <set>
#include "../../ByondTypes.h"
#include "../Dme.h"
#include "WordReplacer.h"

namespace BYOND::dme::parser{

    using Dme = BYOND::dme::Dme;
    using ByondTypes = BYOND::ByondTypes;

 class PostParser final{

    private:

        Dme* dme;
        std::map<std::string, std::string> *globalVars;

        std::map<std::string, Dme::DmeItem *> *additionalCreatedItems = new std::map<std::string, Dme::DmeItem *>();
        std::vector<Dme::DmeItem*> *roots = new std::vector<Dme::DmeItem*>();

        std::regex *letterPattern = new std::regex("[a-zA-Zа-яА-Я]+");
        std::regex *numberPattern = new std::regex("\\d+");

        std::vector<std::string> mathSymbols = {"+", "-", "*", "/"};

    public:
        PostParser(Dme* dme) : dme(dme), globalVars(dme->getGlobalVars())
        {
        }

    public:

        void doParse() {
            for (auto itemEntry : *dme->items) {
                Dme::DmeItem* item = itemEntry.second;
                if (ByondTypes::GLOBAL != itemEntry.first) {
                    // Assign parent
                    if (hasParent(item->type)) {
                        connectParentAndChild(determineParent(item->type), item);
                    }

                    // Replace global vars in item with values
                    for (auto varEntry : *item->vars) {
                        item->setVar(varEntry.first, WordReplacer::replace(varEntry.second, *globalVars));
                    }

                    // Evaluate math expressions
                    for (auto varEntry : *item->vars) {
                        std::string value = varEntry.second;
                        if (noLetterMarkers(value) && hasMathMarkers(value)) {
                            try {
                                double newValue = stod(value);
                                long longNum = (long) newValue;
                                if (longNum == newValue) {
                                   item->setVar(varEntry.first, longNum);
                                } else {
                                   item->setVar(varEntry.first, newValue);
                                }
                                
                            } catch (...) {
                                spdlog::error("Exception Ignored");
                            }
                        }
                    }

                    // Add to roots if able
                    if (item->parentPath == ByondTypes::DATUM || item->type == ByondTypes::DATUM) {
                        roots->push_back(item);
                    }
                }
            }

            // During parent determining additional items are created. They are not declared in project,
            // and exist in form of intermediate objects, but they should exist in Dme.
            for (auto dmeItem : *additionalCreatedItems) {
                dme->addItem(dmeItem.second);
            }

            // Makes parents to know about every subtype.
            for (auto root : *roots) {
                setAndReturnAllSubtypes(root);
            }
        }
    private:

        std::set<std::string>* setAndReturnAllSubtypes(Dme::DmeItem* item) {
            std::set<std::string>*  tempSubtypes = new std::set<std::string>();
            std::set<std::string>*  itemSubtypes = item->allSubtypes;

            for (auto subtype : *itemSubtypes) {
                tempSubtypes->merge(*setAndReturnAllSubtypes(dme->getItem(subtype)));
            }
            itemSubtypes->merge(*tempSubtypes);

            return itemSubtypes;
        }



        bool noLetterMarkers(std::string text) {
            std::smatch m;
            std::regex_search(text,m,*letterPattern);
            return text.find("\"") == std::string::npos && text.find("'") == std::string::npos && m.empty();
        }

        bool hasMathMarkers(std::string text) {
            for (auto mathSymbol : mathSymbols) {
                if (text.find(mathSymbol) != std::string::npos) {
                    std::smatch m;
                    std::regex_search(text,m,*numberPattern);
                    int matchCount = m.size();
                    return matchCount > 1;
                }
            }
            return false;
        }

        Dme::DmeItem* determineParent(std::string type) {
            std::string parentPath = ByondTypes::DATUM;

            if (type.find_first_of('/') != type.find_last_of('/')) {
                parentPath = type.substr(0, type.find_last_of('/'));
            } else {
                if(type == ByondTypes::AREA || type == ByondTypes::TURF || type == ByondTypes::OBJ || type == ByondTypes::MOB){
                    parentPath = ByondTypes::ATOM;
                }
            }

            Dme::DmeItem* parent = dme->getItem(parentPath);

            if (parent == nullptr) {
                if (additionalCreatedItems->find(parentPath)!= additionalCreatedItems->end()) {
                    parent = additionalCreatedItems->at(parentPath);
                } else {
                    parent = new Dme::DmeItem(parentPath, dme);
                    connectParentAndChild(determineParent(parentPath), parent);
                    additionalCreatedItems->emplace(parentPath, parent);
                }
            }

            return parent;
        }

        void connectParentAndChild(Dme::DmeItem* parent, Dme::DmeItem* child) {
            parent->addToAllSubtype(child);
            parent->addDirectSubtype(child);
            if (child->parentPath.empty()) {
                child->parentPath = parent->type;
            }
        }

        bool hasParent(std::string type) {
            return !(ByondTypes::DATUM == (type)
                    || ByondTypes::CLIENT == (type)
                    || ByondTypes::WORLD == (type)
                    || ByondTypes::LIST == (type)
                    || ByondTypes::SAVEFILE == (type));
        }
    };


};

