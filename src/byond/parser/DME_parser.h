#ifndef _DME_PARSER_H
#define _DME_PARSER_H
#pragma once

#include "../tree/DME_tree_item.h"
#include "../tree/DME_tree.h"
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <cctype>
#include <stdexcept>
#include <utility>
#include <regex>
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <fstream>
#include <future>
#include <thread>
#include "../utils/exception_helper.h"
#include "../utils/string_helper.h"
#include "../utils/string_builder.h"
#include "../utils/util.h"
#include "../utils/cached_pattern.h"
#include "spdlog/spdlog.h"


namespace BYOND{

	class DME_Parser;

class ThreadWrapper{
	public:
		std::ifstream *tempVar;
		std::filesystem::path *path;
		bool* isMainFile;
		DME_Parser *parser;

		ThreadWrapper(DME_Parser *parser,std::ifstream *tempVar, std::filesystem::path* path, bool* isMainFile = nullptr): 
		parser(parser),
		tempVar(tempVar),
		path(path),
		isMainFile(isMainFile)
		{

		}

};


class DME_Parser{

 	public:
		int _numPartitions = 42;
		std::filesystem::path* dmepath;
		std::ifstream dme;
		bool isCommenting = false;
		bool inMultilineString = false;
		int multilineStringDepth = 0;
		int parenthesisDepth = 0;
		int stringDepth = 0;
		int stringExpDepth = 0;
		int parenthesesDepth = 0;
		std::vector<int> arrayDepth = std::vector<int>(50);

		DME_Tree* tree;

		std::unordered_map<std::string, std::string> macros = std::unordered_map<std::string, std::string>();
	private:
			int indentDepth; // For parsing tabs
			int lowestProcDepth = -1; // Lowest indent depth for the current proc, or -1 if no proc
			std::vector<std::vector<std::string>> pathList; // Keeps track of the current path sections - explained later
			std::stringstream *fullPathBuilder = new std::stringstream(); // Builds the full path of a line
			std::vector<std::string> splitLine; // For storing the line split on '/'
			std::vector<std::string> subPath; // The part of the path given in the current line
			std::string restOfTheLine; // The part of the line that doesn't define the path

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

		}

		DME_Parser(std::filesystem::path *path, DME_Tree *tree)
		{
			this->dme = std::ifstream(*path);
			this->dmepath = path;
			this->tree = tree;
		}

		DME_Parser(std::filesystem::path *path)
		{
			this->dme = std::ifstream(*path);
            this->dmepath = path;
			this->tree = new DME_Tree();
		}


		static void doSubParseThread(void *subparseWrapper){
			ThreadWrapper *wrapper = static_cast<ThreadWrapper*>(subparseWrapper);
			wrapper->parser->doSubParse(*wrapper->tempVar, *wrapper->path); 
		}

		static void doParseThread(void *subparseWrapper){
			ThreadWrapper *wrapper = static_cast<ThreadWrapper*>(subparseWrapper);
			wrapper->parser->doParse(*wrapper->tempVar, *wrapper->path,true); 
		}

		virtual void parseDME()
		{
			// Parse stddef.dm for macros and such.
			std::stringstream sstream;
			sstream << "stddef.dm";

			std::ifstream  tempVar(Util::getFile(sstream.str()));

			std::filesystem::path currentp = std::filesystem::path("stddef.dm");

			ThreadWrapper *subparseWrapper = new ThreadWrapper(this,&tempVar,&currentp);
			void* voidsubwrapper = static_cast<void*>(subparseWrapper);
			std::thread t1(doSubParseThread, voidsubwrapper);

			t1.join();

			std::ifstream tempVar2(dmepath->string());
			ThreadWrapper *parseWrapper = new ThreadWrapper(this,&tempVar2,dmepath);
			void* voidwrapper = static_cast<void*>(parseWrapper);
			std::thread t2(doParseThread, voidwrapper);

			t2.join();
			
			tree->completeTree();

		}

		std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
			size_t start_pos = 0;
			while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
				str.replace(start_pos, from.length(), to);
				start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
			}
			return str;
		}

		std::vector<std::string> split(const std::string& s, const  char* seperator)
		{
			std::vector<std::string> output;

			std::string::size_type prev_pos = 0, pos = 0;

			while ((pos = s.find(seperator, pos)) != std::string::npos)
			{
				std::string substring(s.substr(prev_pos, pos - prev_pos));

				output.push_back(substring);

				prev_pos = ++pos;
			}

			output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

			return output;
		}

		static inline void ltrim(std::string& s) {
			s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
				return !std::isspace(ch);
				}));
		}

		// trim from end (in place)
		static inline void rtrim(std::string& s) {
			s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
				return !std::isspace(ch);
				}).base(), s.end());
		}

		// trim from both ends (in place)
		static inline void trim(std::string& s) {
			ltrim(s);
			rtrim(s);
		}

		virtual void doParse(std::ifstream &br, std::filesystem::path currentFile, bool isMainFile)
		{
			std::ifstream wstream(currentFile.string());
			std::string line = "";
			std::vector<std::string> lines;
			std::stringstream runOn;
			int includeCount = 0;
			// This part turns spaces into tabs, strips all the comments, and puts multiline statements on one line.
			while (std::getline(wstream, line))
			{
				line = stripComments(line);
				line = ReplaceAll(line, "\\t", " ");
				if (!StringHelper::trim(line).empty())
				{
					if (StringHelper::endsWith(line, "\\"))
					{
						line = line.substr(0, line.length() - 1);
						runOn << line;
					}
					else if (inMultilineString)
					{
						runOn << line;
						runOn << "\\n";
					}
					else if (parenthesisDepth > 0)
					{
						runOn << line;
					}
					else
					{
						runOn << line;
						line = runOn.str();
						runOn.str(std::string());
						lines.push_back(line);
						if (isMainFile && StringHelper::trim(line).find("#include", 0) == 0)
						{
							includeCount++;
						}

					}

				}
			}

			std::vector<std::string> pathTree;

			int currentInclude = 0;

			if (isMainFile)
			{
				spdlog::info("Object Tree Generation");

				spdlog::info(currentFile.string());


				//delete t;
			}

			for (auto line1 : lines)
			{
				line = line1;
				std::stringstream l;
    			l << line.c_str();
				//spdlog::info("Line: {}", line);
				// Process #include, #define, and #undef
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
								
								spdlog::info("Parsing included DM file {}", system_agnostic_path);
								std::filesystem::path *include_path = new std::filesystem::path(system_agnostic_path);
								doSubParse(*includedFile,*include_path);
							

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
						std::string varName = StringHelper::trim(matcher[1].str());
						std::string varVal = StringHelper::trim(matcher[2].str());
						tree->getOrCreateDME_Tree_Item(StringHelper::trim(fullPathBuilder->str()))->setVar(varName, varVal);
					}
				}
			}

			delete fullPathBuilder;
			
		}

	private:

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


		virtual void doSubParse(std::ifstream &br, std::filesystem::path currentFile)
		{

			spdlog::info("Subparse : {}",currentFile.string());
			DME_Parser* parser = new DME_Parser(&currentFile,tree);

			br = std::ifstream(currentFile.string());
			parser->macros = macros;
			parser->doParse(br, currentFile, false);
			delete parser;


		}

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
						*splitPathBuffer << (path->substr(i, path->length() ));
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

	public:
		virtual std::string stripComments(const std::string& s)
		{
			std::stringstream o;
			for (int i = 0; i < s.length(); i++)
			{
				wchar_t pC = ' ';
				if (i - 1 >= 0)
				{
					pC = s[i - 1];
				}
				wchar_t ppC = ' ';
				if (i - 2 >= 0)
				{
					ppC = s[i - 2];
				}
				wchar_t c = s[i];
				wchar_t nC = ' ';
				if (i + 1 < s.length())
				{
					nC = s[i + 1];
				}
				if (!isCommenting)
				{
					if (c == '/' && nC == '/' && stringDepth == 0)
					{
						break;
					}
					if (c == '/' && nC == '*' && stringDepth == 0)
					{
						isCommenting = true;
						continue;
					}
					if (c == '"' && nC == '}' && (pC != '\\' || ppC == '\\') && stringDepth == multilineStringDepth && inMultilineString)
					{
						inMultilineString = false;
					}
					if (c == '"' && (pC != '\\' || ppC == '\\') && stringDepth != stringExpDepth && (!inMultilineString || multilineStringDepth != stringDepth))
					{
						stringDepth--;
					}
					else if (c == '"' && stringDepth == stringExpDepth && (!inMultilineString || multilineStringDepth != stringDepth))
					{
						stringDepth++;
						if (pC == '{')
						{
							inMultilineString = true;
							multilineStringDepth = stringDepth;
						}
					}
					if (c == '[' && stringDepth == stringExpDepth)
					{
						arrayDepth[stringExpDepth]++;
					}
					else if (c == '[' && (pC != '\\' || ppC == '\\') && stringDepth != stringExpDepth)
					{
						stringExpDepth++;
					}

					if (c == ']' && arrayDepth[stringExpDepth] != 0)
					{
						arrayDepth[stringExpDepth]--;
					}
					else if (c == ']' && stringDepth > 0 && stringDepth == stringExpDepth)
					{
						stringExpDepth--;
					}
					if (c == '(' && stringDepth == stringExpDepth)
					{
						parenthesisDepth++;
					}
					if (c == ')' && stringDepth == stringExpDepth)
					{
						parenthesisDepth--;
					}
					o.put(c);
				}
				else
				{
					if (c == '*' && nC == '/')
					{
						isCommenting = false;
						i++;
					}
				}

			}

			return o.str();
		}

		static std::string cleanPath(std::string& s)
		{
			if (!StringHelper::startsWith(s, "/"))
			{
				s = "/" + s;
			}
			if (StringHelper::endsWith(s, "/"))
			{
				s = s.substr(0, s.length() - 1);
			}
			return s;
		}

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
	};


};




#endif