/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:40:15 by armendes          #+#    #+#             */
/*   Updated: 2022/04/07 20:47:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook( void )
{
	return;
}

PhoneBook::~PhoneBook( void )
{
	return;
}

void	PhoneBook::setContact( Contact contact )
{
	int	id;

	id = contact.getId();
	tabContact[id % 8] = contact;
}

void	PhoneBook::add( void )
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	Contact		contact;

	std::cout << "Enter the first name: ";
	std::cin >> firstName;
	std::cout << "Enter the last name: ";
	std::cin >> lastName;
	std::cout << "Enter the nickname: ";
	std::cin >> nickName;
	std::cout << "Enter the phone number: ";
	std::cin >> phoneNumber;
	std::cout << "Enter the darkest secret: ";
	std::cin >> darkestSecret;

	contact.setContact(firstName,
						lastName,
						nickName,
						phoneNumber,
						darkestSecret);
	this->setContact(contact);
}

void	PhoneBook::search( void )
{
	for(int i=0; i < 8; i++)
	{
		if (this->tabContact[i].getId() > 7)
			std::cout << this->tabContact[i].getId() - 8 << std::endl;
		else
			std::cout << this->tabContact[i].getId() << std::endl;
	}
}