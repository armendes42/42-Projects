/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:30:37 by tinaserra         #+#    #+#             */
/*   Updated: 2022/02/20 19:49:01 by tinaserra        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "castType.hpp"

bool	detectChar(std::string str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

bool	detectInt(std::string str)
{
	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return false;
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return false;
	for (size_t i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool	detectFloat(std::string str)
{
	size_t	i;
	bool	d = false;

	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return false;
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return false;
	for (i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (i == str.length() - 1)
				return (str[i] == 'f');
			if (str[i] == '.')
			{
				if (d)
					return false;
				d = true;
			}
			else
				return false;
		}
	}
	return false;
}

bool	detectDouble(std::string str)
{
	size_t	i;
	bool	d = false;

	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return false;
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return false;
	for (i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (d)
					return false;
				d = true;
			}
			else
				return false;
		}
	}
	return true;
}

int		checkException(std::string str)
{
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return FLOAT;
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return DOUBLE;
	return UNKNOWN;
}

int		detectType(std::string str)
{
	int i;

	if ((i = checkException(str)) != UNKNOWN)
		return i;
	if (detectChar(str))
		return CHAR;
	if (detectInt(str))
		return INT;
	if (detectFloat(str))
		return FLOAT;
	if (detectDouble(str))
		return DOUBLE;
	return UNKNOWN;
}