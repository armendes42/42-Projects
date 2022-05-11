/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:54:30 by armendes          #+#    #+#             */
/*   Updated: 2022/05/11 18:18:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

MateriaSource::MateriaSource(void)
{
  // std::cout << "A MateriaSource has been created" << std::endl;
  for (int i = 0; i < 4; i++)
    this->_materiaLearnTab[i] = NULL;
	return;
}

MateriaSource::MateriaSource(MateriaSource const &T)
{
  // std::cout << "Copy constructor of MateriaSource has been used" << std::endl;
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
    this->_materiaLearnTab[i] = T._materiaLearnTab[i];
  }
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
  // std::cout << "A MateriaSource has been destroyed" << std::endl;
  for (int i = 0; i < 4; i++)
  {
    if (this->_materiaLearnTab[i])
      delete this->_materiaLearnTab[i];
  }
	return;
}

void MateriaSource::learnMateria(AMateria* m)
{
  int i = 0;
  while (this->_materiaLearnTab[i] != NULL && i < 4)
    i++;
  if (i == 4)
  {
    std::cout << "This Materia Source can't learn more Materia" << std::endl;
    return;
  }
  this->_materiaLearnTab[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
  int i = 0;
  while (this->_materiaLearnTab[i] != NULL && i < 4)
  {
    if (this->_materiaLearnTab[i]->getType() == type)
      return (this->_materiaLearnTab[i]->clone());
    i++;
  }
  std::cout << "The type of the Materia is unknown!" << std::endl;
  return (0);
}
