/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:35:53 by armendes          #+#    #+#             */
/*   Updated: 2022/05/10 16:45:47 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria(std::string const & type)
{
	std::cout << "An AMateria has been created" << std::endl;
	this->_type = type;
	return;
}

AMateria::AMateria(AMateria const &T)
{
	std::cout << "Copy constructor of AMateria has been used" << std::endl;
	*this = T;
	return;
}

AMateria &AMateria::operator=(AMateria const &T)
{
	if (this == &T)
		return (*this);
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "An AMateria has been destroyed" << std::endl;
	return;
}
