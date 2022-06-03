/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:48:45 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:23:13 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

Brain::Brain(void)
{
	std::cout << "A Brain has been created" << std::endl;

	const std::string txt[5] = {"I am a Dog!", "I am a Cat!",
													"I need sleep!", "I eat a lot!",
													"I love my life!"};

	for (int i = 0; i < 100; i++)
		this->ideas[i] = txt[rand() % 5];
	return;
}

Brain::Brain(Brain const &T)
{
	std::cout << "Copy constructor of Brain has been used" << std::endl;
	*this = T;
	return;
}

Brain &Brain::operator=(Brain const &T)
{
	if (this == &T)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = T.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "A Brain has been destroyed" << std::endl;
	return;
}
