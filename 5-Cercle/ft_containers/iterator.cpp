/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:29:44 by armendes          #+#    #+#             */
/*   Updated: 2022/06/22 16:29:45 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include <iostream>
#include <string>

iterator::iterator(void)
{
	return;
}

iterator::iterator(iterator const &T)
{
	*this = T;
	return;
}

iterator &iterator::operator=(iterator const &T)
{
	if (this == &T)
		return (*this);
	return (*this);
}

iterator::~iterator(void)
{
	return;
}
