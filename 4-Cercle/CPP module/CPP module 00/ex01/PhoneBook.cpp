/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:40:15 by armendes          #+#    #+#             */
/*   Updated: 2022/04/04 20:37:06 by armendes         ###   ########.fr       */
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

void	PhoneBook::setContact( int id )
{
	tabContact[id % 8] = this;
}