#pragma once

#include <string>
#include <regex>
#include <map>
#include <sstream>

namespace BYOND{

    class WordReplacer {

    private:
        static inline std::regex *WORD = new std::regex("(?!<[\\w\"/])\\w+(?![\\w\"/])");

    public:
        // Parse every word in provided text and replace it with value from 'searchMap' if key for it found.
        static std::string replace(std::string fullText, std::map<std::string, std::string> searchMap) {
            if (!isStringValue(fullText)) {
                std::smatch m;
                std::regex_search(fullText,m,*WORD);
                std::stringstream *output = new  std::stringstream();

                for(int i = 0; i < m.size(); i++){
                    std::string parsedWord = m[i].str();
                    //m.appendReplacement(output, searchMap.getOrDefault(parsedWord, parsedWord));
                    if(searchMap.find(parsedWord) != searchMap.end()){
                         *output << searchMap.at(parsedWord);
                    }else{
                        *output << parsedWord;
                    }
                   
                }

                return output->str();
            } else {
                return fullText;
            }
        }

    private:

        static bool isStringValue(std::string  value) {
            return startsAndEndsWith(value, '"') || startsAndEndsWith(value, '\'');
        }

        static bool startsAndEndsWith(std::string str, char c) {
            return str[0] == c && str[str.length() - 1] == c;
        }

    public:
         WordReplacer() {}
    };

};

