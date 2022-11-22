/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:33:36 by armendes          #+#    #+#             */
/*   Updated: 2022/11/22 16:41:46 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include "type_traits.hpp"

namespace ft
{
	template <typename It>
	struct iterator_traits
	{
	    typedef typename It::iterator_category iterator_category;
	    typedef typename It::value_type        value_type;
	    typedef typename It::difference_type   difference_type;
	    typedef typename It::pointer           pointer;
	    typedef typename It::reference         reference;
	};

	template <typename It>
	struct iterator_traits<It*>
	{
	    typedef std::random_access_iterator_tag iterator_category;
	    typedef typename remove_cv<It>::type    value_type;
	    typedef std::ptrdiff_t                  difference_type;
	    typedef It*                             pointer;
	    typedef It&                             reference;
	};

	template <typename It>
	class reverse_iterator
	    : public std::iterator<
	          typename iterator_traits<It>::iterator_category, typename iterator_traits<It>::value_type,
	          typename iterator_traits<It>::difference_type, typename iterator_traits<It>::pointer,
	          typename iterator_traits<It>::reference>
	{
		public:
		    typedef It                                            iterator_type;
		    typedef typename iterator_traits<It>::value_type      value_type;
		    typedef typename iterator_traits<It>::difference_type difference_type;
		    typedef typename iterator_traits<It>::reference       reference;
		    typedef typename iterator_traits<It>::pointer         pointer;

		public:
		    reverse_iterator() : _curr() { }

		    reverse_iterator(const reverse_iterator& it) : _curr(it._curr) { }

		    explicit reverse_iterator(iterator_type it) : _curr(it)	{ }

		    template <typename Iter>
		    reverse_iterator(const reverse_iterator<Iter>& it) : _curr(it.base()) { }

		    ~reverse_iterator() { }

		    reverse_iterator& operator=(const reverse_iterator& other)
		    {
		        _curr = other._curr;
		        return (*this);
		    }

		public:
		    iterator_type base() const
		    {
		        return (_curr);
		    }

		    reference operator*() const
		    {
		        It tmp = _curr;
		        return (*--tmp);
		    }

		    pointer operator->() const
		    {
		        return (&(operator*()));
		    }

		    reverse_iterator& operator++()
		    {
		        --_curr;
		        return (*this);
		    }

		    reverse_iterator operator++(int)
		    {
		        return (reverse_iterator(_curr--));
		    }

		    reverse_iterator& operator--()
		    {
		        ++_curr;
		        return (*this);
		    }

		    reverse_iterator operator--(int)
		    {
		        return (reverse_iterator(_curr++));
		    }

		    reverse_iterator operator+(difference_type n) const
		    {
		        return (reverse_iterator(_curr - n));
		    }

		    reverse_iterator& operator+=(difference_type n)
		    {
		        _curr -= n;
		        return (*this);
		    }

		    reverse_iterator operator-(difference_type n) const
		    {
		        return (reverse_iterator(_curr + n));
		    }

		    reverse_iterator& operator-=(difference_type n)
		    {
		        _curr += n;
		        return (*this);
		    }

		    reference operator[](difference_type n) const
		    {
		        return (*(*this + n));
		    }

		protected:
		    It _curr;
	};

	template <typename ItL, typename ItR>
	inline bool operator==(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
	    return (lhs.base() == rhs.base());
	}

	template <typename It>
	inline bool operator==(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
	    return (lhs.base() == rhs.base());
	}

	template <typename ItL, typename ItR>
	inline bool operator!=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
	    return (lhs.base() != rhs.base());
	}

	template <typename It>
	inline bool operator!=(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
	    return (lhs.base() != rhs.base());
	}

	template <typename ItL, typename ItR>
	inline bool operator>(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
	    return (lhs.base() < rhs.base());
	}

	template <typename It>
	inline bool operator>(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
	    return (lhs.base() < rhs.base());
	}

	template <typename ItL, typename ItR>
	inline bool operator<(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
	    return (lhs.base() > rhs.base());
	}

	template <typename It>
	inline bool operator<(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
	    return (lhs.base() > rhs.base());
	}

	template <typename ItL, typename ItR>
	inline bool operator>=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
	    return (lhs.base() <= rhs.base());
	}

	template <typename It>
	inline bool operator>=(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
	    return (lhs.base() <= rhs.base());
	}

	template <typename ItL, typename ItR>
	inline bool operator<=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
	    return (lhs.base() >= rhs.base());
	}

	template <typename It>
	inline bool operator<=(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
	    return (lhs.base() >= rhs.base());
	}

	template <typename ItL, typename ItR>
	inline typename reverse_iterator<ItL>::difference_type operator-(const reverse_iterator<ItL>& lhs,
	                                                                 const reverse_iterator<ItR>& rhs)
	{
	    return (rhs.base() - lhs.base());
	}

	template <typename It>
	inline typename reverse_iterator<It>::difference_type operator-(const reverse_iterator<It>& lhs,
	                                                                const reverse_iterator<It>& rhs)
	{
	    return (rhs.base() - lhs.base());
	}

	template <typename It>
	inline reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type n,
	                                      const reverse_iterator<It>& it)
	{
	    return (reverse_iterator<It>(it.base() - n));
	}

}

#endif
