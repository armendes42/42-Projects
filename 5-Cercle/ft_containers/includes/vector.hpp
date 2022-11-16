/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:37:19 by armendes          #+#    #+#             */
/*   Updated: 2022/11/16 21:43:57 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <sstream>
# include <iterator>
# include <limits>
# include "enable_if.hpp"
# include "equal.hpp"
# include "is_integral.hpp"
# include "iterator_traits.hpp"
# include "lexicographical_compare.hpp"
# include "reverse_iterator.hpp"
# include "vector_iterator.hpp"

namespace ft
{

	template < typename T, typename Alloc = std::allocator<T> >
	class vector
	{

		public:

			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::vector_iterator<pointer, vector>		iterator;
			typedef ft::vector_iterator<const_pointer, vector>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename allocator_type::difference_type	difference_type;
			typedef size_t										size_type;

			// vector() : _alloc(allocator_type()), _start(NULL), _end(NULL), _end_cap(NULL) { }

			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _end_cap(NULL) { }

			explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _end_cap(NULL)
			{
				if (n == 0)
					return ;
				check_size(n);
				_start = _alloc.allocate(n);
				_end_cap = _start + n;
				_end = _end_cap;
				construct_range(_start, _end, val);
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _alloc(alloc), _start(NULL), _end(NULL), _end_cap(NULL)
			{
				typedef typename ft::iterator_traits<InputIterator>::iterator_category category;
				range_init(first, last, category());
			}

			vector(const vector& src) : _alloc(src._alloc), _start(NULL), _end(NULL), _end_cap(NULL)
			{
				const size_type cap = src.capacity();
				if (cap == 0)
					return ;
				_start = _alloc.allocate(cap);
				_end_cap = _start + cap;
				_end = construct_range(_start, src._start, src._end);	
			}

			~vector()
			{
				deallocate_v();
			}

			vector& operator=(const vector& x)
			{
				if (&x == this)
					return (*this);
				assign(x.begin(), x.end());
				return (*this);
			}

			iterator begin()
			{
				return (iterator(_start));
			}

			const_iterator begin() const
			{
				return (const_iterator(_start));
			}

			iterator end()
			{
				return (iterator(_end));
			}

			const_iterator end() const
			{
				return (const_iterator(_end));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			size_type size() const
			{
				return (static_cast<size_type>(_end - _start));
			}

			size_type max_size() const
			{
				return (std::min(_alloc.max_size(), static_cast<size_type>(std::numeric_limits<difference_type>::max())));
			}

			void resize(size_type n, value_type val = value_type())
			{
				const size_type len = size();
				if (n > len)
				{
					insert(end(), n - len, val);
				}
				else if (n < len)
				{
					erase_at_end(_start + n);
				}
			}

			size_type capacity() const
			{
				return (static_cast<size_type>(_end_cap - _start));
			}

			bool empty() const
			{
				return (_start == _end);
			}

			void reserve (size_type new_cap)
			{
				if (new_cap > capacity())
				{
					check_size(new_cap);
					pointer new_start = _alloc.allocate(new_cap);
					pointer new_end;
					new_end = construct_range(new_start, _start, _end);
					deallocate_v();
					_start = new_start;
					_end = new_end;
					_end_cap = _start + new_cap;
				}
			}

			reference operator[] (size_type n)
			{
				return (*(_start + n));
			}

			const_reference operator[] (size_type n) const
			{
				return (*(_start + n));
			}

			reference at (size_type n)
			{
				range_check(n);
				return ((*this)[n]);
			}

			const_reference at (size_type n) const
			{
				range_check(n);
				return ((*this)[n]);
			}

			reference front()
			{
				return (*begin());
			}

			const_reference front() const
			{
				return (*begin());
			}

			reference back()
			{
				return (*(end() - 1));
			}

			const_reference back() const
			{
				return (*(end() - 1));
			}

			pointer data()
			{
				return (_start);
			}

			const_pointer data() const
			{
				return (_start);
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				typedef typename iterator_traits<InputIterator>::iterator_category category;
				range_assign(first, last, category());
			}

			void assign (size_type n, const value_type& val)
			{
				if (n > capacity())
				{
					vector tmp(n, val);
					tmp.swap(*this);
				}
				else if (n > size())
				{
					std::fill(begin(), end(), val);
					const size_type extra = n - size();
					_end = construct_range(_end, _end + extra, val);
				}
				else
				{
					pointer it = std::fill_n(_start, n, val);
					erase_at_end(it);
				}
			}

			void push_back (const value_type& val)
			{
				if (!should_grow())
				{
					_alloc.construct(_end, val);
					++_end;
				}
				else
					insert(end(), val);
			}

			void pop_back()
			{
				--_end;
				_alloc.destroy(_end);
			}

			iterator insert (iterator position, const value_type& val)
			{
				const size_type index = position - begin();
				insert(position, 1 , val);
				return (iterator(_start + index));
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				if (n != 0)
				{
					const size_type extra_space = _end_cap - _end;
					if (extra_space >= n)
					{
						const size_type elems_after = end() - position;
						pointer old_end = _end;
						if (elems_after > n)
						{
							_end = construct_range(_end, _end - n, _end);
							std::copy_backward(position.base(), old_end - n, old_end);
							std::fill_n(position, n, val);
						}
						else
						{
							_end = construct_range(_end, _end + (n - elems_after), val);
							_end = construct_range(_end, position.base(), old_end);
							std::fill(position.base(), old_end, val);
						}
					}
					else
					{
						const size_type new_size = calculate_growth(n);
						pointer new_start = _alloc.allocate(new_size);
						pointer new_end;
						new_end = construct_range(new_start, _start, position.base());
						new_end = construct_range(new_end, new_end + n, val);
						new_end = construct_range(new_end, position.base(), _end);
						deallocate_v();
						_start = new_start;
						_end = new_end;
						_end_cap = new_start + new_size;
					}
				}
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				typedef typename ft::iterator_traits<InputIterator>::iterator_category category;
				range_insert(position, first, last, category());
			}
			
			iterator erase (iterator position)
			{
				if (position + 1 != end())
					std::copy(position + 1, end(), position);
				--_end;
				_alloc.destroy(_end);
				return (position);
			}

			iterator erase (iterator first, iterator last)
			{
				if (first != last)
				{
					if (last != end())
						std::copy(last, end(), first);
					pointer new_end = first.base() + (end() - last);
					erase_at_end(new_end);
				}
				return (first);
			}

			void swap (vector& x)
			{
				std::swap(_start, x._start);
				std::swap(_end, x._end);
				std::swap(_end_cap, x._end_cap);
			}

			void clear(void)
			{
				erase_at_end(_start);
			}

			allocator_type get_allocator() const
			{
				return (this->_alloc);
			}

			private:

				template <typename InputIterator>
				void range_init(InputIterator first, InputIterator last, std::input_iterator_tag)
				{
					for(; first != last; ++first)
						push_back(*first);
				}

				template <typename ForwardIterator>
				void range_init(ForwardIterator first, ForwardIterator last, std::forward_iterator_tag)
				{
					const size_type n = ft::difference(first, last);
					if (n == 0)
						return ;
					check_size(n);
					_start = _alloc.allocate(n);
					_end_cap = _start + n;
					_end = construct_range(_start, first, last);
				}

				template <typename InputIterator>
				void range_assign(InputIterator first, InputIterator last, std::input_iterator_tag)
				{
					clear();
					for (; first != last; ++first)
						push_back(*first);
				}

				template <typename ForwardIterator>
				void range_assign(ForwardIterator first, ForwardIterator last, std::forward_iterator_tag)
				{
					const size_type n = ft::difference(first, last);
					if (n < size())
					{
						iterator it = std::copy(first, last, begin());
						erase_at_end(it.base());
					}
					else
					{
						ForwardIterator it = first;
						std::advance(it, size());
						std::copy(first, it, begin());
						insert(end(), it, last);
					}
				}

				template <typename InputIterator>
				void range_insert(iterator position, InputIterator first, InputIterator last, std::input_iterator_tag)
				{
					if (position == end())
					{
						for (; first != last; ++first)
							push_back(*first);
					}
					else if (first != last)
					{
						vector tmp(first, last);
						insert(position, tmp.begin(), tmp.end());
					}
				}

				template <typename ForwardIterator>
				void range_insert(iterator position, ForwardIterator first, ForwardIterator last, std::forward_iterator_tag)
				{
					if (first != last)
					{
						const size_type n = ft::difference(first, last);
						check_size(n);
						const size_type extra_space = _end_cap - _end;
						if (extra_space >= n)
						{
							const size_type elems_after = end() - position;
							pointer old_end = _end;
							if (elems_after > n)
							{
								_end = construct_range(_end, _end - n, _end);
								std::copy_backward(position.base(), old_end - n, _end);
								std::copy(first, last, position);
							}
							else
							{
								ForwardIterator mid = first;
								std::advance(mid, elems_after);
								_end = construct_range(_end, mid, last);
								_end = construct_range(_end, position.base(), old_end);
								std::copy(first, mid, position);
							}
						}
						else
						{
							const size_type new_size = calculate_growth(n);
							pointer new_start = _alloc.allocate(new_size);
							pointer new_end = new_start;
							new_end = construct_range(new_start, _start, position.base());
							new_end = construct_range(new_end, first, last);
							new_end = construct_range(new_end, position.base(), _end);
							deallocate_v();
							_start = new_start;
							_end = new_end;
							_end_cap = new_start + new_size;
						}
					}
				}

				bool should_grow() const
				{
					return (_end == _end_cap);
				}

				void deallocate_v()
				{
					if (_start != NULL)
					{
						clear();
						_alloc.deallocate(_start, capacity());
					}
				}

				template <typename It>
				pointer construct_range(pointer dest, It start, It end)
				{
					for (; start != end; ++dest, (void)++start)
						_alloc.construct(dest, *start);
					return (dest);
				}

				pointer construct_range(pointer dest, const_pointer end, const_reference val)
				{
					for (; dest != end; ++dest)
						_alloc.construct(dest, val);
					return (dest);
				}

				void destroy_range(pointer start, pointer end)
				{
					for (; start != end; ++start)
						_alloc.destroy(start);
				}

				void erase_at_end(pointer position)
				{
					destroy_range(position, _end);
					_end = position;
				}

				void length_exception() const
				{
					throw std::length_error("cannot create ft::vector larger than max_size()");
				}

				size_type calculate_growth(size_type extra) const
				{
					const size_type max = max_size();
					const size_type cap = capacity();
					if ((max - cap) < extra)
						length_exception();
					if (cap >= (max / 2))
						return (max);
					return (std::max(size() + extra, cap * 2));
				}

				void check_size(size_type n)
				{
					if (n > max_size())
						length_exception();
				}

				void range_check(size_type n) const
				{
					if (n >= size())
					{
						std::stringstream ss;

						ss << "Index " << n << " is out of range (size = " << size();
						throw std::out_of_range(ss.str());
					}
				}

			private:

				allocator_type	_alloc;
				pointer			_start;
				pointer			_end;
				pointer			_end_cap;

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
