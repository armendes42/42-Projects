/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:40:15 by armendes          #+#    #+#             */
/*   Updated: 2022/03/30 16:48:34 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook( void )
{
	std::cout << "Constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}