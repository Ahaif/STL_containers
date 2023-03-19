/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:10:51 by ahaifoul          #+#    #+#             */
/*   Updated: 2023/03/19 09:24:37 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iterator>
#include <string>
#include <iostream>

namespace ft
{
    template<class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;  
    };

    template <class T>
    struct iterator_traits<T*>
    {
        typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
        typedef std::random_access_iterator_tag	iterator_category;
    };

    template <class T>
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
        typedef std::random_access_iterator_tag	iterator_category;
    };
};

#endif