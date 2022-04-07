/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:37:08 by armendes          #+#    #+#             */
/*   Updated: 2022/04/07 20:47:16 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main()
{
	std::string	entry;
	PhoneBook	repertory;

	while (true && entry.compare("EXIT") != 0 && !std::cin.eof())
	{
		std::cout << "Type your command: ";
		std::getline(std::cin, entry);
		if (entry.compare("ADD") == 0)
			repertory.add();
		if (entry.compare("SEARCH") == 0)
			repertory.search();
	}
	return (0);
}