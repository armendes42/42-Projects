/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:29:41 by armendes          #+#    #+#             */
/*   Updated: 2022/05/05 20:44:56 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool  bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(-4, 4);
	Point b(-2, 4);
	Point c(-3, 2);

	// Point inside the triangle
	Point point1(-3, 3);
	std::cout << bsp(a, b, c, point1) << std::endl;

	// Point outside the triangle
	Point point2(-3, 5);
	std::cout << bsp(a, b, c, point2) << std::endl;

	// Point on a summit
	Point point3(-3, 2);
	std::cout << bsp(a, b, c, point3) << std::endl;

	// Point on an edge
	Point point4(-2.46f, 3.09f);
	std::cout << bsp(a, b, c, point4) << std::endl;

	return 0;

}
