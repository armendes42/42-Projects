/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:56:59 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 20:24:44 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", target, 72, 45)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &T) : Form(T)
{
	*this = T;
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &T)
{
  if (this == &T)
    return (*this);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

void RobotomyRequestForm::action(Bureaucrat const & executor) const
{
  srand(time(NULL));
  int random = rand() % 2;

	this->execute(executor);
  std::cout << "* Drilling Noises *, ";
  if (random == 0)
    std::cout << executor.getName() << " has been perfectly robotomised. * Drilling Noises *" << std::endl;
  if (random == 1)
    std::cout << "The robotomisation has failed. * Drilling Noises *" << std::endl;
}
