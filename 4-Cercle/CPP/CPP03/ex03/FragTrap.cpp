/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:02:51 by armendes          #+#    #+#             */
/*   Updated: 2022/05/31 17:14:28 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
  std::cout << "FragTrap " << name << " is created!" << std::endl;
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
	return;
}

FragTrap::FragTrap(FragTrap const &T) : ClapTrap(T)
{
  std::cout << "Copy constructor FragTrap called" << std::endl;
	*this = T;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &T)
{
	if (this == &T)
		return (*this);
	return (*this);
}

FragTrap::~FragTrap(void)
{
  std::cout << "FragTrap " << this->getName() << " is destroyed!" << std::endl;
	return;
}

void FragTrap::attack(const std::string &target)
{
	if (this->getHitPoints() <= 0)
    std::cout << "FragTrap " << this->getName() << " is dead!" << std::endl;
  else if (this->getEnergyPoints() != 0)
  {
    std::cout << "FragTrap " << this->getName() << " attacks ";
    std::cout << target << ", causing " << this->getAttackDamage();
    std::cout << " points of damage!" << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
  }
  else
  {
    std::cout << "FragTrap " << this->getName();
    std::cout << " can't attack because he has no more Energy Points!" << std::endl;
  }
}

void FragTrap::highFivesGuys(void)
{
  if (this->getHitPoints() <= 0)
    std::cout << "FragTrap " << this->getName() << " is dead!" << std::endl;
  else
    std::cout << "Hey Guys do you want to high five?" << std::endl;
}
