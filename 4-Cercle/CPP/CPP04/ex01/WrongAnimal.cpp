/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:06:44 by armendes          #+#    #+#             */
/*   Updated: 2022/05/10 16:19:07 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(void)
{
  std::cout << "A Wrong Animal has been created" << std::endl;
  this->type = "WrongAnimal";
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const &T)
{
  std::cout << "Copy constructor of Wrong Animal has been used" << std::endl;
	*this = T;
	return;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &T)
{
	if (this == &T)
		return (*this);
  this->type = T.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
  std::cout << "A Wrong Animal has been destroyed" << std::endl;
	return;
}

void WrongAnimal::makeSound(void) const
{
  std::cout << "* Wrong Noises *" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
  return (this->type);
}
