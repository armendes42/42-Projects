/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:22:01 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 18:28:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Dog::Dog(void)
{
  std::cout << "A Dog has been created" << std::endl;
  this->type = "Dog";
  this->_brain = new Brain();
	return;
}

Dog::Dog(Dog const &T)
{
  std::cout << "Copy constructor of Dog has been used" << std::endl;
  this->_brain = new Brain();
	*this = T;
	return;
}

Dog &Dog::operator=(Dog const &T)
{
	if (this == &T)
		return (*this);
  this->type = T.getType();
  *(this->_brain) = *(T.getBrain());
	return (*this);
}

Animal &Dog::operator=(Animal const &T)
{
	if (this == &T)
		return (*this);
  this->type = T.getType();
  *(this->_brain) = *(T.getBrain());
	return (*this);
}

Dog::~Dog(void)
{
  std::cout << "A Dog has been destroyed" << std::endl;
  delete this->_brain;
	return;
}

void Dog::makeSound(void) const
{
  std::cout << "Woof Woof" << std::endl;
}

Brain *Dog::getBrain(void) const
{
  return (this->_brain);
}
