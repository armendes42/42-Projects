/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:20:48 by armendes          #+#    #+#             */
/*   Updated: 2022/05/27 18:39:50 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "Put an argument with these forms:" << std::endl;
    std::cout << "For a char: \"'a'\"" << std::endl;
    std::cout << "For an int: 42" << std::endl;
    std::cout << "For a float: 42.0f" << std::endl;
    std::cout << "For a double: 42.0" << std::endl;
    return (1);
  }
  std::string str = argv[1];
  Conversion conv(str);
  std::cout << conv;
}
