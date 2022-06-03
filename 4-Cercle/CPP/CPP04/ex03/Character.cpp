/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:16:15 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:56:24 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Character::Character(std::string name)
{
  std::cout << "A Character has been created" << std::endl;
  this->_name = name;
  for (int i = 0; i < 4; i++)
    this->_materiaTab[i] = NULL;
	return;
}

Character::Character(Character const &T)
{
  std::cout << "Copy constructor of Character has been used" << std::endl;
	*this = T;
	return;
}

Character &Character::operator=(Character const &T)
{
	if (this == &T)
		return (*this);
  for (int i = 0; i < 4; i++)
	{
		if (this->_materiaTab[i] != NULL)
		{
			delete this->_materiaTab[i];
			this->_materiaTab[i] = NULL;
		}
	}
  this->_name = T.getName();
  for (int i = 0; i < 4; i++)
  {
    if (this->_materiaTab[i] != NULL)
      equip(T._materiaTab[i]->clone());
    else
      this->_materiaTab[i] = NULL;
  }
	return (*this);
}

Character::~Character(void)
{
  std::cout << "A Character has been destroyed" << std::endl;
  for (int i = 0; i < 4; i++)
  {
    if (this->_materiaTab[i] != NULL)
      delete this->_materiaTab[i];
  }
  return;
}

std::string const & Character::getName(void) const
{
  return (this->_name);
}

void Character::equip(AMateria* m)
{
  if (m == NULL)
	{
		std::cout << "Invalid AMateria" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaTab[i] == NULL)
		{
		  this->_materiaTab[i] = m;
			std::cout << m->getType() << " has been added to " << this->_name << " inventory" << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	return ;
}

void Character::unequip(int idx)
{
  if (idx < 0 || idx > 3 || this->_materiaTab[idx] == NULL)
	{
		std::cout << "Nothing to unequip" << std::endl;
		return ;
	}
	std::cout << this->_materiaTab[idx]->getType() << " has been removed to " << this->_name << " inventory" << std::endl;
	this->_materiaTab[idx] = NULL;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
  if (idx < 0 || idx > 3 || this->_materiaTab[idx] == NULL)
	{
		std::cout << "Invalid AMateria to use" << std::endl;
		return ;
	}
	this->_materiaTab[idx]->use(target);
	return ;
}
