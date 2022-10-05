/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:37:19 by armendes          #+#    #+#             */
/*   Updated: 2022/10/05 19:12:58 by armendes         ###   ########.fr       */
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

			typedef T	value_type;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer	pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef ft::random_access_iterator<value_type>	iterator;
			typedef ft::random_access_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef size_t	size_type;
			typedef std::ptrdiff_t	difference_type;

		private:
		
			T *_array;
			A _alloc;
			size_type _size;
			size_type  _allocSize;

		public:

			//Constructors, Destructor and Overload of =
			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
				_array = _alloc.allocate(0);
				_allocSize = 0;
				_size = 0;
			};

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n)
			{
				_allocSize = n;
				_array = _alloc.allocate(n);
				for(size_type i = 0; i < n; i++) {
					_alloc.construct(&_array[i], val);
					}
			};

			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
						const allocator_type& alloc = allocator_type(),
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) : _alloc(alloc)
			{
				_array = NULL;
				_size = 0;
				_allocSize = 0;
				assign(first, last);
			};

			vector(const vector& x) : _alloc(x._alloc)
			{
				_array = NULL;
				_size = 0;
				_allocSize = 0;
				*this = x;
			};

			~vector()
			{
				clear();
				_alloc.deallocate(_begin, capacity());
			};

			vector& operator=(const vector& x)
			{
				assign(x.begin(), x.end());
				return (*this);
			};

			//Iterators Functions
			iterator begin()
			{
				return (_array);
			};

			const_iterator begin() const
			{
				return (_array);
			};

			iterator end()
			{
				return (_array + _size);
			};

			const_iterator end() const
			{
				return (_array + _size);
			};

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			};

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			};

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			};

			//Capacity Functions
			size_type size() const
			{
				return (_size);
			};

			size_type max_size() const
			{
				return (allocator_type().max_size());
			};

			void resize(size_type n, value_type val = value_type())
			{
				if (size < this->_size)
				{
					while (size < this->_size)
						this->_alloc.destroy(&this->_array[--this->_size]);
				}
				else
				{
					size_type const &tmp = this->_size;

					if (size <= this->_allocSize)
						;
					else if (size <= tmp * 2)
						this->reserve(tmp * 2);
					else
						this->reserve(size);
					while (this->_size < size)
						this->_alloc.construct(&this->_array[this->_size++], val);
				}
			};

			size_type capacity() const
			{
				return (_allocSize);
			}

			bool empty() const
			{
				return (_size == 0 ? true : false);
			};

			void reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("vector::reserve");
				size_type y = -1;
				if (_allocSize < n)
				{
					T *newArr = _alloc.allocate(n + 1);
					while (++y <= n && y < size())
					{
						_alloc.construct(&newArr[y], _array[y]);
						_alloc.destroy(_array + y);
					}
					_alloc.deallocate(_array, size());
					_allocSize = n;
					_array = newArr;
				}
			};

			//Element access
			reference operator[] (size_type n)
			{
				return (_array[n]);
			};

			const_reference operator[] (size_type n) const
			{
				return (_array[n]);
			};

			reference at (size_type n)
			{
				std::stringstream str;
				if (pos > size())
				{
					str << "vector::_M_range_check: __n (which is " << pos << ") >= size() (which is " << size() << ")";
					throw std::out_of_range(str.str());
				}
				else
					return (_array[pos]);
			};

			const_reference at (size_type n) const
			{
				std::stringstream str;
				if (pos > size())
				{
					str << "vector::_M_range_check: __n (which is " << pos << ") >= size() (which is " << size() << ")";
					throw std::out_of_range(str.str());
				}
				else
					return (_array[pos]);
			};

			reference front()
			{
				return (*(begin()));
			};

			const_reference front() const
			{
				return (*(begin()));
			};

			reference back()
			{
				return (*(end() - 1));
			};

			const_reference back() const
			{
				return (*(end() - 1));
			};

			//Modifiers Functions
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				clear();
				insert(begin(), first, last);
			};

			void assign (size_type n, const value_type& val)
			{
				clear();
        		resize(n, val);
			};

			void push_back (const value_type& val)
			{
				if (_size + 1 > _allocSize)
				{
					if (_size > 0)
						reserve(_size * 2);
					else
						reserve(1);
				}
				_alloc.construct(&_array[_size], val);
				_size++;
			};

			void pop_back()
			{
				erase(end() - 1);
			};

			iterator insert (iterator position, const value_type& val)
			{
				difference_type delta = pos - begin();
				insert(pos, 1, value);
				return (begin() + delta);
			};

			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type		len = position - this->begin();

				if (_size + n > _allocSize)
				{
					if (_size + n > _allocSize * 2)
						this->reserve(_size + n);
					else if (_size > 0)
					{
						if (_size == 0)
							reserve(n);
						this->reserve(_size * 2);
					}
					else
						this->reserve(1);
				}
				for (size_type i = 0 ; i < n ; i++)
					_alloc.construct(_array + _size + i, val);
				for (int i = _size - 1 ; i >= 0 && i >= (int)len ; i--)
					_array[i + n] = _array[i];
				for (size_type i = len ; i < len + n ; i++)
					_array[i] = val;
				_size = _size + n;
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				size_type len = position - this->begin();
				size_type n = 0;

				for (InputIT tmp = first ; tmp != last && n <= this->max_size() ; tmp++)
					n++;
				if (_size + n > _allocSize)
				{
					if (_size + n > _allocSize * 2)
						this->reserve(_size + n);
					else if (_size >= 0)
					{
						if (_size == 0)
							reserve(n);
						this->reserve(_size * 2);
					}
					else
						this->reserve(1);
				}
				for (size_type i = 0 ; i < n ; i++)
					_alloc.construct(_array + _size + i, *first);
				for (int i = _size - 1 ; i >= 0 && i >= (int)len ; i--)
					_array[i + n] = _array[i];
				for (size_type i = len ; i < len + n ; i++)
					_array[i] = *first++;
				_size = _size + n;
			};
			
			iterator erase (iterator position)
			{
				return (erase(pos, pos + 1));
			};

			iterator erase (iterator first, iterator last)
			{
				iterator ret = first;
				size_t len = last - first;
				iterator end = this->end();

				while (last != end)
				{
					*first = *last;
					++first; ++last;
				}
				while (len-- > 0)
					_alloc.destroy(&_array[--_size]);
				return (ret);
			};

			void swap (vector& x)
			{
				if (this == &x)
					return ;

				pointer tmp_begin = _begin;
				pointer tmp_end = _end;
				pointer tmp_capacity = _capacity;
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
				if (empty())
					return ;
				erase(begin(), end());
			};

			//Allocator Function
			allocator_type get_allocator() const
			{
				return (_alloc);
			};

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
