/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:29 by armendes          #+#    #+#             */
/*   Updated: 2022/05/12 16:17:23 by armendes         ###   ########.fr       */
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
    std::cout << Billy << std::endl;
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
