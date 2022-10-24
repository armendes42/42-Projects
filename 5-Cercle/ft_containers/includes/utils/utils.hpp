/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:57:31 by armendes          #+#    #+#             */
/*   Updated: 2022/10/24 16:58:47 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {

	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator start, InputIterator end)
    {
		typename iterator_traits<InputIterator>::difference_type len = 0;

		while (start != end)
        {
			len++;
			++start;
		}
		return (len);
	}

}

#endif