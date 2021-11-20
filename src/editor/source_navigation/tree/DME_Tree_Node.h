#ifndef _DME_TREE_NODE_H
#define _DME_TREE_NODE_H

#pragma once
#include <string>
#include "../../../byond/tree/DME_tree_item.h"
#include <vector>
#include <algorithm>

namespace MYG
{
    template<typename T>
    class DefaultMutableTreeNode
    {
        
    public:
        // member vars
        std::string data;
        std::vector<DefaultMutableTreeNode<T>*> children;
        DefaultMutableTreeNode<T> *parent;
        
        // constructor
        DefaultMutableTreeNode(std::string data): data(data),parent(nullptr) {}

        void add(DefaultMutableTreeNode<T> *newChild){
            newChild->parent = this;
            children.push_back(newChild);
            std::sort(children.begin(),children.end(),[&]( DefaultMutableTreeNode<T> *obj1,  DefaultMutableTreeNode<T> *obj2){
                return obj1->data.compare(obj2->data) > 0;
            });

        }


    };

	class DME_Tree_Tree_Node : public DefaultMutableTreeNode<BYOND::DME_Tree_Item*>
	{
	private:
		BYOND::DME_Tree_Item *node;

	public:
		virtual ~DME_Tree_Tree_Node()
		{
			delete node;
		}

		DME_Tree_Tree_Node(BYOND::DME_Tree_Item *node) : DefaultMutableTreeNode<BYOND::DME_Tree_Item*>(node->getName())
		{
			this->node = node;
		}

		virtual BYOND::DME_Tree_Item *getNode()
		{
			return node;
		}
	};

}



#endif