#ifndef NODE_HPP
#include <vector>
#include <stack>
#include <functional>
#include <list>
#include <iterator>
#include <type_traits>

/** A class representing an arbitrary tree **/	
template<typename T>
class Node {
protected:
	T value;
	std::list<Node<T>> children;

	using iterator_type = Node<T>;
	using const_iterator_type = const Node<T>;
	template<typename value_type>
	class Iterator : public std::iterator<std::forward_iterator_tag, value_type> {
		value_type* node;
		std::stack<value_type*> nexts;

	public:
		//Constructor
		explicit Iterator(value_type* node) : node(node) { }

		//Takes this iterator to the next step
		Iterator<value_type>& operator++() {
			//If I have children, recurse into firstborn child!
			//Otherwise I am a leaf which looks for guidance in stack (if there is guidance)
			//Otherwise, I am the lastborn child of every node
			const size_t numChildren = node->children.size();
			if(numChildren > 0) {
				//If firstborn child has siblings, remember the siblings s.t we can iterate to them later on
				if(numChildren > 1) {
					//Order is reversed since we want the closest sibling to be ontop of the stack
					//We only want to add siblings to firstborn child, not firstborn itself, hence std::prev(..., 1)
					for(auto it = node->children.rbegin(); it != std::prev(node->children.rend(), 1); it++) {
						nexts.push(&(*it));
					}
				}
				node = &node->children.front();
			} else if(nexts.size() > 0) {
				node = nexts.top();
				nexts.pop();
			} else {
				//Stack is empty and I'm a leaf so the iteration is done!
				node = nullptr;
			}
			return *this;
		}

		Iterator operator++(int) { 
			Iterator ret = *this;
			++(*this);
			return ret;
		}

		//Two iterators are considered to be at the same place iff the pointer they hold is equal
		//So if two iterators stand on value 1 and 1 then they're not equal (since tree may hold several 1's)
		constexpr bool operator==(const Iterator& other) const { return node == other.node; }
		constexpr bool operator!=(const Iterator& other) const { return !(*this == other); }

		//Iterator-dereference operator. Returns const reference if iterator is const-iterator, otherwise returns non-const reference
		constexpr typename std::conditional<std::is_same<value_type, const_iterator_type>::value, const T&, T&>::type operator*() const { return node->get(); }
	};

public:

	//Construct node with value
	Node(const T& value) : value(value) { }

	//Move-constructor with value
	Node(T&& value) : value(value) { }

	//Copy-constructor
	Node(const Node<T>& node) : value(node.value) {
		for(const Node<T>& child : node.children) {
			add(Node(child));
		}
	}

	//Move-constructor
	Node(Node<T>&& node) : value(node.value) {
		value = node.value;
		children = node.children;
		node.children.clear();
	}

	//Destructor
	virtual ~Node() { }

	//Non-const begin and end
	Iterator<iterator_type> begin() { return Iterator<iterator_type>(this); }
	Iterator<iterator_type> end() { return Iterator<iterator_type>(nullptr); }

	//Const begin and end
	Iterator<const_iterator_type> begin() const { return Iterator<const_iterator_type>(this); }
	Iterator<const_iterator_type> end() const { return Iterator<const_iterator_type>(nullptr); }

	//Check if this tree is topologically equal to other tree (does not check values on nodes!)
	bool topoeq(const Node<T>& other) const {
		bool ret = true;
		if(children.size() != other.children.size()) return false;
		for(auto it = children.begin(), otherIt = other.children.begin(); it != children.end(); it++) {
			ret = ret && (*it).topoeq(*otherIt++);
		}
		return ret;
	}

	//Check if this tree is topologically equal and check if values are equal
	bool equal(const Node<T>& other) const {
		bool ret = true;
		if(value != other.value || children.size() != other.children.size()) return false;
		for(auto it = children.cbegin(), otherIt = other.children.cbegin(); it != children.cend(); it++) {
			ret = ret && (*it).equal(*otherIt++);
		}
		return ret;
	}

	constexpr bool operator==(const Node<T>& other) const { return equal(other); }

	//Assignment operator (using copy-constructor on argument)
	Node<T>& operator=(Node<T> other) {
		std::swap(value, other.value);
		std::swap(children, other.children);
		return *this;
	}

	const T& get() const { return value; } //Const get
	T& get() { return value; } //Non-const get

	//Append child to vector of children.
	Node& add(const T& value) {
		children.emplace_back(value);
		return children.back();
	}

	//Append child to vector of children by copying node
	Node& add(const Node<T>& node) {
		children.emplace_back(node);
		return children.back();
	}

	//Append child to vector of children by copying node
	Node& add(const Node<T>&& node) {
		children.emplace_back(node);
		return children.back();
	}

	//Removes last child from vector of children
	void remove() {
		children.pop_back();
	}

	//Updates each element in tree via f
	Node<T>& inplace_transform(const std::function<T(const T& value)>& f) {
		for(T& value : *this) value = f(value);
		return *this;
	}

	//Transforms every element of this tree into a new tree (which is topologically equivalent)
	template<typename U, typename F>
	Node<U> transform(const F& f) const {
		Node<U> root(f(value));
		for(const Node<T>& child : children) {
			root.add(child.transform<U, F>(f));
		}
		return root;
	}

	//Maps each edge of this tree into trees of nodes of pairs of values connected to edge 
	//with initial value to that of parent value
	Node<std::pair<T, T>> edgetrees(const Node<T>& parent) const {
		Node<std::pair<T, T>> node(std::pair<T,T>{parent.get(), value});
		for(const Node<T>& child : children) {
			node.add(child.edgetrees(*this));
		}
		return node;
	}

	//Maps each edge of this tree into trees of nodes of pairs of values connected to edge 
	std::list<Node<std::pair<T, T>>> edgetrees() const {
		std::list<Node<std::pair<T, T>>> ret;
		for(const Node<T>& child : children) {
			ret.emplace_back(child.edgetrees(*this));
		}
		return ret;
	}

	//Applied a function to each pair of (parent, child) and outputs it to N trees,
	//where N is number of children of root
	template<typename U, typename F>
	std::list<Node<U>> difftrees(const F& f) const {
		std::list<Node<U>> ret;
		for(const Node<std::pair<T, T>>& tree : edgetrees()) {
			ret.emplace_back(tree.template transform<U, F>(f));
		}
		return ret;
	}

	//Return number of nodes in tree
	size_t size() const {
		size_t count = 1;
		for(auto child : children) {
			count += child.size();
		}
		return count;
	}
};

#endif //NODE_HPP