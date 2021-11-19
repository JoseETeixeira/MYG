#pragma once

#include "DME_tree_item.h"

namespace BYOND
{

	class DME_Tree_Listener
	{
	public:
		virtual void onNodeAdded(DME_Tree_Item *node) = 0;

		virtual void onNodeRemoved(DME_Tree_Item *node) = 0;
	};

}
