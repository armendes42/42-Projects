/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:37:56 by armendes          #+#    #+#             */
/*   Updated: 2022/10/24 15:39:26 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

namespace ft {

	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {

		ft::pair<T1, T2>	retPair(x, y);

		return (retPair);
	}
};

#endif