/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:42:04 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:53:32 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

Ice::Ice(void) : AMateria("ice")
{
  std::cout << "An Ice has been created" << std::endl;
	return;
}

Ice::Ice(Ice const &T) : AMateria(T)
{
  std::cout << "Copy constructor of Ice has been used" << std::endl;
	*this = T;
	return;
}

Ice &Ice::operator=(Ice const &T)
{
	if (this == &T)
		return (*this);
	return (*this);
}

Ice::~Ice(void)
{
  std::cout << "An Ice has been destroyed" << std::endl;
	return;
}

AMateria* Ice::clone(void) const
{
  AMateria *new_ice = new Ice();
  return (new_ice);
}

void Ice::use(ICharacter& target)
{
  std::cout << "* shoots an ice bolt at " << target.getName();
  std::cout << " *" << std::endl;
}
