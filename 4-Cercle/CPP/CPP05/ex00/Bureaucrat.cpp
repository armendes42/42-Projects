/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:58 by armendes          #+#    #+#             */
/*   Updated: 2022/05/11 18:42:02 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat(std::string name, int grade)
{
  std::cout << "A Bureaucrat has been created" << std::endl;
  try
  {

  }
  catch (int )
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
