/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:21:45 by armendes          #+#    #+#             */
/*   Updated: 2022/05/09 19:10:55 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

Cat::Cat(void)
{
  std::cout << "A Cat has been created" << std::endl;
  this->type = "Cat";
	return;
}

Cat::Cat(Cat const &T)
{
  std::cout << "Copy constructor of Cat has been used" << std::endl;
	*this = T;
	return;
}

Cat &Cat::operator=(Cat const &T)
{
	if (this == &T)
		return (*this);
  this->type = T.type;
	return (*this);
}

Cat::~Cat(void)
{
  std::cout << "A Cat has been destroyed" << std::endl;
	return;
}

void Cat::makeSound(void) const
{
  std::cout << "Meow Meow" << std::endl;
}
