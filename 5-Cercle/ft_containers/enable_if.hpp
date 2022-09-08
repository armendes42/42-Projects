/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:59:58 by armendes          #+#    #+#             */
/*   Updated: 2022/09/08 17:16:42 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

template<bool Cond, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T>
{
	typedef T type;
};

#endif
