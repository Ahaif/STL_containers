/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <ahaifoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:10:58 by ahaifoul          #+#    #+#             */
/*   Updated: 2023/03/19 09:14:08 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <limits>
#include "iterator.hpp"
#include "utils.hpp"
#include "reverse_iterator.hpp"

namespace ft 
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:       /*        Members Type   */
            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type :: reference        reference;
            typedef typename allocator_type :: const_reference  const_reference;
            typedef typename allocator_type :: pointer          pointer;
            typedef typename allocator_type :: const_pointer    const_pointer;
            typedef typename allocator_type :: size_type        size_type;
            typedef typename allocator_type :: difference_type	difference_type;
            typedef vecIter<pointer>                            iterator;
            typedef vecIter<const_pointer>						const_iterator;
            typedef ft::reverse_iterator<pointer>				reverse_iterator;
			typedef ft::reverse_iterator<const_pointer>			const_reverse_iterator;


        private:     /*        Vector Staff      */
            allocator_type      _alloc;
            value_type*         _vec;
            size_type           _size;
            size_type           _capacity;


        public :   /*   Constructors   */
            explicit vector (const allocator_type& alloc = allocator_type()): 
                _alloc(alloc), _vec(nullptr), _size(0), _capacity(0) {};

            explicit vector (size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type()) :
                 _alloc(alloc), _vec(nullptr), _size(0), _capacity(0) 
            {
                assign(n, val);
            };

            // check if enable if is necessary
            template <class InputIterator>
            vector (InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,const allocator_type& alloc = allocator_type()):
                    _alloc(alloc), _vec(nullptr), _size(0), _capacity(0)
            {
                    assign(first, last);
            };


            vector (const vector& x): _vec(nullptr), _size(0), _capacity(0)
             { *this = x;};

            //DESTRUCTORS
        public:
            ~vector(){
                    clear();
                    _alloc.deallocate(_vec, _capacity);
               };

        public: /*             operator =                         */
			vector& operator= (const vector& x)
			{
				if (this != &x)
				{
					this->_alloc = x._alloc;
					assign(x.begin(), x.end());
					this->_size = x._size;
					this->_capacity = x._capacity;
				}
				return (*this);
			};
         

        public :  /*   MODIFERS  */
            void assign (size_type n, const value_type& val)
            {
                try{
                
                    clear();
                    if (n > capacity())
                    {
                        this->_alloc.deallocate(this->_vec, capacity());
                        this->_vec = this->_alloc.allocate(n);
                        this->_capacity = n;
                    }
                    for (size_t i = 0; i < n; i++)
                    {
                        this->_alloc.construct(this->_vec + i, val);
                        _size++;

                    }
                }
                catch(const std::bad_alloc& e)
                {
                    clear();
                    this->_alloc.deallocate(this->_vec, capacity());
                }
            }

            template <class InputIterator>
            void assign(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
            {
                try{
                        difference_type len = last - first;
                        clear();
                        if (static_cast<unsigned long>(len) > capacity())
                        {
                            this->_alloc.deallocate(this->_vec, capacity());
                            this->_vec = this->_alloc.allocate(len);
                            this->_capacity = len;
                        
                            
                        }
                        for (long i = 0; i < len; i++)
                        {
                            try{
                                this->_alloc.construct(this->_vec + i, *(first + i));
                                this->_size++;
                            }
                             catch(...)
                            {
                                clear();
                                this->_alloc.deallocate(this->_vec, capacity());
                                throw;
                            }
                        }

                    this->_size = len;  
                }
                catch(const std::bad_alloc& e)
                {
                    clear();
                    this->_alloc.deallocate(this->_vec, capacity());
                }
  
            }

            iterator insert (iterator position, const value_type& val)
            {
                difference_type diff = end() - position;
				if (this->_size == this->_capacity)
						reserve(capacity() * 2);
				iterator	it = end();
				while (diff != 0)
				{
					*(it) = *(it - 1);
					it--;
					diff--;
				}
				*(it) = val;
				++this->_size;
				return (it);
            };

            void insert (iterator position, size_type n, const value_type& val)
            {
                difference_type diff = end() - position;
				difference_type posIndex = position - begin();
				if (size() + n > capacity())
				{
					if (size() + n > capacity() * 2)
						reserve(size() + n);
					else
						reserve(capacity() * 2);
				}
				iterator it = end() - 1;
				for (size_t i = 0; i < diff; i++)
				{
					*(it + n) = *(it);
					it--;
				}
				it = begin() + posIndex;
				for (size_t i = 0; i < n; i++)
				{
					*(it + i) = val;
				}
				this->_size += n;
            };

           template <class InputIterator>
            void insert (iterator position, InputIterator first,typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
            {

                try{
                        
                        vector tmp(first, last);
    
                        if (tmp.size() == 0)
                            return;

                        if (first > last || ((position <= begin()) && (position > end())))
                            return;
         
                        difference_type	diff = end() - position;
                        difference_type	len	= last - first;
                        difference_type posIndex = position - begin();
                        
                        if (size() + len > capacity())
                        {
                            if (size() + len > capacity() * 2)
                                reserve(size() + len);
                            else
                                reserve(capacity() * 2);
                        }
                        iterator it = end() - 1;
                        for (long i = 0; i < diff; i++)
                        {
                            *(it + len) = *(it);
                            it--;
                        }
                        it = begin() + posIndex;
                        int i = 0;
                        for (; i < len; i++)
                            *(it + i) = *(first++);
                        _size = _size + len;
                }
                catch(const std::bad_alloc& e)
                {
                    clear();
                    this->_alloc.deallocate(this->_vec, _capacity);
                }
        
            }

            void clear()
			{
                while (_size != 0)
                    pop_back();
			};

            void push_back (const value_type& val)
            {
                if (this->_size == this->_capacity)
					reserve(capacity() * 2);
				if (this->_vec == NULL)
					reserve(1);
				this->_alloc.construct(this->_vec + this->_size, val);
				++this->_size;
            }

            void pop_back()
            {
                this->_alloc.destroy(this->_vec + this->_size);
                --this->_size;
            }

            void swap (vector& x)
			{
       
				std::swap(x._size, this->_size);
				std::swap(x._capacity, this->_capacity);
				std::swap(x._alloc, this->_alloc);
				std::swap(x._vec, this->_vec);
			};

            iterator erase (iterator position)
            {
                iterator it = position;
				this->_alloc.destroy(it.base());
				while (it != end() - 1)
				{
					*(it) = *(it + 1);
					it++;
				}
				this->_size--;
				return (position);
            };

            iterator erase (iterator first, iterator last)
            {
               
                if (last < first || first < begin() || last > end()) {
                    return end();
                }
                difference_type	len = last - first;
                iterator it = first;
                while (last != end()) {
                    *it = std::move(*last);
                    ++it;
                    ++last;
                }

                for (; it != end(); ++it) {
                    _alloc.destroy(it.base());
                }
                _size -= len;
                return first;

            };
            

         public : /*   ------CAPACITY-------------  */
            size_type   capacity()    const   {return this->_capacity;};
            size_type   size()        const   { return this->_size; };
            bool        empty()       const	  { return (!this->_size); };
            size_type   max_size() const{ return (std::min<size_type>(std::numeric_limits<size_type>::max() / sizeof(value_type), std::numeric_limits<difference_type>::max())); };
            void        reserve (size_type n)
            {
                if (n > capacity())
                {
                    value_type*		temp = this->_alloc.allocate(n);
                    if (this->_vec != NULL)
                    {
                        for (size_t i = 0; i < size(); i++)
                        {
                            this->_alloc.construct(temp + i, this->_vec[i]);
                            this->_alloc.destroy(this->_vec + i);
                        }
                        this->_alloc.deallocate(this->_vec, capacity());
                    }
                    this->_capacity = n;
                    this->_vec = temp;
                   
                }
            };

            void    resize (size_type n, value_type val = value_type())
            {
               
                if (n != this->_size)
                {
                    value_type* temp = this->_alloc.allocate(n);
                    if (n < this->_size)
                    {
                        for (size_t i = 0; i < n; i++)
                            this->_alloc.construct(temp + i, this->_vec[i]);
                        for (int i = 0; i < size(); i++) 
                            this->_alloc.destroy(&this->_vec[i]);
                
                        this->_alloc.deallocate(this->_vec, capacity());
                        this->_size = n;
                        this->_vec = temp;
                    
                    }
                    else if (n > this->_size)
                    {
                        if (n > this->_capacity)
                            this->_capacity = _capacity * 2;
                        for(size_t i = 0; i < this->_size; i++)
                        {
                            this->_alloc.construct(temp + i, this->_vec[i]);
                            this->_alloc.destroy(&this->_vec[i]);
                        }
                        this->_alloc.deallocate(this->_vec, capacity());
                        for (size_t i; i < n; i++)
                            this->_alloc.construct(temp + i, val);
                        this->_size = n;
                        
                        this->_vec = temp;
                    }
                    
                }
            }

            // ------ACCESS ELEM-------------
            reference       operator[] (size_type n) { return (this->_vec[n]); };
		    const_reference operator[] (size_type n) const { return (this->_vec[n]); };
            reference       at         (size_type n)
			{
				if (n >= size())
					throw std::out_of_range("vector");
				return (this->_vec[n]);
			};
			const_reference at         (size_type n) const
			{
				if (n >= size())
					throw std::out_of_range("vector");
				return (this->_vec[n]);
			};
            reference       front() { return (this->_vec[0]); };
			const_reference front() const { return (this->_vec[0]); };
			reference       back() { return (this->_vec[this->_size - 1]); };
			const_reference back() const { return (this->_vec[this->_size - 1]); };

        //  /*-----Iterators-----*/
            iterator	           begin()        {return (iterator(this->_vec)); };
            const_iterator         begin()  const {return (const_iterator(this->_vec)); };
            iterator               end()          {return (iterator(begin() + size())); };
            const_iterator         end()    const {return (const_iterator(begin() + size())); }
            reverse_iterator       rbegin()       {return (reverse_iterator((end() - 1).base())); };
            const_reverse_iterator rbegin() const {return (const_reverse_iterator((end() - 1).base())); };
            reverse_iterator       rend()         {return (reverse_iterator((begin() - 1).base())); };
            const_reverse_iterator rend()   const {return (const_reverse_iterator((begin() - 1).base())); };


        public: // ----- get_allocator----
            allocator_type get_allocator() const {return(this->_alloc);};

    };


    //swap
    template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	};

    	/*             relational operators                         */
 
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));};
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs));};
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));};
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs));};
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));};
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs));};

};

#endif