#ifndef SET_HPP
#define SET_HPP

#include <functional>

namespace ft
{
    template < class T,                        // set::key_type/value_type
           class Compare = std :: less<T>,        // set::key_compare/value_compare
           class Alloc = std :: allocator<T> >    // set::allocator_type
           class set
           {
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
        


           };
    


};



#endif




