/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:29:41 by armendes          #+#    #+#             */
/*   Updated: 2022/05/05 16:34:30 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a(10);
	Fixed b(20);
	bool verif_one = (a > b);

	Fixed c(30);
	Fixed d(20);
	bool verif_two = (c > d);

	std::cout << verif_one << std::endl;
	
	return 0;

}