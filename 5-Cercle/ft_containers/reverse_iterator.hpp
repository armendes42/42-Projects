/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:25:46 by armendes          #+#    #+#             */
/*   Updated: 2022/09/06 16:52:59 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define REVERSE_ITERATOR_HPP

namespace ft
{

	template<typename _Iterator>
  	class reverse_iterator
  	: public iterator<typename iterator_traits<_Iterator>::iterator_category,
											typename iterator_traits<_Iterator>::value_type,
											typename iterator_traits<_Iterator>::difference_type,
											typename iterator_traits<_Iterator>::pointer,
                      typename iterator_traits<_Iterator>::reference>
    {

		protected:
      _Iterator current;
      typedef iterator_traits<_Iterator>		__traits_type;

    public:
      typedef _Iterator																iterator_type;
      typedef typename __traits_type::difference_type	difference_type;
      typedef typename __traits_type::pointer					pointer;
      typedef typename __traits_type::reference				reference;

			reverse_iterator();
			reverse_iterator(iterator_type _x);

}

#endif
