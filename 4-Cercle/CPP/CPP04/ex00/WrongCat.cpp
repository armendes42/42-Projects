/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:07:20 by armendes          #+#    #+#             */
/*   Updated: 2022/05/09 19:46:44 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat(void)
{
  std::cout << "A Wrong Cat has been created" << std::endl;
  this->type = "WrongCat";
	return;
}

WrongCat::WrongCat(WrongCat const &T)
{
  std::cout << "Copy constructor of Wrong Cat has been used" << std::endl;
	*this = T;
	return;
}

WrongCat &WrongCat::operator=(WrongCat const &T)
{
	if (this == &T)
		return (*this);
  this->type = T.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
  std::cout << "A Wrong Cat has been destroyed" << std::endl;
	return;
}

void WrongCat::makeSound(void) const
{
  std::cout << "Strange Meow" << std::endl;
}
