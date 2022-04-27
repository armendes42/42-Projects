/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:40:15 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 15:42:43 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <math.h>

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::setContact(Contact contact)
{
	int	id;

	id = contact.getId();
	tabContact[id % 8] = contact;
}

void	PhoneBook::add(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	Contact		contact;

	while (firstName.empty() == true && !std::cin.eof())
	{
		std::cout << "Enter the first name: ";
		std::getline(std::cin, firstName);
	}
	while (lastName.empty() == true && !std::cin.eof())
	{
		std::cout << "Enter the last name: ";
		std::getline(std::cin, lastName);
	}
	while (nickName.empty() == true && !std::cin.eof())
	{
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, nickName);
	}
	while (phoneNumber.empty() == true && !std::cin.eof())
	{
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, phoneNumber);
	}
	while (darkestSecret.empty() == true && !std::cin.eof())
	{
		std::cout << "Enter the darkest secret: ";
		std::getline(std::cin, darkestSecret);
	}

	contact.setContact(firstName,
						lastName,
						nickName,
						phoneNumber,
						darkestSecret);
	this->setContact(contact);
}

void	PhoneBook::format_output(std::string line)
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

void	PhoneBook::format_id(int id)
{
	int	len;
	int	copy_of_id;
	int	space;

	len = 0;
	if (id > 7)
		id -= 8;
	copy_of_id = id;
	while (copy_of_id != 0)
	{
		copy_of_id /= 10;
		len++;
	}
	if (id == 0)
		len = 1;
	if (len > 10)
	{
		id = id / (int)pow(10, (len - 10));
		std::cout << copy_of_id;
		std::cout << ".";
	}
	else if (len == 10)
		std::cout << id;
	else
	{
		space = 10 - len;
		for (int i=0; i < space; i++)
			std::cout << " ";
		std::cout << id;
	}
}

int		PhoneBook::check_id(int id)
{
	for (int i=0; i < 8; i++)
	{
		if (id == this->tabContact[i].getId())
			return (1);
	}
	return (0);
}

void	PhoneBook::print_the_contact(int id)
{
	if (id < 0)
		std::cout << "The index must be positive and on the list" << std::endl;
	else
	{
		id += 8;
		if (check_id(id) == 0)
		{
			std::cout << "The index is not on the list" << std::endl;
			return ;
		}
		id %= 8;
		if (this->tabContact[id].getFirstName().empty() == true)
		{
			std::cout << "The index is not on the list" << std::endl;
		}
		else
		{
			std::cout << "First Name : " << this->tabContact[id].getFirstName() << std::endl;
			std::cout << "Last Name : " << this->tabContact[id].getLastName() << std::endl;
			std::cout << "NickName : " << this->tabContact[id].getNickName() << std::endl;
			std::cout << "Phone Number : " << this->tabContact[id].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret : " << this->tabContact[id].getDarkestSecret() << std::endl;
		}
	}
}

void	PhoneBook::search(void)
{
	std::string	line;
	int			id;
	std::string index;

	std::cout << "#############################################" << std::endl;
	std::cout << "#                  PhoneBook                #" << std::endl;
	std::cout << "#############################################" << std::endl;
	line = this->tabContact[0].getFirstName();
	if (line.empty() == true)
	{
		std::cout << "#            PhoneBook is empty             #" << std::endl;
		std::cout << "#############################################" << std::endl;
	}
	else
	{
		std::cout << "#     Index|First Name| Last Name| Nick Name#" << std::endl;
		std::cout << "#############################################" << std::endl;
		for (int i=0; i < 8; i++)
		{
			line = this->tabContact[i].getFirstName();
			if (line.empty() == true)
			{
				std::cout << "#############################################" << std::endl;
				break ;
			}
			else
			{
				std::cout << "#";
				id = this->tabContact[i].getId();
					format_id(id);
				std::cout << "|";
				line = this->tabContact[i].getFirstName();
				if (line.empty() == false)
					format_output(line);
				std::cout << "|";
				line = this->tabContact[i].getLastName();
				if (line.empty() == false)
					format_output(line);
				std::cout << "|";
				line = this->tabContact[i].getNickName();
				if (line.empty() == false)
					format_output(line);
				std::cout << "#" << std::endl;
			}
		}
		if (line.empty() == false)
			std::cout << "#############################################" << std::endl;
		while (index.empty() == true && !std::cin.eof())
		{
			std::cout << "Enter the index of the contact you want: ";
			std::getline(std::cin, index);
		}
		if (!std::cin.eof())
		{
			id = atoi(index.c_str());
			print_the_contact(id);
		}
	}
}