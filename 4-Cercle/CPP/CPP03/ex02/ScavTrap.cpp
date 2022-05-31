/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:14:17 by armendes          #+#    #+#             */
/*   Updated: 2022/05/31 16:52:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " is created!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	return;
}

ScavTrap::ScavTrap(ScavTrap const &T) : ClapTrap(T)
{
	std::cout << "Copy constructor ScavTrap called" << std::endl;
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
	std::cout << "ScavTrap " << this->getName() << " is destroyed!" << std::endl;
	return;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getHitPoints() <= 0)
    std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
  else if (this->getEnergyPoints() != 0)
  {
    std::cout << "ScavTrap " << this->getName() << " attacks ";
    std::cout << target << ", causing " << this->getAttackDamage();
    std::cout << " points of damage!" << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
  }
  else
  {
    std::cout << "ScavTrap " << this->getName();
    std::cout << " can't attack because he has no more Energy Points!" << std::endl;
  }
}

void ScavTrap::guardGate(void)
{
	if (this->getHitPoints() <= 0)
		std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
	else
		std::cout << "ScavTrap " << this->getName() << " has entered Gate Keeper mode!" << std::endl;
}
