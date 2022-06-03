/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:05:01 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 16:31:09 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

Intern::Intern(void)
{
	std::cout << "An Intern has been created" << std::endl;
	return;
}

Intern::Intern(Intern const &T)
{
	*this = T;
	return;
}

Intern &Intern::operator=(Intern const &T)
{
	if (this == &T)
		return (*this);
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "An Intern has been destroyed" << std::endl;
	return;
}

Form *Intern::makeForm(std::string nameForm, std::string target)
{
  t_form_struct formList[] =
  {
    {"shrubbery creation", new ShrubberyCreationForm(target)},
    {"robotomy request", new RobotomyRequestForm(target)},
    {"presidential pardon", new PresidentialPardonForm(target)},
    {"", NULL}
  };

  Form *new_form = NULL;

  for (int i = 0; formList[i].formType != NULL; i++)
  {
    if (nameForm.compare(formList[i].formName) == 0)
      new_form = formList[i].formType;
    else
      delete formList[i].formType;
  }

  if (new_form == NULL)
    std::cout << "Intern didn't find the form " << nameForm << std::endl;
  else
    std::cout << "Intern creates the form " << nameForm << std::endl;

  return (new_form);
}
