#pragma once
#include <string>
#include "../Dme.h"
#include <fstream>
#include "../../utils/string_builder.h"


namespace BYOND{

    class Builder {

    private:

        int indentLevel = -1;
        StringBuilder *text = new StringBuilder();

    public:

        Builder() {
        }

        Builder* append(char c) {
            text->append(c);
            return this;
        }

        Builder* append(std::string s) {
            text->append(s);
            return this;
        }

        FileLine* build() {
            FileLine *fileLine = new FileLine();
            fileLine->indentLevel = indentLevel;
            fileLine->text = StringHelper::trim(text->toString()); 
            return fileLine;
        }

        bool hasNoIndent() {
            return indentLevel == -1;
        }

        void setIndentLevel(int indentLevel) {
            this->indentLevel = indentLevel;
        }
    };
    
    class FileLine {
    

        public:
            std::string text;
            int indentLevel;

            FileLine() {}

            static Builder* builder() {
                return new Builder();
            }

            bool hasNoIndent() {
                return indentLevel == -1;
            }

     
    };

   
};

