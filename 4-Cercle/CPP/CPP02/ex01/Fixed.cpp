/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:29:37 by armendes          #+#    #+#             */
/*   Updated: 2022/05/05 19:55:32 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_nb_of_bytes = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return ;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = (value << Fixed::_nb_of_bytes);
	return ;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_nb_of_bytes));
	return ;
}

Fixed::Fixed(const Fixed &T)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = T;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &T)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this == &T)
		return (*this);
	this->_value = T.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stdout, Fixed const &value)
{
	stdout << value.toFloat();
	return (stdout);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << Fixed::_nb_of_bytes));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_nb_of_bytes);
}
