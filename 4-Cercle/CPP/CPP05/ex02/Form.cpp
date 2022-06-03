/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:21:21 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 16:15:06 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <string>

const int Form::highestGrade = 1;
const int Form::lowestGrade = 150;

Form::Form(std::string name, std::string target, int sign_grade, int exec_grade) : _name(name), _target(target), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
  this->_signed = false;
  if (sign_grade < highestGrade || exec_grade < highestGrade)
    throw GradeTooHighException();
  if (sign_grade > lowestGrade || exec_grade > lowestGrade)
    throw GradeTooLowException();
  std::cout << "A Form has been created" << std::endl;
	return;
}

Form::Form(Form const &T) : _name(T._name), _sign_grade(T._sign_grade), _exec_grade(T._exec_grade)
{
  std::cout << "Copy constructor of Form has been used" << std::endl;
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
  std::cout << "A Form has been destroyed" << std::endl;
	return;
}

std::string Form::getName(void) const
{
  return (this->_name);
}

std::string Form::getTarget(void) const
{
  return (this->_target);
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

void Form::beSigned(Bureaucrat &person)
{
  if (this->_signed == true)
    throw AlreadySignedException();
  if (person.getGrade() <= this->_sign_grade)
  {
    std::cout << "The form " << this->_name << " has been signed by " << person.getName() << std::endl;
    this->_signed = true;
  }
  else
    throw GradeTooLowException();
}

void Form::execute(Bureaucrat const & executor) const
{
  if (this->_signed == false)
    throw NotSignedException();
  if (executor.getGrade() > this->_exec_grade)
    throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &stdout, Form const &form)
{
  stdout << form.getName() << ", ";
  if (form.getSigned() == true)
    stdout << "is signed";
  else
    stdout << "is not signed";
  stdout << ", grade required for signing: " << form.getSignGrade();
  stdout << ", grade required for executing: " << form.getExecGrade();
  stdout << ".";
  return (stdout);
}
