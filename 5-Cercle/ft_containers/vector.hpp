/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:27:15 by armendes          #+#    #+#             */
/*   Updated: 2022/11/23 18:23:32 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
# include <limits>
# include <memory>
# include <sstream>
# include <stdexcept>
# include "iterator.hpp"
# include "utility.hpp"
# include "vector_iterator.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
		    typedef T                                        value_type;
		    typedef Allocator                                allocator_type;
		    typedef typename allocator_type::size_type       size_type;
		    typedef typename allocator_type::difference_type difference_type;
		    typedef value_type&                              reference;
		    typedef const value_type&                        const_reference;
		    typedef typename allocator_type::pointer         pointer;
		    typedef typename allocator_type::const_pointer   const_pointer;
		    typedef vector_iterator<pointer, vector>         iterator;
		    typedef vector_iterator<const_pointer, vector>   const_iterator;
		    typedef ft::reverse_iterator<iterator>           reverse_iterator;
		    typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;

		public:
		    vector() : _alloc(allocator_type()), _start(NULL), _end(NULL), _end_cap(NULL) { }

		    vector(const vector& other) : _alloc(other._alloc), _start(NULL), _end(NULL), _end_cap(NULL)
		    {
		        const size_type cap = other.capacity();
		        if (cap == 0)
		            return;
		        _start = _alloc.allocate(cap);
		        _end_cap = _start + cap;
		        _end = construct_range(_start, other._start, other._end);
		    }

		    explicit vector(const allocator_type& alloc) : _alloc(alloc), _start(NULL), _end(NULL), _end_cap(NULL) { }

		    explicit vector(size_type count, const value_type& value = value_type(),
		                    const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _end_cap(NULL)
		    {
		        if (count == 0)
		            return;
		        check_size(count);
		        _start = _alloc.allocate(count);
		        _end_cap = _start + count;
		        _end = _end_cap;
		        construct_range(_start, _end, value);
		    }

		    template <typename InputIt>
		    vector(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last,
		           const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _end_cap(NULL)
		    {
		        typedef typename iterator_traits<InputIt>::iterator_category category;
		        range_init(first, last, category());
		    }

		    vector& operator=(const vector& other)
		    {
		        if (&other == this)
		            return (*this);
		        assign(other.begin(), other.end());
		        return (*this);
		    }

		    ~vector()
		    {
		        deallocate_v();
		    }

		public:
		    template <typename InputIt>
		    void assign(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last)
		    {
		        typedef typename iterator_traits<InputIt>::iterator_category category;
		        range_assign(first, last, category());
		    }

		    void assign(size_type count, const T& value)
		    {
		        if (count > capacity())
						{
		            vector tmp(count, value);
		            tmp.swap(*this);
		        }
						else if (count > size())
						{
		            std::fill(begin(), end(), value);
		            const size_type extra = count - size();
		            _end = construct_range(_end, _end + extra, value);
		        }
						else
						{
		            pointer it = std::fill_n(_start, count, value);
		            erase_at_end(it);
		        }
		    }

		    allocator_type get_allocator() const
		    {
		        return (_alloc);
		    }

		    reference at(size_type pos)
		    {
		        range_check(pos);
		        return ((*this)[pos]);
		    }

		    const_reference at(size_type pos) const
		    {
		        range_check(pos);
		        return ((*this)[pos]);
		    }

		    reference operator[](size_type pos)
		    {
		        return (*(_start + pos));
		    }

		    const_reference operator[](size_type pos) const
		    {
		        return (*(_start + pos));
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

		    bool empty() const
		    {
		        return (_start == _end);
		    }

		    size_type size() const
		    {
		        return (static_cast<size_type>(_end - _start));
		    }

		    size_type max_size() const
		    {
						return (allocator_type().max_size());
		    }

		    void reserve(size_type new_cap)
		    {
		        if (new_cap > capacity())
						{
								if (new_cap > max_size())
				            throw std::length_error("vector::reserve");
		            pointer new_start = _alloc.allocate(new_cap);
		            pointer new_end;
		            new_end = construct_range(new_start, _start, _end);
		            deallocate_v();
		            _start = new_start;
		            _end = new_end;
		            _end_cap = _start + new_cap;
		        }
		    }

		    size_type capacity() const
		    {
		        return (static_cast<size_type>(_end_cap - _start));
		    }

		    iterator insert(iterator pos, const value_type& value)
		    {
		        const size_type index = pos - begin();
		        insert(pos, 1, value);
		        return (iterator(_start + index));
		    }

		    void insert(iterator pos, size_type count, const value_type& value)
		    {
		        if (count != 0)
						{
		            const size_type extra_space = _end_cap - _end;
		            if (extra_space >= count)
								{
		                const size_type elems_after = end() - pos;
		                pointer old_end = _end;
		                if (elems_after > count)
										{
		                    _end = construct_range(_end, _end - count, _end);
		                    std::copy_backward(pos.base(), old_end - count, old_end);
		                    std::fill_n(pos, count, value);
		                }
										else
										{
		                    _end = construct_range(_end, _end + (count - elems_after), value);
		                    _end = construct_range(_end, pos.base(), old_end);
		                    std::fill(pos.base(), old_end, value);
		                }
		            }
								else
								{
		                const size_type new_size = calculate_growth(count);
		                pointer new_start = _alloc.allocate(new_size);
		                pointer new_end;
		                new_end = construct_range(new_start, _start, pos.base());
		                new_end = construct_range(new_end, new_end + count, value);
		                new_end = construct_range(new_end, pos.base(), _end);
		                deallocate_v();
		                _start = new_start;
		                _end = new_end;
		                _end_cap = new_start + new_size;
		            }
		        }
		    }

		    template <class InputIt>
		    void insert(iterator pos, InputIt first,
		                typename enable_if<!is_integral<InputIt>::value, InputIt>::type last)
		    {
		        typedef typename iterator_traits<InputIt>::iterator_category category;
		        range_insert(pos, first, last, category());
		    }

		    void clear()
		    {
		        erase_at_end(_start);
		    }

		    iterator erase(iterator pos)
		    {
		        if (pos + 1 != end())
		            std::copy(pos + 1, end(), pos);
		        --_end;
		        _alloc.destroy(_end);
		        return (pos);
		    }

		    iterator erase(iterator first, iterator last)
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

		    void push_back(const value_type& value)
		    {
		        if (!should_grow())
						{
		            _alloc.construct(_end, value);
		            ++_end;
		        }
						else
						{
		            insert(end(), value);
		        }
		    }

		    void pop_back()
		    {
		        --_end;
		        _alloc.destroy(_end);
		    }

		    void resize(size_type count, value_type value = value_type())
		    {
		        const size_type len = size();
		        if (count > len)
						{
		            insert(end(), count - len, value);
		        }
						else if (count < len)
						{
		            erase_at_end(_start + count);
		        }
		    }

		    void swap(vector& other)
		    {
		        std::swap(_start, other._start);
		        std::swap(_end, other._end);
		        std::swap(_end_cap, other._end_cap);
		    }

		private:
		    template <typename InputIt>
		    void range_init(InputIt first, InputIt last, std::input_iterator_tag)
		    {
		        for (; first != last; ++first)
		            push_back(*first);
		    }

		    template <typename ForwardIt>
		    void range_init(ForwardIt first, ForwardIt last, std::forward_iterator_tag)
		    {
		        const size_type count = std::distance(first, last);
		        if (count == 0)
		            return;
		        check_size(count);
		        _start = _alloc.allocate(count);
		        _end_cap = _start + count;
		        _end = construct_range(_start, first, last);
		    }

		    template <typename InputIt>
		    void range_assign(InputIt first, InputIt last, std::input_iterator_tag)
		    {
		        clear();
		        for (; first != last; ++first)
		            push_back(*first);
		    }

		    template <typename ForwardIt>
		    void range_assign(ForwardIt first, ForwardIt last, std::forward_iterator_tag)
		    {
		        const size_type count = std::distance(first, last);
		        if (count < size())
						{
		            iterator it = std::copy(first, last, begin());
		            erase_at_end(it.base());
		        }
						else
						{
		            ForwardIt it = first;
		            std::advance(it, size());
		            std::copy(first, it, begin());
		            insert(end(), it, last);
		        }
		    }

		    template <typename InputIt>
		    void range_insert(iterator pos, InputIt first, InputIt last, std::input_iterator_tag)
		    {
		        if (pos == end())
						{
		            for (; first != last; ++first)
		                push_back(*first);
		        }
						else if (first != last)
						{
		            vector tmp(first, last);
		            insert(pos, tmp.begin(), tmp.end());
		        }
		    }

		    template <typename ForwardIt>
		    void range_insert(iterator pos, ForwardIt first, ForwardIt last, std::forward_iterator_tag)
		    {
		        if (first != last)
						{
		            const size_type count = std::distance(first, last);
		            check_size(count);
		            const size_type extra_space = _end_cap - _end;
		            if (extra_space >= count)
								{
		                const size_type elems_after = end() - pos;
		                pointer old_end = _end;
		                if (elems_after > count)
										{
		                    _end = construct_range(_end, _end - count, _end);
		                    std::copy_backward(pos.base(), old_end - count, old_end);
		                    std::copy(first, last, pos);
		                }
										else
										{
		                    ForwardIt mid = first;
		                    std::advance(mid, elems_after);
		                    _end = construct_range(_end, mid, last);
		                    _end = construct_range(_end, pos.base(), old_end);
		                    std::copy(first, mid, pos);
		                }
		            }
								else
								{
		                const size_type new_size = calculate_growth(count);
		                pointer new_start = _alloc.allocate(new_size);
		                pointer new_end = new_start;
		                new_end = construct_range(new_start, _start, pos.base());
		                new_end = construct_range(new_end, first, last);
		                new_end = construct_range(new_end, pos.base(), _end);
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
		    pointer construct_range(pointer dst, It start, It end)
		    {
		        for (; start != end; ++dst, (void)++start)
		            _alloc.construct(dst, *start);
		        return (dst);
		    }

		    pointer construct_range(pointer dst, const_pointer end, const_reference value)
		    {
		        for (; dst != end; ++dst)
		            _alloc.construct(dst, value);
		        return (dst);
		    }

		    void destroy_range(pointer start, pointer end)
		    {
		        for (; start != end; ++start)
		            _alloc.destroy(start);
		    }

		    void erase_at_end(pointer pos)
		    {
		        destroy_range(pos, _end);
		        _end = pos;
		    }

		    void length_exception() const
		    {
		        throw std::length_error("cannot create ft::vector larger than max_size()");
		    }

		    size_type calculate_growth(size_type extra) const
		    {
		        const size_type max = max_size();
		        const size_type cap = capacity();
		        if (max - cap < extra)
		            length_exception();
		        if (cap >= max / 2)
		            return (max);
		        return (std::max(size() + extra, cap * 2));
		    }

		    void check_size(size_type count)
		    {
		        if (count > max_size())
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
		    allocator_type _alloc;
		    pointer _start;
		    pointer _end;
		    pointer _end_cap;
	};

	template <typename T, typename Alloc>
	inline void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
	    x.swap(y);
	}

	template <typename T, typename Alloc>
	inline bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
	    return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <typename T, typename Alloc>
	inline bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
	    return (!(lhs == rhs));
	}

	template <typename T, typename Alloc>
	inline bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
	    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename T, typename Alloc>
	inline bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
	    return (!(rhs < lhs));
	}

	template <typename T, typename Alloc>
	inline bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
	    return (rhs < lhs);
	}

	template <typename T, typename Alloc>
	inline bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
	    return (!(lhs < rhs));
	}

}

#endif
