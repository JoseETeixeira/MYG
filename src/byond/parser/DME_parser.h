#ifndef _DME_PARSER_H
#define _DME_PARSER_H
#pragma once

#include "../tree/DME_tree_item.h"
#include "../tree/DME_tree.h"
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <stdexcept>
#include <utility>
#include <regex>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <fstream>
#include <future>
#include <thread>
#include "../utils/exception_helper.h"
#include "../utils/string_helper.h"
#include "../utils/string_builder.h"
#include "../utils/util.h"
#include "spdlog/spdlog.h"


namespace BYOND{


class DME_Parser{

enum class ParseLevel
    {
        SINGLE_QUOTES,
        DOUBLE_QUOTES,
        INDEX,
        STRING_INLINE,
        MULTILINE_STRING,
        PARENS,
        BASE
    };

public:
		DME_Tree *tree;

private:
		std::ifstream* dme;

		

        std::filesystem::path path;

		/**
		 * Group 1 is file to include
		 */
		static inline std::regex *INCLUDE_PATTERN = new std::regex ("\\s*?#include\\s+\"(.+)\"\\s*");

		/**
		 * Group 1 is the name of the macro
		 * Group 2 is the value of the macro
		 */
		static inline std::regex  *DEFINE_PATTERN = new std::regex ("\\s*?as#define\\s+([^\\s]+)\\s+(.+)\\s*");

		/**
		 * Group 1 is the macro to undefine
		 */
		static inline std::regex  *UNDEF_PATTERN = new std::regex ("\\s*?#undef\\s+([^\\s]+)\\s*");

		/**
		 * Group 1 is the name of the proc
		 * Group 2 is the parameters
		 */
		static inline std::regex  *PROC_PATTERN = new std::regex ("^\\s*?(?:proc/)?([\\w/]+?)\\s*\\((.*)\\)\\s*");

		/**
		 * Group 1 is the type and flags and name of the var
		 * Group 2 is what was assigned
		 */
		static inline std::regex  *VAR_PATTERN = new std::regex ("^\\s*?(?:var/)?([\\w/]+)\\s*=\\s*(.+)");

	public:
		virtual ~DME_Parser()
		{
			//delete dme;
			delete tree;
		}

		DME_Parser(std::ifstream *dme,std::filesystem::path *path, DME_Tree *tree):dme(dme)
		{
			this->path = *path;
			this->tree = tree;
		}

		DME_Parser(std::ifstream *dme,std::filesystem::path *path):dme(dme)
		{
            this->path = *path;
			this->tree = new DME_Tree();
		}

		/*
		virtual std::future<DME_Tree*> *parse()
		{
            std::promise<DME_Tree*> future;
            std::thread* t;

			try
			{
				// Begin by parsing stddef.dm, then parse the DME
                std::ifstream *stddef = new std::ifstream("stddef.dm");
				subParse(tree,stddef, nullptr);
				t = new std::thread( [&future,this]{ 
                    std::ifstream *tempVar = new std::ifstream(dme);
                    subParse(tree, tempVar, path);
                    future.set_value_at_thread_exit(tree);
                
                });

                t->detach();
			}
			catch (const IOException &e)
			{
				spdlog::error(e.what());
			}

			delete t;
			return &future.get_future();
		}
		
		*/

		virtual DME_Tree *parseSynchronously()
		{
			spdlog::info("Enter parse sync");
			try
			{
				spdlog::info("Begin DME parse");
				// Begin by parsing stddef.dm, then parse the DME
				//subParse(tree, new BufferedReader(new InputStreamReader(this.getClass().getResourceAsStream("/stddef.dm"))), null);
				std::ifstream *stddef = new std::ifstream("stddef.dm");
				subParse(tree,stddef, std::filesystem::path(""));

                subParse(tree, dme, path);
			}
			catch (const IOException &e)
			{
				spdlog::error(e.what());
			}
			return tree;
		}

		/**
		 * Parses an individual file.
		 *
		 * @param reader The reader of the file
		 * @throws IOException If an IOException occurs reading from the buffer
		 */
	private:
		void subParse(DME_Tree *tree, std::ifstream* reader, std::filesystem::path currentFile)
		{
			std::vector<std::string> lines; // Relatively small, so ArrayList will outperform LinkedList
			std::stringstream *lineBuffer = new std::stringstream(); // Buffer for multilines and incomplete parens

			std::list<ParseLevel> parseStack; // Stack for nested operations
			parseStack.push_back(ParseLevel::BASE);

			// Variables for parsing the var defs - this could get ugly
			std::vector<std::vector<std::string>> pathList; // Keeps track of the current path sections - explained later
			int indentDepth; // For parsing tabs
			int lowestProcDepth = -1; // Lowest indent depth for the current proc, or -1 if no proc
			std::stringstream *fullPathBuilder = new std::stringstream(); // Builds the full path of a line
			std::vector<std::string> splitLine; // For storing the line split on '/'
			std::vector<std::string> subPath; // The part of the path given in the current line
			std::string restOfTheLine; // The part of the line that doesn't define the path

			bool inComment = false; // Flag for a multiline comment

			std::string currentLine; // Current line
			int lineCount = 0; // Current line #
			while (std::getline(*reader, currentLine))
			{
				lineCount++;
				std::string space = "#";

				if (beginsAfterSpaces(&currentLine,&space ))
				{
					// Preprocessor statement, so buffer verbatim
					lines.push_back(currentLine);
					continue;
				}

				// Iterate over every character for initial parse
				for (int i = 0; i < currentLine.length(); i++)
				{
					//Check for end of multiline comment
					if (inComment)
					{
						std::string sequence = "*/";
						if (checkSequence(&sequence, &currentLine, i))
						{
							inComment = false;
							i++;
						}
					}
					else
					{
						ParseLevel depth = parseStack.back();

						// Comment Checks - Comments don't occur in strings, including single-quote ones (files)
						if (depth != ParseLevel::SINGLE_QUOTES && depth != ParseLevel::DOUBLE_QUOTES && depth != ParseLevel::MULTILINE_STRING)
						{
							std::string sequence = "/*";
							if (checkSequence(&sequence, &currentLine, i))
							{
								inComment = true;
								i++;
								continue;
							}
							std::string second_sequence = "//";
							if (checkSequence(&second_sequence, &currentLine, i))
							{
								break;
							}
						}

						// Not a comment, so buffer the character then check the expression stack
						*lineBuffer << currentLine[i];

						// String escapes first
						if (depth == ParseLevel::SINGLE_QUOTES || depth == ParseLevel::DOUBLE_QUOTES || depth == ParseLevel::MULTILINE_STRING)
						{
							if (currentLine[i] == '\\')
							{
								i++;
								continue;
							}
						}

						// Expression end testing
						switch (depth)
						{
							case BYOND::DME_Parser::ParseLevel::PARENS:
								if (currentLine[i] == ')')
								{
									parseStack.pop_back();
									continue;
								}
								break;
							case BYOND::DME_Parser::ParseLevel::INDEX:
							case BYOND::DME_Parser::ParseLevel::STRING_INLINE:
								if (currentLine[i] == ']')
								{
									parseStack.pop_back();
									continue;
								}
								break;
							case BYOND::DME_Parser::ParseLevel::SINGLE_QUOTES:
								if (currentLine[i] == '\'')
								{
									parseStack.pop_back();
									continue;
								}
								break;
							case BYOND::DME_Parser::ParseLevel::DOUBLE_QUOTES:
								if (currentLine[i] == ('\"'))
								{
									parseStack.pop_back();
									continue;
								}
								break;
							case BYOND::DME_Parser::ParseLevel::MULTILINE_STRING:
								std::string sequence = "\"}";
								if (checkSequence(&sequence, &currentLine, i))
								{
									i++;
									parseStack.pop_back();
									continue;
								}
								break;
						}
						// Expression begin testing
						if (depth == ParseLevel::BASE || depth == ParseLevel::PARENS || depth == ParseLevel::INDEX || depth == ParseLevel::STRING_INLINE)
						{
							std::string sequence = "{\"";
							
							if (currentLine[i] == '(')
							{
								parseStack.push_back(ParseLevel::PARENS);
								continue;
							}
							else if (currentLine[i] == '[')
							{
								parseStack.push_back(ParseLevel::INDEX);
								continue;
							}
							else if (currentLine[i] == '\"')
							{
								parseStack.push_back(ParseLevel::DOUBLE_QUOTES);
								continue;
							}
							else if (currentLine[i] == '\'')
							{
								parseStack.push_back(ParseLevel::SINGLE_QUOTES);
								continue;
							}
							
							else if (checkSequence(&sequence, &currentLine, i))
							{
								i++;
								parseStack.push_back(ParseLevel::MULTILINE_STRING);
								continue;
							}
						}
						// String embeds
						if (depth == ParseLevel::DOUBLE_QUOTES || depth == ParseLevel::MULTILINE_STRING)
						{
							if (currentLine[i] == '[')
							{
								parseStack.push_back(ParseLevel::STRING_INLINE);
							}
						}
					}
				}
				// End of character loop - check multiline string, hanging parens, and linebreak escapes before storing line
				if (parseStack.back() == ParseLevel::BASE)
				{

				if ((*lineBuffer >> std::ws).peek() != std::char_traits<char>::eof()) {
						lines.push_back(lineBuffer->str());
				}
			
				lineBuffer->str(std::string());
				}
				else if (parseStack.back() == ParseLevel::MULTILINE_STRING)
				{
					*lineBuffer << "\n";
				}
				else if (!(parseStack.back() == ParseLevel::PARENS || StringHelper::endsWith(currentLine, "\\")))
				{

					spdlog::error("Bad line state after parsing line {}: "+ std::to_string(lineCount) + "discarding line. Last parse state: {}", currentFile.relative_path().string(), parseStack.back());
					lineBuffer->str(std::string());
				}
			}

			lineCount = 0;

			// All lines validated and processed - parse tree now
			for (auto line : lines)
			{
				if (isBlank(&line))
				{
					continue;
				}

				std::string space = "#";
				std::string define = "#define";
				std::string undefine = "#undef";
				if (beginsAfterSpaces(&line, &space))
				{
					std::string include = "#include";
					// Preprocessor directives first, these short-circuit all other line processing
					if (beginsAfterSpaces(&line, &include))
					{
						std::smatch matcher;
						std::regex_search(line,matcher,*INCLUDE_PATTERN);
						if (!matcher.empty())
						{
							std::string includedPath = matcher[1].str();
							if (StringHelper::endsWith(includedPath, ".dm") || StringHelper::endsWith(includedPath, ".dme"))
							{
								std::string dmPath = currentFile.parent_path().string() + "/"+includedPath;
								std::string system_agnostic_path;
								#ifdef __linux__ 
									system_agnostic_path = StringHelper::ReplaceAll(dmPath,"\\","/");
								#elif _WIN32
									system_agnostic_path = StringHelper::ReplaceAll(dmPath,"/","\\");
								#else
									system_agnostic_path = StringHelper::ReplaceAll(dmPath,"\\","/");
								#endif

								spdlog::info("Checking included DM file {}", system_agnostic_path);
								std::ifstream *includedFile = new std::ifstream(system_agnostic_path);
								if (includedFile->good())
								{
									spdlog::info("Parsing included DM file {}", includedPath);
									subParse(tree, includedFile, std::filesystem::path(currentFile.parent_path().filename()));
								}

							}
							else
							{
								spdlog::error(currentFile.string() + " includes non-DM file " + includedPath + ", ignoring");
							}
						}
					}
					else if (beginsAfterSpaces(&line, &define))
					{
						std::smatch matcher;
						std::regex_search(line,matcher,*DEFINE_PATTERN);
						if (!matcher.empty())
						{
							std::string defineName = matcher[1].str();
							if (defineName == "FILE_DIR")
							{
								std::filesystem::path *filedir = new std::filesystem::path(matcher[2].str());
								tree->addFileDir(filedir);
								// TODO: FILE_DIR
							}
							else
							{
								tree->addMacro(matcher[1].str(), matcher[2].str());
							}
						}
					}
					else if (beginsAfterSpaces(&line, &undefine))
					{
						std::smatch matcher;
						std::regex_search(line,matcher,*UNDEF_PATTERN);
						if (!matcher.empty())
						{
							tree->removeMacro(matcher[1].str());
						}
					}
					continue;
				}
				// Not a preprocessor statement, process normally.

				// Indent processing: pathList is a list of String lists. Each String list represents a subsection of
				// a path, like ["obj", "machinery", "vending"] for example. For each tab indent, a new String list
				// is added to the list at the corresponding spot. For example:
				/*
				/obj/machinery      pathList: {["obj", "machinery"]}
				    atmospherics    pathList: {["obj", "machinery"], ["atmospherics"]}
				        binary      pathList: {["obj", "machinery"], ["atmospherics"], ["binary"]}
				 */

				fullPathBuilder->str(std::string());
				indentDepth = getIndentDepth(&line);
				if (indentDepth <= lowestProcDepth)
				{
					lowestProcDepth = -1;
				}

				if (!(lowestProcDepth >= 0 && indentDepth >= lowestProcDepth))
				{
					// Clears the path list down to the current level
					for (int i = pathList.size() - 1; i >= indentDepth; i--)
					{
						pathList.erase(pathList.begin() + i);
					}
					// Ensures enough nodes are present for the current indent

					subPath = std::vector<std::string>();

					splitLine = splitPath(&line);

					for (auto pathSequence : splitLine)
					{
						std::string pathSection;
						for (auto i = pathSequence.begin(); i != pathSequence.end(); ++i)
							pathSection += *i;
						if (pathSection.empty() || pathSection == "const" || pathSection == "static" || pathSection == "global" || pathSection == "tmp")
						{
							continue;
						}
						std::smatch matcher;
						std::regex_search(pathSection,matcher,*PROC_PATTERN);
						if (!matcher.empty())
						{
							if (lowestProcDepth < 0)
							{
								lowestProcDepth = indentDepth;
							}
							break;
						}
						if (pathSection.find("var") != std::string::npos || pathSection.find("=") != std::string::npos)
						{
							break;
						}
						subPath.push_back(StringHelper::trim(pathSection));
					}
					for (int i = pathList.size(); i <= indentDepth; i++)
					{
						pathList.push_back(std::vector<std::string>());
					}
					pathList[indentDepth] = subPath;

					// The full path of the line, tabs and the current stuff
					std::string pathBuilder;
					for (auto i = pathList.begin(); i != pathList.end(); ++i){
						std::string tempstring;
						for (auto j = i->begin(); j!= i->end(); ++j)
							tempstring += *j+ "/";
						pathBuilder += tempstring ;
					}
						

					*fullPathBuilder << pathBuilder;
					
					// The actual "meat" of the line, with no directory
					restOfTheLine = splitLine[splitLine.size() - 1];
					std::smatch matcher;
					std::regex_search(restOfTheLine,matcher,*VAR_PATTERN);
					if (!matcher.empty())
					{
						//System.out.println("Var found in " + fullPathBuilder + ": " + matcher.group(1) + " = " + matcher.group(2));
						std::string varName = StringHelper::trim(matcher[1].str());
						std::string varVal = StringHelper::trim(matcher[2].str());
						tree->getOrCreateDME_Tree_Item(StringHelper::trim(fullPathBuilder->str()))->setVar(varName, varVal);
					}
				}

				lineCount++;
			}

			delete fullPathBuilder;
//JAVA TO C++ CONVERTER TODO TASK: A 'delete lineBuffer' statement was not added since lineBuffer was passed to a method or constructor. Handle memory management manually.
		}

		// A few utilities to make code more concise

//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static inline std::stringstream *splitPathBuffer = new std::stringstream();

		/**
		 * Splits the given line into its path segments, and the remainder of the line as the last element.
		 *
		 * @param path Path to split
		 * @return An array of path segments and then the line
		 */
		static std::vector<std::string> splitPath(std::string *path)
		{
			splitPathBuffer->str(std::string());
			std::vector<std::string> pathSections;

			for (int i = 0; i < path->size(); i++)
			{
				if (std::isalnum(path->at(i)) || path->at(i) == '_')
				{
					*splitPathBuffer << path->at(i);
				}
				else
				{
					if (path->at(i) == '/')
					{
						pathSections.push_back(splitPathBuffer->str());
						splitPathBuffer->str(std::string());
					}
					else
					{
						*splitPathBuffer << (path->substr(i, path->length() - i));
						pathSections.push_back(splitPathBuffer->str());
						return pathSections;
					}
				}
			}
			std::string tmpstring = splitPathBuffer->str();
			if (tmpstring.length() > 0)
			{
				pathSections.push_back(tmpstring);
			}

			return pathSections;
		}


		// The following methods are static methods designed to (hopefully) perform faster
		// than what you could get with Java String methods, since they're slightly more
		// purpose-built. Testing should be done.

		/**
		 * Checks if the sequence of characters <code>subString</code> is present at index <code>index</code> in string <code>fullString</code>.
		 *
		 * @param fullString The full string
		 * @param subString  The subsequence to check
		 * @param index      Where to subString
		 * @return <code>true</code> if the sequence of characters in <code>subString</code> is present at index <code>index</code> in <code>fullString</code>, else false
		 */
		static bool checkSequence(std::string *subString, std::string *fullString, int index)
		{
			if (index < 0 || index > fullString->size() - subString->size())
			{
				return false;
			}
			for (int i = 0; i < subString->size(); i++)
			{
				if (!(subString->at(i) == fullString->at(i + index)))
				{
					return false;
				}
			}
			return true;
		}

		/**
		 * A replacement for <code>string.trim().isEmpty()</code> that doesn't allocate a new string.
		 *
		 * @param str String to check
		 * @return <code>true</code> if the string is empty, <code>false</code> if it isn't.
		 */
		static bool isBlank(std::string *str)
		{
			for (int i = 0; i < str->size(); i++)
			{
				if (!std::isspace(str->at(i)))
				{
					return false;
				}
			}
			return true;
		}

		/**
		 * A replacement for <code>string.trim().beginsWith()</code> that doesn't allocate a new string.
		 *
		 * @param str String to check
		 * @param beg Beginning to look for
		 * @return <code>true</code> if <code>str</code>'s first non-whitespace characters are <code>beg</code>
		 */
		static bool beginsAfterSpaces(std::string *str, std::string *beg)
		{
			int i;
			for (i = 0; i < str->size(); i++)
			{
				if (str->at(i) != ' ' && str->at(i) != '\t')
				{
					break;
				}
			}
			if (i + beg->size() > str->size())
			{
				return false;
			}
			for (int j = 0; j < beg->size(); j++)
			{
				if (str->at(i + j) != beg->at(j))
				{
					return false;
				}
			}
			return true;
		}

		/**
		 * Returns the amount of tabs at the beginning of the line
		 *
		 * @param line String to check the indent depth of
		 * @return Amount of tabs before the first character or end of the given string
		 */
		int getIndentDepth(std::string *line)
		{
			int i;
			for (i = 0; i < line->size(); i++)
			{
				if (!(line->at(i) == '\t'))
				{
					break;
				}
			}
			return i;
		}

		/**
		 * Used to keep track of expressions and such in the initial parse
		 */
	private:
		

		class ParseLevelHelper
		{
		private:
			static std::vector<std::pair<ParseLevel, std::string>> pairs()
			{
				return
				{
					{ParseLevel::SINGLE_QUOTES, "SINGLE_QUOTES"},
					{ParseLevel::DOUBLE_QUOTES, "DOUBLE_QUOTES"},
					{ParseLevel::INDEX, "INDEX"},
					{ParseLevel::STRING_INLINE, "STRING_INLINE"},
					{ParseLevel::MULTILINE_STRING, "MULTILINE_STRING"},
					{ParseLevel::PARENS, "PARENS"},
					{ParseLevel::BASE, "BASE"}
				};
			}

		public:
			static std::vector<ParseLevel> values()
			{
				std::vector<ParseLevel> temp;
				for (auto pair : pairs())
				{
					temp.push_back(pair.first);
				}
				return temp;
			}

			static std::string enumName(ParseLevel value)
			{
				for (auto pair : pairs())
				{
					if (pair.first == value)
						return pair.second;
				}

				throw std::runtime_error("Enum not found.");
			}

			static int ordinal(ParseLevel value)
			{
				std::vector<std::pair<ParseLevel, std::string>> temp = pairs();
				for (std::size_t i = 0; i < temp.size(); i++)
				{
					if (temp[i].first == value)
						return i;
				}

				throw std::runtime_error("Enum not found.");
			}

			static ParseLevel enumFromString(std::string value)
			{
				for (auto pair : pairs())
				{
					if (pair.second == value)
						return pair.first;
				}

				throw std::runtime_error("Enum not found.");
			}
		};


};


};




#endif