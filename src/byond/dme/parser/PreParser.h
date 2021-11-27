#pragma once
#include "spdlog/spdlog.h"
#include "FileLine.h"
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <list>
#include "../../utils/string_helper.h"

namespace BYOND::dme::parser{

    class PreParser final{

    private:

        static inline char NEW_LINE = '\n';
        static inline char SLASH = '/';
        static inline char BACKSLASH = '\\';
        static inline char SPACE = ' ';
        static inline char STAR = '*';
        static inline char LEFT_BRACKET = '[';
        static inline char RIGHT_BRACKET = ']';
        static inline char LEFT_PARENTHESIS = '(';
        static inline char RIGHT_PARENTHESIS = ')';
        static inline char LEFT_FIGURE_BRACKET = '{';
        static inline char RIGHT_FIGURE_BRACKET = '}';
        static inline char QUOTE = '"';
        static inline char TAB = '\t';

        static inline std::string NEW_LINE_ESCAPE = "\\n";
        static inline std::string QUOTE_ESCAPE = "\"";
        static inline std::string QUOTE_ESCAPE_EXTRA = "\\\"";

        enum class Syntax {
            STRING, MULTI_STRING,
            COMMENT, MULTI_COMMENT,
            BRACKETS, PARENTHESES, INITIAL
        };

    public:

        // Strips comments and splits file into separate lines.
        static std::vector<FileLine*> parse(std::ifstream& file,std::string filename) {
			spdlog::info("Parsing {}", filename);
            StringBuilder *text = new StringBuilder();

            try {

                std::string line;
                while (std::getline(file, line))
                {
                   text->append(line);

                    if (StringHelper::endsWith(line,"\\")) {
                        text->setLength(text->length() - 1);
                    } else {
                        text->append(NEW_LINE);
                    }
                }
              
                text->append(NEW_LINE);
            } catch (IOException e) {
                spdlog::error(e.what());
            }

            return doParse(text->toString(), filename);
        }

        static std::vector<FileLine *> doParse(std::string text, std::string fileName) {
			std::list<Syntax>* syntaxStack = new std::list<Syntax>();
			std::vector<FileLine*>* fileLines = new std::vector<FileLine*>();
			FileLine::Builder* fileLineBuilder = new FileLine::Builder();

			bool hasNonWhitespace = false;
			int indentLevel = 0;

			for (int charIndex = 0; charIndex < text.length() - 1; charIndex++)
			{
				char currentChar = text[charIndex];
				char nextChar = text[charIndex + 1];

				Syntax currentSyntax = syntaxStack->size() > 0 ? syntaxStack->back() : Syntax::INITIAL;


			    bool inString =  (currentSyntax == Syntax::STRING || currentSyntax == Syntax::MULTI_STRING);
				bool inComment = (currentSyntax == Syntax::COMMENT || currentSyntax == Syntax::MULTI_COMMENT);

				if (currentChar == BACKSLASH && nextChar != NEW_LINE && inString)
				{ 
					fileLineBuilder->append(currentChar)->append(nextChar);
					charIndex++;
					continue;
				}
				else if (currentChar == NEW_LINE || (currentChar == BACKSLASH && nextChar == NEW_LINE))
				{
					hasNonWhitespace = false;
					indentLevel = 0;

					if (inComment && currentSyntax == Syntax::COMMENT)
					{
						syntaxStack->pop_back();
					}

					if (!inComment && currentChar == BACKSLASH)
					{
						fileLineBuilder->append(SPACE);
						charIndex++;
					}
					else if (syntaxStack->empty())
					{
						FileLine* line = fileLineBuilder->build();
						fileLines->push_back(line);
						fileLineBuilder = FileLine::builder();
					}
					else if (currentSyntax == Syntax::MULTI_STRING)
					{
						fileLineBuilder->append(NEW_LINE_ESCAPE);
					}
					else if (!inString)
					{
						fileLineBuilder->append(SPACE);
					}

					continue;
				}
				else if (inComment)
				{
					if (currentChar == SLASH && nextChar == STAR && currentSyntax != Syntax::COMMENT)
					{
						syntaxStack->push_back(Syntax::MULTI_COMMENT);
						charIndex++;
					}
					else if (currentChar == STAR && nextChar == SLASH && currentSyntax == Syntax::MULTI_COMMENT)
					{
						syntaxStack->pop_back();
						charIndex++;
					}
					continue;
				}
				else if (!inString && currentChar == SLASH && nextChar == SLASH)
				{
					syntaxStack->push_back(Syntax::COMMENT);
					charIndex++;
					continue;
				}
				else if (!inString && currentChar == SLASH && nextChar == STAR)
				{
					syntaxStack->push_back(Syntax::MULTI_COMMENT);
					charIndex++;
					continue;
				}
				else if (currentChar == LEFT_BRACKET)
				{
					syntaxStack->push_back(Syntax::BRACKETS);
				}
				else if (currentSyntax == Syntax::BRACKETS && currentChar == RIGHT_BRACKET)
				{
					syntaxStack->pop_back();
				}
				else if (!inString && currentChar == QUOTE)
				{
					syntaxStack->push_back(Syntax::STRING);
				}
				else if (currentSyntax == Syntax::STRING && currentChar == QUOTE)
				{
					syntaxStack->pop_back();
				}
				else if (!inString && currentChar == LEFT_PARENTHESIS)
				{
					syntaxStack->push_back(Syntax::PARENTHESES);
				}
				else if (currentSyntax == Syntax::PARENTHESES && currentChar == RIGHT_PARENTHESIS)
				{
					syntaxStack->pop_back();
				}
				else if (currentChar == LEFT_FIGURE_BRACKET && nextChar == QUOTE && !inString)
				{
					syntaxStack->push_back(Syntax::MULTI_STRING);
					charIndex++;
					fileLineBuilder->append(QUOTE_ESCAPE);
					continue;
				}
				else if (currentChar == QUOTE && nextChar == RIGHT_FIGURE_BRACKET)
				{
					syntaxStack->pop_back();
					charIndex++;
					fileLineBuilder->append(QUOTE_ESCAPE);
					continue;
				}
				else if (currentChar == QUOTE)
				{
					fileLineBuilder->append(QUOTE_ESCAPE_EXTRA);
					continue;
				}
				if ((currentChar != SPACE && currentChar != TAB) || hasNonWhitespace)
				{
					fileLineBuilder->append(currentChar);
				}
				if (currentChar != SPACE && currentChar != TAB && !hasNonWhitespace)
				{
					hasNonWhitespace = true;

					if (fileLineBuilder->hasNoIndent())
					{
						fileLineBuilder->setIndentLevel(indentLevel);
					}
				}
				else if (!hasNonWhitespace)
				{
					indentLevel++;
				}
			}

			fileLines->push_back(fileLineBuilder->build());

			if (syntaxStack->size() > 0)
			{
				//delete fileLines;
				//delete syntaxStack;
				if (syntaxStack->size() > 1) {
					throw std::runtime_error(StringHelper::toString("Syntax stack is not empty in file " + fileName + "!" ));
                    
                }
			}

			std::vector<FileLine*> filteredFileLines;

			for (auto line : *fileLines)
			{
				if (!line->text.empty())
				{
					spdlog::info(line->text);
					filteredFileLines.push_back(line);
				}
			}

			//JAVA TO C++ CONVERTER TODO TASK: A 'delete fileLines' statement was not added since fileLines was passed to a method or constructor. Handle memory management manually.
			//JAVA TO C++ CONVERTER TODO TASK: A 'delete syntaxStack' statement was not added since syntaxStack was passed to a method or constructor. Handle memory management manually.
			return filteredFileLines;
        }

        

        PreParser() { }
    };

};
