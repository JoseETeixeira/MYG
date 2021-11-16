#pragma once

#include <string>
#include <vector>
#include "stringhelper.h"
#include "tangible_filesystem.h"
#include <iostream>
#include <sstream>
#include <fstream>

namespace BYOND
{

	/**
	 * This class contains various utilities.
	 */
	class Util
	{

		/**
		 * The Unix separator character.
		 */
	private:
		static constexpr char UNIX_SEPARATOR = '/';

		/**
		 * The Windows separator character.
		 */
		static constexpr char WINDOWS_SEPARATOR = '\\';

		/**
		 * The system separator character.
		 */
		static inline const char SYSTEM_SEPARATOR = FileSystem::preferredSeparator();

		/**
		 * Attempts to retrieve a {@link InputStream} representation of a file.
		 *
		 * @param path a path to a file.
		 * @return a {@link InputStream} representation of the file passed
		 */
	public:
		static std::wifstream getFile(const std::string &path)
		{
			return  std::wifstream(path); 
		}

		/**
		 * Attempts to retrieve a {@code byte[]} representation of a file.
		 *
		 * @param path a path to a file.
		 * @return a {@code byte[]} representation of a file.
		 * @throws IOException
		 */
		static std::vector<signed char> getFileAsBytes(const std::wstring &path)
		{
			std::stringstream sstream;
			sstream << path.c_str();
			std::wifstream inputStream = getFile(sstream.str());
			
			inputStream.seekg(0, std::ios_base::end);
			size_t length = inputStream.tellg();
			inputStream.seekg(0, std::ios_base::beg);

			std::vector<signed char> buffer;
			buffer.reserve(length);
			std::copy( std::istreambuf_iterator<wchar_t>(inputStream),
					std::istreambuf_iterator<wchar_t>(),
					std::back_inserter(buffer) );

		
			return std::vector<signed char>();
		}

		/**
		 * Determines if Windows file system is in use.
		 *
		 * @return true if the system is Windows
		 */
		static bool isWindowsSystem()
		{
			return SYSTEM_SEPARATOR == WINDOWS_SEPARATOR;
		}

		/**
		 * Converts all separators to the Unix separator of forward slash.
		 *
		 * @param path the path to be changed, null ignored
		 * @return the updated path
		 */
		static std::wstring separatorsToUnix(const std::wstring &path)
		{
			if (path == L"" || path.find(WINDOWS_SEPARATOR) == std::wstring::npos)
			{
				return path;
			}
			std::wstring p = path;
			return p.replace(WINDOWS_SEPARATOR,UNIX_SEPARATOR,path);
		}

		/**
		 * Converts all separators to the Windows separator of backslash.
		 *
		 * @param path the path to be changed, null ignored
		 * @return the updated path
		 */
		static std::wstring separatorsToWindows(const std::wstring &path)
		{
			if (path == L"" || path.find(UNIX_SEPARATOR) == std::wstring::npos)
			{
				return path;
			}
			std::wstring p = path;
			return p.replace(UNIX_SEPARATOR,WINDOWS_SEPARATOR,path);
		}

		/**
		 * Converts all separators to the system separator.
		 *
		 * @param path the path to be changed, null ignored
		 * @return the updated path
		 */
		static std::wstring separatorsToSystem(const std::wstring &path)
		{
			if (path == L"")
			{
				return L"";
			}
			if (isWindowsSystem())
			{
				return separatorsToWindows(path);
			}
			else
			{
				return separatorsToUnix(path);
			}
		}

		
	};

}