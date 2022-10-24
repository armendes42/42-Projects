/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:29:35 by armendes          #+#    #+#             */
/*   Updated: 2022/10/24 15:27:45 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <cstddef>

namespace ft
{

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template <typename _Category, typename _T, typename _Distance = std::ptrdiff_t, class _Pointer = _T*, class _Reference = _T&>
	struct iterator
	{
		typedef	_Category	iterator_category;
		typedef	_T			value_type;
		typedef	_Distance	difference_type;
		typedef _Pointer	pointer;
		typedef _Reference	reference;
	};

	template <typename _Iterator>
  	struct iterator_traits
	{
  		typedef typename _Iterator::value_type            value_type;
		typedef typename _Iterator::difference_type       difference_type;
    	typedef typename _Iterator::pointer               pointer;
    	typedef typename _Iterator::reference             reference;
	};

	template <typename T>
  	struct iterator_traits<T*>
	{
  		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
  		typedef std::ptrdiff_t				difference_type;
  		typedef T*							pointer;
  		typedef T&							reference;
	};

	template <typename T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef const T*					pointer;
		typedef const T&					reference;
	};


};

#endif
