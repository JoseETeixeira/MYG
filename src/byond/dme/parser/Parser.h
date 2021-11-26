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

namespace BYOND{
    
    class Parser {

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
            dme = new Dme();
            std::ifstream  dmeStream(INITIAL_DME_FILE);
            dme->mergeWithJson(dmeStream);

            dme->absoluteRootPath = dmeFile.parent_path().root_path();
            macroses = dme->getMacroses();
        }

        void parseFile(std::ifstream& file, std::string filename) {
            std::deque<bool> *preProcessStack = new std::deque<bool>();
            int preProcessBlocked = 0;

            for (FileLine* line : PreParser::parse(file,filename)) {
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
                    val macrosMatcher = define.matcher(lineText);
                    if (macrosMatcher.find() && macrosMatcher.group(2) != null) {
                        val macrosValue = macrosMatcher.group(2).replace("$", "\\$");
                        macroses.put(macrosMatcher.group(1), WordReplacer.replace(macrosValue, macroses));
                    }

                    // Parse included file if exist
                    val fileMatcher = include.matcher(lineText);
                    if (fileMatcher.find()) {
                        val filePath = fileMatcher.group(1).replace('\\', File.separatorChar);
                        val fullFilePath = file.getParentFile().getAbsolutePath().concat(File.separator).concat(filePath);

                        if (filePath.endsWith(ByondFiles.DMM_SUFFIX)) {
                            dme.addMapFile(fullFilePath);
                        } else {
                            dme.addIncludedFile(fullFilePath);
                            parseFile(new File(fullFilePath));
                        }
                    }

                    continue;
                }

                final String fullPath = formFullPath(line);
                final String type = formTypeName(fullPath);

                val dmeItem = dme.getItemOrCreate(type);
                val varMatcher = varDefinition.matcher(fullPath);

                if (varMatcher.find()) {
                    val value = varMatcher.group(2);

                    if (value != null) {
                        val varName = varMatcher.group(1);
                        dmeItem.setVar(varName, WordReplacer.replace(value, macroses));
                    } else {
                        dmeItem.setEmptyVar(varMatcher.group(3));
                    }
                }
            }
        }

        private String formFullPath(final FileLine line) {
            val expectedSize = line.getIndentLevel() + 1;
            if (pathTree.length < expectedSize) {
                val newPathTree = new String[expectedSize];
                System.arraycopy(pathTree, 0, newPathTree, 0, pathTree.length);
                pathTree = newPathTree;
            }

            pathTree[line.getIndentLevel()] = line.getText();
            var fullPath = new StringBuilder();

            for (int i = 0; i < line.getIndentLevel() + 1; i++) {
                String item = pathTree[i];

                if (item != null && !item.isEmpty()) {
                    if (item.charAt(0) == '/') {
                        fullPath = new StringBuilder(item);
                    } else {
                        fullPath.append('/').append(item);
                    }
                }
            }

            return fullPath.toString();
        }

        private String formTypeName(final String fullPath) {
            val typeName = new StringBuilder();

            for (val pathPart : fullPath.split("/")) {
                if (pathPart.isEmpty()) {
                    continue;
                } else if (notPartOfTypeName(pathPart)) {
                    break;
                }

                typeName.append('/').append(pathPart);
            }

            return typeName.length() > 0 ? typeName.toString() : ByondTypes.GLOBAL;
        }

        private boolean notPartOfTypeName(final String pathPart) {
            return pathPart.contains("=") || pathPart.contains("(")
                    || "var".equals(pathPart) || "proc".equals(pathPart) || "global".equals(pathPart)
                    || "static".equals(pathPart) || "tmp".equals(pathPart) || "verb".equals(pathPart);
        }
    };
};

