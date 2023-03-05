/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:10:55 by ahaifoul          #+#    #+#             */
/*   Updated: 2023/02/23 18:06:59 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include <string>
#include <iterator>
#include "iterator.hpp"

#include "../iterator_traits.hpp"


namespace ft 
{
    template<class T>
	class reverse_iterator 
	{
		public:
			typedef T													iterator_type;
			typedef typename iterator_traits<T>::iterator_category		iterator_category;
			typedef typename iterator_traits<T>::value_type				value_type;
			typedef	typename iterator_traits<T>::difference_type		difference_type;
			typedef typename iterator_traits<T>::pointer				pointer;
			typedef typename iterator_traits<T>::reference				reference;

		private:
			iterator_type	_it;
        
        public : 
            reverse_iterator(): _it(nullptr){};
            explicit reverse_iterator(iterator_type X): _it(X){};
            template<class Iter>
            reverse_iterator ( const reverse_iterator<Iter>& rev_it ): _it(rev_it.base()) {};

			iterator_type			base() const							{ return (this->_it); };
			reference				operator*() const						{ return (*this->_it); };
			reverse_iterator		operator+( difference_type n ) const	{ return (reverse_iterator(this->_it - n)); };
			reverse_iterator		operator-( difference_type n ) const	{ return (reverse_iterator(this->_it + n)); };
			reverse_iterator&		operator++()							{
				
				--this->_it; return (*this); };								// pre-increment
			reverse_iterator		operator++(int)							{ reverse_iterator temp(*this); --(this->_it); return (temp); };	// post-increment
			reverse_iterator&		operator--()							{
				
				++this->_it; return (*this); };								// pre-decrement
			reverse_iterator		operator--(int)							{ 
				// std::cout<<"vvv"<<std::endl;
				reverse_iterator temp(*this); --(*this); return (temp); };	// post-decrement
			reverse_iterator&		operator+=( difference_type n )			{ this->_it -= n; return (*this); };
			reverse_iterator&		operator-=( difference_type n )			{ this->_it += n; return (*this); };
			pointer					operator->()							{ return (&(operator*())); };
			reference				operator[]( difference_type n ) const	{ return (*(this->_it + n)); };
	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); };
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); };
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); };
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); };
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); };
	template <class Iterator>
	bool operator>=  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); };



	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{ return (reverse_iterator<Iterator>( rev_it - n)); };
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); };

}







#endif 

