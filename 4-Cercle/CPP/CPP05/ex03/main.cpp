/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:29 by armendes          #+#    #+#             */
/*   Updated: 2022/05/16 17:19:37 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>

int main()
{
  Intern        usefulIdiot;
  Bureaucrat    paul("Paul", 3);
  Form        *form;
  
  form = usefulIdiot.makeForm("this one doesn't exist", "Justin");
  if (form)
      delete form;
  form = usefulIdiot.makeForm("presidential pardon", "Maynard");
  if (form)
      delete form;
  form = usefulIdiot.makeForm("shrubbery creation", "Danny");
  if (form)
      delete form;
  form = usefulIdiot.makeForm("robotomy request", "Adam");
  form->beSigned(paul);
  form->execute(paul);
  if (form)
      delete form;

    return 0;
}
