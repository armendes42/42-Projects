/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:37:19 by armendes          #+#    #+#             */
/*   Updated: 2022/09/12 18:36:30 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "iterator_traits.hpp"
# include "iterator.hpp"

namespace ft
{

	template <typename T, typename Alloc = allocator<T>>
	class vector
	{
		private:

		allocator_type	_alloc;
		pointer					_begin;
		pointer					_end;
		size_type				_capacity;

		public:

		typedef T																											value_type;
		typedef Alloc																									allocator_type;
		typedef typename allocator_type::reference										reference;
		typedef typename allocator_type::const_reference							const_reference;
		typedef typename allocator_type::pointer											pointer;
		typedef typename allocator_type::const_pointer								const_pointer;
		typedef typename ft::random_access_iterator<value_type>				iterator;
		typedef typename ft::random_access_iterator<const value_type> const_iterator;
		typedef typename ft::reverse_iterator<value_type>							iterator;
		typedef typename ft::reverse_iterator<const value_type> 			const_iterator;
		typedef typename std::ptrdiff_t																difference_type;
		typedef typename std::size_t																	size_type;

		explicit vector (const allocator_type& alloc = allocator_type()) :
	};

}

#endif
