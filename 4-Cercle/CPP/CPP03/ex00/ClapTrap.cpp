/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:49:47 by armendes          #+#    #+#             */
/*   Updated: 2022/05/31 16:43:18 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(std::string name)
{
  std::cout << "ClapTrap " << name << " is created!" << std::endl;
  this->_name = name;
  this->_hitPoints = 10;
  this->_energyPoints = 10;
  this->_attackDamage = 0;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &T)
{
  std::cout << "Copy constructor called";
	*this = T;
	return;
}

ClapTrap  &ClapTrap::operator=(ClapTrap const &T)
{
  if (this == &T)
    return (*this);
  this->_name = T.getName();
  this->_hitPoints = T.getHitPoints();
  this->_energyPoints = T.getEnergyPoints();
  this->_attackDamage = T.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap(void)
{
  std::cout << "ClapTrap " << this->_name << " is destroyed!" << std::endl;
	return;
}

void ClapTrap::attack(const std::string &target)
{
  if (this->_hitPoints <= 0)
    std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
  else if (this->_energyPoints != 0)
  {
    std::cout << "ClapTrap " << this->_name << " attacks ";
    std::cout << target << ", causing " << this->_attackDamage;
    std::cout << " points of damage!" << std::endl;
    this->_energyPoints--;
  }
  else
  {
    std::cout << "ClapTrap " << this->_name;
    std::cout << " can't attack because he has no more Energy Points!" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount)
{
  if ((this->_hitPoints - (int)amount) <= 0)
    std::cout << "ClapTrap " << this->_name << " is attacked and dies!" << std::endl;
  else
  {
    std::cout << "ClapTrap " << this->_name << " is attacked and loses ";
    std::cout << amount << " Hit Points!" << std::endl;
  }
  this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (this->_hitPoints <= 0)
    std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
  else if (this->_energyPoints != 0)
  {
    std::cout << "ClapTrap " << this->_name << " is repaired by ";
    std::cout << amount << " points." << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints--;
  }
  else
  {
    std::cout << "ClapTrap " << this->_name;
    std::cout << " can't be repaired because he has no more Energy Points!" << std::endl;
  }
}

std::string ClapTrap::getName(void) const
{
  return (this->_name);
}

int ClapTrap::getHitPoints(void) const
{
  return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const
{
  return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const
{
  return (this->_attackDamage);
}

void ClapTrap::setName(std::string name)
{
  this->_name = name;
  return ;
}

void ClapTrap::setHitPoints(int nb)
{
  this->_hitPoints = nb;
  return ;
}

void ClapTrap::setEnergyPoints(int nb)
{
  this->_energyPoints = nb;
  return ;
}

void ClapTrap::setAttackDamage(int nb)
{
  this->_attackDamage = nb;
  return ;
}
