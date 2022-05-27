/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:06:05 by armendes          #+#    #+#             */
/*   Updated: 2022/05/27 19:45:20 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "errno.h"

Conversion::Conversion(std::string str)
{
	this->_b = false;
	if (isSpecial(str))
	{
		if (isInf(str))
			this->_special = "+inf";
		else if (isMinusInf(str))
			this->_special = "-inf";
		else if (isNan(str))
			this->_special = "nan";
	}
	else if (isChar(str))
	{
		this->_c = toChar(str);
		this->_i = static_cast<int>(this->_c);
		this->_f = static_cast<float>(this->_c);
		this->_d = static_cast<double>(this->_c);
		this->_special = "NULL";
	}
	else if (isInt(str))
	{
		this->_i = toInt(str);
		this->_c = static_cast<char>(this->_i);
		this->_f = static_cast<float>(this->_i);
		this->_d = static_cast<double>(this->_i);
		this->_special = "NULL";
	}
	else if (isFloat(str))
	{
		this->_f = toFloat(str);
		this->_c = static_cast<char>(this->_f);
		this->_i = static_cast<int>(this->_f);
		this->_d = static_cast<double>(this->_f);
		this->_special = "NULL";
	}
	else if (isDouble(str))
	{
		this->_d = toDouble(str);
		this->_c = static_cast<char>(this->_d);
		this->_i = static_cast<int>(this->_d);
		this->_f = static_cast<float>(this->_d);
		this->_special = "NULL";
	}
	else
		this->_b = true;
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
	this->_special = T.getSpecial();
	this->_b = T.getBool();
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

std::string Conversion::getSpecial(void) const
{
	return (this->_special);
}

bool Conversion::getBool(void) const
{
	return (this->_b);
}

bool Conversion::isSpecial(std::string str)
{
	std::string strTab[] = {
		"+inf", "-inf", "nan",
		"+inff", "-inff", "nanf"
	};

	for (int i = 0; i < 6; i++)
		if (str.compare(strTab[i]) == 0)
			return (true);
	return (false);
}

bool Conversion::isInf(std::string str)
{
	if (str.compare("+inf") == 0 || str.compare("+inff") == 0)
		return (true);
	return (false);
}

bool Conversion::isMinusInf(std::string str)
{
	if (str.compare("-inf") == 0 || str.compare("-inff") == 0)
		return (true);
	return (false);
}

bool Conversion::isNan(std::string str)
{
	if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		return (true);
	return (false);
}

bool Conversion::isChar(std::string str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
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

char Conversion::toChar(std::string str)
{
	if (str.length() == 3)
		return (str[1]);
	return (str[0]);
}

int Conversion::toInt(std::string str)
{
	long result = strtol(str.c_str(), NULL, 10);
	if (result < std::numeric_limits<int>::min || result > std::numeric_limits<int>::max)
	{
		errno = ERANGE;
		return (0);
	}
	return (static_cast<int>(result));
}

float Conversion::toFloat(std::string str)
{
	return (strtof(str.c_str(), NULL));
}

double Conversion::toDouble(std::string str)
{
	return (strtod(str.c_str(), NULL));
}

std::ostream	&operator<<(std::ostream &stdout, Conversion const &conv)
{
	if (conv.getBool() == true)
	{
		stdout << "char: impossible" << std::endl;
		stdout << "int: impossible" << std::endl;
		stdout << "float: impossible" << std::endl;
		stdout << "double: impossible" << std::endl;
		return (stdout);
	}

	//char
	stdout << "char: ";
	if (conv.getSpecial().compare("NULL"))
		stdout << "impossible" << std::endl;
	else if (conv.getInt() < 0 || conv.getInt() > 127)
		stdout << "Not displayable" << std::endl;
	else if ((conv.getInt() >= 0 && conv.getInt() < 32) || conv.getInt() == 127)
		stdout << "Not displayable" << std::endl;
	else
		stdout << conv.getChar() << std::endl;

	//int
	stdout << "int: ";
	if (conv.getSpecial().compare("NULL"))
		stdout << "impossible" << std::endl;
	else if (conv.getInt() < INT_MIN || conv.getInt() > INT_MAX)
		stdout << "underflow or overflow" << std::endl;
	else
		stdout << conv.getInt() << std::endl;

	//float
	stdout << "float: ";
	if (conv.getSpecial().compare("NULL"))
		stdout << conv.getSpecial();
	else
	{
		stdout << conv.getFloat();
		float f = conv.getFloat() - conv.getInt();
		if (f == 0.0)
			stdout << ".0";
	}
	stdout << "f" << std::endl;

	//double
	stdout << "double: ";
	if (conv.getSpecial().compare("NULL"))
		stdout << conv.getSpecial();
	else
	{
		stdout << conv.getDouble();
		double d = conv.getDouble() - conv.getInt();
		if (d == 0.0)
			stdout << ".0";
	}
	stdout << std::endl;
	return (stdout);
}
