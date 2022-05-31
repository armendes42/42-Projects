/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:29:47 by armendes          #+#    #+#             */
/*   Updated: 2022/05/31 16:58:03 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name), ClapTrap(name)
{
  std::cout << "DiamondTrap " << name << " is created!" << std::endl;
  ClapTrap::_name = name + "_clap_name";
  this->_name = name;
  this->_hitPoints = FragTrap::_hitPoints;
  this->_energyPoints = ScavTrap::_energyPoints;
  this->_attackDamage = FragTrap::_attackDamage;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const &T) : ScavTrap(T), FragTrap(T), ClapTrap(T)
{
  std::cout << "Copy constructor DiamondTrap called" << std::endl;
	*this = T;
	return;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &T)
{
	if (this == &T)
		return (*this);
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
  std::cout << "DiamondTrap " << this->getName() << " is destroyed!" << std::endl;
	return;
}

void DiamondTrap::attack(const std::string &target)
{
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
  if (this->getHitPoints() <= 0)
    std::cout << "DiamondTrap " << this->_name << " is dead!" << std::endl;
  else
  {
    std::cout << "My name is " << this->_name << " and my ClapTrap name is ";
    std::cout << ClapTrap::_name << std::endl;
  }
}

std::string DiamondTrap::getName(void) const
{
  return (this->_name);
}

int DiamondTrap::getHitPoints(void) const
{
  return (this->_hitPoints);
}

int DiamondTrap::getEnergyPoints(void) const
{
  return (this->_energyPoints);
}

int DiamondTrap::getAttackDamage(void) const
{
  return (this->_attackDamage);
}
