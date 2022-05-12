/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:21:21 by armendes          #+#    #+#             */
/*   Updated: 2022/05/12 17:25:16 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <string>

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
  // std::cout << "A Form has been created" << std::endl;
  this->_signed = false;
  if (sign_grade < highestGrade || exec_grade < hid)
	return;
}

Form::Form(Form const &T)
{
  // std::cout << "Copy constructor of Form has been used" << std::endl;
	*this = T;
	return;
}

Form &Form::operator=(Form const &T)
{
  if (this == &T)
		return (*this);
  this->_signed = T._signed;
	return *this;
}

Form::~Form(void)
{
  // std::cout << "A Form has been destroyed" << std::endl;
	return;
}

std::string Form::getName(void) const
{
  return (this->_name);
}

bool Form::getSigned(void) const
{
  return (this->_signed);
}

int Form::getSignGrade(void) const
{
  return (this->_sign_grade);
}

int Form::getExecGrade(void) const
{
  return (this->_exec_grade);
}

int Form::beSigned(Bureaucrat &person)
{
  if (this->_signed == true)
  {
    std::cout << "The form " << this->_name << " is already signed" << std::endl;
    return (1);
  }
  if (person.getGrade() <= this->_sign_grade)
  {
    std::cout << "The form " << this->_name << " has been signed by " << person.getName() << std::endl;
    this->_signed = true;
    return (0);
  }
  else
  {
    throw GradeTooLowException();
    return (2);
  }
}

std::ostream &operator<<(std::ostream &stdout, Form const &form)
{
  stdout << form.getName() << ", ";
  if (form.getSigned() == true)
    stdout << "is signed ";
  else
    stdout << "is not signed ";
  stdout << ", grade required for signing: " << form.getSignGrade();
  stdout << ", grade required for executing: " << form.getExecGrade();
  stdout << ".";
  return (stdout);
}
