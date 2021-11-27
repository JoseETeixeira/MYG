#pragma once
#include <string>
#include "../Dme.h"
#include <fstream>
#include "Parser.h"
#include "PostParser.h"

namespace BYOND::dme::parser
{
    using Dme = BYOND::dme::Dme;
    
    class DmeParser final {

       public:
            static Dme* parse(std::filesystem::path dmeFile) {
                Parser *parser = new Parser(dmeFile);
                std::ifstream file(dmeFile.string());
                parser->parseFile(file, dmeFile);
                Dme *dme = parser->dme;
                PostParser *post_parser  = new PostParser(dme);
                post_parser->doParse();
                return dme;
            }


            DmeParser() {}
    };
}

