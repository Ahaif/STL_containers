/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:35:52 by ahaifoul          #+#    #+#             */
/*   Updated: 2023/02/06 11:48:02 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP


#include "set.hpp"

namespace ft
{
    template<class T1,class T2> 
    struct pair
    {
            typedef  T1 first_type;
            typedef  T2 second_type;

            first_type first;
            second_type second;

            explicit pair(): first(), second() {};
            pair( const T1& x, const T2& y ): first(x), second(y){};
            template< class U1, class U2 >
            pair( const pair<U1, U2>& p ): first(p.first), second(p.second){};

            template<class U, class V>
		    pair<U,V>& operator= (const pair<U,V>& pr)
		    {
			    if (this != &pr)
			    {
				    this->first = pr.first;
				    this->second = pr.second;
			    }
			    return (*this);
		    };
    };

            	/*             relational operators of pair                         */
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); };
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); };
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); };
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs<lhs); };
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs<lhs; };
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs<rhs); };

	/*             make_pair function                         */
	template <class T1,class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y) { return (ft::pair<T1,T2>(x,y)); };

}

#endif