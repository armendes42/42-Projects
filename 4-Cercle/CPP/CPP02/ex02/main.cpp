/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:29:41 by armendes          #+#    #+#             */
/*   Updated: 2022/05/25 17:14:58 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a(10);
	Fixed b(10);
	bool verif_one = (a > b);
	std::cout << verif_one << std::endl;
	verif_one = (a < b);
	std::cout << verif_one << std::endl;
	verif_one = (a >= b);
	std::cout << verif_one << std::endl;
	verif_one = (a <= b);
	std::cout << verif_one << std::endl;
	verif_one = (a == b);
	std::cout << verif_one << std::endl;
	verif_one = (a != b);
	std::cout << verif_one << std::endl;

	std::cout << std::endl;

	Fixed c(a + b);
	std::cout << c << std::endl;
	c = (a - b);
	std::cout << c << std::endl;
	c = (a * b);
	std::cout << c << std::endl;
	c = (a / b);
	std::cout << c << std::endl;

	std::cout << std::endl;

	std::cout << "pre a " << a++ << std::endl;
	std::cout << "post a " << a << std::endl;
	std::cout << "pre a " << ++a << std::endl;
	std::cout << "post a " << a << std::endl;
	std::cout << "pre a " << a-- << std::endl;
	std::cout << "post a " << a << std::endl;
	std::cout << "pre a " << --a << std::endl;
	std::cout << "post a " << a << std::endl;

	std::cout << std::endl;

	Fixed d;
	Fixed const e( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << d << std::endl;
	std::cout << ++d << std::endl;
	std::cout << d << std::endl;
	std::cout << d++ << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << Fixed::max( d, e ) << std::endl;

	return 0;

}
