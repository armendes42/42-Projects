/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:13:56 by armendes          #+#    #+#             */
/*   Updated: 2022/10/17 17:15:41 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"
# include "nullptr.hpp"

namespace ft
{

	template <class Iterator>
	class random_access_iterator : public ft::iterator<random_access_iterator_tag, Iterator>
	{
		public:

		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::iterator_category	iterator_category;
		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::value_type				value_type;
		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::difference_type		difference_type;
		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::pointer					pointer;
		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::reference			reference;

		random_access_iterator() : _current(nullptr_) {}
		explicit random_access_iterator(pointer x) : _current(x) {}
		random_access_iterator(random_access_iterator const &other) : _current(other._current) {}
		virtual ~random_access_iterator() {}

		random_access_iterator& operator=(const random_access_iterator &other)
		{
			if (this == &other)
				return (*this);
			this->_current = other._current;
			return (*this);
		}


		reference operator*() const
		{
			return (*(_current));
		}

		pointer operator->() const
		{
			return (_current);
		}

		reference	operator[](difference_type n) const
		{
			return (*(_current + n));
		}

		random_access_iterator&		operator++()
		{
			++(this->_current);
			return (*this);
		}

		random_access_iterator&		operator--()
		{
			this->_current--;
			return *this;
		}

		random_access_iterator		operator++( int )
		{
			random_access_iterator	tmp(*this);
			++(*this);
			return (tmp);
		}

		random_access_iterator		operator--( int )
		{
			random_access_iterator	tmp(*this);
			--(*this);
			return (tmp);
		}

		random_access_iterator		operator+( difference_type const & rhs ) const
		{
			return (this->_current + rhs);
		}

		friend random_access_iterator	operator+(difference_type n, random_access_iterator const &rhs)
		{
			return (rhs._element + n);//redo this function
		};

		friend difference_type	operator+(random_access_iterator const &lhs, random_access_iterator const &rhs)
		{
			return (lhs._element + rhs._element);
		};

		random_access_iterator		operator-( difference_type const & rhs ) const
		{
			return (this->_current - rhs);
		}

		friend random_access_iterator	operator-(difference_type n, random_access_iterator const &rhs)
		{
			return (rhs._element - n);
		};

		friend difference_type	operator-(random_access_iterator const &lhs, random_access_iterator const &rhs)
		{
			return (lhs._element - rhs._element);
		};

		random_access_iterator		operator+=( difference_type const & rhs )
		{
			return (random_access_iterator(this->_current += rhs));
		}

		random_access_iterator		operator-=( difference_type const & rhs )
		{
			return (random_access_iterator(this->_current -= rhs));
		}

		operator					random_access_iterator<const Iterator>(void) {
			return (random_access_iterator<const Iterator>(_current));
		}

		difference_type	operator+(random_access_iterator x)
		{
			return (this->_current + x._current);
		}

		difference_type	operator-(random_access_iterator x)
		{
			return (this->_current - x._current);
		}

		private:
			pointer			_current;

	};

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
