#pragma once

#include "IconSubstate.h"

namespace com::github::tgstation::fastdmm::dmirender
{

	using Color = java::awt::Color;

	class RenderInstance : public Comparable<RenderInstance*>
	{
	public:
		IconSubstate *substate;
		Color *color;
		float x = 0;
		float y = 0;
		int plane = 0;
		float layer = 0;
		int creationIndex = 0;

		virtual ~RenderInstance()
		{
			delete substate;
			delete color;
		}

		RenderInstance(int creationIndex)
		{
			this->creationIndex = creationIndex;
		}

		int compareTo(RenderInstance *o) 
		{
			float cnA = plane;
			float cnB = o->plane;
			if (cnA == cnB)
			{
				cnA = layer;
				cnB = o->layer;
			}
			if (cnA == cnB)
			{
				cnA = creationIndex;
				cnB = o->creationIndex;
			}
			return cnA < cnB ? -1 : (cnA == cnB ? 0 : 1);
		}
	};

}
