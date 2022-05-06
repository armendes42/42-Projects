/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:14:17 by armendes          #+#    #+#             */
/*   Updated: 2022/05/06 18:52:26 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap " << name << " is created!" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &T)
{
	std::cout << "Copy constructor called";
	*this = T;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &T)
{
	if (this == &T)
		return (*this);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " is destroyed!" << std::endl;
	return;
}
