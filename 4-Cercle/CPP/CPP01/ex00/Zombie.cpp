/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:43:45 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 16:20:54 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	this->name = name;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "The zombie " << this->name << " has been destroyed" << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

std::string	Zombie::getName(void)
{
	return (this->name);
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}