#pragma once

#include "../CachedPattern.h"
#include "../Util.h"
#include "ObjectTree.h"
#include "ObjectTreeItem.h"
#include <string>
#include <unordered_map>
#include <vector>
#include "../stringhelper.h"
#include "../stringbuilder.h"

namespace com::github::tgstation::fastdmm::objtree
{

	using CachedPattern = com::github::tgstation::fastdmm::CachedPattern;
	using Util = com::github::tgstation::fastdmm::Util;

	using BorderLayout = java::awt::BorderLayout;
	using BufferedReader = java::io::BufferedReader;
	using InputStreamReader = java::io::InputStreamReader;
	using File = java::io::File;
	using FileReader = java::io::FileReader;
	using IOException = java::io::IOException;
	using Paths = java::nio::file::Paths;
	using Path = java::nio::file::Path;
	using ArrayList = java::util::ArrayList;
	using HashMap = java::util::HashMap;
	using Map = java::util::Map;
	using Matcher = java::util::regex::Matcher;
	using Pattern = java::util::regex::Pattern;

	using JDialog = javax::swing::JDialog;
	using JFrame = javax::swing::JFrame;
	using JLabel = javax::swing::JLabel;
	using JProgressBar = javax::swing::JProgressBar;

	// Ah, the parser. It looks like it was written by 2 people: One that knows regex, and one that doesn't.
	// Part of it was written before I had any clue how to regex, and the other part was after.

	// I'm still amazed that this runs faster than BYOND's object tree generator, despite it being written in Java.

	class ObjectTreeParser
	{
	public:
		bool isCommenting = false;
		bool inMultilineString = false;
		int multilineStringDepth = 0;
		int parenthesisDepth = 0;
		int stringDepth = 0;
		int stringExpDepth = 0;
		int parenthesesDepth = 0;
		std::vector<int> arrayDepth = std::vector<int>(50);

		ObjectTree *tree;

		std::unordered_map<std::wstring, std::wstring> macros = std::unordered_map<std::wstring, std::wstring>();
		JFrame *modalParent;

	private:
//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static const CachedPattern *QUOTES_PATTERN = new CachedPattern(L"^\"(.*)\"$");
//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static const CachedPattern *DEFINE_PATTERN = new CachedPattern(L"#define +([\\d\\w]+) +(.+)");
//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static const CachedPattern *UNDEF_PATTERN = new CachedPattern(L"#undef[ \\t]*([\\d\\w]+)");
//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static const CachedPattern *MACRO_PATTERN = new CachedPattern(L"(?<![\\d\\w\"])\\w+(?![\\d\\w\"])");

	public:
		virtual ~ObjectTreeParser()
		{
			delete tree;
			delete modalParent;
		}

		ObjectTreeParser()
		{
			tree = new ObjectTree();
		}

		ObjectTreeParser(ObjectTree *tree)
		{
			this->tree = tree;
		}

		virtual void parseDME(File *file)
		{
			// Parse stddef.dm for macros and such.
			BufferedReader tempVar(new InputStreamReader(Util::getFile(L"stddef.dm")));
			doSubParse(&tempVar, Paths->get(L"stddef.dm"));

			BufferedReader tempVar2(new FileReader(file));
			doParse(&tempVar2, file->toPath(), true);
		}

		virtual void doParse(BufferedReader *br, Path *currentFile, bool isMainFile)
		{
			std::wstring line = L"";
			std::vector<std::wstring> lines;
			StringBuilder *runOn = new StringBuilder();
			int includeCount = 0;
			// This part turns spaces into tabs, strips all the comments, and puts multiline statements on one line.
			while ((line = br->readLine()) != L"")
			{
				line = stripComments(line);
				line = line.replaceAll(L"\\t", L" ");
				if (!StringHelper::trim(line)->isEmpty())
				{
					if (StringHelper::endsWith(line, L"\\"))
					{
						line = line.substr(0, line.length() - 1);
						runOn->append(line);
					}
					else if (inMultilineString)
					{
						runOn->append(line);
						runOn->append(L"\\n");
					}
					else if (parenthesisDepth > 0)
					{
						runOn->append(line);
					}
					else
					{
						runOn->append(line);
						line = runOn->toString();
						runOn->setLength(0);
						lines.push_back(line);
						if (isMainFile && StringHelper::trim(line)->startsWith(L"#include"))
						{
							includeCount++;
						}
					}
				}
			}
			br->close();

			std::vector<std::wstring> pathTree;

			int currentInclude = 0;

			JProgressBar *dpb = nullptr;
			JDialog *dlg = nullptr;
			JLabel *lbl = nullptr;
			if (isMainFile)
			{
				JDialog * const tdlg = new JDialog(modalParent, L"Object Tree Generation", modalParent != nullptr);
				dlg = tdlg;
				dpb = new JProgressBar(0, includeCount);
				dlg->add(BorderLayout::CENTER, dpb);
				lbl = new JLabel(L"");
				dlg->add(BorderLayout::NORTH, lbl);
				dlg->setDefaultCloseOperation(JDialog::DO_NOTHING_ON_CLOSE);
				dlg->setSize(300, 75);
				Thread *t = new Thread([&] ()
				{
				tdlg->setVisible(true);
				});
				t->start();

				delete t;
			}

			for (auto line1 : lines)
			{
				line = line1;
				// Process #include, #define, and #undef
				if (StringHelper::trim(line)->startsWith(L"#"))
				{
					line = StringHelper::trim(line);
					if (StringHelper::startsWith(line, L"#include"))
					{
						std::wstring path = L"";
						std::wstring includeData = line.split(L" ")[1];
						if (StringHelper::startsWith(includeData, L"\"") || StringHelper::startsWith(includeData, L"<"))
						{
							// "path\to\file.dm" OR <path\to\library.dme>
							path = includeData.substr(1, (includeData.length() - 1) - 1);
						}
						else
						{
							System::err::println(currentFile->getFileName() + L" has an invalid #include statement: " + line);
							continue;
						}
						if (isMainFile)
						{
							lbl->setText(path);
						}
						if (StringHelper::endsWith(path, L".dm") || StringHelper::endsWith(path, L".dme"))
						{
							File *includeFile = new File(currentFile->getParent().toFile(), Util::separatorsToSystem(path));
							if (!includeFile->exists())
							{
								System::err::println(currentFile->getFileName() + L" references a nonexistent file: " + includeFile->getAbsolutePath());

								delete includeFile;
								continue;
							}
							BufferedReader tempVar(new FileReader(includeFile));
							doSubParse(&tempVar, includeFile->toPath());

//JAVA TO C++ CONVERTER TODO TASK: A 'delete includeFile' statement was not added since includeFile was passed to a method or constructor. Handle memory management manually.
						}
						if (isMainFile)
						{
							currentInclude++;
							dpb->setValue(currentInclude);
						}
					}
					else if (StringHelper::startsWith(line, L"#define"))
					{
						Matcher *m = DEFINE_PATTERN->getMatcher(line);
						if (m->find())
						{
							std::wstring group = m->group(1);
							if (group == L"FILE_DIR")
							{
								Matcher *quotes = QUOTES_PATTERN->getMatcher(m->group(2));
								if (quotes->find())
								{
									// 2 ways this can't happen:
									// Somebody intentionally placed broken FILE_DIR defines.
									// It's the . FILE_DIR, which has no quotes, and we don't need.
									tree->fileDirs.push_back(Paths->get(Util::separatorsToSystem(quotes->group(1))));
								}

							}
							else
							{
								macros.emplace(m->group(1), m->group(2)->replace(L"$", L"\\$"));
							}
						}
					}
					else if (StringHelper::startsWith(line, L"#undef"))
					{
						Matcher *m = UNDEF_PATTERN->getMatcher(line);
						if (m->find() && macros.find(m->group(1)) != macros.end())
						{
							macros.erase(m->group(1));
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
				pathTree[level] = cleanPath(StringHelper::trim(line));
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
				std::vector<std::wstring> divided = fullPath.split(L"\\/");
				std::wstring affectedObjectPath = L"";
				for (auto item : divided)
				{
					if (item.isEmpty())
					{
						continue;
					}
					if (item.equalsIgnoreCase(L"static") || item.equalsIgnoreCase(L"global") || item.equalsIgnoreCase(L"tmp"))
					{
						continue;
					}
					if (item.equals(L"proc") || item.equals(L"verb") || item.equals(L"var"))
					{
						break;
					}
					if (item.contains(L"=") || item.contains(L"("))
					{
						break;
					}
					affectedObjectPath += L"/" + item;
				}
				ObjectTreeItem *item = tree->getOrCreate(affectedObjectPath);
				if (fullPath.find(L"(") != std::wstring::npos && (int)fullPath.find(L"(") < (int)fullPath.rfind(L"/"))
				{
					continue;
				}
				fullPath = fullPath.replaceAll(L"/tmp", L""); // Let's avoid giving a shit about whether the var is tmp, static, or global.
				fullPath = fullPath.replaceAll(L"/static", L"");
				fullPath = fullPath.replaceAll(L"/global", L"");
				// Parse the var definitions.
				if (fullPath.find(L"var/") != std::wstring::npos || (fullPath.find(L"=") != std::wstring::npos && (!fullPath.find(L"(") != std::wstring::npos || (int)fullPath.find(L"(") > (int)fullPath.find(L"="))))
				{
					std::vector<std::wstring> split = Pattern::compile(L"=")->split(fullPath, 2);
										var tempVar2 = split[0].rfind(L"/") + 1;
					std::wstring varname = StringHelper::trim(split[0].substr(tempVar2, split[0].length() - (tempVar2)));
					if (split.size() > 1)
					{
						std::wstring val = StringHelper::trim(split[1]);
						std::wstring origVal = L"";
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
						}
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
			if (dlg != nullptr)
			{
				dlg->setVisible(false);
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
			delete runOn;
		}

	private:
		void doSubParse(BufferedReader *br, Path *currentFile)
		{
			ObjectTreeParser *parser = new ObjectTreeParser(tree);
			parser->macros = macros;
			parser->doParse(br, currentFile, false);

			delete parser;
		}

	public:
		virtual std::wstring stripComments(const std::wstring &s)
		{
			StringBuilder *o = new StringBuilder();
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
					o->append(c);
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

			delete o;
			return o->toString();
		}

		static std::wstring cleanPath(const std::wstring &s)
		{
			// Makes sure that paths start with a slash, and don't end with a slash.
			if (!StringHelper::startsWith(s, L"/"))
			{
				s = L"/" + s;
			}
			if (StringHelper::endsWith(s, L"/"))
			{
				s = s.substr(0, s.length() - 1);
			}
			return s;
		}
	};

}
