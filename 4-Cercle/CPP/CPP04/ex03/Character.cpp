/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:16:15 by armendes          #+#    #+#             */
/*   Updated: 2022/05/11 18:18:20 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Character::Character(std::string name)
{
  // std::cout << "A Character has been created" << std::endl;
  this->_name = name;
  for (int i = 0; i < 4; i++)
    this->_materiaTab[i] = NULL;
	return;
}

Character::Character(Character const &T)
{
  // std::cout << "Copy constructor of Character has been used" << std::endl;
	*this = T;
	return;
}

Character &Character::operator=(Character const &T)
{
	if (this == &T)
		return (*this);
  this->_name = T._name;
  for (int i = 0; i < 4; i++)
  {
    if (this->_materiaTab[i])
      delete this->_materiaTab[i];
    this->_materiaTab[i] = T._materiaTab[i];
  }
	return (*this);
}

Character::~Character(void)
{
  // std::cout << "A Character has been destroyed" << std::endl;
  for (int i = 0; i < 4; i++)
  {
    if (this->_materiaTab[i])
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
  int i = 0;
  while (this->_materiaTab[i] != NULL && i < 4)
    i++;
  if (i == 4)
  {
    std::cout << "The inventory is full!" << std::endl;
    return;
  }
  this->_materiaTab[i] = m;
}

void Character::unequip(int idx)
{
  if (idx < 0 || idx > 3)
  {
    std::cout << "The index is too low or too big!" << std::endl;
    return;
  }
  if (this->_materiaTab[idx] == NULL)
  {
    std::cout << "There is no Materia at this index!" << std::endl;
    return;
  }
  this->_materiaTab[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
  if (idx < 0 || idx > 3)
  {
    std::cout << "The index is too low or too big!" << std::endl;
    return;
  }
  if (this->_materiaTab[idx] == NULL)
  {
    std::cout << "There is no Materia at this index!" << std::endl;
    return;
  }
  this->_materiaTab[idx]->use(target);
}
