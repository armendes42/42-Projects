/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:29 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 16:12:41 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main(void)
{
  try
  {
    Bureaucrat Billy("Billy", 2);
    Bureaucrat EvilBilly("EvilBilly", 1);
    std::cout << Billy << std::endl;
    std::cout << EvilBilly << std::endl;
    Form form1("First Form", 1, 1);
    // Form form2("Second Form", 0, 1);
    // Form form3("Third Form", 151, 1);
    std::cout << form1 << std::endl;
    Billy.signForm(form1);
    EvilBilly.signForm(form1);
    Billy.signForm(form1);
    Billy.upGrade();
    std::cout << Billy << std::endl;
    Billy.upGrade();
    std::cout << Billy << std::endl;
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  try
  {
    Bureaucrat Amine("Amine", 149);
    std::cout << Amine << std::endl;
    Amine.downGrade();
    std::cout << Amine << std::endl;
    Amine.downGrade();
    std::cout << Amine << std::endl;
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
}
