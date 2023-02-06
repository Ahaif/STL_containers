#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "set.hpp"

#define RED 1
#define BLACK 0
#define DBLACK 2

namespace ft
{
    template<class T>
    struct Node
    {
        public:
			typedef T				value_type;
		public:
			value_type		key;
			Node*	parent;
			Node*	left;
			Node*	right;
			int		color;

		public:
			Node(): key() {};
			Node(T key): key(key){};
    };
    template <class T, class Compare, class Allocator>
	class rbTree
    {
		public:
		/******************  typedef all template parameters        ***********************/
			typedef T								value_type;
			typedef Compare							key_compare;
			typedef Allocator					    allocator_type;

		private:
		/******************  typedef member Types of Nodes    ***********************/
			typedef typename allocator_type::template rebind<Node<T> >::other	allocator_node;
			typedef typename allocator_node::reference							node_reference;
			typedef typename allocator_node::const_reference					node_const_reference;
			typedef typename allocator_node::difference_type					node_difference_type;
			typedef typename allocator_node::pointer							node_pointer;
			typedef typename allocator_node::const_pointer						node_const_pointer;
			typedef typename allocator_node::size_type							node_size_type;
			typedef Node<value_type>											Node_type;
			typedef Node_type*	 												Node_ptr;
		public:
		/****************** typedef member Types of Tree iterator     ***********************/
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::difference_type					difference_type;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::size_type							size_type;
			// typedef typename value_type										key_type;
			// typedef typename value_type::second_type							mapped_type;
			typedef ft::TreeIter<pointer, Node_ptr>								iterator;
			typedef ft::TreeIter<const_pointer, Node_ptr>						const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>                       const_reverse_iterator;
		private:
		/****************** Declare all attributes needed in Tree  ***********************/
			allocator_node								_alloc;
			key_compare									_comp;
			Node_ptr									_root;
			Node_ptr									_end;
			int											_size;
		public:
		/****************** Tree constructor and distructor ***********************/
		rbTree(const key_compare &compare = key_compare(), const allocator_type& alloc = allocator_type()): _size(0), _comp(compare), _alloc(alloc)
		{
			this->_end = create_node(value_type());
			this->_root = this->_end;
			std :: cout << "constructor of red black tree called" << std::endl;

		}
		~rbTree(){};

		private:
			Node_ptr _search(Node_ptr temp, value_type key) const
			{
				if (temp == nullptr)
					return(this->_end);

				if (temp->key == key)
					return(temp);
				else if(this->_comp(key, temp->key))
					return(_search(temp->left, key));
				else if(this->_comp(temp->key, key))
					return(_search(temp->right, key));
				

				return(this->_end);
			}
			//post order traversal
			void	_clearTree(Node_ptr root)
			{
				if(root != nullptr)
				{
					_clearTree(root->left);
					_clearTree(root->right);
					this->_alloc.destroy(root);
					this->_alloc.deallocate(root, 1);

				}
			}
			Node_ptr _min() const
			{
				Node_ptr temp = this->_root;
				while(temp != this->_end && temp->left)
					temp = temp->left;
				return(temp);
			}
			Node_ptr _max() const
			{
				Node_ptr temp = this->_root;
				while(temp != this->_end && temp->right)
					temp = temp->right;
				return(temp);
			}
			void insertFixup(Node_ptr node)
			{
				// std::cout <<node->color<<std::endl;
				std::cout <<"passed"<<std::endl;
				std::cout <<node->color<<std::endl;
				
				if(node->parent->color == RED)
				{
					//RESOLVING DOUBLE RED
					//COLOR OF UNCLE IS CASE DISTINCTION IN RESOLVING DR

					
					//check wich side left or right 
					if(node->parent == node->parent->left)
					{
						
						Node_ptr uncle = node->parent->right;
						if(uncle->color == RED)
						{
							node->parent->color  = BLACK;
							uncle->color = BLACK;
							node->parent->parent->color = RED;
							
						

							// std::cout << "passed" << std::endl;
							// uncle->color = BLACK;
							// node->parent->color = BLACK;
							// node->parent->parent->color = RED;
							// leftRotate(node);

						}
					}
					
					
				}
				
			}
			Node_ptr _insert(Node_ptr temp, Node_ptr newNode)
			{
				
				
				newNode->color = RED;
				if (temp == nullptr || temp == this->_end)
					return (newNode);
				if (!this->_comp(temp->key, newNode->key))
				{
					temp->left = _insert(temp->left, newNode);
					if (temp->left == newNode)
						newNode->parent = temp;
				}
				else if (this->_comp(temp->key, newNode->key))
				{
					temp->right = _insert(temp->right, newNode);
					if (temp->right == newNode)
						newNode->parent = temp;
				}
				else
					return (temp);
				
	
				
				
				// _ReSetHeight(temp);
				// temp = _reBalance(temp);
				
				return (temp);
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
			Node_ptr search(value_type key)
			{
				if(this->_root == this->_end)
					return(this->_end);
				else
				{
					return(_search(this->_root, key));
				}
			}


			//ITERATORS-----------------------------------
			Node_ptr	begin(){return(_min());}
			Node_ptr	begin() const {return(_min());}
			Node_ptr	end() {return(this->_end);}
			Node_ptr	end() const {return(this->_end);}

			Node_ptr	rbegin(){return(this->_end);}
			Node_ptr	rbegin() const {return(this->_end());}
			Node_ptr	rend(){return(this->_min());}
			Node_ptr	rend() const {return(this->_min());}


			//CAPACITY-----------------------------------
			bool		empty() const
			{
				if(this->_root == this->_end)
					return(true);
				else
					return(false);
			}
			size_type	size() const {return(this->_size);}
			size_type	max_size() const{return(std::min<size_type>(std::numeric_limits<size_type>::max() / sizeof(Node_type), std::numeric_limits<difference_type>::max()));}
			
			
			//MODIFIERS-----------------------------------
			void clear()
			{
				if(this->_root != this->_end)
				{
					_clearTree(this->_root);
					this->_size = 0;
					this->_root = this->_end;

				}
				std::cout << "destructor rbTree called but nothing is deleted until now" << std::endl;
			}
			//insert
			Node_ptr	insert(value_type const &value)
			{
				Node_ptr new_node = create_node(value);
				if(this->_root == this->_end)
				{
					this->_root = new_node;
					new_node->color = BLACK;
					this->_root->parent = this->_end;
					this->_end->left = this->_root;
					this->_size++;
				}
				else
				{
					
					this->_size++;
					new_node = _insert(this->_root, new_node);
					insertFixup(new_node);
					
				}
				return(new_node);

			}
			//erase
			void swap(rbTree& x)
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

			//LOOKUP-----------------------------------
			size_type count( const value_type& key ) const 
			{
				Node_ptr ret = search(key);
				if(ret)
					return 1;
				else
					return 0;
			}

			Node_ptr	lower_bound(const value_type& key) const
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

				while (!this->_comp(val, node->key.first))
				{
					node = successor(node);
					if (node == nullptr || node == this->_end)
					{
						return (this->_end);
					}
				}
				return (node);
			};
			//helper function to print set

			Node_ptr	_print(Node_ptr root)
			{
				
				if(root == nullptr || root == this->_end)
					return(root);

				if(root->left)
					_print(root->left);

				std::cout<<"node key is: " <<root->key;
				std::cout<<" node color is -> : "<<root->color<<std::endl;

				if (root->right)
					_print(root->right);

				return (root);

			}
			void 	print()
			{
				Node_ptr node = this->_root;
				_print(node);

			}

			

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
				y->parent = x->parent;
				x->parent = y;
				if (T2 != nullptr)
					T2->parent = x;
				// x->height = std::max(_Height(x->left), _Height(x->right)) + 1;
				// y->height = std::max(_Height(y->left), _Height(y->right)) + 1;
				return y;
			};

			Node_ptr rightRotate(Node_ptr parent)
			{
				Node_ptr child = parent->left;
				Node_ptr T2 = child->right;
				Node_ptr p = parent->parent;
				child->right = parent;
				parent->left = T2;
				if (p != this->_end)
				{
					if (p->right == parent)
						p->right = child;
					else
						p->left = child;
				}
				child->parent = parent->parent;
				parent->parent = child;
				if (T2 != nullptr)
					T2->parent = parent;
				// parent->height = std::max(_Height(parent->left), _Height(parent->right)) + 1;
				// child->height = std::max(_Height(child->left), _Height(child->right)) + 1;
				return child;
			};








			

    };


		template<class Node_ptr>
		Node_ptr _TreeMin(Node_ptr temp)
		{
			while (temp->left != nullptr)
				temp = temp->left;
			return (temp);
		};

		template<class Node_ptr>
		Node_ptr _TreeMax(Node_ptr temp)
		{
			while (temp->right != nullptr)
				temp = temp->right;
			return (temp);
		};

		template<class Node_ptr>
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

		template<class Node_ptr>
		Node_ptr predecessor(Node_ptr node)
		{
			if (node->left)
				return (_TreeMax(node->left));

			Node_ptr temp = node->parent;
			while (temp && temp->left == node)
			{
				node = temp;
				temp = temp->parent;
			}
			if (temp == nullptr)
				return (node);
			return (temp);
		};





};












#endif