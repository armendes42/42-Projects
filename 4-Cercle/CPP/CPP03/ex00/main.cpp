/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:49:45 by armendes          #+#    #+#             */
/*   Updated: 2022/05/31 16:43:02 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
  ClapTrap Foo("Foo");

  std::cout << Foo.getName() << " has " << Foo.getHitPoints() << " Hit Points!" << std::endl;
  Foo.beRepaired(5);
  std::cout << Foo.getName() << " now has " << Foo.getHitPoints() << " Hit Points!" << std::endl;
  Foo.takeDamage(5);
  std::cout << Foo.getName() << " now has " << Foo.getHitPoints() << " Hit Points!" << std::endl;
  std::cout << std::endl;
  for (int i = 0; i < 12; i++)
  {
    std::cout << Foo.getName() << " has " << Foo.getEnergyPoints() << " EnergyPoints!" << std::endl;
    Foo.attack("Bar");
  }
  std::cout << std::endl;
  Foo.beRepaired(5);

  Foo.takeDamage(20);
  Foo.beRepaired(2);
  Foo.attack("Bar");

  return 0;
}
