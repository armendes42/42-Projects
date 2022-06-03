/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:56:49 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 16:24:40 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", target, 145, 137)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &T) : Form(T)
{
	*this = T;
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &T)
{
  if (this == &T)
    return (*this);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		Form::execute(executor);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	std::string str = this->getTarget() + "_shrubbery";
  std::ofstream file(str.c_str());
  if (file.is_open() == false)
    throw std::ofstream::failure("File: " + this->getTarget() + "_shrubbery can't be open");
  file << ASCII_TREES;
}
