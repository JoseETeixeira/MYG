#pragma once
#include <string>
#include "../Dme.h"
#include "../../ByondFiles.h"
#include "../../ByondTypes.h"
#include <fstream>
#include <regex>
#include <vector>
#include <map>
#include <deque>
#include "PreParser.h"
#include "../../utils/string_helper.h"
#include "WordReplacer.h"

namespace BYOND::dme::parser{
    using Dme = BYOND::dme::Dme;
    using ByondFiles = BYOND::ByondFiles;
    using ByondTypes = BYOND::ByondTypes;
    
    class Parser final {

        private:
            static inline std::string INITIAL_DME_FILE = "initial_dme.json";

            static inline std::string DIRECTIVE_HASH = "#";
            static inline std::string DIRECTIVE_UNDEF = "undef";
            static inline std::string DIRECTIVE_IFDEF = "ifdef";
            static inline std::string DIRECTIVE_IFNDEF = "ifndef";
            static inline std::string DIRECTIVE_IF = "if";
            static inline std::string DIRECTIVE_HASHED_ENDIF = "#endif";


            static inline std::regex *directives = new std::regex("#(ifdef|ifndef|undef|if)[\\s]+(.+)");
            static inline std::regex *include = new std::regex("#include\\s+\"(.*(?:\\.dm|\\.dme|\\.dmm))\"");
            static inline std::regex *define = new std::regex("^#define\\s+(\\w+)(?:\\([^)]*\\))?(?:\\s+(.+))?");
            static inline std::regex *varDefinition = new std::regex("^[/\\w]+(?:var(?:/[\\w/]+)?)?/(\\w+)\\s*=\\s*(.+)|^[/\\w]+(?:var(?:/[\\w/]+)?)/(\\w+)");

        public:
            std::vector<std::string> pathTree;

            Dme* dme;
            std::map<std::string, std::string> *macroses;

            Parser(std::filesystem::path dmeFile) {
                spdlog::info(dmeFile.string());
                dme = new Dme();
                using std::filesystem::current_path;
                spdlog::info(current_path().string() + "\\" + INITIAL_DME_FILE);
                std::ifstream  dmeStream(current_path().string()+"\\"+INITIAL_DME_FILE);
                dme->mergeWJson(dmeStream);
                dme->fileDir = dmeFile.root_path().string();
                dme->absoluteRootPath = dmeFile.relative_path().remove_filename().string();
                macroses = dme->getMacroses();
            }

            void parseFile(std::ifstream& file, std::filesystem::path filename) {
                std::deque<bool> *preProcessStack = new std::deque<bool>();
                int preProcessBlocked = 0;

                for (FileLine* line : PreParser::parse(file,filename.string())) {
                    std::string lineText = line->text;

                    if (line->hasNoIndent()) {
                        continue;
                    }

                    if (StringHelper::startsWith(lineText,DIRECTIVE_HASH)) {
                        if (lineText.find(DIRECTIVE_HASHED_ENDIF) != std::string::npos && !preProcessStack->back()) {
                            preProcessStack->pop_back();
                            preProcessBlocked--;
                        }

                        std::smatch matcher;
                        std::regex_search(lineText,matcher,*directives);

                        if (!matcher.empty()) {
                            std::string macrosValue = matcher[2].str();
                            if(matcher[1].str() == DIRECTIVE_UNDEF){
                                macroses->erase(macrosValue);
                            }
                            else  if(matcher[1].str() == DIRECTIVE_IFDEF){
                                bool isDefined = macroses->find(macrosValue)!=macroses->end();
                                preProcessStack->push_back(isDefined);

                                if (!isDefined) {
                                    preProcessBlocked++;
                                }
                            }
                            else  if(matcher[1].str() == DIRECTIVE_IFNDEF){
                                bool isNotDefined = macroses->find(macrosValue) != macroses->end();
                                preProcessStack->push_back(isNotDefined);

                                if (!isNotDefined) {
                                    preProcessBlocked++;
                                }
                            }
                            else  if(matcher[1].str() == DIRECTIVE_IF){
                            
                                preProcessStack->push_back(true);
                            }

                        }
                        if (preProcessBlocked > 0) {
                            continue;
                        }

                        // Add new macros value if exists
                        std::smatch macrosMatcher;
                        std::regex_search(lineText,macrosMatcher,*define);
                        if (!macrosMatcher.empty() && !macrosMatcher[2].str().empty()) {
                            std::string macrosValue = StringHelper::replace(macrosMatcher[2].str(),"$", "\\$");
                            macroses->emplace(macrosMatcher[1].str(), WordReplacer::replace(macrosValue, *macroses));
                        }

                        // Parse included file if exist
                        std::smatch fileMatcher;
                        std::regex_search(lineText,fileMatcher,*include);
                        if (!fileMatcher.empty()) {
                            #if defined(WIN32)
                                std::string filePath = StringHelper::replace(fileMatcher[1].str(),"/","\\");
                                std::string fullFilePath =filename.parent_path().root_path().string()+filename.parent_path().relative_path().string() +"\\"+filePath;
                            #else if defined(LINUX)
                                std::string filePath = StringHelper::replace(fileMatcher[1].str(),"\\","/");
                                std::string fullFilePath =filename.parent_path().root_path().string()+filename.parent_path().relative_path().string() +"/"+filePath;
                            #endif
                            spdlog::info("Found file {}",fullFilePath);

                            if (StringHelper::endsWith(filePath,ByondFiles::DMM_SUFFIX)) {
                                dme->addMapFile(fullFilePath);
                            } else {
                                dme->addIncludedFile(fullFilePath);
                                std::ifstream f(fullFilePath);
                                parseFile(f,fullFilePath);
                            }
                        }

                        continue;
                    }

                    std::string fullPath = formFullPath(line);
                    std::string type = formTypeName(fullPath);

                    Dme::DmeItem* dmeItem = dme->getItemOrCreate(type);
                    std::smatch varMatcher;
                    std::regex_search(fullPath,varMatcher,*varDefinition);

                    if (!varMatcher.empty()) {
                        std::string value = varMatcher[2].str();

                        if (!value.empty()) {
                            std::string varName = varMatcher[1].str();
                            dmeItem->setVar(varName, WordReplacer::replace(value, *macroses));
                        } else {
                            dmeItem->setEmptyVar(varMatcher[3].str());
                        }
                    }
                }
            }

        private:
            std::string formFullPath(FileLine *line) {
                int expectedSize = line->indentLevel + 1;
                if (pathTree.size() < expectedSize) {
                    std::vector<std::string> *newPathTree = new std::vector<std::string>(expectedSize);
                    std::copy_n(pathTree.begin(),pathTree.size(),newPathTree->begin());
                    pathTree = *newPathTree;
                }

                pathTree[line->indentLevel] = line->text;
                StringBuilder *fullPath = new StringBuilder();

                for (int i = 0; i < line->indentLevel + 1; i++) {
                    std::string item = pathTree[i];

                    if (!item.empty()) {
                        if (item[0] == '/') {
                            fullPath = new StringBuilder(item);
                        } else {
                            fullPath->append('/')->append(item);
                        }
                    }
                }

                return fullPath->toString();
            }

            std::string formTypeName(std::string fullPath) {
                StringBuilder *typeName = new StringBuilder();

                for (auto pathPart : StringHelper::split(fullPath,'/')) {
                    if (pathPart.empty()) {
                        continue;
                    } else if (notPartOfTypeName(pathPart)) {
                        break;
                    }

                    typeName->append('/')->append(pathPart);
                }

                return typeName->length() > 0 ? typeName->toString() : ByondTypes::GLOBAL;
            }

            bool notPartOfTypeName(std::string pathPart) {
                return pathPart.find("=") != std::string::npos || pathPart.find("(") != std::string::npos
                        || strcmp("var",pathPart.c_str()) == 0 || strcmp("proc",pathPart.c_str()) == 0 || strcmp("global",pathPart.c_str()) == 0
                        || strcmp("static",pathPart.c_str()) == 0 || strcmp("tmp",pathPart.c_str()) == 0 || strcmp("verb",pathPart.c_str()) == 0;
            }
    };
};

