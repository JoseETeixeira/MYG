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

		ObjectTree* tree;

		std::unordered_map<std::wstring, std::wstring> macros = std::unordered_map<std::wstring, std::wstring>();



	public:
		virtual ~ObjectTreeParser()
		{
			delete tree;
		}

		ObjectTreeParser()
		{
			tree = new ObjectTree();
		}

		ObjectTreeParser(ObjectTree* tree)
		{
			this->tree = tree;
		}

		virtual void parseDME(std::filesystem::path file)
		{
			// Parse stddef.dm for macros and such.
			std::stringstream sstream;
			sstream << L"stddef.dm";

			std::wifstream  tempVar(Util::getFile(sstream.str()));
			doSubParse(tempVar, std::filesystem::path(L"stddef.dm"));

			std::wifstream tempVar2(file.string());
			doParse(tempVar2, file, true);
		}

		std::wstring ReplaceAll(std::wstring str, const std::wstring& from, const std::wstring& to) {
			size_t start_pos = 0;
			while ((start_pos = str.find(from, start_pos)) != std::wstring::npos) {
				str.replace(start_pos, from.length(), to);
				start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
			}
			return str;
		}

		std::vector<std::wstring> split(const std::wstring& s, const  wchar_t* seperator)
		{
			std::vector<std::wstring> output;

			std::wstring::size_type prev_pos = 0, pos = 0;

			while ((pos = s.find(seperator, pos)) != std::wstring::npos)
			{
				std::wstring substring(s.substr(prev_pos, pos - prev_pos));

				output.push_back(substring);

				prev_pos = ++pos;
			}

			output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

			return output;
		}

		static inline void ltrim(std::wstring& s) {
			s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
				return !std::isspace(ch);
				}));
		}

		// trim from end (in place)
		static inline void rtrim(std::wstring& s) {
			s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
				return !std::isspace(ch);
				}).base(), s.end());
		}

		// trim from both ends (in place)
		static inline void trim(std::wstring& s) {
			ltrim(s);
			rtrim(s);
		}

		virtual void doParse(std::wifstream& br, std::filesystem::path currentFile, bool isMainFile)
		{
			std::wifstream wstream;
			std::wstring line = L"";
			std::vector<std::wstring> lines;
			std::wstringstream runOn;
			int includeCount = 0;
			// This part turns spaces into tabs, strips all the comments, and puts multiline statements on one line.
			while (std::getline(br, line))
			{
				line = stripComments(line);
				line = ReplaceAll(line, L"\\t", L" ");
				if (!StringHelper::trim(line).empty())
				{
					if (StringHelper::endsWith(line, L"\\"))
					{
						line = line.substr(0, line.length() - 1);
						runOn << line;
					}
					else if (inMultilineString)
					{
						runOn << line;
						runOn << L"\\n";
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
						if (isMainFile && StringHelper::trim(line).find(L"#include", 0) == 0)
						{
							includeCount++;
						}
					}
				}
			}

			std::vector<std::wstring> pathTree;

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
				spdlog::info("Line: {}", l.str());
				// Process #include, #define, and #undef
				if (StringHelper::trim(line).find(L"#", 0) == 0)
				{
					line = StringHelper::trim(line);
					if (line.find(L"#include", 0) == 0)
					{
						std::wstring path = L"";
						std::wstring includeData = split(line, L" ")[1];
						if (includeData.find(L"\"", 0) == 0 || includeData.find(L"<", 0) == 0)
						{
							// "path\to\file.dm" OR <path\to\library.dme>
							path = includeData.substr(1, (includeData.length() - 1) - 1);
						}
						else
						{
							spdlog::error(currentFile.filename().string() + " has an invalid #include statement: ");
							continue;
						}
						if (isMainFile)
						{
							std::stringstream ppp;
    						ppp << path.c_str();
							spdlog::info("Path : {}",ppp.str());
							//lbl->setText(path);
						}
						if (StringHelper::endsWith(path, L".dm") || StringHelper::endsWith(path, L".dme"))
						{
							//std::wstring cfile = .generic_wstring();
							std::wifstream includeFile = std::wifstream(Util::getFile(currentFile.parent_path().filename().string()));

							doSubParse(includeFile, currentFile.parent_path().filename());

							//JAVA TO C++ CONVERTER TODO TASK: A 'delete includeFile' statement was not added since includeFile was passed to a method or constructor. Handle memory management manually.
						}
						if (isMainFile)
						{
							currentInclude++;
							
						}
						spdlog::info(currentInclude);
						spdlog::info(currentFile.string());
					}
					else if (StringHelper::startsWith(line, L"#define"))
					{
						std::wsmatch m;
						std::regex_search(line, m, std::wregex(L"#define +([\\d\\w]+) +(.+)"));
						if (!m.empty())
						{
							std::wstring group = m[1].str();
							if (group == L"FILE_DIR")
							{
								std::wstring file_group = m[2].str();
								std::wsmatch quotes;
								std::regex_search(file_group, quotes, std::wregex(L"^\"(.*)\"$"));
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
								std::wstring group = m[1].str();
								std::wstring value = m[2].str();
								value = ReplaceAll(value, L"$", L"\\$");
								macros.emplace(group, value);
							}
						}
					}
					else if (StringHelper::startsWith(line, L"#undef"))
					{
						std::wsmatch m;
						std::regex_search(line, m, std::wregex(L"#undef[ \\t]*([\\d\\w]+)"));
						if (!m.empty() && macros.find(m[1].str()) != macros.end())
						{
							macros.erase(macros[m[1].str()]);
						}
					}

					continue;
				}
				// How far is this line indented?
				int level = 0;
				for (int j = 0; j < line.length(); j++)
				{
					if (line[j] == L' ')
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
					pathTree.push_back(L"");
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
				std::wstring fullPath = L"";
				for (auto c : pathTree)
				{
					fullPath += c;
				}
				// Now, split it again, and rebuild it again, but only figure out how big the object itself is.
				std::vector<std::wstring> divided = split(fullPath, L"\\/");
				std::wstring affectedObjectPath = L"";
				for (auto item : divided)
				{
					if (item.empty())
					{
						continue;
					}
					if (StringHelper::toLower(item) == L"static" || StringHelper::toLower(item) == (L"global") || StringHelper::toLower(item) == (L"tmp"))
					{
						continue;
					}
					if (item == (L"proc") || item == (L"verb") || item == (L"var"))
					{
						break;
					}
					if (fullPath.find(L"=") != std::wstring::npos)
					{
						break;
					}
					if (fullPath.find(L"(") != std::wstring::npos) {
						break;
					}
					affectedObjectPath += L"/" + item;
				}
				ObjectTreeItem* item = tree->getOrCreate(affectedObjectPath);
				if (fullPath.find(L"(") != std::wstring::npos && (int)fullPath.find(L"(") < (int)fullPath.find(L"/"))
				{
					continue;
				}
				fullPath = ReplaceAll(fullPath, L"/tmp", L""); // Let's avoid giving a shit about whether the var is tmp, static, or global.
				fullPath = ReplaceAll(fullPath, L"/static", L"");
				fullPath = ReplaceAll(fullPath, L"/global", L"");
				// Parse the var definitions.
				if (fullPath.find(L"var/") != std::wstring::npos || (fullPath.find(L"=") != std::wstring::npos && (fullPath.find(L"(") != std::wstring::npos || (int)fullPath.find(L"(") > (int)fullPath.find(L"="))))
				{
					std::wstring split = fullPath;
					auto tempVar2 = split.find(L"/") + 1;
					std::wstring varname = StringHelper::trim(split.substr(tempVar2, split.length() - (tempVar2)));
					if (split.size() > 1)
					{
						std::wstring val = StringHelper::trim(varname);
						std::wstring origVal = L"";

						/*
						while (origVal != val)
						{
							origVal = val;
							// Trust me, this is the fastest way to parse the macros.
							Matcher *m = std:::wregex("(?<![\\d\\w\"])\\w+(?![\\d\\w\"])")->getMatcher(val);
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
		void doSubParse(std::wifstream& br, std::filesystem::path currentFile)
		{
			spdlog::info("Subparse : {}",currentFile.string());
			ObjectTreeParser* parser = new ObjectTreeParser(tree);
			parser->macros = macros;
			parser->doParse(br, currentFile, false);

			delete parser;
		}

	public:
		virtual std::wstring stripComments(const std::wstring& s)
		{
			std::wstringstream o;
			for (int i = 0; i < s.length(); i++)
			{
				wchar_t pC = L' ';
				if (i - 1 >= 0)
				{
					pC = s[i - 1];
				}
				wchar_t ppC = L' ';
				if (i - 2 >= 0)
				{
					ppC = s[i - 2];
				}
				wchar_t c = s[i];
				wchar_t nC = L' ';
				if (i + 1 < s.length())
				{
					nC = s[i + 1];
				}
				if (!isCommenting)
				{
					if (c == L'/' && nC == L'/' && stringDepth == 0)
					{
						break;
					}
					if (c == L'/' && nC == L'*' && stringDepth == 0)
					{
						isCommenting = true;
						continue;
					}
					if (c == L'"' && nC == L'}' && (pC != L'\\' || ppC == L'\\') && stringDepth == multilineStringDepth && inMultilineString)
					{
						inMultilineString = false;
					}
					if (c == L'"' && (pC != L'\\' || ppC == L'\\') && stringDepth != stringExpDepth && (!inMultilineString || multilineStringDepth != stringDepth))
					{
						stringDepth--;
					}
					else if (c == L'"' && stringDepth == stringExpDepth && (!inMultilineString || multilineStringDepth != stringDepth))
					{
						stringDepth++;
						if (pC == L'{')
						{
							inMultilineString = true;
							multilineStringDepth = stringDepth;
						}
					}
					if (c == L'[' && stringDepth == stringExpDepth)
					{
						arrayDepth[stringExpDepth]++;
					}
					else if (c == L'[' && (pC != L'\\' || ppC == L'\\') && stringDepth != stringExpDepth)
					{
						stringExpDepth++;
					}

					if (c == L']' && arrayDepth[stringExpDepth] != 0)
					{
						arrayDepth[stringExpDepth]--;
					}
					else if (c == L']' && stringDepth > 0 && stringDepth == stringExpDepth)
					{
						stringExpDepth--;
					}
					if (c == L'(' && stringDepth == stringExpDepth)
					{
						parenthesisDepth++;
					}
					if (c == L')' && stringDepth == stringExpDepth)
					{
						parenthesisDepth--;
					}
					o.put(c);
				}
				else
				{
					if (c == L'*' && nC == L'/')
					{
						isCommenting = false;
						i++;
					}
				}

			}

			return o.str();
		}

		static std::wstring cleanPath(std::wstring& s)
		{
			// Makes sure that paths start with a slash, and don't end with a slash.
			if (!s.find(L"/", 0) == 0)
			{
				s = L"/" + s;
			}
			if (s.find(L"/", s.length()) == 0)
			{
				s = s.substr(0, s.length() - 1);
			}
			return s;
		}
	};

}
