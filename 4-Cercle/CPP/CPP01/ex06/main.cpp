/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:52:54 by armendes          #+#    #+#             */
/*   Updated: 2022/05/02 19:53:33 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	std::string	level;
	Harl		Karen;

	if (argc != 2)
	{
		std::cerr << "You must enter a level!" << std::endl;
		return (0);
	}
	else
	{
		level = argv[1];
		Karen.switchComplain(level);
	}
}