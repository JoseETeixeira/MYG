#pragma once
#include <string>
#include "../Dme.h"
#include <fstream>
#include "Parser.h"
#include "PostParser.h"

namespace BYOND{
    
    class DmeParser {

       public:
            static Dme* parse(std::filesystem::path dmeFile) {
                Parser *parser = new Parser(dmeFile);
                std::ifstream file(dmeFile.string());
                parser->parseFile(file, dmeFile.filename());
                Dme *dme = parser->dme;
                PostParser *post_parser  = new PostParser(dme);
                post_parser->doParse();
                return dme;
            }


            DmeParser() {}
    };
}

