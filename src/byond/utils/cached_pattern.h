#pragma once

#include <string>
#include <regex>

namespace BYOND
{

	/**
	 * Simple wrapper to lazily compile a Pattern
	 */
	class CachedPattern
	{

	private:
		std::string regexp;
		std::regex* cachedPattern;
		
		int flags = 0;

		/**
		 * Constructs a new cached regex pattern.
		 *
		 * @param regexp The regex.
		 */
	public:
		virtual ~CachedPattern()
		{
            delete cachedPattern;
		}

		CachedPattern(const std::string &regexp)
		{
			this->regexp = regexp;
		}

		CachedPattern()
		{
		}

		/**
		 * Switches the ignoreCase setting on the matcher.
		 *
		 * @param setting The new setting.
		 * @return The pattern it applies to.
		 */
		virtual CachedPattern *setIgnoreCase(bool setting)
		{
			int newflags = flags;
			if (newflags != flags)
			{
				flags = newflags;
				cachedPattern = nullptr;
			}
			return this;
		}

		/**
		 * Returns the Java Regex Pattern object that has been cached.
		 *
		 * @return The Pattern.
		 */
		virtual std::regex *getPattern()
		{
			
			
			cachedPattern = new std::regex(regexp);
			
			return cachedPattern;
		}

		/**
		 * Returns the stored regex.
		 *
		 * @return the regexp
		 */
		virtual std::string getRegexp()
		{
			return regexp;
		}

		/**
		 * Obtains the matcher for this pattern.
		 *
		 * @param input the input to match to.
		 * @return the matcher.
		 */
		virtual std::smatch getMatcher(std::string input)
		{
			std::smatch patternMatch;
			std::regex_search(input,patternMatch,*getPattern());
			return patternMatch;
		}

	};

}
