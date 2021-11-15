#include "../CachedPattern.h"
#include "../Util.h"
#include "ObjectTree.h"
#include "ObjectTreeItem.h"
#include <string>
#include <regex>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <thread>
#include "../stringhelper.h"
#include "../stringbuilder.h"
#pragma once



namespace BYOND
{


	// Ah, the parser. It looks like it was written by 2 people: One that knows regex, and one that doesn't.
	// Part of it was written before I had any clue how to regex, and the other part was after.

	// I'm still amazed that this runs faster than BYOND's object tree generator, despite it being written in Java.

	class ObjectTreeParser
	{
	public:
        std::filesystem::path dme;
		bool isCommenting = false;
		bool inMultilineString = false;
		int multilineStringDepth = 0;
		int parenthesisDepth = 0;
		int stringDepth = 0;
		int stringExpDepth = 0;
		int parenthesesDepth = 0;
		std::vector<int> arrayDepth = std::vector<int>(50);

		ObjectTree *tree;

		std::unordered_map<std::string, std::string> macros = std::unordered_map<std::string, std::string>();

	private:
//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static inline std::regex QUOTES_PATTERN = std::regex("^\"(.*)\"$");
//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static inline std::regex DEFINE_PATTERN = std::regex("#define +([\\d\\w]+) +(.+)");
//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static inline std::regex UNDEF_PATTERN =  std::regex("#undef[ \\t]*([\\d\\w]+)");
//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static inline  std::regex MACRO_PATTERN = std::regex("(?<![\\d\\w\"])\\w+(?![\\d\\w\"])");

	public:
		virtual ~ObjectTreeParser()
		{
			delete tree;
		}

		ObjectTreeParser()
		{
			tree = new ObjectTree();
		}

		ObjectTreeParser(ObjectTree *tree)
		{
			this->tree = tree;
		}

		virtual void parseDME(std::filesystem::path file)
		{
			// Parse stddef.dm for macros and such.
			
			std::ifstream  tempVar(Util::getFile("../../resources/stddef.dm"));
			doSubParse(tempVar, std::filesystem::path("../../resources/stddef.dm"));

			std::ifstream tempVar2(file.string());
			doParse(tempVar2, file, true);
		}

		std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
			size_t start_pos = 0;
			while((start_pos = str.find(from, start_pos)) != std::string::npos) {
				str.replace(start_pos, from.length(), to);
				start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
			}
			return str;
		}

		std::vector<std::string> split(const std::string& s,const  char* seperator)
		{
		std::vector<std::string> output;

			std::string::size_type prev_pos = 0, pos = 0;

			while((pos = s.find(seperator, pos)) != std::string::npos)
			{
				std::string substring( s.substr(prev_pos, pos-prev_pos) );

				output.push_back(substring);

				prev_pos = ++pos;
			}

			output.push_back(s.substr(prev_pos, pos-prev_pos)); // Last word

			return output;
		}

		static inline void ltrim(std::string &s) {
			s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
				return !std::isspace(ch);
			}));
		}

		// trim from end (in place)
		static inline void rtrim(std::string &s) {
			s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
				return !std::isspace(ch);
			}).base(), s.end());
		}

		// trim from both ends (in place)
		static inline void trim(std::string &s) {
			ltrim(s);
			rtrim(s);
		}

		virtual void doParse(std::ifstream &br, std::filesystem::path currentFile, bool isMainFile)
		{
			std::string line = "";
			std::vector<std::string> lines;
			std::stringstream runOn;
			int includeCount = 0;
			// This part turns spaces into tabs, strips all the comments, and puts multiline statements on one line.
			while (std::getline(br, line))
			{
				line = stripComments(line);
				line = ReplaceAll(line,"\\t"," ");
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
						lines.push_back(line);
						if (isMainFile && StringHelper::trim(line).rfind("#include", 0) == 0)
						{
							includeCount++;
						}
					}
				}
			}
			br.close();

			std::vector<std::string> pathTree;

			int currentInclude = 0;

			if (isMainFile)
			{
				spdlog::info("Object Tree Generation");
				std::thread *t = new std::thread([&] ()
				{
					spdlog::info(currentFile.string());
				});
				t->join();

				delete t;
			}

			for (auto line1 : lines)
			{
				line = line1;
				// Process #include, #define, and #undef
				if (StringHelper::trim(line).rfind("#", 0) == 0)
				{
					line = StringHelper::trim(line);
					if (line.rfind("#include", 0) == 0)
					{
						std::string path = "";
						std::string includeData = split(line," ")[1];
						if (includeData.rfind("\"", 0) == 0  || includeData.rfind("<", 0) == 0 )
						{
							// "path\to\file.dm" OR <path\to\library.dme>
							path = includeData.substr(1, (includeData.length() - 1) - 1);
						}
						else
						{
							spdlog::error(currentFile.filename().string() + " has an invalid #include statement: " + line);
							continue;
						}
						if (isMainFile)
						{
							//lbl->setText(path);
						}
						if (StringHelper::endsWith(path, ".dm") || StringHelper::endsWith(path, ".dme"))
						{
							std::ifstream includeFile = std::ifstream(Util::getFile(currentFile.parent_path().filename().string()));
							
							doSubParse(includeFile, currentFile.parent_path().filename());

//JAVA TO C++ CONVERTER TODO TASK: A 'delete includeFile' statement was not added since includeFile was passed to a method or constructor. Handle memory management manually.
						}
						if (isMainFile)
						{
							currentInclude++;
							spdlog::info(currentInclude);
							spdlog::info(currentFile.string());
						}
					}
					else if (StringHelper::startsWith(line, "#define"))
					{
						std::smatch m;
						std::regex_search(line, m,DEFINE_PATTERN);
						if (!m.empty())
						{
							std::string group = m.str(1);
							if (group == "FILE_DIR")
							{
								std::string file_group = m.str(2);
								std::smatch quotes;
								std::regex_search(file_group, quotes,QUOTES_PATTERN);
								if (!quotes.empty())
								{
									// 2 ways this can't happen:
									//std::string quotes_group = quotes.str(1);
									// Somebody intentionally placed broken FILE_DIR defines.
									// It's the . FILE_DIR, which has no quotes, and we don't need.
									//tree->fileDirs.push_back(std::filesystem::path(Util::separatorsToSystem(quotes_group)));
								}

							}
							else
							{
								std::string group = m.str(1);
								std::string value = m.str(2);
								value = ReplaceAll(value,"$","\\$");
								macros.emplace(group, value);
							}
						}
					}
					else if (StringHelper::startsWith(line, "#undef"))
					{
						std::smatch m;
						std::regex_search(line, m,UNDEF_PATTERN);
						if (!m.empty() && macros.find(m.str(1)) != macros.end())
						{
							macros.erase(m.str(1));
						}
					}

					continue;
				}
				// How far is this line indented?
				int level = 0;
				for (int j = 0; j < line.length(); j++)
				{
					if (line[j] == ' ')
					{
						level++;
					}
					else
					{
						break;
					}
				}
				// Rebuild the path tree.
				for (int j = pathTree.size(); j <= level; j++)
				{
					pathTree.push_back("");
				}
				trim(line);
				pathTree[level] = cleanPath(line);
				if (pathTree.size() > level + 1)
				{
					for (int j = pathTree.size() - 1; j > level; j--)
					{
						pathTree.erase(pathTree.begin() + j);
					}
				}
				std::string fullPath = "";
				for (auto c : pathTree)
				{
					fullPath += c;
				}
				// Now, split it again, and rebuild it again, but only figure out how big the object itself is.
				std::vector<std::string> divided = split(fullPath,"\\/");
				std::string affectedObjectPath = "";
				for (auto item : divided)
				{
					if (item.empty())
					{
						continue;
					}
					if (StringHelper::toLower(item) == "static" || StringHelper::toLower(item) == ("global") || StringHelper::toLower(item) == ("tmp"))
					{
						continue;
					}
					if (item == ("proc") || item == ("verb") || item == ("var"))
					{
						break;
					}
					if (fullPath.find("=") != std::string::npos)
					{
						break;
					}
					if (fullPath.find("(") != std::string::npos) {
						break;
					}
					affectedObjectPath += "/" + item;
				}
				ObjectTreeItem *item = tree->getOrCreate(affectedObjectPath);
				if (fullPath.find("(") != std::string::npos && (int)fullPath.find("(") < (int)fullPath.rfind("/"))
				{
					continue;
				}
				fullPath = ReplaceAll(fullPath,"/tmp", ""); // Let's avoid giving a shit about whether the var is tmp, static, or global.
				fullPath = ReplaceAll(fullPath,"/static", "");
				fullPath = ReplaceAll(fullPath,"/global", "");
				// Parse the var definitions.
				if (fullPath.find("var/") != std::string::npos || (fullPath.find("=") != std::string::npos && (fullPath.find("(") != std::string::npos || (int)fullPath.find("(") > (int)fullPath.find("="))))
				{
					std::string split = fullPath;
					auto tempVar2 = split.rfind("/") + 1;
					std::string varname = StringHelper::trim(split.substr(tempVar2, split.length() - (tempVar2)));
					if (split.size() > 1)
					{
						std::string val = StringHelper::trim(varname);
						std::string origVal = "";

						/*
						while (origVal != val)
						{
							origVal = val;
							// Trust me, this is the fastest way to parse the macros.
							Matcher *m = MACRO_PATTERN->getMatcher(val);
							StringBuilder *outVal = new StringBuilder();
							while (m->find())
							{
								if (macros.find(m->group(0)) != macros.end())
								{
									m->appendReplacement(outVal, macros[m->group(0)]);
								}
								else
								{
									m->appendReplacement(outVal, m->group(0));
								}
							}
							m->appendTail(outVal);
							val = outVal->toString();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete outVal' statement was not added since outVal was passed to a method or constructor. Handle memory management manually.
						}*/
						/*// Parse additions.
						Matcher m = Pattern.compile("([\\d\\.]+)[ \\t]*\\+[ \\t]*([\\d\\.]+)").matcher(val);
						StringBuffer outVal = new StringBuffer();
						while(m.find()) {
							m.appendReplacement(outVal, (Float.parseFloat(m.group(1)) + Float.parseFloat(m.group(2)))+"");
						}
						m.appendTail(outVal);
						val = outVal.toString();
						// Parse subtractions.
						m = Pattern.compile("([\\d\\.]+)[ \\t]*\\-[ \\t]*([\\d\\.]+)").matcher(val);
						outVal = new StringBuffer();
						while(m.find()) {
							m.appendReplacement(outVal, (Float.parseFloat(m.group(1)) - Float.parseFloat(m.group(2)))+"");
						}
						m.appendTail(outVal);
						val = outVal.toString();*/

						item->setVar(varname, val);
					}
					else
					{
						item->setVar(varname);
					}
				}
			}
			// Reset variables
			isCommenting = false;
			inMultilineString = false;
			multilineStringDepth = 0;
			parenthesisDepth = 0;
			stringDepth = 0;
			stringExpDepth = 0;
			parenthesesDepth = 0;
			arrayDepth = std::vector<int>(50);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete lbl' statement was not added since lbl was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete dpb' statement was not added since dpb was passed to a method or constructor. Handle memory management manually.
			//delete runOn;
		}

	private:
		void doSubParse(std::ifstream  &br, std::filesystem::path currentFile)
		{
			ObjectTreeParser *parser = new ObjectTreeParser(tree);
			parser->macros = macros;
			parser->doParse(br, currentFile, false);

			delete parser;
		}

	public:
		virtual std::string stripComments(const std::string &s)
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
					o << std::to_string(c);
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

		static std::string cleanPath(std::string &s)
		{
			// Makes sure that paths start with a slash, and don't end with a slash.
			if (!s.rfind("/", 0) == 0)
			{
				s = "/" + s;
			}
			if (s.rfind("/", s.length()) == 0)
			{
				s = s.substr(0, s.length() - 1);
			}
			return s;
		}
	};

}
