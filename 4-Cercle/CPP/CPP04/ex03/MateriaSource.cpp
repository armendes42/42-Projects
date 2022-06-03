/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:54:30 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:56:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

MateriaSource::MateriaSource(void)
{
  std::cout << "A MateriaSource has been created" << std::endl;
  for (int i = 0; i < 4; i++)
    this->_materiaLearnTab[i] = NULL;
	return;
}

MateriaSource::MateriaSource(MateriaSource const &T)
{
  std::cout << "Copy constructor of MateriaSource has been used" << std::endl;
	*this = T;
	return;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &T)
{
	if (this == &T)
		return (*this);
  for (int i = 0; i < 4; i++)
  {
    if (this->_materiaLearnTab[i])
      delete this->_materiaLearnTab[i];
    this->_materiaLearnTab[i] = T._materiaLearnTab[i]->clone();
  }
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
  std::cout << "A MateriaSource has been destroyed" << std::endl;
  for (int i = 0; i < 4; i++)
  {
    if (this->_materiaLearnTab[i] != NULL)
      delete this->_materiaLearnTab[i];
  }
	return;
}

void MateriaSource::learnMateria(AMateria* m)
{
  if (m == NULL)
  {
    std::cout << "No Materia to learn" << std::endl;
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    if (this->_materiaLearnTab[i] == NULL)
    {
      this->_materiaLearnTab[i] = m;
      std::cout << m->getType() << " has been learned" << std::endl;
      return;
    }
  }
  std::cout << "This Materia Source can't learn more Materia" << std::endl;
  return;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
  if (type != "ice" && type != "cure")
    return (NULL);
  for (int i = 0; i < 4; i++)
	{
		if (this->_materiaLearnTab[i] != NULL && !this->_materiaLearnTab[i]->getType().compare(type))
		{
			std::cout << type << " has been created" << std::endl;
			return (this->_materiaLearnTab[i]->clone());
		}
	}
  std::cout << "The type of the Materia is unknown!" << std::endl;
  return (NULL);
}
