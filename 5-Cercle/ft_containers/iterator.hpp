/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:13:56 by armendes          #+#    #+#             */
/*   Updated: 2022/09/12 17:58:46 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

	template <typename Iterator>
	class random_access_iterator : ft::iterator<random_access_iterator_tag, Iterator>
	{
		private:
		pointer			_current;


		public:

		typedef					Iterator																																	iterator_type;
		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::iterator_category	iterator_category;
		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::value_type				value_type;
		typedef typename		ft::iterator<random_access_iterator_tag, Iterator>::difference_type		difference_type;
		typedef typename 		ft::iterator<random_access_iterator_tag, Iterator>::pointer						pointer;
		typedef typename 		ft::iterator<random_access_iterator_tag, Iterator>::reference					reference;

		random_access_iterator() : _current() {};
		random_access_iterator(pointer x) : _current(x) {};
		random_access_iterator(random_access_iterator &other) : _current(other._current) {};
		virtual ~random_access_iterator() {};

		random_access_iterator& operator=(const random_access_iterator &other)
		{
			if (this == &other)
				return (*this);
			this->_current = other._current
			return (*this);
		};

		pointer base() const
		{
			return (this->_current);
		};

		reference operator*() const
		{
			return *this->_current;
		};

		pointer operator->() const
		{
			return (&(operator*());
		};

		reference	operator[](difference_type n) const
		{
			return *(this->_current + n);
		};

		random_access_iterator&		operator++()
		{
			++(_current);
			return *this;
		};

		random_access_iterator&		operator--()
		{
			--(_current);
			return *this;
		};

		random_access_iterator		operator++( int )
		{
			random_access_iterator	tmp(*this);
			operator++();
			return tmp;
		}

		random_access_iterator		operator--( int )
		{
			random_access_iterator	tmp(*this);
			operator--();
			return tmp;
		};

		random_access_iterator		operator+( difference_type n ) const
		{
			return random_access_iterator(this->_current + n);
		};

		random_access_iterator		operator-( difference_type n ) const
		{
			return random_access_iterator(this->_current - n);
		};

		random_access_iterator&		operator+=( difference_type n )
		{
			this->_current += n;
			return *this;
		};

		random_access_iterator&		operator-=( difference_type n )
		{
			this->_current -= n;
			return *this;
		};

		operator					random_access_iterator<const Iterator>(void) {
			return (random_access_iterator<const Iterator>(_current));
		}

		friend bool operator== (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<Iterator>& rhs)
		{
			return (rhs.base() == lhs.base());
		};

		friend bool operator!= (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<Iterator>& rhs)
		{
			return (rhs.base() != lhs.base());
		};

		friend bool operator<  (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<Iterator>& rhs)
		{
			return (rhs.base() < lhs.base());
		};

		friend bool operator<= (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<Iterator>& rhs)
		{
			return (rhs.base() <= lhs.base());
		};

		friend bool operator>  (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<Iterator>& rhs)
		{
			return (rhs.base() > lhs.base());
		};

		friend bool operator>= (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<Iterator>& rhs)
		{
			return (rhs.base() >= lhs.base());
		};

		template <class IteratorR>
		friend bool operator== (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<IteratorR>& rhs)
		{
			return (rhs.base() == lhs.base());
		};

		template <class IteratorR>
		friend bool operator!= (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<IteratorR>& rhs)
		{
			return (rhs.base() != lhs.base());
		};

		template <class IteratorR>
		friend bool operator<  (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<IteratorR>& rhs)
		{
			return (rhs.base() < lhs.base());
		};

		template <class IteratorR>
		friend bool operator<= (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<IteratorR>& rhs)
		{
			return (rhs.base() <= lhs.base());
		};

		template <class IteratorR>
		friend bool operator>  (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<IteratorR>& rhs)
		{
			return (rhs.base() > lhs.base());
		};

		template <class IteratorR>
		friend bool operator>= (const random_access_iterator<Iterator>& lhs,
						const random_access_iterator<IteratorR>& rhs)
		{
			return (rhs.base() >= lhs.base());
		};

	};

}

#endif
