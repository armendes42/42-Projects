/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:37:19 by armendes          #+#    #+#             */
/*   Updated: 2022/09/20 14:40:09 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <exception>
# include <stdexcept>
# include "iterator_traits.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "equal.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "nullptr.hpp"
# include "lexicographical_compare.hpp"

namespace ft
{

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{

		public:

		typedef T																											value_type;
		typedef Alloc																									allocator_type;
		typedef typename allocator_type::reference										reference;
		typedef typename allocator_type::const_reference							const_reference;
		typedef typename allocator_type::pointer											pointer;
		typedef typename allocator_type::const_pointer								const_pointer;
		typedef typename ft::random_access_iterator<value_type>				iterator;
		typedef typename ft::random_access_iterator<const value_type> const_iterator;
		typedef typename ft::reverse_iterator<value_type>							reverse_iterator;
		typedef typename ft::reverse_iterator<const value_type> 			const_reverse_iterator;
		typedef typename allocator_type::size_type            size_type;
		typedef typename allocator_type::difference_type      difference_type;


		//Constructors, Destructor and Overload of =
		explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _end(NULL), _capacity(0) {};

		explicit vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _end(NULL), _capacity(n)
		{
			try
			{
				this->_begin = this->_alloc.allocate(n);
			}
			catch (std::exception &e)
			{
				throw std::length_error("ft::vector");
			}
			this->_end = this->_begin;
			for (size_type i = 0; i < n; i++)
			{
				this->_alloc.construct(this->_end, val);
				this->_end++;
			}
		};

		template <class InputIterator>
    	vector(InputIterator first, InputIterator last,
    				const allocator_type& alloc = allocator_type(),
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr_) : _alloc(alloc), _begin(NULL), _end(NULL), _capacity(0)
		{
			size_type n = ft::distance(first, last);
			this->_begin = this->_alloc.allocate(n);
			this->_end = this->_begin;
			for(size_type i = 0; i < n; i++)
			{
				this->_alloc.construct(this->_end, *first);
				this->_end++;
				first++;
			}
		};

		vector(const vector& x) : _alloc(x._alloc), _begin(NULL), _end(NULL), _capacity(x._capacity)
		{
			this->_begin = this->_alloc.allocate(x.size());
			this->_end = this->_begin;
			for (size_type i = 0; i < x.size(); i++)
			{
				this->_alloc.construct(this->_end, x[i]);
				this->_end++;
			}
		};

		~vector()
		{
			this->clear();
			this->_alloc.deallocate(this->_begin, this->_capacity);
		};

		vector& operator=(const vector& x)
		{
			if (this == &x)
				return (*this);
			this->clear();
			this->insert(this->_end, x._begin, x._end);
			return (*this);
		};

		//Iterators Functions
		iterator begin()
		{
			return (this->_begin);
		};

		const_iterator begin() const
		{
			return (this->_begin);
		};

		iterator end()
		{
			if (this->empty())
				return (this->_begin);
			return (this->_end);
		};

		const_iterator end() const
		{
			if (this->empty())
				return (this->_begin);
			return (this->_end);
		};

		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->_end));
		};

		const_reverse_iterator rbegin() const
		{
			return (reverse_iterator(this->_end));
		};

		reverse_iterator rend()
		{
			return (reverse_iterator(this->_begin));
		};

		const_reverse_iterator rend() const
		{
			return (reverse_iterator(this->_begin));
		};

		//Capacity Functions
		size_type size() const
		{
			size_type result;
			while (this->_begin && this->_begin != this->_end)
			{
				this->_begin++;
				result++;
			}
			return (result);
		};

		size_type max_size() const
		{
			return (allocator_type().max_size());
		};

		void resize(size_type n, value_type val = value_type())
		{
			if (n > this->max_size())
				throw (std::length_error("vector::resize"));
			else if (n < this->size())
			{
				while (this->size() > n)
				{
					--this->_end();
					this->_alloc.destroy(this->_end);
				}
			}
			else
				this->insert(this->_end, n - this->size(), val);
		};

		size_type capacity() const
		{
			return (this->_capacity - this->_begin);
		};

		bool empty() const
		{
			if (this->size() == 0)
				return (true);
			return (false);
		};

		void reserve(size_type n)
		{
			if (n > this->max_size())
				throw (std::length_error("vector::reserve"));
			else if (n > this->_capacity)
			{
				pointer ex_begin = this->_begin;
				pointer ex_end = this->_end;
				size_type ex_capacity = this->capacity();
				size_type ex_size = this->size();
				this->_begin = this->_alloc.allocate(n);
				this->_capacity = this->_begin + n;
				this->_end = this->_begin;
				while (ex_begin != ex_end)
				{
					this->_alloc.construct(this->_end, *ex_begin);
					this->_end++;
					ex_begin++;
				}
				this->_alloc.deallocate(ex_begin - ex_size, ex_capacity);
			}
		};

		//Element access
		reference operator[] (size_type n)
		{
			return (*(this->_begin + n));
		};

		const_reference operator[] (size_type n) const
		{
			return (*(this->_begin + n));
		};

		reference at (size_type n)
		{
			if (n >= this->size())
				throw (std::out_of_range("vector::checkRange"));
			return ((*this)[n]);
		};

		const_reference at (size_type n) const
		{
			if (n >= this->size())
				throw (std::out_of_range("vector::checkRange"));
			return ((*this)[n]);
		};

		reference front()
		{
			return (*this->_begin);
		};

		const_reference front() const
		{
			return (*this->_begin);
		};

		reference back()
		{
			return (*this->_end);
		};

		const_reference back() const
		{
			return (*this->_end);
		};

		//Modifiers Functions
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr_)
		{
			this->clear();
			size_type n = ft::distance(first, last);
			this->reserve(n);
			for (; n > 0; n--, this->_end++, first++)
			{
				this->_alloc.construct(this->_end, *first);
			}
		};

		void assign (size_type n, const value_type& val)
		{
			this->clear();
			this->reserve(n);
			for (; n > 0; n--, this->_end++)
			{
				this->_alloc.construct(this->_end, val);
			}
		};

		void push_back (const value_type& val)
		{
			size_type n = ft::distance(this->_begin, this->_end);

			if (n > this->capacity())
			{
				size_type new_size = (this->size() > 0) ? this->size() * 2 : 1;
				this->reserve(new_size);
			}
			this->_alloc.construct(this->_end, val);
			this->_end++;
		};

		void pop_back()
		{
			this->_alloc.destroy(&this->back());
			this->_end--;
		};

		iterator insert (iterator position, const value_type& val)
		{
			this->insert(position, 1, val);
			return (this->begin() + position);
		};

		void insert (iterator position, size_type n, const value_type& val)
		{
			if (this->size() + n >= this->capacity())
				reserve(this->size() + n);
			else
				reserve(this->size() * 2);
			if (position == this->_end)
			{
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}
		};

		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last)
		{

		};

		iterator erase (iterator position)
		{

		};

		iterator erase (iterator first, iterator last)
		{

		};

		void swap (vector& x)
		{
			pointer tmp_begin = this->_begin;
			pointer tmp_end = this->_end;
			size_type tmp_capacity = this->_capacity;
			allocator_type tmp_alloc = this->_alloc;

			this->_begin = x._begin;
			this->_end = x._end;
			this->_capacity = x._capacity;
			this->_alloc = x._alloc;

			x._begin = tmp_begin;
			x._end = tmp_end;
			x._capacity = tmp_capacity;
			x._alloc = tmp_alloc;

		};

		void clear()
		{
			for (size_type i = 0; i < this->capacity(); i++)
			{
				this->_alloc.destroy(this->_begin);
				this->_begin++;
			}
			this->_begin = NULL;
			this->_end = NULL;
			this->_capacity = 0;
		};

		//Allocator Function
		allocator_type get_allocator() const
		{

		};

		private:

		allocator_type	_alloc;
		pointer					_begin;
		pointer					_end;
		size_type				_capacity;

	};

	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};

	template <class T, class Alloc>
  	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	};

	template <class T, class Alloc>
  	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T, class Alloc>
  	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	};

	template <class T, class Alloc>
  	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	};

	template <class T, class Alloc>
  	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	};

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	};

}

#endif
