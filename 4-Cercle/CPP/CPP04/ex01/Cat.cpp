/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:21:45 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 18:28:35 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Cat::Cat(void)
{
  std::cout << "A Cat has been created" << std::endl;
  this->type = "Cat";
  this->_brain = new Brain();
	return;
}

Cat::Cat(Cat const &T)
{
  std::cout << "Copy constructor of Cat has been used" << std::endl;
  this->_brain = new Brain();
	*this = T;
	return;
}

Cat &Cat::operator=(Cat const &T)
{
	if (this == &T)
		return (*this);
  this->type = T.getType();
  *(this->_brain) = *(T.getBrain());
	return (*this);
}

Animal &Cat::operator=(Animal const &T)
{
	if (this == &T)
		return (*this);
  this->type = T.getType();
  *(this->_brain) = *(T.getBrain());
	return (*this);
}

Cat::~Cat(void)
{
  std::cout << "A Cat has been destroyed" << std::endl;
  delete this->_brain;
	return;
}

void Cat::makeSound(void) const
{
  std::cout << "Meow Meow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
  return (this->_brain);
}
