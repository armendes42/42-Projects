/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:49:45 by armendes          #+#    #+#             */
/*   Updated: 2022/05/09 16:01:37 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
  ClapTrap Foo("Foo");

  std::cout << Foo.getName() << " has " << Foo.getHitPoints() << " Hit Points!" << std::endl;
  Foo.beRepaired(5);
  std::cout << Foo.getName() << " now has " << Foo.getHitPoints() << " Hit Points!" << std::endl;
  Foo.takeDamage(5);
  std::cout << Foo.getName() << " now has " << Foo.getHitPoints() << " Hit Points!" << std::endl;
  std::cout << std::endl;
  Foo.setEnergyPoints(10);
  for (int i = 0; i < 12; i++)
  {
    std::cout << Foo.getName() << " has " << Foo.getEnergyPoints() << " EnergyPoints!" << std::endl;
    Foo.attack("Bar");
  }
  std::cout << std::endl;
  Foo.beRepaired(5);
  std::cout << std::endl;

  ScavTrap Arthur("arthur");
  ScavTrap Scav(Arthur);
  Scav.setName("Scav");

  std::cout << std::endl;
  Arthur.attack("david");
  Scav.attack("sergiu");
  Arthur.guardGate();
  std::cout << std::endl;

  return 0;
}
