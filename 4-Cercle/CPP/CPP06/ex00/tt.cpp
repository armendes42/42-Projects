/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:54:27 by vserra            #+#    #+#             */
/*   Updated: 2022/02/21 12:09:48 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "castType.hpp"

/*
 * ./StaticCast 41555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
*/

int		main(int ac, char *av[])
{
	if (ac == 1)
		std::cout << "\033[1;33mMets des arguments ta race!\033[0m" << std::endl;
	if (ac != 2)
	{
		std::cout << std::endl << "Format: " << std::endl;
		std::cout << " ----------------- " << std::endl;
		std::cout << "| Char    | \"'a'\" |" << std::endl;
		std::cout << "| Int     | 42    |" << std::endl;
		std::cout << "| Float   | 42.0f |" << std::endl;
		std::cout << "| Double  | 42.0  |" << std::endl;
		std::cout << " ----------------- " << std::endl;
		return (0);
	}
	std::string arg(av[1]);
	if (arg.length() == 0)
	{
		std::cout << "\033[1;33mArguments vide!\033[0m" << std::endl;
		return (0);
	}

	int		t = detectType(arg);
	converter	converters[4] = {&fromChar, &fromInt, &fromFloat, &fromDouble};
	if (t == UNKNOWN)
		std::cout << "Unknown type" << std::endl;
	else
		converters[t](arg);
	return (0);
}