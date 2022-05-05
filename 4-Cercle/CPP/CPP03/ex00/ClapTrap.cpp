/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:49:47 by armendes          #+#    #+#             */
/*   Updated: 2022/05/05 21:12:04 by armendes         ###   ########.fr       */
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
  std::cout << "ClapTrap " << name << " is created!" << std::endl;
	*this = src;
	return;
}

ClapTrap  &ClapTrap::operator=(ClapTrap const &T)
{
  if (this == &T)
    return (*this);
  this->_name = T.getName();
  this->_hitPoints = t.getHitPoints();
  this->_energyPoints = T.getEnergyPoints();
  this->_attackDamage = T.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap(void)
{
  std::cout << "ClapTrap " << this->_name << " is destroyed!" << std::endl;
	return;
}

void attack(const std::string &target)
{
  std::cout << "Claptrap " << this.getName() << " attacks ";
  std::cout << target << ", causing " << this.get
}

std::string getName(void)
{
  return (this->_name);
}

int getHitPoints(void)
{
  return (this->_hitPoints);
}

int getEnergyPoints(void)
{
  return (this->_energyPoints);
}

int getAttackDamage(void)
{
  return (this->_attackDamage);
}

void setHitPoints(int nb)
{
  this->_hitPoints = nb;
  return ;
}

void setEnergyPoints(int nb)
{
  this->_energyPoints = nb;
  return ;
}

void setAttackDamage(int nb)
{
  this->_attackDamage = nb;
  return ;
}
