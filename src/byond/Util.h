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
		static constexpr wchar_t UNIX_SEPARATOR = L'/';

		/**
		 * The Windows separator character.
		 */
		static constexpr wchar_t WINDOWS_SEPARATOR = L'\\';

		/**
		 * The system separator character.
		 */
		static inline const wchar_t SYSTEM_SEPARATOR = FileSystem::preferredSeparator();

		/**
		 * Attempts to retrieve a {@link InputStream} representation of a file.
		 *
		 * @param path a path to a file.
		 * @return a {@link InputStream} representation of the file passed
		 */
	public:
		static std::ifstream getFile(const std::wstring &path)
		{
			return  std::ifstream(path, std::ios::binary ); 
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
			std::ifstream inputStream = getFile(path);
			
			inputStream.seekg(0, std::ios_base::end);
			size_t length = inputStream.tellg();
			inputStream.seekg(0, std::ios_base::beg);

			std::vector<signed char> buffer;
			buffer.reserve(length);
			std::copy( std::istreambuf_iterator<char>(inputStream),
					std::istreambuf_iterator<char>(),
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
