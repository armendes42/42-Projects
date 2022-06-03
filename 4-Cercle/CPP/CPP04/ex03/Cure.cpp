/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:42:08 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:53:58 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

Cure::Cure(void) : AMateria("cure")
{
  std::cout << "A Cure has been created" << std::endl;
	return;
}

Cure::Cure(Cure const &T) : AMateria(T)
{
  std::cout << "Copy constructor of Cure has been used" << std::endl;
	*this = T;
	return;
}

Cure &Cure::operator=(Cure const &T)
{
	if (this == &T)
		return (*this);
	return (*this);
}

Cure::~Cure(void)
{
  std::cout << "A Cure has been destroyed" << std::endl;
	return;
}

AMateria* Cure::clone(void) const
{
  AMateria *new_cure = new Cure();
  return (new_cure);
}

void Cure::use(ICharacter& target)
{
  std::cout << "* heals " << target.getName();
  std::cout << "'s wounds *" << std::endl;
}
