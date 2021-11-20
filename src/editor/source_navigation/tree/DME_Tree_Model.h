#pragma once

#include "DME_Tree_Node.h"
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include "../../../byond/utils/exception_helper.h"
#include "../../../byond/tree/DME_tree_listener.h"
#include "../../../byond/tree/DME_tree.h"
#include "spdlog/spdlog.h"


namespace MYG
{

    template<typename T>
    class DefaultTreeModel
    {
        public:
            // constructors
            DefaultTreeModel(): root(nullptr) {}
            DefaultTreeModel(DefaultMutableTreeNode<T>* rootNode): root(rootNode) {}
            
            // member functions
            void Print();

            void setRoot(DefaultMutableTreeNode<T>* rootNode);

            DefaultMutableTreeNode<T>* getRoot(){
                return this->root;
            };

            void insertNodeInto(DefaultMutableTreeNode<T>*newChild, DefaultMutableTreeNode<T>*parent, int index);

            void removeNodeFromParent(DefaultMutableTreeNode<T>* node);

            
        private:
            DefaultMutableTreeNode<T>* root;
            std::string SubTreeAsString(DefaultMutableTreeNode<T>* node);  // Helper method for Print()
            int NodeAtIndex(std::vector<DefaultMutableTreeNode<T>*> children,DefaultMutableTreeNode<T>* node );
        };

        template<typename T>
        int DefaultTreeModel<T>::NodeAtIndex(std::vector<DefaultMutableTreeNode<T>*> children,DefaultMutableTreeNode<T>* node ){
            int i = 0;
            for(DefaultMutableTreeNode<T>* child : children){
                if(child == node){
                    return i;
                }
                i++;
            }
        }


        //Invoked this to remove node at index from its parent.
        template<typename T>
        void DefaultTreeModel<T>::removeNodeFromParent(DefaultMutableTreeNode<T>*node){
            node->parent->children.erase(node->parent->children.begin() + NodeAtIndex(node->parent->children,node));
        }

        //Invoked this to insert newChild at location index in parents children.
        template<typename T>
        void DefaultTreeModel<T>::insertNodeInto(DefaultMutableTreeNode<T>*newChild, DefaultMutableTreeNode<T>*parent, int index){
            parent->children.emplace(parent->children.begin()+index,newChild);
        }
        
        //Sets the tree root
        template<typename T>
        void DefaultTreeModel<T>::setRoot(DefaultMutableTreeNode<T>* rootNode){
            this->root = rootNode;
        }


        /// Print the tree
        template<typename T>
        void DefaultTreeModel<T>::Print(){
            if(this->root == nullptr){
                spdlog::info("{}") ;
            } else{
                spdlog::info( this->SubTreeAsString(this->root));
            }
        }

        /// Print the subtree starting at '*node'
        template<typename T>
        std::string DefaultTreeModel<T>::SubTreeAsString(DefaultMutableTreeNode<T>* node){
            std::string result = "{";
            result += node->data;
            if(node->children.size() == 0){
                for(auto child : node->children){
                    SubTreeAsString(child);
                }
            }
           result += "}";
            return result;
    };


	class DME_Tree_Tree_Model : public DefaultTreeModel<BYOND::DME_Tree_Item*>, public BYOND::DME_Tree_Listener
	{
	private:
		std::unordered_map<BYOND::DME_Tree_Item*, DME_Tree_Tree_Node*> nodeMap = std::unordered_map<BYOND::DME_Tree_Item*, DME_Tree_Tree_Node*>();


	public:
		DME_Tree_Tree_Model(BYOND::DME_Tree *tree) : DefaultTreeModel(nullptr)
		{
           DefaultMutableTreeNode<BYOND::DME_Tree_Item*> *dmt = generateTree(tree->getRootNode());
			this->setRoot(dmt);
			tree->addListener(this);
		}

	private:
		DME_Tree_Tree_Node *generateTree(BYOND::DME_Tree_Item *parent)
		{
			DME_Tree_Tree_Node *parentTreeNode = new DME_Tree_Tree_Node(parent);
			for (BYOND::DME_Tree_Item *child : parent->getChildren())
			{
				parentTreeNode->add(generateTree(child));
			}
			nodeMap.emplace(parent, parentTreeNode);

			return parentTreeNode;
		}

        int NodeIndex(std::vector<BYOND::DME_Tree_Item*> children, BYOND::DME_Tree_Item* node){
            int i = 0;
            for(BYOND::DME_Tree_Item* child : children){
                if(child == node){
                    return i;
                }
                i++;
            }
        } 

	public:
		void onNodeAdded(BYOND::DME_Tree_Item *node) override
		{
			try
			{
				
				this->insertNodeInto(generateTree(node), nodeMap[node->getParent()], NodeIndex(node->getParent()->getChildren(),node));
				
			}
			
			catch (const StackOverflowError &e)
			{
				spdlog::error(e.what());
			}
		}

		void onNodeRemoved(BYOND::DME_Tree_Item *node) override
		{
			
			this->removeNodeFromParent(nodeMap[node]);
		}
	};

}
