/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:22:01 by armendes          #+#    #+#             */
/*   Updated: 2022/05/09 19:10:59 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Dog::Dog(void)
{
  std::cout << "A Dog has been created" << std::endl;
  this->type = "Dog";
	return;
}

Dog::Dog(Dog const &T)
{
  std::cout << "Copy constructor of Dog has been used" << std::endl;
	*this = T;
	return;
}

Dog &Dog::operator=(Dog const &T)
{
	if (this == &T)
		return (*this);
  this->type = T.type;
	return (*this);
}

Dog::~Dog(void)
{
  std::cout << "A Dog has been destroyed" << std::endl;
	return;
}

void Dog::makeSound(void) const
{
  std::cout << "Woof Woof" << std::endl;
}
