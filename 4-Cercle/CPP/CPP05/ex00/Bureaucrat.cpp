/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:58 by armendes          #+#    #+#             */
/*   Updated: 2022/05/12 16:17:06 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
  if (grade < highestGrade)
    throw GradeTooHighException();
  if (grade > lowestGrade)
    throw GradeTooLowException();
  std::cout << "A Bureaucrat has been created" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &T)
{
  std::cout << "Copy constructor of Bureaucrat has been used" << std::endl;
	*this = T;
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &T)
{
	if (this == &T)
		return (*this);
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
  std::cout << "A Bureaucrat has been destroyed" << std::endl;
	return;
}

std::string const Bureaucrat::getName(void) const
{
  return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
  return (this->_grade);
}

void Bureaucrat::upGrade(void)
{
  int tmpGrade = this->getGrade();
  tmpGrade--;
  if (tmpGrade < highestGrade)
    throw GradeTooHighException();
  this->_grade = tmpGrade;
}

void Bureaucrat::downGrade(void)
{
  int tmpGrade = this->getGrade();
  tmpGrade++;
  if (tmpGrade > lowestGrade)
    throw GradeTooLowException();
  this->_grade = tmpGrade;
}

std::ostream	&operator<<(std::ostream &stdout, Bureaucrat const &person)
{
	stdout << person.getName() << ", bureaucrat grade " << person.getGrade() << ".";
	return (stdout);
}
