/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:48:45 by armendes          #+#    #+#             */
/*   Updated: 2022/05/09 19:48:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain(void)
{
	return;
}

Brain::Brain(Brain const &T)
{
	*this = T;
	return;
}

Brain &Brain::operator=(Brain const &T)
{
	if (this == &T)
		return (*this);
	return (*this);
}

Brain::~Brain(void)
{
	return;
}
