/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:29:35 by armendes          #+#    #+#             */
/*   Updated: 2022/09/09 17:11:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{

	struct input_iterator_tag { };

  struct output_iterator_tag { };

  struct forward_iterator_tag : public input_iterator_tag { };

  struct bidirectional_iterator_tag : public forward_iterator_tag { };

  struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef	Category				iterator_category;
		typedef	T								value_type;
		typedef	Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;
	};

	template <class T>
  struct iterator_traits {
  	typedef typename T::value_type            value_type;
		typedef typename T::difference_type       difference_type;
		typedef typename T::iterator_category     iterator_category;
    typedef typename T::pointer               pointer;
    typedef typename T::reference             reference;
	};

	template <class T>
  struct iterator_traits<T*> {
		typedef T                          value_type;
  	typedef ptrdiff_t                  difference_type;
  	typedef random_access_iterator_tag iterator_category;
  	typedef T*                         pointer;
  	typedef T&                         reference;
	};

}

#endif
