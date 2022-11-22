/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:39:51 by armendes          #+#    #+#             */
/*   Updated: 2022/11/22 16:27:25 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#	include "iterator.hpp"

namespace ft
{
	template <typename It, typename Container>
	class vector_iterator
	{
		public:
		    typedef It                                              iterator_type;
		    typedef typename iterator_traits<It>::iterator_category iterator_category;
		    typedef typename iterator_traits<It>::value_type        value_type;
		    typedef typename iterator_traits<It>::difference_type   difference_type;
		    typedef typename iterator_traits<It>::reference         reference;
		    typedef typename iterator_traits<It>::pointer           pointer;

		public:
		    vector_iterator() : _elem(iterator_type()) { }

		    explicit vector_iterator(const iterator_type& it) : _elem(it) { }

		    template <typename Iter>
		    vector_iterator(const vector_iterator<Iter, typename enable_if<is_same<Iter, typename Container::pointer>::value, Container>::type>& it) : _elem(it.base()) { }

		    ~vector_iterator() { };

		    vector_iterator& operator=(const vector_iterator& other)
		    {
		        _elem = other._elem;
		        return (*this);
		    }

		public:
		    const iterator_type& base() const
		    {
		        return (_elem);
		    }

		    reference operator*() const
		    {
		        return (*_elem);
		    }

		    pointer operator->() const
		    {
		        return (_elem);
		    }

		    vector_iterator& operator++()
		    {
		        ++_elem;
		        return (*this);
		    }

		    vector_iterator operator++(int)
		    {
		        return (vector_iterator(_elem++));
		    }

		    vector_iterator& operator--()
		    {
		        --_elem;
		        return (*this);
		    }

		    vector_iterator operator--(int)
		    {
		        return (vector_iterator(_elem--));
		    }

		    reference operator[](difference_type n)
		    {
		        return (*(_elem + n));
		    }

		    vector_iterator& operator+=(difference_type n)
		    {
		        _elem += n;
		        return (*this);
		    }

		    vector_iterator operator+(difference_type n) const
		    {
		        return (vector_iterator(_elem + n));
		    }

		    vector_iterator& operator-=(difference_type n)
		    {
		        _elem -= n;
		        return (*this);
		    }

		    vector_iterator operator-(difference_type n) const
		    {
		        return (vector_iterator(_elem - n));
		    }

		protected:
		    It _elem;
	};

	template <typename ItL, typename ItR, typename Container>
	inline bool operator==(const vector_iterator<ItL, Container>& lhs,
	                       const vector_iterator<ItR, Container>& rhs)
	{
	    return (lhs.base() == rhs.base());
	}

	template <typename It, typename Container>
	inline bool operator==(const vector_iterator<It, Container>& lhs,
	                       const vector_iterator<It, Container>& rhs)
	{
	    return (lhs.base() == rhs.base());
	}

	template <typename ItL, typename ItR, typename Container>
	inline bool operator!=(const vector_iterator<ItL, Container>& lhs,
	                       const vector_iterator<ItR, Container>& rhs)
	{
	    return (lhs.base() != rhs.base());
	}

	template <typename It, typename Container>
	inline bool operator!=(const vector_iterator<It, Container>& lhs,
	                       const vector_iterator<It, Container>& rhs)
	{
	    return (lhs.base() != rhs.base());
	}

	template <typename ItL, typename ItR, typename Container>
	inline bool operator>(const vector_iterator<ItL, Container>& lhs,
	                      const vector_iterator<ItR, Container>& rhs)
	{
	    return (lhs.base() > rhs.base());
	}

	template <typename It, typename Container>
	inline bool operator>(const vector_iterator<It, Container>& lhs,
	                      const vector_iterator<It, Container>& rhs)
	{
	    return (lhs.base() > rhs.base());
	}

	template <typename ItL, typename ItR, typename Container>
	inline bool operator<(const vector_iterator<ItL, Container>& lhs,
	                      const vector_iterator<ItR, Container>& rhs)
	{
	    return (lhs.base() < rhs.base());
	}

	template <typename It, typename Container>
	inline bool operator<(const vector_iterator<It, Container>& lhs,
	                      const vector_iterator<It, Container>& rhs)
	{
	    return (lhs.base() < rhs.base());
	}

	template <typename ItL, typename ItR, typename Container>
	inline bool operator>=(const vector_iterator<ItL, Container>& lhs,
	                       const vector_iterator<ItR, Container>& rhs)
	{
	    return (lhs.base() >= rhs.base());
	}

	template <typename It, typename Container>
	inline bool operator>=(const vector_iterator<It, Container>& lhs,
	                       const vector_iterator<It, Container>& rhs)
	{
	    return (lhs.base() >= rhs.base());
	}

	template <typename ItL, typename ItR, typename Container>
	inline bool operator<=(const vector_iterator<ItL, Container>& lhs,
	                       const vector_iterator<ItR, Container>& rhs)
	{
	    return (lhs.base() <= rhs.base());
	}

	template <typename It, typename Container>
	inline bool operator<=(const vector_iterator<It, Container>& lhs,
	                       const vector_iterator<It, Container>& rhs)
	{
	    return (lhs.base() <= rhs.base());
	}

	template <typename ItL, typename ItR, typename Container>
	inline typename vector_iterator<ItL, Container>::difference_type
	operator-(const vector_iterator<ItL, Container>& lhs, const vector_iterator<ItR, Container>& rhs)
	{
	    return (lhs.base() - rhs.base());
	}

	template <typename It, typename Container>
	inline typename vector_iterator<It, Container>::difference_type
	operator-(const vector_iterator<It, Container>& lhs, const vector_iterator<It, Container>& rhs)
	{
	    return (lhs.base() - rhs.base());
	}

	template <typename It, typename Container>
	inline vector_iterator<It, Container>
	operator+(typename vector_iterator<It, Container>::difference_type n, const vector_iterator<It, Container>& it)
	{
	    return (vector_iterator<It, Container>(it.base() + n));
	}
}

#endif
