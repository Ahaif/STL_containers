
#ifndef ITERATOR_HPP
#define ITERATOR_HPP


#include "vector.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include <iostream>
#include <string>
#include <iterator>
#include "utils.hpp"

namespace ft 
{
    template<class T>
    class vecIter 
    {
        public : 
            typedef T													iterator_type;
			typedef typename iterator_traits<T>::iterator_category		iterator_category;
			typedef typename iterator_traits<T>::value_type				value_type;
			typedef	typename iterator_traits<T>::difference_type		difference_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef typename iterator_traits<T>::reference				reference;

        private :
            iterator_type _it;
	    public:
			vecIter(): _it(nullptr) {};
			explicit	vecIter( iterator_type x ): _it(x) {};
			template <class Iter>
			vecIter ( const vecIter<Iter>& vec_it ): _it(vec_it.base()) {};
            

			iterator_type	base() const							{ return (this->_it); };
			reference		operator*() const						{ return (*this->_it); };
			vecIter			operator+( difference_type n ) const	{ return (vecIter(this->_it + n)); }; 				
			vecIter			operator-( difference_type n ) const	{ return (vecIter(this->_it - n)); };				
			vecIter&		operator++()							{++this->_it; return (*this); };					// pre-increment
			vecIter			operator++(int)							{ vecIter temp(*this); ++(*this); return (temp); }; // post-increment
			vecIter&		operator--()							{--this->_it; return (*this); };					// pre-decrement
			vecIter			operator--(int)							{ vecIter temp(*this); --(*this); return (temp); };	// post-decrement
			vecIter&		operator+=( difference_type n )			{ this->_it += n; return (*this); };
			vecIter&		operator-=( difference_type n )			{ this->_it -= n; return (*this); };
			pointer			operator->()							{ return (&(operator*())); };
			reference		operator[]( difference_type n ) const	{ return (*(this->_it + n)); };
    };
	// free function that takes two arguments, both of which are iterators
	
    template<class Iterator1, class Iterator2>
    bool    operator==(const vecIter<Iterator1> &lhs, const vecIter<Iterator2> &rhs){ return (lhs.base() == rhs.base()); };
    template <class Iterator1, class Iterator2>
	bool    operator!= (const vecIter<Iterator1>& lhs, const vecIter<Iterator2>& rhs) { return (lhs.base() != rhs.base()); };
	template <class Iterator1, class Iterator2>
	bool operator<  (const vecIter<Iterator1>& lhs, const vecIter<Iterator2>& rhs) { return (lhs.base() < rhs.base()); };
	template <class Iterator1, class Iterator2>
	bool operator<= (const vecIter<Iterator1>& lhs, const vecIter<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); };
	template <class Iterator1, class Iterator2>
	bool operator>  (const vecIter<Iterator1>& lhs, const vecIter<Iterator2>& rhs) { return (lhs.base() > rhs.base()); };
	template <class Iterator1, class Iterator2>
	bool operator>=  (const vecIter<Iterator1>& lhs, const vecIter<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); };

    template <class Iterator>
	vecIter<Iterator> operator+ (typename vecIter<Iterator>::difference_type n, const vecIter<Iterator>& vec_it)
	{ return (vecIter<Iterator>( vec_it + n)); };
	template <class Iterator>
	typename vecIter<Iterator>::difference_type operator- (const vecIter<Iterator>& lhs, const vecIter<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); };

};

#endif