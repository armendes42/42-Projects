/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:06:05 by armendes          #+#    #+#             */
/*   Updated: 2022/05/27 17:23:47 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Conversion::Conversion(std::string str)
{
	if (isChar(str))
	{
		this->_c = str[0]; //changer ca;
		this->_i = static_cast<int>(this->_c);
		this->_f = static_cast<float>(this->_c);
		this->_d = static_cast<double>(this->_c);
	}
	else if (isInt(str))
	{
		this->_i = stoi(str); // changer ca;
		this->_c = static_cast<char>(this->_i);
		this->_f = static_cast<float>(this->_i);
		this->_d = static_cast<double>(this->_i);
	}
	else if (isFloat(str))
	{
		this->_f = stof(str); // changer ca;
		this->_c = static_cast<char>(this->_f);
		this->_i = static_cast<int>(this->_f);
		this->_d = static_cast<double>(this->_f);
	}
	else if (isDouble(str))
	{
		this->_d = stod(str); // changer ca;
		this->_c = static_cast<char>(this->_d);
		this->_i = static_cast<int>(this->_d);
		this->_f = static_cast<float>(this->_d);
	}
	else
	{
		this->_c = '0';
		this->_i = 0;
		this->_f = 0;
		this->_d = 0;
		std::cout << "X" << std::endl;
	}
	return;
}

Conversion::Conversion(Conversion const &T)
{
	*this = T;
	return;
}

Conversion &Conversion::operator=(Conversion const &T)
{
	if (this == &T)
		return (*this);
	this->_c = T.getChar();
	this->_i = T.getInt();
	this->_f = T.getFloat();
	this->_d = T.getDouble();
	return (*this);
}

Conversion::~Conversion(void)
{
	return;
}

char Conversion::getChar(void) const
{
  return (this->_c);
}

int Conversion::getInt(void) const
{
	return (this->_i);
}

float Conversion::getFloat(void) const
{
	return (this->_f);
}

double Conversion::getDouble(void) const
{
	return (this->_d);
}

bool Conversion::isChar(std::string str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (true);
	else if (str.length() == 1)
		return (true);
	return (false);
}

bool Conversion::isInt(std::string str)
{
	if (str.length() >= 2 && ((str[0] == '+' && str[1] == '-') || (str[0] == '-' && str[1] == '+')))
		return (false);
	if (str.find_first_of("+") != str.find_last_of("+"))
		return (false);
	if (str.find_first_of("-") != str.find_last_of("-"))
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && !isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (false);
		if (i != 0 && !isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool Conversion::isFloat(std::string str)
{
	if (str.length() >= 2 && ((str[0] == '+' && str[1] == '-') || (str[0] == '-' && str[1] == '+')))
		return (false);
	if (str.find_first_of("+") != str.find_last_of("+"))
		return (false);
	if (str.find_first_of("-") != str.find_last_of("-"))
		return (false);
	if (str.find_first_of(".") != str.find_last_of("."))
		return (false);
	if (str.find_first_of("f") != str.find_last_of("f"))
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && !isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (false);
		if (i == (str.length() - 1) && str[i] != 'f')
			return (false);
		if (i != 0 && i != (str.length() - 1) && !isdigit(str[i]) && str[i] != '.')
			return (false);
	}
	return (true);
}

bool Conversion::isDouble(std::string str)
{
	if (str.length() >= 2 && ((str[0] == '+' && str[1] == '-') || (str[0] == '-' && str[1] == '+')))
		return (false);
	if (str.find_first_of("+") != str.find_last_of("+"))
		return (false);
	if (str.find_first_of("-") != str.find_last_of("-"))
		return (false);
	if (str.find_first_of(".") != str.find_last_of("."))
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && !isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (false);
		if (i != 0 && !isdigit(str[i]) && str[i] != '.')
			return (false);
	}
	return (true);
}

std::ostream	&operator<<(std::ostream &stdout, Conversion const &conv)
{
	stdout << "char: ";
	if (conv.getInt() < 0 || conv.getInt() > 127)
		stdout << "Not displayable" << std::endl;
	else if ((conv.getInt() >= 0 && conv.getInt() < 32) || conv.getInt() == 127)
		stdout << "Not displayable" << std::endl;
	else
		stdout << conv.getChar() << std::endl;

	stdout << "int: " << conv.getInt() << std::endl;

	stdout << "float: " << conv.getFloat();
	float f = conv.getFloat() - conv.getInt();
	if (f == 0.0)
		stdout << ".0";
	stdout << "f" << std::endl;

	stdout << "double: " << conv.getDouble();
	double d = conv.getDouble() - conv.getInt();
	if (d == 0.0)
		stdout << ".0";
	stdout << std::endl;
	return (stdout);
}
