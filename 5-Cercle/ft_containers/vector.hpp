/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:37:19 by armendes          #+#    #+#             */
/*   Updated: 2022/09/20 17:03:09 by armendes         ###   ########.fr       */
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
		explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(nullptr_), _end(nullptr_), _capacity(nullptr_) {};

		explicit vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(nullptr_), _end(nullptr_), _capacity(nullptr_)
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
			for (size_t i = 0; i < n; ++i, ++_end)
			{
				this->_alloc.construct(this->_end, val);
			}
			_capacity = _end;
		};

		template <class InputIterator>
    	vector(InputIterator first, InputIterator last,
    				const allocator_type& alloc = allocator_type(),
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr_) : _alloc(alloc), _begin(nullptr_), _end(nullptr_), _capacity(nullptr_)
		{
			difference_type n = ft::distance(first, last);
			_begin = _alloc.allocate(n);
			_capacity = _begin + n;
			_end = _begin;
			for(; n > 0; --n, ++_end, ++first)
			{
				_alloc.construct(_end, *first);
			}
		};

		vector(const vector& x) : _alloc(x._alloc), _begin(nullptr_), _end(nullptr_), _capacity(nullptr_)
		{
			insert(begin(), x.begin(), x.end());
		};

		~vector()
		{
			if (_begin != nullptr_)
			{
				clear();
				_alloc.deallocate(_begin, capacity());
			}
		};

		vector& operator=(const vector& x)
		{
			if (this == &x)
				return (*this);
			clear();
			insert(end(), x.begin(), x.end());
			return (*this);
		};

		//Iterators Functions
		iterator begin()
		{
			return (iterator(_begin));
		};

		const_iterator begin() const
		{
			return (const_iterator(_begin));
		};

		iterator end()
		{
			return (iterator(_end));
		};

		const_iterator end() const
		{
			return (const_iterator(_end));
		};

		reverse_iterator rbegin()
		{
			return (reverse_iterator(_end));
		};

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(_end));
		};

		reverse_iterator rend()
		{
			return (reverse_iterator(_begin));
		};

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_begin));
		};

		//Capacity Functions
		size_type size() const
		{
			return static_cast<size_type>(_end - _begin);
		};

		size_type max_size() const
		{
			return (allocator_type().max_size());
		};

		void resize(size_type n, value_type val = value_type())
		{
			const size_type cap = capacity();
			size_type old_size = size();

			if (n > max_size())
				throw (std::length_error("vector::resize"));
			else if (n < size())
			{
				while (size() > n)
					_alloc.destroy(--_end);
			}
			else
			{
				if (n > cap)
				{
					if ((cap * 2) >= n)
						reserve(cap * 2);
					else
						reserve(n);
				}
				for (; old_size < n; ++old_size, ++_end)
					_alloc.construct(_end, val);
			}
		};

		size_type capacity() const
		{
			return static_cast<size_type>(_capacity - _begin);
		}

		bool empty() const
		{
			return (size() == 0);
		};

		void reserve(size_type n)
		{
			pointer old_begin = _begin;
			pointer tmp_begin = _begin;
			pointer old_end = _end;
			const size_type old_cap = capacity();

			if (n > max_size())
				throw (std::length_error("vector::reserve"));
			if (n > capacity())
			{
				_begin = _alloc.allocate(n, old_begin);
				_capacity = _begin + n;
				_end = _begin;
				for (; tmp_begin != old_end; ++end, ++tmp_begin)
					_alloc.construct(_end, *tmp_begin);
				_alloc.deallocate(old_begin, old_cap);
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
			if (n >= size())
				throw (std::out_of_range("vector::checkRange"));
			return (*(_begin + n));
		};

		const_reference at (size_type n) const
		{
			if (n >= size())
				throw (std::out_of_range("vector::checkRange"));
			return (*(_begin + n));
		};

		reference front()
		{
			return (*_begin);
		};

		const_reference front() const
		{
			return (*_begin);
		};

		reference back()
		{
			return (*(_end - 1));
		};

		const_reference back() const
		{
			return (*(_end - 1));
		};

		//Modifiers Functions
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr_)
		{
			clear();
			reserve(ft::distance(first, last));
			for (; first != last; ++_end, ++first)
			{
				_alloc.construct(_end, *first);
			}
		};

		void assign (size_type n, const value_type& val)
		{
			clear();
			reserve(n);
			for (; n > 0; --n, ++_end)
			{
				_alloc.construct(_end, val);
			}
		};

		void push_back (const value_type& val)
		{
			if (_end == _capacity)
				reserve(size() > 0 ? size() * 2 : 1);
			_alloc.construct(_end, val);
			++_end;
		};

		void pop_back()
		{
			_alloc.destroy(_end);
			--_end;
		};

		iterator insert (iterator position, const value_type& val)
		{
			insert(position, 1, val);
			return (iterator(position));
		};

		void insert (iterator position, size_type n, const value_type& val)
		{
			const difference_type size = ft::distance(begin(), position);

			resize(size() + n);
			position = begin() + size;

			size_type rhs = ft::distance(position, end() - n);
			pointer old_end = _end - n - 1;

			for (size_type i = 0; i < rhs; ++i, --old_end)
				*(_end - i - 1) = *old_end;

			for (size_type i = 0; i < n; ++i)
				position[i] = val;
		}

		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr_)
		{
			const difference_type size = ft::distance(begin(), position);
			const size_type n = ft::distance(first, last);

			resize(size() + n);
			position = begin() + size;

			size_type rhs = ft::distance(position, end() - n);
			pointer  old_end = _end - n - 1;
			for (size_type i = 0; i < rhs; ++i, --old_end)
				*(_end - i - 1) = *old_end;
			for (size_type i = 0; i < n && first != last; ++i, ++first)
				position[i] = *first;
		};
		
		iterator erase (iterator position)
		{
			iterator ret = position;

			for (; position != end(); ++position)
			{
				_alloc.destroy(&*position);
				_alloc.construct(&*position, *(position + 1));
			}
			--_end;
			return (ret);
		};

		iterator erase (iterator first, iterator last)
		{
			iterator ret = first;

			for (; first != last; --last)
				erase(first);
			return (ret);
		};

		void swap (vector& x)
		{
			if (this == &x)
				return ;

			pointer tmp_begin = _begin;
			pointer tmp_end = _end;
			size_type tmp_capacity = _capacity;
			allocator_type tmp_alloc = _alloc;

			_begin = x._begin;
			_end = x._end;
			_capacity = x._capacity;
			_alloc = x._alloc;

			x._begin = tmp_begin;
			x._end = tmp_end;
			x._capacity = tmp_capacity;
			x._alloc = tmp_alloc;

		};

		void clear()
		{
			const size_type size = size();

			for (size_type i = 0; i < size; ++i)
			{
				--_end;
				_alloc.destroy(_end);
			}
		};

		//Allocator Function
		allocator_type get_allocator() const
		{
			return (allocator_type());
		};

		private:

		allocator_type	_alloc;
		pointer					_begin;
		pointer					_end;
		pointer					_capacity;

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
