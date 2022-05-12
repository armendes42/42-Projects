/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:29 by armendes          #+#    #+#             */
/*   Updated: 2022/05/12 19:55:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

void test_form(Form &form, Bureaucrat &correct, Bureaucrat &wrong)
{
    wrong.signForm(form);
    correct.executeForm(form);
    correct.signForm(form);
    wrong.executeForm(form);
    correct.executeForm(form);
}

int main()
{
    Bureaucrat right("right", 1);
    Bureaucrat wrong("wrong", 150);

    ShrubberyCreationForm form1("target");
    RobotomyRequestForm form2("target");
    PresidentialPardonForm form3("target");
    test_form(form1, right, wrong);
    std::cout << std::endl;
    test_form(form2, right, wrong);
    std::cout << std::endl;
    test_form(form3, right, wrong);
    std::cout << std::endl;

    return 0;
}
