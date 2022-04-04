/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:40:20 by armendes          #+#    #+#             */
/*   Updated: 2022/04/04 20:32:43 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

int	Contact::nbContact = 0;

Contact::Contact( void )
{
	std::cout << "Constructor called" << std::endl;
	this->id = this->nbContact;
	this->nbContact++;
	return;
}

Contact::~Contact( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

std::string	Contact::getFirstName( void	)
{
	return (this->firstName);
}

std::string	Contact::getLastName( void )
{
	return (this->lastName);
}

std::string	Contact::getNickName( void )
{
	return (this->nickName);
}

std::string	Contact::getPhoneNumber( void )
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret( void )
{
	return (this->darkestSecret);
}

int			Contact::getId( void )
{
	return (this->id);
}

void	Contact::setFirstName( std::string firstName )
{
	this->firstName = firstName;
}

void	Contact::setLastName( std::string lastName )
{
	this->lastName = lastName;
}

void	Contact::setNickName( std::string nickName )
{
	this->nickName = nickName;
}

void	Contact::setPhoneNumber( std::string phoneNumber )
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret( std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

void	Contact::setContact( std::string firstName,
							std::string lastName,
							std::string nickName,
							std::string phoneNumber,
							std::string darkestSecret )
{
	setFirstName(firstName);
	setLastName(lastName);
	setNickName(nickName);
	setPhoneNumber(phoneNumber);
	setDarkestSecret(darkestSecret);
}