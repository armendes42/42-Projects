/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:17:42 by armendes          #+#    #+#             */
/*   Updated: 2022/05/10 16:20:01 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(void)
{
	std::cout << "An Animal has been created" << std::endl;
	this->type = "Animal";
	return;
}

Animal::Animal(Animal const &T)
{
	std::cout << "Copy constructor of Animal has been used" << std::endl;
	*this = T;
	return;
}

Animal &Animal::operator=(Animal const &T)
{
	if (this == &T)
		return (*this);
	this->type = T.getType();
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "An Animal has been destroyed" << std::endl;
	return;
}

void Animal::makeSound(void) const
{
	std::cout << "* Noises *" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}
