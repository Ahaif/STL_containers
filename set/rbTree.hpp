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

		}
		~rbTree(){};

		private: // private
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
				if(this->_root == this->_end)
					return(this->_end);
				Node_ptr temp = this->_root;
				while(temp->left != nullptr && temp->left)
					temp = temp->left;
				return(temp);
			}
			Node_ptr _max() const
			{
				Node_ptr temp = this->_root;
				while(temp->right && temp->right != this->_end)
					temp = temp->right;
				return(temp);
			}

			Node_ptr rightRotate(Node_ptr x)
			{
				// std::cout<<"right rotate"<<std::endl;
				// std::cout<<"x is: "<<x->key<<std::endl;

				Node_ptr y = x->left;
				Node_ptr T2 = y->right;
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
				// std::cout<<"x is: "<<x->key<<std::endl;

				// std::cout<<"passed1 "<<std::endl;
				Node_ptr y = x->right;
				// std::cout<<"y is: "<<y->key<<std::endl;
				// std::cout<<"passed"<<y->key<<std::endl;

				Node_ptr T2 = y->left;
				Node_ptr p = x->parent;
				
				
				
				y->left = x;
				x->right = T2;


				// std::cout<<"p is: "<<p->parent->key<<std::endl;
				
				
				
				if (p != this->_end)
				{
					if (p->left == x)
					{
						p->left = y;
						// std::cout <<"passed"<<std::endl;
						
					}
					else
					{
						p->right = y;
						// std::cout <<"passed"<<std::endl;
					}
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
				
				while(node && node->color == RED && node->parent->color == RED)
					{
						// std::cout<<"node is: "<<node->key<<std::endl;
						if(node->parent == node->parent->parent->left)
			 			{
							Node_ptr right_uncle = node->parent->parent->right;
							if(right_uncle && right_uncle->color == RED)
							{
								// std::cout<<"case z : node uncle RED, recolor " <<std::endl;
								node->parent->color = BLACK;
								right_uncle->color = BLACK;
								node = node->parent->parent;
								if(node->parent->parent)
									node->parent->parent->color = RED;

							}
							else
							{
								// std::cout<<"case 2 : node uncle black(triangle) right-side, LR+RR+COL " <<std::endl;
								
								if(node->parent == node->parent->parent->left)
								{
									
									node = node->parent;
									// std::cout<<"node before LR is: "<<node->key<<std::endl;
									rightRotate(node);
									// std::cout<<"node after LR is: "<<node->key<<std::endl;
									// std::cout<<"node parent after LR is: "<<node->parent->key<<std::endl;
									// std::cout<<"node grand-parent after LR is: "<<node->parent->parent->key<<std::endl;
									

									
								}
								
								
								node->parent->color = BLACK;
								node->parent->parent->color = RED;
								
								
								leftRotate(node->parent);
								// std::cout<<"node after RR is: "<<node->key<<std::endl;
								// std::cout<<"node parent after RR is: "<<node->parent->key<<std::endl;
								// std::cout<<"node grand-parent after RR is: "<<node->parent->parent->key<<std::endl;
								

							}
						}
						else
						{
							Node_ptr left_uncle = node->parent->parent->left;
							if(left_uncle && left_uncle->color == RED)
							{
								// std::cout<<"case 1 : node uncle RED in right side, recolor " <<std::endl;
								node->parent->color = BLACK;
								left_uncle->color = BLACK;
								node->parent->parent->color = RED;
								node = node->parent->parent;

							}
							else
							{
								// std::cout<<"case 3 : node uncle BLACK(line) in right side, LR " <<std::endl;
								if(node->parent == node->parent->parent->right)
								{
									
									node = node->parent;
									node->color = BLACK;
									node->parent->color = RED;
									// std::cout<<"node before lr: "<<node->key<<std::endl;
									// std::cout<<"node parent before is: "<<node->parent->key<<std::endl;

									leftRotate(node->parent);
									
									// // break;
									// std::cout<<"node after lr: "<<node->key<<std::endl;
									// std::cout<<"node parent after is: "<<node->parent->key<<std::endl;
								
									
								}
							}

						}
						// node = node->parent->parent;
						this->_root->color = BLACK;
						
					}

					return(nullptr);

			}

			Node_ptr	_insert(Node_ptr newNode)
			{

				Node_ptr t = nullptr;
				Node_ptr x = this->_root;
				while(x != nullptr)
				{
					t = x;
					if(!this->_comp(x->key, newNode->key))
						x = x->left;
					else if(this->_comp(x->key, newNode->key))
						x = x->right;

				}
				newNode->parent = t;
				if(!this->_comp(t->key, newNode->key))
					t->left = newNode;
				else
					t->right = newNode;
				insertFixup(newNode);
				return(newNode);
			}
			void transplant(Node_ptr u, Node_ptr v)
			{
				
				if(u->parent == nullptr)
				{
					this->_root = v;
				}
				else if (u == u->parent->left)
				{
					u->parent->left = v;
				}
				else
				{
					
					u->parent->right = v;
					
				}
				std::cout<<"passed 2"<<std::endl;
				if(v != nullptr)
					v->parent = u->parent;
				std::cout<<"passed 3"<<std::endl;
			}

			Node_ptr _delete(Node_ptr root, Node_ptr node)
			{
				//transplant help us move subtree within rb tree (3condition)
				
				Node_ptr y = node;
				Node_ptr x = nullptr;
				int y_color = y->color;
				
				if(node->left == nullptr)
				{
					
					x = node->right;
					transplant(node, x);
					

				}
				else if (node->right == nullptr)
				{
					x = node->left;
					transplant(node, x);
				}
				else
				{
					
					y = _TreeMin(node->right);
					std::cout<<"y is: "<<y->key<<std::endl;
					y_color = y->color;
					x = y->right;

			
					

				
					if(y->parent == node)
					{
						if(x ==nullptr)
							y->parent->right = nullptr;
						else
							x->parent = y;
						std::cout<<"passed"<<std::endl;
					}
					else
					{
						transplant(y, y->right);
						y->right = node->right;
						y->right->parent = y;
					}

					
					transplant(node, y);
					y->left = node->left;
					y->left->parent = y;
					y->color = node->color;

				}
				std::cout<<"passed _remove"<<std::endl;
				
				delete node;
				// if(y->color == BLACK)
				// {
				// 	delete_Fixup(x);
				// }
				return(root);
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
				if(this->_root == this->_end)
					return(this->_end);
				else
				{
					return(_search(this->_root, key));
				}
			}


			//ITERATORS-----------------------------------
			iterator		begin()			{ return (iterator(_min()));};
			const_iterator	begin() const	{ return (const_iterator(_min()));};
			iterator		end() 			{ return (iterator(this->_end));};
			const_iterator	end() 	const 	{ return (const_iterator(this->_end));}


			reverse_iterator		rbegin()		{return(reverse_iterator(iterator(_max())));}
			const_reverse_iterator	rbegin() const {return(const_reverse_iterator(iterator(_max())));}
			reverse_iterator		rend()			{return (reverse_iterator((iterator(_min() - 1))));}
			const_reverse_iterator	rend() const 	{return(const_reverse_iterator((iterator(_min() - 1))));}


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
			}
			//insert
			Node_ptr	insert(value_type const &value)
			{
				Node_ptr new_node = create_node(value);
				if(this->_root == this->_end)
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
				return(new_node);

			}

			
			
			//erase
			void	remove(value_type const &value)
			{
				Node_ptr node = search(value);
				if(node != this->_end)
				{
					this->_root = _delete(this->_root, node);
				}
				else
					std::cout<<"node is not found"<<std::endl;
				
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

			//LOOKUP-----------------------------------
			size_type count( const value_type& key ) const 
			{
				Node_ptr ret = search(key);
				if(ret != this->_end)
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

				while (!this->_comp(val, node->key))
				{
					node = successor(node);
					if (node == nullptr || node == this->_end)
						return (this->_end);
				}
				return (node);
			};
			//helper function to print set

			Node_ptr	_print(Node_ptr root, int level)
			{
				
				if(root == nullptr || root == this->_end)
					return(root);

				_print(root->right, level + 1);
				for (int i = 0; i < level; i++)
    				std::cout << "    ";
				std::cout << root->key << "-"<<root->color <<std::endl;
				_print(root->left, level + 1);

				
				return (root);

			}
			void 	print()
			{
				Node_ptr node = this->_root;
				_print(node, 0);
				std::cout<<"the root is: "<<node->key<<std::endl;

			}	


		
	

    };
		
		template<class Node_ptr>
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
				
			
			while (temp->right && temp->right != nullptr)
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

		





};












#endif