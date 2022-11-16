/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:25:46 by armendes          #+#    #+#             */
/*   Updated: 2022/11/16 18:17:54 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

	template <typename It>
  	class reverse_iterator : public iterator<typename iterator_traits<It>::iterator_category,
											typename iterator_traits<It>::value_type,
											typename iterator_traits<It>::difference_type,
											typename iterator_traits<It>::pointer,
											typename iterator_traits<It>::reference>
    {

		protected:
			It	_current;

    	public:
			typedef It												iterator_type;
			typedef typename iterator_traits<It>::value_type		value_type;
			typedef typename iterator_traits<It>::difference_type	difference_type;
			typedef typename iterator_traits<It>::pointer			pointer;
			typedef typename iterator_traits<It>::reference			reference;

			reverse_iterator() : _current() { }

			explicit reverse_iterator(iterator_type x) : _current(x) { }

			reverse_iterator(const reverse_iterator& other) : _current(other._current) { }

			template <typename Iter>
			reverse_iterator(const reverse_iterator<It>& other) : _current(other.base()) { }

			~reverse_iterator() { }

			reverse_iterator& operator=(const reverse_iterator& other)
			{
				if (&other == this)
					return (*this);
				_current = other._current;
				return (*this);
			}

			iterator_type base() const
			{
				return (_current);
			}

			reference operator*() const
			{
				It tmp = _current;
				return (*(--tmp));
			}

			pointer operator->() const
			{
				return (&(operator*()));
			}

			reverse_iterator& operator++(void)
			{
				--_current;
				return (*this);
			}

			reverse_iterator operator++( int )
			{
				return (reverse_iterator(_current--));
			}

			reverse_iterator& operator--(void)
			{
				++_current;
				return (*this);
			}

			reverse_iterator operator--(int)
			{
				return (reverse_iterator(_current++));
			}

			reverse_iterator operator+(difference_type n) const
			{
				return reverse_iterator(_current - n);
			}

			reverse_iterator& operator+=(difference_type n)
			{
				_current -= n;
				return (*this);
			}

			reverse_iterator operator-(difference_type n) const
			{
				return reverse_iterator(_current + n);
			}

			reverse_iterator& operator-=(difference_type n)
			{
				_current += n;
				return (*this);
			}

			reference operator[](difference_type n) const
			{
				return (*(*this + n));
			}

	};

	template <typename ItL, typename ItR>
	inline bool operator==(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename It>
	inline bool operator==(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename ItL, typename ItR>
	inline bool operator!=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename It>
	inline bool operator!=(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename ItL, typename ItR>
	inline bool operator>(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename It>
	inline bool operator>(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename ItL, typename ItR>
	inline bool operator<(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename It>
	inline bool operator<(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename ItL, typename ItR>
	inline bool operator>=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename It>
	inline bool operator>=(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename ItL, typename ItR>
	inline bool operator<=(const reverse_iterator<ItL>& lhs, const reverse_iterator<ItR>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename It>
	inline bool operator<=(const reverse_iterator<It>& lhs, const reverse_iterator<It>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename ItL, typename ItR>
	inline typename reverse_iterator<ItL>::difference_type operator-(const reverse_iterator<ItL>& lhs,
																	const reverse_iterator<ItR>& rhs)
	{
		return rhs.base() - lhs.base();
	}

	template <typename It>
	inline typename reverse_iterator<It>::difference_type operator-(const reverse_iterator<It>& lhs,
																	const reverse_iterator<It>& rhs)
	{
		return rhs.base() - lhs.base();
	}

	template <typename It>
	inline reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type n,
										const reverse_iterator<It>& it)
	{
		return reverse_iterator<It>(it.base() - n);
	}

};

#endif
