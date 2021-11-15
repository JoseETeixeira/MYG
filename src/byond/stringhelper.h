#pragma once

//----------------------------------------------------------------------------------------
//	Copyright © 2007 - 2021 Tangible Software Solutions, Inc.
//	This class can be used by anyone provided that the copyright notice remains intact.
//
//	This class is used to replace some string methods, including
//	conversions to or from strings.
//----------------------------------------------------------------------------------------
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <codecvt>

class StringHelper
{
public:
	static std::string toLower(std::string source)
	{
		std::transform(source.begin(), source.end(), source.begin(), [](unsigned char c){ return std::tolower(c); });
		return source;
	}

	static std::string toUpper(std::string source)
	{
		std::transform(source.begin(), source.end(), source.begin(), [](unsigned char c){ return std::toupper(c); });
		return source;
	}

	static std::string trimStart(std::string source, const std::string &trimChars = " \t\n\r\v\f")
	{
		return source.erase(0, source.find_first_not_of(trimChars));
	}

	static std::string trimEnd(std::string source, const std::string &trimChars = " \t\n\r\v\f")
	{
		return source.erase(source.find_last_not_of(trimChars) + 1);
	}

	static std::string trim(std::string source, const std::string &trimChars = " \t\n\r\v\f")
	{
		return trimStart(trimEnd(source, trimChars), trimChars);
	}

	static std::string replace(std::string source, const std::string &find, const std::string &replace)
	{
		std::size_t pos = 0;
		while ((pos = source.find(find, pos)) != std::string::npos)
		{
			source.replace(pos, find.length(), replace);
			pos += replace.length();
		}
		return source;
	}

	static bool startsWith(const std::string &source, const std::string &value)
	{
		if (source.length() < value.length())
			return false;
		else
			return source.compare(0, value.length(), value) == 0;
	}

	static bool endsWith(const std::string &source, const std::string &value)
	{
		if (source.length() < value.length())
			return false;
		else
			return source.compare(source.length() - value.length(), value.length(), value) == 0;
	}

	static std::vector<std::string> split(const std::string &source, char delimiter)
	{
		std::vector<std::string> output;
		std::stringstream ss(source);
		std::string nextItem;

		while (std::getline(ss, nextItem, delimiter))
		{
			output.push_back(nextItem);
		}

		return output;
	}

	template<typename T>
	static std::string toString(const T &subject)
	{
		std::stringstream ss;
		ss << subject;
		return ss.str();
	}

	template<typename T>
	static T fromString(const std::string &subject)
	{
		std::stringstream ss(subject);
		T target;
		ss >> target;
		return target;
	}

	static bool isEmptyOrWhiteSpace(const std::string &source)
	{
		if (source.length() == 0)
			return true;
		else
		{
			for (std::size_t index = 0; index < source.length(); index++)
			{
				if (!std::isspace(source[index]))
					return false;
			}

			return true;
		}
	}

	template<typename T>
	static std::string formatSimple(const std::string &input, T arg)
	{
		std::stringstream ss;
		std::size_t lastFormatChar = std::string::npos;
		std::size_t percent = std::string::npos;
		while ((percent = input.find('%', percent + 1)) != std::string::npos)
		{
			if (percent + 1 < input.length())
			{
				if (input[percent + 1] == '%')
				{
					percent++;
					continue;
				}

				std::size_t formatEnd = std::string::npos;
				std::string index;
				for (std::size_t i = percent + 1; i < input.length(); i++)
				{
					if (input[i] == 's')
					{
						index = "1";
						formatEnd = i;
						break;
					}
					else if (input[i] == '$' && i + 1 < input.length() && input[i + 1] == 's')
					{
						index = input.substr(percent + 1, i - percent - 1);
						formatEnd = i + 1;
						break;
					}
					else if (!std::isdigit(input[i]))
						break;					
				}

				if (formatEnd != std::string::npos)
				{
					ss << input.substr(lastFormatChar + 1, percent - lastFormatChar - 1);
					lastFormatChar = formatEnd;

					if (index == "1")
						ss << arg;
					else
						throw std::runtime_error("Only simple positional format specifiers are handled by the 'formatSimple' helper method.");
				}
			}
		}

		if (lastFormatChar + 1 < input.length())
			ss << input.substr(lastFormatChar + 1);

		return ss.str();
	}

	template<typename T>
	static std::string formatSimple(const std::string &input, const std::vector<T> &args)
	{
		std::stringstream ss;
		std::size_t lastFormatChar = std::string::npos;
		std::size_t percent = std::string::npos;
		while ((percent = input.find('%', percent + 1)) != std::string::npos)
		{
			if (percent + 1 < input.length())
			{
				if (input[percent + 1] == '%')
				{
					percent++;
					continue;
				}

				std::size_t formatEnd = std::string::npos;
				std::string index;
				for (std::size_t i = percent + 1; i < input.length(); i++)
				{
					if (input[i] == 's')
					{
						index = "1";
						formatEnd = i;
						break;
					}
					else if (input[i] == '$' && i + 1 < input.length() && input[i + 1] == 's')
					{
						index = input.substr(percent + 1, i - percent - 1);
						formatEnd = i + 1;
						break;
					}
					else if (!std::isdigit(input[i]))
						break;					
				}

				if (formatEnd != std::string::npos)
				{
					ss << input.substr(lastFormatChar + 1, percent - lastFormatChar - 1);
					lastFormatChar = formatEnd;
					ss << args[std::stoi(index) - 1];
				}
			}
		}

		if (lastFormatChar + 1 < input.length())
			ss << input.substr(lastFormatChar + 1);

		return ss.str();
	}

	template<typename T1, typename T2>
	static std::string formatSimple(const std::string &input, T1 arg1, T2 arg2)
	{
		std::stringstream ss;
		std::size_t lastFormatChar = std::string::npos;
		std::size_t percent = std::string::npos;
		while ((percent = input.find('%', percent + 1)) != std::string::npos)
		{
			if (percent + 1 < input.length())
			{
				if (input[percent + 1] == '%')
				{
					percent++;
					continue;
				}

				std::size_t formatEnd = std::string::npos;
				std::string index;
				for (std::size_t i = percent + 1; i < input.length(); i++)
				{
					if (input[i] == 's')
					{
						index = "1";
						formatEnd = i;
						break;
					}
					else if (input[i] == '$' && i + 1 < input.length() && input[i + 1] == 's')
					{
						index = input.substr(percent + 1, i - percent - 1);
						formatEnd = i + 1;
						break;
					}
					else if (!std::isdigit(input[i]))
						break;					
				}

				if (formatEnd != std::string::npos)
				{
					ss << input.substr(lastFormatChar + 1, percent - lastFormatChar - 1);
					lastFormatChar = formatEnd;

					if (index == "1")
						ss << arg1;
					else if (index == "2")
						ss << arg2;
					else
						throw std::runtime_error("Only simple positional format specifiers are handled by the 'formatSimple' helper method.");
				}
			}
		}

		if (lastFormatChar + 1 < input.length())
			ss << input.substr(lastFormatChar + 1);

		return ss.str();
	}

	template<typename T1, typename T2, typename T3>
	static std::string formatSimple(const std::string &input, T1 arg1, T2 arg2, T3 arg3)
	{
		std::stringstream ss;
		std::size_t lastFormatChar = std::string::npos;
		std::size_t percent = std::string::npos;
		while ((percent = input.find('%', percent + 1)) != std::string::npos)
		{
			if (percent + 1 < input.length())
			{
				if (input[percent + 1] == '%')
				{
					percent++;
					continue;
				}

				std::size_t formatEnd = std::string::npos;
				std::string index;
				for (std::size_t i = percent + 1; i < input.length(); i++)
				{
					if (input[i] == 's')
					{
						index = "1";
						formatEnd = i;
						break;
					}
					else if (input[i] == '$' && i + 1 < input.length() && input[i + 1] == 's')
					{
						index = input.substr(percent + 1, i - percent - 1);
						formatEnd = i + 1;
						break;
					}
					else if (!std::isdigit(input[i]))
						break;					
				}

				if (formatEnd != std::string::npos)
				{
					ss << input.substr(lastFormatChar + 1, percent - lastFormatChar - 1);
					lastFormatChar = formatEnd;

					if (index == "1")
						ss << arg1;
					else if (index == "2")
						ss << arg2;
					else if (index == "3")
						ss << arg3;
					else
						throw std::runtime_error("Only simple positional format specifiers are handled by the 'formatSimple' helper method.");
				}
			}
		}

		if (lastFormatChar + 1 < input.length())
			ss << input.substr(lastFormatChar + 1);

		return ss.str();
	}

	
};
