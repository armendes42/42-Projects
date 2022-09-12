/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:37:19 by armendes          #+#    #+#             */
/*   Updated: 2022/09/12 21:23:27 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "iterator_traits.hpp"
# include "iterator.hpp"

namespace ft
{

	template <typename T, typename Alloc = allocator<T>>
	class vector
	{
		private:

		allocator_type	_alloc;
		pointer					_begin;
		pointer					_end;
		size_type				_capacity;

		public:

		typedef T																											value_type;
		typedef Alloc																									allocator_type;
		typedef typename allocator_type::reference										reference;
		typedef typename allocator_type::const_reference							const_reference;
		typedef typename allocator_type::pointer											pointer;
		typedef typename allocator_type::const_pointer								const_pointer;
		typedef typename ft::random_access_iterator<value_type>				iterator;
		typedef typename ft::random_access_iterator<const value_type> const_iterator;
		typedef typename ft::reverse_iterator<value_type>							iterator;
		typedef typename ft::reverse_iterator<const value_type> 			const_iterator;
		typedef typename std::ptrdiff_t																difference_type;
		typedef typename std::size_t																	size_type;


		//Constructors, Destructor and Overload of =
		explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _end(NULL), _capacity(0) {};

		explicit vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _end(NULL), _capacity(n)
		{
			try
			{
				_begin = _alloc.allocate(n);
			}
			catch (std::exception &e)
			{
				throw std::length_error("ft::vector");
			}
			_end = _begin;
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_end, val);
				_end++;
			}
		};

		template <class InputIterator>
    vector(InputIterator first, InputIterator last,
    				const allocator_type& alloc = allocator_type(),
					typename ft::enable_if <>) : _alloc(alloc), _begin(NULL), _end(NULL), _capacity(0)
		{
			size_type n = ft::distance(first, last);
			_begin = _alloc.allocate(n);
			_end = _begin;
			for(size_type i = 0; i < n; i++)
			{
				_alloc.construct(_end, *first);
				_end++;
				first++;
			}
		};

		vector(const vector& x) : _alloc(x._alloc), _begin(NULL), _end(NULL), _capacity(x._capacity)
		{
			_begin = _alloc.allocate(x.size);
			_end = _begin;
			for (size_type i = 0; i < x.size; i++)
			{
				_alloc.construct(_end, x[i]);
				_end++;
			}
		};

		~vector()
		{
			clear();
			_alloc.deallocate(_begin, _capacity);
		};

		vector& operator=(const vector& x)
		{
			if (this == &x)
				return (*this);
			clear();
			insert(_end(), x._begin(), x._end());
			return (*this);
		};

		//Iterators Functions
		iterator begin()
		{
			return (_begin);
		};

		const_iterator begin() const
		{
			return (_begin);
		};

		iterator end()
		{
			if (empty())
				return (_begin);
			return (_end);
		};

		const_iterator end() const
		{
			if (empty())
				return (_begin);
			return (_end);
		};

		reverse_iterator rbegin()
		{
			return (reverse_iterator(_end));
		};

		const_reverse_iterator rbegin() const
		{
			return (reverse_iterator(_end));
		};

		reverse_iterator rend()
		{
			return (reverse_iterator(_begin));
		};

		const_reverse_iterator rend() const
		{
			return (reverse_iterator(_begin));
		};

		//Capacity Functions
		size_type size() const
		{
			size_type result;
			while (_begin && _begin != _end)
			{
				_begin++;
				_result++;
			}
			return (result);
		};

		size_type max_size() const
		{
			return (allocator_type().max_size());
		};

		void resize(size_type n, value_type val = value_type())
		{
			if (n > max_size())
				throw (std::length_error("vector::resize"));
			else if (n < size())
			{
				while (size() > n)
				{
					--_end();
					_alloc.destroy(_end)
				}
			}
			else
				insert(_end(), n - size(), val);
		};

		size_type capacity() const
		{
			return (_end_capacity - _begin);
		};

		bool empty() const
		{
			if (size() == 0)
				return (true);
			return (false);
		};

		void reserve(size_type n)
		{
			if (n > max_size())
				throw (std::length_error("vector::reserve"));
			else if (n > _capacity)
			{
				pointer ex_begin = _begin;
				pointer ex_end = _end;
				size_type ex_capacity = capacity();
				size_type ex_size = size();
				_begin = _alloc.allocate(n);
				_capacity = _begin + n;
				_end = _begin;
				while (ex_begin != ex_end)
				{
					_alloc.construct(_end, *ex_begin);
					_end++;
					ex_begin++;
				}
				_alloc.deallocate(ex_begin - ex_size, ex_capacity);
			}
		};

		//Element access
		reference operator[] (size_type n)
		{
			return (*(_begin + n));
		};

		const_reference operator[] (size_type n) const
		{
			return (*(_begin + n));
		};

		reference at (size_type n)
		{
			
		};

	};

}

#endif
