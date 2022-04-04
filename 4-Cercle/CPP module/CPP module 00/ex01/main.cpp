/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:37:08 by armendes          #+#    #+#             */
/*   Updated: 2022/04/04 20:41:20 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main()
{
	std::string	entry;

	std::cin >> entry;
	if (entry == "ADD")
		std::cout << "bonjour" << std::endl;
	return (0);
}