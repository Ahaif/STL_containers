#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "set.hpp"

#define RED 1
#define BLACK 0
#define DBLACK 2

namespace ft
{
	template <class T>
	struct Node
	{
	public:
		typedef T value_type;

	public:
		value_type key;
		Node *parent;
		Node *left;
		Node *right;
		int color;

	public:
		Node() : key(){};
		Node(T key) : key(key){};
	};
	template <class T, class Compare, class Allocator>
	class rbTree
	{
	public:
		/******************  typedef all template parameters        ***********************/
		typedef T value_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;

	private:
		/******************  typedef member Types of Nodes    ***********************/
		typedef typename allocator_type::template rebind<Node<T> >::other allocator_node;
		typedef typename allocator_node::reference node_reference;
		typedef typename allocator_node::const_reference node_const_reference;
		typedef typename allocator_node::difference_type node_difference_type;
		typedef typename allocator_node::pointer node_pointer;
		typedef typename allocator_node::const_pointer node_const_pointer;
		typedef typename allocator_node::size_type node_size_type;
		typedef Node<value_type> Node_type;
		typedef Node_type *Node_ptr;

	public:
		/****************** typedef member Types of Tree iterator     ***********************/
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::size_type size_type;
		// typedef typename value_type	::first_type							key_type;
		// typedef typename value_type::second_type							mapped_type;
		typedef ft::TreeIter<pointer, Node_ptr> iterator;
		typedef ft::TreeIter<const_pointer, Node_ptr> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
		/****************** Declare all attributes needed in Tree  ***********************/
		allocator_node _alloc;
		key_compare _comp;
		Node_ptr _root;
		Node_ptr _end;
		int _size;

	public:
		/****************** Tree constructor and distructor ***********************/
		rbTree(const key_compare &compare = key_compare(), const allocator_type &alloc = allocator_type()) : _size(0), _comp(compare), _alloc(alloc)
		{
			this->_end = create_node(value_type());
			this->_root = this->_end;
		}
		~rbTree(){};

		// void print_tree()
		// {
		// 	std::cout << "----------------------------------------------" << std::endl;
		// 	print2d(this->_root, 0);
		// 	std::cout << "----------------------------------------------" << std::endl;
		// }

	private: // private
		Node_ptr _search(Node_ptr const &temp, value_type const &key) const
		{
		
			if (temp == NULL)
				return (this->_end);

			if (temp->key == key)
				return (temp);
			else if (this->_comp(key, temp->key))
				return (_search(temp->left, key));
			else if (this->_comp(temp->key, key))
				return (_search(temp->right, key));

			return (this->_end);
		}
		// post order traversal
		void _clearTree(Node_ptr &root)
		{
			if (root != nullptr)
			{
				_clearTree(root->left);
				_clearTree(root->right);
				this->_alloc.destroy(root);
				this->_alloc.deallocate(root, 1);
			}
		}
		Node_ptr _min() const
		{
			if (this->_root == this->_end)
				return (this->_end);
			Node_ptr temp = this->_root;
			while (temp && temp->left && temp->left != nullptr)
				temp = temp->left;
			return (temp);
		}
		Node_ptr _max() const
		{
			Node_ptr temp = this->_root;
			while (temp->right && temp->right != this->_end)
				temp = temp->right;
			return (temp);
		}

		Node_ptr rightRotate(Node_ptr x)
		{
			// std::cout<<"right rotate"<<std::endl;
			// std::cout<<"x is: "<<x->key<<std::endl;

			Node_ptr y = x->left;
			Node_ptr T2 = nullptr;
			if (y->right != nullptr)
				T2 = y->right;
			Node_ptr p = x->parent;

			// std::cout<<"y is: "<<y->key<<std::endl;

			y->right = x;
			x->left = T2;

			// std::cout<<"p is: "<<p->parent->key<<std::endl;

			if (p != this->_end)
			{
				if (p->right == x)
					p->right = y;
				else
					p->left = y;
			}
			else
			{
				this->_root = y;

				this->_end->left = this->_root;
				this->_root->parent = this->_end;
			}

			y->parent = p;
			x->parent = y;

			if (T2 != nullptr)
				T2->parent = x;
			return y;
		};

		Node_ptr leftRotate(Node_ptr x)
		{

			Node_ptr y = x->right;

			Node_ptr T2 = y->left;
			Node_ptr p = x->parent;

			y->left = x;
			x->right = T2;

			if (p != this->_end)
			{
				if (p->left == x)
					p->left = y;
				else
					p->right = y;
			}
			else
			{
				this->_root = y;

				this->_end->left = this->_root;
				this->_root->parent = this->_end;
			}

			y->parent = x->parent;
			x->parent = y;

			if (T2 != nullptr)
				T2->parent = x;
			return y;
		};
		Node_ptr insertFixup(Node_ptr node)
		{

			while (node && node->color == RED && node->parent->color == RED)
			{
				if (node->parent == node->parent->parent->left)
				{
					Node_ptr grandparent = node->parent->parent;
					Node_ptr right_sibling = node->parent->parent->right;
					if (right_sibling && right_sibling->color == RED)
					{
						if (grandparent != this->_root)
							grandparent->color = RED;
						if (grandparent->left)
							grandparent->left->color = BLACK;
						if (grandparent->right)
							grandparent->right->color = BLACK;
						node = grandparent;
					}
					else
					{
						if (node == node->parent->right)
						{
							grandparent->left = leftRotate(grandparent->left);
						}
						Node_ptr tmp = rightRotate(grandparent);
						tmp->color = BLACK;
						tmp->left->color = RED;
						tmp->right->color = RED;
					}
				}
				else
				{
					Node_ptr grandparent = node->parent->parent;
					Node_ptr left_sibling = node->parent->parent->left;
					if (left_sibling && left_sibling->color == RED)
					{
						if (grandparent != this->_root)
							grandparent->color = RED;
						if (grandparent->left)
							grandparent->left->color = BLACK;
						if (grandparent->right)
							grandparent->right->color = BLACK;
						node = grandparent;
					}
					else
					{
						if (node == node->parent->left)
						{
							grandparent->right = rightRotate(grandparent->right);
						}
						Node_ptr tmp = leftRotate(grandparent);
						tmp->color = BLACK;
						tmp->left->color = RED;
						tmp->right->color = RED;
					}
				}
				// node = node->parent->parent;
				this->_root->color = BLACK;
			}

			return (nullptr);
		}

		Node_ptr _insert(Node_ptr newNode)
		{

			Node_ptr t = nullptr;
			Node_ptr x = this->_root;
			while (x != nullptr)
			{
				t = x;
				if (!this->_comp(x->key, newNode->key))
					x = x->left;
				else if (this->_comp(x->key, newNode->key))
					x = x->right;
			}
			newNode->parent = t;
			if (!this->_comp(t->key, newNode->key))
				t->left = newNode;
			else
				t->right = newNode;
			insertFixup(newNode);
			return (newNode);
		}

		// void x_right_case(Node_ptr x, Node_ptr w)
		// {
		// 	if (w->color == RED) {
		// 		w->color = BLACK;
		// 		x->parent->color = RED;
		// 		rightRotate(x->parent);
		// 		w = x->parent->left;
		// 	}
		// 	if (w->left->color == BLACK && w->right->color == BLACK) {
		// 		w->color = RED;
		// 		x = x->parent;
		// 	} else {
		// 		if (w->left->color == BLACK) {
		// 		w->right->color = BLACK;
		// 		w->color = RED;
		// 		leftRotate(w);
		// 		w = x->parent->left;
		// 		}
		// 		w->color = x->parent->color;
		// 		x->parent->color = BLACK;
		// 		w->left->color = BLACK;
		// 		rightRotate(x->parent);
		// 		x = this->_root;
		// 	}

		// }

		void x_right_case(Node_ptr &node, Node_ptr &sibling, Node_ptr &parent)
		{
			// std::cout<<"right case  node is:  "<<x->key<< " color is: "<<x->color<<std::endl;
			// std::cout << "right case  node is:  " << node->key << " color is: " << node->color << std::endl;
					if (sibling->color == RED)
					{
						// WR
						sibling->color = BLACK;
						parent->color = RED;

						rightRotate(parent);
						sibling = parent->right;
						if(sibling == nullptr)
							return;
					}
					if (get_color(sibling) == BLACK && get_color(sibling->left) == BLACK && get_color(sibling->right) == BLACK)
					{

						sibling->color = RED;
						// parent->color = BLACK;
						node = parent;
					
					}
					else
					{
						// std::cout << "pass by " << std::endl;
						if (get_color(sibling->right) == BLACK)
						{
							sibling->left->color = BLACK;
							sibling->color = RED;

							leftRotate(sibling);
							sibling = parent->right;
							if(sibling == nullptr)
								return;
						}
					
						int tmp = 0;
						tmp = parent->color;
						parent->color = sibling->color;
						sibling->color = tmp;
						// sibling->color = parent->color;
						// sibling->parent->color = BLACK;
						// if(w->right)
						
						rightRotate(parent);
						sibling->right->color = BLACK;
						node = this->_root;
					}
		}

		void transplant(Node_ptr &u, Node_ptr &v)
		{
			if (v == nullptr)
			{
				if (u == this->_root)
				{
					this->_root = this->_end;
					this->_end->left = this->_root;
				}
				else if (u == u->parent->left)
					u->parent->left = nullptr;
				else if (u == u->parent->right)
				{
					u->parent->right = nullptr;
				}
			}
			else
			{
				if (u == this->_root)
				{
					this->_root = v;
					this->_end->left = v;
					// std::cout<<"change root to: "<< this->_root->key<<std::endl;
				}
				else if (u == u->parent->left)
				{
					u->parent->left = v;
				}
				else if (u == u->parent->right)
				{

					u->parent->right = v;
				}
				v->parent = u->parent;
			}
		}

		bool get_color(Node_ptr const &node)
		{
			if (node == nullptr)
				return (BLACK);
			return (node->color);
		}

		void delete_Fixup(Node_ptr &node, Node_ptr &parent, int color)
		{
			// 4 types of fixes
			// WR
			// WB-LRB
			// WB-LB_RR
			// WB-LR_RB

			if (color != BLACK) // node is leaf DB
				return;
	
			node->color = color;
			Node_ptr sibling = get_sibling(node);
			if(sibling == nullptr)
			{
				node->color = BLACK;
				return;
			}
				

				
				// Node_ptr parent = node->parent;

			while (node != this->_root && node->color == BLACK)
			{
				// std::cout<<"delete fix_up"<<std::endl;
				parent = sibling->parent;
				if (sibling == parent->right)
				{
					// std::cout << "left case  node is:  " << node->key << " color is: " << node->color << std::endl;

					if (sibling->color == RED)
					{
						// WR
						sibling->color = BLACK;
						parent->color = RED;

						leftRotate(parent);
						sibling = parent->right;
						if(sibling == nullptr)
							break;
						
					}
					if (get_color(sibling) == BLACK && get_color(sibling->left) == BLACK && get_color(sibling->right) == BLACK)
					{

						sibling->color = RED;
						// parent->color = BLACK;
						node = parent;
						
					}
					else
					{
						
						if (get_color(sibling->right) == BLACK)
						{
							sibling->left->color = BLACK;
							sibling->color = RED;

							rightRotate(sibling);
							sibling = parent->right;
							if(sibling == nullptr)
								break;
						}
						int tmp = 0;
						tmp = parent->color;
						parent->color = sibling->color;
						sibling->color = tmp;
						// sibling->color = parent->color;
						// sibling->parent->color = BLACK;
						// if(w->right)
						
						leftRotate(parent);
						sibling->right->color = BLACK;
						node = this->_root;
					}
				}
				else
					x_right_case(node, sibling, parent);
				sibling = get_sibling(node);
				if(sibling == nullptr)
					break;
			}
			
			node->color = BLACK;
		}
		Node_ptr get_sibling(Node_ptr const &node)
		{
			if (node == nullptr || node == this->_root)
				return NULL;
			if (node->parent->right == node)
			{
				return node->parent->left;
			}
			return node->parent->right;
		}

		Node_ptr _delete(Node_ptr &root, Node_ptr &node)
		{

			// transplant help us move subtree within rb tree (3condition)

			// std::cout <<"node is:" << node->key <<std::endl;

			if (node == nullptr)
				return nullptr;

			Node_ptr parent = node->parent;
			Node_ptr right = node->right;
			Node_ptr left = node->left;

			Node_ptr tmp = node;
			int original_color = node->color;

			if (left == nullptr && right == nullptr)
			{

				if (node == this->_root)
				{
					// update -root
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					this->_root = this->_end;
					this->_end->left = this->_root;
					return nullptr;
				}
				else if (node == parent->left)
				{

					transplant(node, left);
					// _alloc.destroy(node);
					// _alloc.deallocate(node, 1);
				}
				else
				{
					transplant(node, right);
					// _alloc.destroy(node);
					// _alloc.deallocate(node, 1);
				}
				// if (this->_root)
				if(left == nullptr)
					delete_Fixup(tmp, parent, original_color);
				else
					delete_Fixup(left, parent, original_color);
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
			}
			else if (left == nullptr)
			{
				transplant(node, node->right);

				_alloc.destroy(node);
				_alloc.deallocate(node, 1);

				if(right == nullptr)
					delete_Fixup(tmp, parent, original_color);
				else
					delete_Fixup(right, parent, original_color);

				// if node is black delete fix up on node right = x
			}

			else if (right == nullptr)
			{
	
				transplant(node, node->left);

				_alloc.destroy(node);
				_alloc.deallocate(node, 1);

				std::cout << original_color << std::endl;

				if(left == nullptr)
					delete_Fixup(tmp, parent, original_color);
				else
					delete_Fixup(left, parent, original_color);

				// if node is black delete fix up on node left = x
			}
			else
			{

				Node_ptr success = _TreeMin(right);
				original_color = success->color;
				if (success->parent == node)
				{
					if (node == this->_root)
					{
						this->_root = success;
						success->parent = this->_end;
						this->_end->left = this->_root;
					}
					else
					{
						success->parent = parent;
						parent->right = success;
					}
				}
				else
				{
			
					transplant(success, success->right);
					success->right = node->right;
					success->right->parent = success;
				}
				transplant(node, success);
				success->left = node->left;
				success->left->parent = success;
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				// delete fix up succes ->right  = x
				if(success->right == nullptr)
					delete_Fixup(tmp, parent, original_color);
				else
					delete_Fixup(success, parent, original_color);


				
			}

			return (this->_root);
		}

	public:
		Node_ptr create_node(value_type key)
		{
			Node_ptr new_node = this->_alloc.allocate(1);
			this->_alloc.construct(new_node, key);
			new_node->parent = nullptr;
			new_node->left = nullptr;
			new_node->right = nullptr;
			return (new_node);
		}

		Node_ptr search(value_type const &key) const
		{

			if (this->_root == this->_end)
				return (this->_end);
			else
			{
				return (_search(this->_root, key));
			}
		}

		// ITERATORS-----------------------------------
		iterator begin() { return (iterator(_min())); };
		const_iterator begin() const { return (const_iterator(_min())); };
		iterator end() { return (iterator(this->_end)); };
		const_iterator end() const { return (const_iterator(this->_end)); }

		reverse_iterator rbegin() { return (reverse_iterator(iterator(_max()))); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(iterator(_max()))); }
		reverse_iterator rend() { return (reverse_iterator((iterator(_min() - 1)))); }
		const_reverse_iterator rend() const { return (const_reverse_iterator((iterator(_min() - 1)))); }

		// CAPACITY-----------------------------------
		bool empty() const
		{
			if (this->_root == this->_end)
				return (true);
			else
				return (false);
		}
		size_type size() const { return (this->_size); }
		size_type max_size() const { return (std::min<size_type>(std::numeric_limits<size_type>::max() / sizeof(Node_type), std::numeric_limits<difference_type>::max())); }

		// MODIFIERS-----------------------------------
		void clear()
		{
			if (this->_root != this->_end)
			{
				_clearTree(this->_root);
				this->_size = 0;
				this->_root = this->_end;
			}
		}
		// insert
		Node_ptr insert(value_type const &value)
		{
			Node_ptr new_node = create_node(value);
			if (this->_root == this->_end)
			{
				this->_root = new_node;
				new_node->color = BLACK;
				this->_end->left = this->_root;
				this->_root->parent = this->_end;
				++this->_size;
			}
			else
			{

				new_node->color = RED;
				++this->_size;
				_insert(new_node);
			}
			return (new_node);
		}

		// erase
		size_t remove(value_type const &value)
		{
			// std::cout<<"tree before------"<<std::endl;
			// print_tree();
		

				Node_ptr node = search(value);
				if (node != this->_end && node)
				{
					_delete(this->_root, node);
					// std::cout<<"tree after deletion----- root is: "<<this->_root->key<<std::endl;
					// print_tree();
					this->_size--;
					return (1);
				}
				else
					return (0);

			

		}

		void swap(rbTree &x)
		{
			size_type tmp_size = x._size;
			allocator_type tmp_alloc = x._alloc;
			Node_ptr tmp_root = x._root;
			Node_ptr tmp_end = x._end;

			x._size = this->_size;
			_size = tmp_size;

			x._alloc = this->_alloc;
			this->_alloc = tmp_alloc;

			x._end = this->_end;
			this->_end = tmp_end;

			x._root = this->_root;
			this->_root = tmp_root;
		}

		// LOOKUP-----------------------------------
		size_type count(const value_type &key) const
		{
			Node_ptr ret = search(key);
			if (ret != this->_end)
				return 1;
			else
				return 0;
		}

		Node_ptr lower_bound(const value_type &key) const
		{
			Node_ptr node = _min();

			while (!this->_comp(key, node->key))
			{
				if (key == node->key)
					break;
				node = successor(node);
				if (node == nullptr || node == this->_end)
				{
					return (this->_end);
				}
			}
			return (node);
		}

		Node_ptr upper_bound(value_type val) const
		{
			Node_ptr node = _min();

			while (!this->_comp(val, node->key))
			{
				node = successor(node);
				if (node == nullptr || node == this->_end)
					return (this->_end);
			}
			return (node);
		};
		// helper function to print set

		Node_ptr _print(Node_ptr root, int level)
		{

			if (root == nullptr || root == this->_end)
				return (root);

			_print(root->right, level + 1);
			for (int i = 0; i < level; i++)
				std::cout << "    ";
			std::cout << root->key << "-" << root->color << std::endl;
			_print(root->left, level + 1);

			return (root);
		}
		void print()
		{
			Node_ptr node = this->_root;
			if (node != nullptr)
				_print(node, 0);
			std::cout << "the root is: " << node->key << std::endl;
		}

		// void print2d(Node_ptr root, int space)
		// {
		// 	if (root == NULL)
		// 	    return;
		// 	space += 10;
		// 	print2d(root->right, space);
		// 	std::cout << std::endl;
		// 	for (int i = 10; i < space; i++)
		// 	    std::cout << " ";
		// 	std::cout << root->key << ":";
		// 	// if (root->_parent != NULL)
		// 	//     std::cout << *root->_parent->_key;
		// 	if (root->color == BLACK)
		// 	    std::cout << ":BLACK" << std::endl;
		// 	else
		// 	    std::cout << ":RED" << std::endl;
		// 	print2d(root->left, space);
		// }
	};

	template <class Node_ptr>
	Node_ptr predecessor(Node_ptr node)
	{

		// if(node == nullptr && node->left)
		// {

		// 	node = node->left;
		// 	return (_TreeMax(node->left));

		// }
		if (node->left && node)
		{

			return (_TreeMax(node->left));
		}

		Node_ptr temp = node->parent;

		while (temp && temp->left == node)
		{
			node = temp;
			temp = temp->parent;
		}
		if (temp == 0)
			return (node);
		return (temp);
	}

	template <class Node_ptr>
	Node_ptr _TreeMin(Node_ptr temp)
	{
		while (temp && temp->left != nullptr)
			temp = temp->left;
		return (temp);
	};

	template <class Node_ptr>
	Node_ptr _TreeMax(Node_ptr temp)
	{

		while (temp->right && temp->right != nullptr)
			temp = temp->right;

		return (temp);
	};

	template <class Node_ptr>
	Node_ptr successor(Node_ptr node)
	{

		if (node->right)
			return (_TreeMin(node->right));

		Node_ptr temp = node->parent;
		while (temp && temp->right == node)
		{
			node = temp;
			temp = temp->parent;
		}
		return (temp);
	};

};

#endif