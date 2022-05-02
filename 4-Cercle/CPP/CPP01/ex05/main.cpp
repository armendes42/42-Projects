/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:52:54 by armendes          #+#    #+#             */
/*   Updated: 2022/05/02 19:26:23 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	Karen;

	Karen.complain("debug");
	std::cout << std::endl;
	Karen.complain("error");
	std::cout << std::endl;
	Karen.complain("info");
	std::cout << std::endl;
	Karen.complain("warning");
	std::cout << std::endl;
}