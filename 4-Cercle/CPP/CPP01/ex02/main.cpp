/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:30:27 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 18:44:03 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "The memory address of the str variable is: " << &str << std::endl;
	std::cout << "The memory address hold by the stringPTR variable is: " << stringPTR << std::endl;
	std::cout << "The memory address hold by the stringREF variable is: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the str variable is: " << str << std::endl;
	std::cout << "The value pointed to by the stringPTR variable is: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by the stringREF variable is: " << stringREF << std::endl;
}