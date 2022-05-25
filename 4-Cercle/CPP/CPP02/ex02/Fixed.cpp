/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:29:37 by armendes          #+#    #+#             */
/*   Updated: 2022/05/25 17:16:04 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_nb_of_bytes = 8;

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return ;
}

Fixed::Fixed(int const value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = (value << Fixed::_nb_of_bytes);
	return ;
}

Fixed::Fixed(float const value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_nb_of_bytes));
	return ;
}

Fixed::Fixed(const Fixed &T)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = T;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &T)
{
	// std::cout << "Copy assignement operator called" << std::endl;
	if (this == &T)
		return (*this);
	this->_value = T.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &T) const
{
	// std::cout << "More than operator called" << std::endl;
	if (this == &T)
		return (false);
	if (this->_value > T.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &T) const
{
	// std::cout << "Less than operator called" << std::endl;
	if (this == &T)
		return (false);
	if (this->_value < T.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &T) const
{
	// std::cout << "More than or equal operator called" << std::endl;
	if (this == &T)
		return (true);
	if (this->_value >= T.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &T) const
{
	// std::cout << "Less than equal operator called" << std::endl;
	if (this == &T)
		return (true);
	if (this->_value <= T.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &T) const
{
	// std::cout << "Equal operator called" << std::endl;
	if (this == &T)
		return (true);
	if (this->_value == T.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &T) const
{
	// std::cout << "Not equal operator called" << std::endl;
	if (this == &T)
		return (false);
	if (this->_value != T.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &T)
{
	// std::cout << "Plus operator called" << std::endl;
	Fixed	new_fix(*this);

	new_fix.setRawBits(this->_value + T.getRawBits());
	return (new_fix);
}

Fixed	Fixed::operator-(const Fixed &T)
{
	// std::cout << "Minus operator called" << std::endl;
	Fixed	new_fix(*this);

	new_fix.setRawBits(this->_value - T.getRawBits());
	return (new_fix);
}

Fixed	Fixed::operator*(const Fixed &T)
{
	// std::cout << "Product operator called" << std::endl;
	Fixed	new_fix(*this);
	long tmp1;
	long tmp2;

	tmp1 = (long)this->_value;
	tmp2 = (long)T.getRawBits();
	new_fix.setRawBits((tmp1 * tmp2) / (1 << Fixed::_nb_of_bytes));
	return (new_fix);
}

Fixed	Fixed::operator/(const Fixed &T)
{
	// std::cout << "Divide operator called" << std::endl;
	Fixed	new_fix(*this);
	long tmp1;
	long tmp2;

	tmp1 = (long)this->_value;
	tmp2 = (long)T.getRawBits();
	new_fix.setRawBits(tmp1 * (1 << Fixed::_nb_of_bytes) / tmp2);
	return (new_fix);
}

Fixed	Fixed::operator++()
{
	// std::cout << "Pre incrementation operator called" << std::endl;
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	// std::cout << "Post incrementation operator called" << std::endl;
	Fixed	new_fix(*this);

	operator++();
	return (new_fix);
}

Fixed	Fixed::operator--()
{
	// std::cout << "Pre decrementation operator called" << std::endl;
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	// std::cout << "Post decrementation operator called" << std::endl;
	Fixed	new_fix(*this);

	operator--();
	return (new_fix);
}

std::ostream	&operator<<(std::ostream &stdout, Fixed const &value)
{
	stdout << value.toFloat();
	return (stdout);
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
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

Fixed	&Fixed::min(Fixed &T1, Fixed &T2)
{
	if (T1 > T2)
		return (T2);
	return (T1);
}

Fixed	&Fixed::max(Fixed &T1, Fixed &T2)
{
	if (T1 > T2)
		return (T1);
	return (T2);
}

Fixed const	&Fixed::min(Fixed const &T1, Fixed const &T2)
{
	if (T1 > T2)
		return (T2);
	return (T1);
}

Fixed const	&Fixed::max(Fixed const &T1, Fixed const &T2)
{
	if (T1 > T2)
		return (T1);
	return (T2);
}
