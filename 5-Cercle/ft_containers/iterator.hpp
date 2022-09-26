/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:13:56 by armendes          #+#    #+#             */
/*   Updated: 2022/09/26 17:53:19 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"
# include "nullptr.hpp"

namespace ft
{

	template <typename Iterator>
	class random_access_iterator : ft::iterator<random_access_iterator_tag, Iterator>
	{
		public:

		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::iterator_category	iterator_category;
		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::value_type				value_type;
		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::difference_type		difference_type;
		typedef T*																						pointer;
		typedef T&																						reference;

		random_access_iterator() : _current() {}
		explicit random_access_iterator(pointer x) : _current(x) {}
		random_access_iterator(random_access_iterator &other) : _current(other._current) {}
		virtual ~random_access_iterator() { _current = NULL}

		random_access_iterator& operator=(const random_access_iterator &other)
		{
			if (this == &other)
				return (*this);
			this->_current = other._current;
			return (*this);
		}

		pointer base() const
		{
			return (this->_current);
		}

		reference operator*() const
		{
			return *_current;
		}

		pointer operator->() const
		{
			return (&(operator*()));
		}

		reference	operator[](difference_type n) const
		{
			return *(_current + n);
		}

		random_access_iterator&		operator++()
		{
			++_current;
			return *this;
		}

		random_access_iterator&		operator--()
		{
			--_current;
			return *this;
		}

		random_access_iterator		operator++( int )
		{
			random_access_iterator	tmp(*this);
			++_current;
			return tmp;
		}

		random_access_iterator		operator--( int )
		{
			random_access_iterator	tmp(*this);
			--_current;
			return tmp;
		}

		random_access_iterator		operator+( difference_type n ) const
		{
			return random_access_iterator(this->_current + n);
		}

		random_access_iterator		operator-( difference_type n ) const
		{
			return random_access_iterator(_current - n);
		}

		random_access_iterator&		operator+=( difference_type n )
		{
			_current += n;
			return *this;
		}

		random_access_iterator&		operator-=( difference_type n )
		{
			_current -= n;
			return *this;
		}

		operator					random_access_iterator<const Iterator>(void) {
			return (random_access_iterator<const Iterator>(_current));
		}

		// template <class Iterator>
		// friend random_access_iterator<Iterator>	operator+(
		// 				difference_type n,
		// 				const random_access_iterator<Iterator>& x)
		// {
		// 	return random_access_iterator<Iterator>(x.base() + n);
		// }

		// template <class IteratorL, class IteratorR>
		// friend difference_type	operator-(
		// 				const random_access_iterator<IteratorL>& lhs,
		// 				const random_access_iterator<IteratorR>& rhs)
		// {
		// 	return lhs.base() - rhs.base();
		// }

		private:
		pointer			_current;

	};

	template <class IteratorL, class IteratorR>
	bool operator== (const random_access_iterator<IteratorL>& lhs,
					const random_access_iterator<IteratorR>& rhs)
	{
		return (rhs.base() == lhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator!= (const random_access_iterator<IteratorL>& lhs,
					const random_access_iterator<IteratorR>& rhs)
	{
		return (rhs.base() != lhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator<  (const random_access_iterator<IteratorL>& lhs,
					const random_access_iterator<IteratorR>& rhs)
	{
		return (rhs.base() < lhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator<= (const random_access_iterator<IteratorL>& lhs,
					const random_access_iterator<IteratorR>& rhs)
	{
		return (rhs.base() <= lhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator>  (const random_access_iterator<IteratorL>& lhs,
					const random_access_iterator<IteratorR>& rhs)
	{
		return (rhs.base() > lhs.base());
	}

	template <class IteratorL, class IteratorR>
	bool operator>= (const random_access_iterator<IteratorL>& lhs,
					const random_access_iterator<IteratorR>& rhs)
	{
		return (rhs.base() >= lhs.base());
	}

	template<class InputIt>
	typename ft::iterator_traits<InputIt>::difference_type
	distance(InputIt first, InputIt last)
	{
		typename ft::iterator_traits<InputIt>::difference_type size = 0;
		if (first == last)
			return (0);
		for (; first != last; ++first, ++size);
		return (size);
	}

}

#endif
