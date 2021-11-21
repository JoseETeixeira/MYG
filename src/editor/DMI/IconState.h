#pragma once

#include "DMI.h"
#include "IconSubstate.h"
#include <string>
#include <vector>

namespace MYG::dmirender
{

	class IconState
	{
	public:
		DMI *dmi;
		std::wstring name;
		int dirCount = 1;
		int frameCount = 1;
		std::vector<float> delays;
		std::vector<IconSubstate*> substates;

		virtual ~IconState()
		{
			delete dmi;
		}

		IconState(const std::wstring &name)
		{
			this->name = name;
		}

		virtual IconSubstate *getSubstate(int dir, int frame)
		{
			return substates[dirToIndex(dir) + ((frame % frameCount) * dirCount)];
		}

		virtual IconSubstate *getSubstate(int dir)
		{
			return getSubstate(dir, 0);
		}

//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static const std::vector<int> dirToIndexArray = std::vector<int>{0, 1, 0, 1, 2, 6, 4, 2, 3, 7, 5, 3, 2, 1, 0, 0};
		virtual int dirToIndex(int dir)
		{ // Converts dm dirs (2,1,4,8,6,10,5,9) to indices(0,1,2,3,4,5,6,7)
			if (dirCount == 1) // One direction = don't bother.
			{
				return 0;
			}
			if (dir > 16)
			{
				return 0;
			}
			if (dir < 0)
			{
				return 0;
			}
			int out = dirToIndexArray[dir];
			if (out > 3 && dirCount == 4)
			{
				out -= 4;
			}
			return out;
		}

//JAVA TO C++ CONVERTER TODO TASK: C++ does not allow initialization of static non-const/integral fields in their declarations - choose the conversion option for separate .h and .cpp files:
		static const std::vector<int> indexToDirArray = std::vector<int>{2, 1, 4, 8, 6, 10, 5, 9};
	};

}
