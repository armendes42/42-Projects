/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:40:15 by armendes          #+#    #+#             */
/*   Updated: 2022/04/26 16:17:07 by armendes         ###   ########.fr       */
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

void	PhoneBook::format_output( std::string line )
{
	int	len;
	int	space;

	if (line.length() > 10)
	{
		for (int i=0; i < 9; i++)
			std::cout << line[i];
		std::cout << ".";
	}
	else if (line.length() == 10)
	{
		for (int i=0; i < 10; i++)
			std::cout << line[i];
	}
	else
	{
		len = line.length();
		space = 10 - len;
		for (int i=0; i < space; i++)
			std::cout << " ";
		for (int i=0; i < len; i++)
			std::cout << line[i];
	}
}

void	PhoneBook::search( void )
{
	int			len__of_line;
	std::string	line;

	std::cout << "############################################" << std::endl;
	std::cout << "#                  PhoneBook               #" << std::endl;
	std::cout << "############################################" << std::endl;
	line = this->tabContact[0].getFirstName();
	if (line.empty() == true)
	{
		std::cout << "#            PhoneBook is empty            #" << std::endl;
		std::cout << "############################################" << std::endl;
	}
	else
	{
		for (int i=0; i < 8; i++)
		{
			std::cout << "#";
			line = this->tabContact[i].getId();
			if (line.empty() == false)
				format_output(line);
			std::cout << "|";
			line = this->tabContact[i].getFirstName();
			if (line.empty() == false)
				format_output(line);
			else
				break ;
			std::cout << "|";
			line = this->tabContact[i].getLastName();
			if (line.empty() == false)
				format_output(line);
			else
				break ;
			std::cout << "|";
			line = this->tabContact[i].getNickName();
			if (line.empty() == false)
				format_output(line);
			else
				break ;
			std::cout << "|";



			// if (this->tabContact[i].getId() > 7)
			// 	std::cout << this->tabContact[i].getId() - 8 << std::endl;
			// else
			// 	std::cout << this->tabContact[i].getId() << std::endl;
		}
	}
}