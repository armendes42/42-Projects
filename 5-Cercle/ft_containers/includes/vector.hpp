/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:37:19 by armendes          #+#    #+#             */
/*   Updated: 2022/10/24 17:33:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{

		public:

			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::vector_iterator<value_type>				iterator;
			typedef ft::vector_iterator<const value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename allocator_type::difference_type	difference_type;
			typedef size_t										size_type;

			explicit vector(const allocator_type& alloc = allocator_type())
			{
				this->_alloc = alloc;
				this->_size = 0;
				this->_capacity = 0;
				this->_start = NULL;
				this->_end = NULL;
			}

			explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
			{
				this->_alloc = alloc;
				this->_size = n;
				this->_capacity = n;
				this->_start = this->_alloc.allocate(n);
				this->_end = this->_start;
				
				for (size_t i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_end, val);
					this->_end++;
				}
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				this->_alloc = alloc;
				this->_size = ft::distance(first, last);
				this->_capacity = this->_size;
				this->_start = this->_alloc.allocate(this->_capacity);
				this->_end = this->_start;

				while (first != last)
				{
					this->alloc.construct(this->_end, *first);
					++first;
					this->_end++;
				}
			}

			vector (const vector& src)
			{

				size_type	n = src.size();
				pointer		tmp;

				this->_start = this->_alloc.allocate(n);
				this->_end = this->_start;
				this->_size = n;
				this->_capacity = n;
				tmp = src._start;

				while (0 < n) {

					this->_alloc.construct(this->_end++, *tmp++);
					n--;
				}
			}

			virtual ~vector()
			{
				this->clear();
				this->_alloc.deallocate(this->_start, this->_capacity);
			}

			vector& operator=(const vector& x)
			{
				if (*this == rhs)
					return (*this);
				this->clear();
				this->insert(this->end(), x.begin(), x.end());
				return (*this);
			}

			iterator begin()
			{
				return (iterator(this->_start));
			}

			const_iterator begin() const
			{
				return (const_iterator(this->_start));
			}

			iterator end()
			{
				return (iterator(this->_end));
			}

			const_iterator end() const
			{
				return (const_iterator(this->_end));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->_end));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->_end));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(this->_start));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->_start));
			}

			size_type size() const
			{
				return (this->_size);
			}

			size_type max_size() const
			{
				return (this->_alloc.max_size());
			}

			void resize(size_type n, value_type val = value_type())
			{
				if (n < this->_size)
				{
					while (n < this->_size)
					{
						this->_size--;
						this->_alloc.destroy((this->_start + this->_size));
					}
				}
				else
				{
					if (n <= this->_capacity)
						;
					else if (n <= this->_size * 2)
						this->reserve(this->_size * 2);
					else
						this->reserve(size);
					while (this->_size < n)
					{
						this->_alloc.construct(this->_start + this->_size, val);
						this->_size++;
					}
				}
				this->_end = this->_start + this->_size;
			}

			size_type capacity() const
			{
				return (this->_capacity);
			}

			bool empty() const
			{
				if (this->_size == 0)
					return (true);
				return (false);
			}

			void reserve (size_type capacity)
			{
				vector		res;
				iterator	itBegin = this->begin();
				iterator	itEnd = this->end();

				if (capacity > this->max_size())
					throw std::length_error("Error : Alloc size is greater than max_size");
				if (capacity <= this->capacity())
					return ;
				difference_type len = ft::distance(itBegin, itEnd);
				if (capacity < (size_t)len)
					throw std::bad_alloc();
				res._alloc = this->_alloc;
				res._size = len;
				res._capacity = capacity;
				res._start = res._alloc.allocate(capacity);
				res._end = res._start + res._size;
				for (size_type i = 0; itBegin != itEnd; ++itBegin)
				{
					res._alloc.construct(res._start + i, *itBegin);
					i++;
				}
				if (this->_start != NULL)
				{
					this->clear();
					this->_alloc.deallocate(this->_start, this->_capacity);
					this->_start = NULL;
					this->_size = 0;
					this->_capacity = 0;
				}
				this->_alloc = res._alloc;
				this->_start = res._start;
				this->_end = res._end;
				this->_size = res._size;
				this->_capacity = res._capacity;
				res._start = NULL;
				res._size = 0;
				res._capacity = 0;
			}

			reference operator[] (size_type n)
			{
				return (this->start[n]);
			}

			const_reference operator[] (size_type n) const
			{
				return (this->start[n]);
			}

			reference at (size_type n)
			{
				if (n >= this->size())
					throw std::out_of_range("vector::checkRange");
				return (this->_start[n]);
			}

			const_reference at (size_type n) const
			{
				if (n >= this->size())
					throw std::out_of_range("vector::checkRange");
				return (this->_start[n]);
			}

			reference front()
			{
				return (*(this->_start));
			}

			const_reference front() const
			{
				return (*(this->_start));
			}

			reference back()
			{
				return (*(this->_end - 1));
			}

			const_reference back() const
			{
				return (*(this->_end - 1));
			}

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
		}

		void assign (size_type n, const value_type& val)
		{
			clear();
			reserve(n);
			for (; n > 0; --n, ++_end)
			{
				_alloc.construct(_end, val);
			}
		}

		void push_back (const value_type& val)
		{
			if (_end == _capacity)
				reserve(size() > 0 ? size() * 2 : 1);
			_alloc.construct(_end, val);
			++_end;
		}

		void pop_back()
		{
			_alloc.destroy(_end);
			--_end;
		}

		iterator insert (iterator position, const value_type& val)
		{
			insert(position, 1, val);
			return (iterator(position));
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type pos = ft::distance(begin(), position);

			resize(size() + n);
			position = begin() + pos;
			
			size_type toMoveRight = ft::distance(position, end() - n);
			pointer oldEnd = _end - n - 1;
			for (size_type i = 0; i < toMoveRight; i++) {
				*(_end - i - 1) = *oldEnd--;
			}
			for (size_type i = 0; i < n; i++) {
				*(position + i) = val;
			}
		}

		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr_)
		{
			size_type pos = ft::distance(begin(), position);
			size_type n = ft::distance(first, last);

			resize(size() + n);
			position = begin() + pos;
			
			size_type toMoveRight = ft::distance(position, end() - n);
			pointer oldEnd = _end - n - 1;
			for (size_type i = 0; i < toMoveRight; i++) {
				*(_end - i - 1) = *oldEnd--;
			}
			for (size_type i = 0; i < n && first != last; i++, first++) {
				*(position + i) = *first;
			}
		}
		
		iterator erase (iterator position)
		{
			iterator pos = position;
			size_type toDestroyPos = ft::distance(begin(), position);

			_alloc.destroy(_begin + toDestroyPos);

			for (; pos + 1 != end(); ++pos)
				*pos = *(pos + 1);
			--_end;
			return iterator(position);
		}

		iterator erase (iterator first, iterator last)
		{
			for (; first != last; --last)
				erase(first);
			return iterator(first);
		}

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

		}

		void clear()
		{
			const size_type size = this->size();

			for (size_type i = 0; i < size; ++i)
			{
				--_end;
				_alloc.destroy(_end);
			}
		}

		//Allocator Function
		allocator_type get_allocator() const
		{
			return (allocator_type());
		}

		private:

			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			pointer			_start;
			pointer			_end;

	};

	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
  	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
  	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
  	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
  	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
  	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

};

#endif
