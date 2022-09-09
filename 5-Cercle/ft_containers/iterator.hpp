/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:13:56 by armendes          #+#    #+#             */
/*   Updated: 2022/09/09 17:49:27 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

	template <typename Iterator>
	class reverse_iterator
	{
		protected:
		iterator_type			_current;


		public:
		typedef	Iterator																											iterator_type;
		typedef typename		ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename		ft::iterator_traits<Iterator>::value_type					value_type;
		typedef typename		ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename 		ft::iterator_traits<Iterator>::pointer						pointer;
		typedef typename 		ft::iterator_traits<Iterator>::reference					reference;

		reverse_iterator() : _current() {};

		template<class U>
		reverse_iterator(const reverse_iterator<U> &x) : _current(x._current) {};

		template<class U>
		reverse_iterator&		operator=(const reverse_iterator<U> &rhs)
		{
			if (this == &rhs)
				return *this;
			this->_current = rhs.base();
			return (*this);
		};

	};

}

#endif
