#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "set.hpp"

namespace ft
{
    template<class T>
    struct Node
    {
        public:
			typedef T				value_type;
		public:
			T		key;
			Node*	parent;
			Node*	left;
			Node*	right;
			int		height;

		public:
			Node(): key() {};
			Node(T key): key(key){};
    };
    template <class T, class Compare, class Allocator>
	class Tree
    {

    };






};












#endif