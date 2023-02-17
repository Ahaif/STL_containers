#ifndef SET_HPP
#define SET_HPP


#include <functional>

#include "iterator.hpp"
#include "rbTree.hpp"
#include "utils.hpp"




namespace ft
{
    template < class T,                        // set::key_type/value_type
           class Compare = std :: less<T>,        // set::key_compare/value_compare
           class Alloc = std :: allocator<T> >    // set::allocator_type
           class set
           {
				public:

					typedef T											key_type;
					typedef T											value_type;
					typedef	Compare										key_compare;
					typedef	Compare										value_compare;
					typedef Alloc										allocator_type;
					typedef typename allocator_type::difference_type	difference_type;
					typedef typename allocator_type::size_type			size_type;
					typedef typename allocator_type::reference			reference;
					typedef typename allocator_type::const_reference	const_reference;
					typedef typename allocator_type::pointer			pointer;
					typedef typename allocator_type::const_pointer		const_pointer;

				

				private:
					typedef Node<value_type>								Node_type;
					typedef Node_type*										Node_ptr;
					typedef rbTree<value_type, key_compare, allocator_type>	Tree_type;
					typedef Tree_type*										Tree_ptr;

				public:
					typedef typename Tree_type::iterator				iterator;
					typedef typename Tree_type::const_iterator			const_iterator;
					typedef ft::reverse_iterator<iterator>				reverse_iterator;
					typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

				private:
					Tree_type _tree;
					allocator_type	_alloc;
                	key_compare		_comp;


				public:
					//MEMBER FUNCTIONS-----------------------------------
					explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(comp, alloc), _alloc(alloc), _comp(comp)
					{
					};
					// template< class InputIt >
					// set( InputIt first, InputIt last,const Compare& comp = Compare(),const Allocator& alloc = Allocator() );

					template< class InputIt >
					set( InputIt first, InputIt last, \
					 const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					 : _tree(comp, alloc), _alloc(alloc), _comp(comp)
					{
						insert(first, last);

					}

					~set(){this->_tree.clear();}

					set& operator=( const set& x)
					{
						// this->_tree.clear();
						// for (iterator it = other.begin(); it != other.end(); ++it) {
                    	// 	insert(*it);
                		// 	}
						
							// this->_tree.clear();
							// this->_alloc = other._alloc;
							// this->_comp = other._comp;
							// insert(other.begin(), other.end());

							// return(*this);

						  _tree.clear();
                		for (const_iterator it = x.begin(); it != x.end(); ++it) {
                    		this->_tree.insert(*it);
						}
						return(*this);
                	}
						

					allocator_type get_allocator() const{
						return(allocator_type());
					}

					//ITERATORS-----------------------------------
					iterator			end() 		{return(this->_tree.end());}
					const_iterator		end() const {return(this->_tree.end());}

					iterator			begin(){return(this->_tree.begin());}
					const_iterator			begin() const {return(this->_tree.begin());}

					reverse_iterator	rbegin(){return(this->_tree.rbegin());}
					const_reverse_iterator	rbegin() const {return(this->_tree.rbegin());}

					reverse_iterator	rend(){
						return(this->_tree.rend());
						}
					const_reverse_iterator	rend() const {return(this->_tree.rend());}

					//CAPACITY-------------------------------------
					bool				empty() const{return (this->_tree.empty());}
					size_type			size() const {return(this->_tree.size());}
					size_type			max_size() const{return(this->tree.max_size());}

					//MODIFIERS-----------------------------------
					void				clear(){this->_tree.clear();}
					//insert
					ft::pair<iterator, bool> insert(const value_type& value)
					{
					 
						iterator node = iterator(this->_tree.search(value));
						if (node != end())
							return (ft::pair<iterator,bool>(node, false));
						

						Node_ptr inserted_node = this->_tree.insert(value);
						return (ft::pair<iterator,bool>(iterator(inserted_node), true));
						
					}
					template< class InputIt >
					void insert( InputIt first, InputIt last)
					{
						while (first != last)
						{
							this->_tree.insert(*first);
							first++;
						}
					}


					iterator insert( iterator pos, const value_type& value )
					{
						(void) pos;
						return (insert(value).first);

					}
					//erase
					size_type erase(iterator position )
					{
						this->_tree.remove(*position);
						return(1);
						

					}
					size_type erase( const value_type& key)
					{
						this->_tree.remove(key);
						return(1);
					}

					void				swap( set &other){this->_tree.swap(other._tree);}

					//LOOKUP--------------------------------------

					
					iterator 			find( const key_type& key) {return (iterator(this->_tree.search(key)));}
					iterator 			find( const key_type& key) const {return (const_iterator(this->_tree.search(key)));}
					
					size_type			count (const value_type& k) const	{ return (this->_tree.count(k)); };

					iterator			lower_bound( const key_type& key ){return(iterator(this->_tree.lower_bound(key)));}
					const_iterator 		lower_bound( const key_type& key ) const {return(const_iterator(this->_tree.lower_bound(key)));};
					iterator			upper_bound( const key_type& key ){return(iterator(this->_tree.upper_bound(key)));}
					const_iterator 		upper_bound( const key_type& key ) const {return(const_iterator(this->_tree.upper_bound(key)));};
					ft :: pair<const_iterator, const_iterator>	equal_range (const key_type &k)	const	{ return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); };
					ft :: pair<iterator, iterator>				equal_range (const key_type &k)			{ return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); };


					//OBESERVERS----------------------------------
					key_compare key_comp() const {return (this->_comp);}
					value_compare value_comp() const {return (this->value_compare());} 


					
					void print(){this->_tree.print();}


           };

		   //NON-MEMBERS-FUNCTIONS------------------------
		   		template <class Key,class Compare, class Alloc>
				bool operator== (const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs) { return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));};
				template <class Key,class Compare, class Alloc>
				bool operator!= (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) { return (!(lhs == rhs));};
				template <class Key, class Compare, class Alloc>
				bool operator<  (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));};
				template <class Key, class Compare, class Alloc>
				bool operator<= (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) { return (!(rhs < lhs));};
				template <class Key, class Compare, class Alloc>
				bool operator>  (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) { return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));};
				template <class Key, class Compare, class Alloc>
				bool operator>= (const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs) { return (!(lhs < rhs));};


				/*             swap                         */
				template <class Key,  class Compare, class Alloc>
				void swap  (set<Key,Compare,Alloc>& x, set<Key, Compare,Alloc>& y) { x.swap(y); };
};

#endif




