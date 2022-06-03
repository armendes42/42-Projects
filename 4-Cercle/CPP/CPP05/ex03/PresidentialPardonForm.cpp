/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:57:04 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 16:24:58 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", target, 25, 5)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &T) : Form(T)
{
	*this = T;
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &T)
{
  if (this == &T)
    return (*this);
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
  std::cout << executor.getName() << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}
