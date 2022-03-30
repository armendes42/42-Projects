/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:40:20 by armendes          #+#    #+#             */
/*   Updated: 2022/03/30 16:47:15 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact( void )
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Contact::~Contact( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}