/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:49:45 by armendes          #+#    #+#             */
/*   Updated: 2022/05/31 16:59:31 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
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
  Foo.takeDamage(20);
  Foo.beRepaired(2);
  Foo.attack("Bar");
  std::cout << std::endl;

  ScavTrap Arthur("arthur");
  ScavTrap Scav(Arthur);
  Scav.setName("Scav");

  std::cout << std::endl;
  Arthur.attack("david");
  Scav.attack("sergiu");
  Arthur.guardGate();
  std::cout << "My name is " << Arthur.getName();
  std::cout << " and my hit points are " << Arthur.getHitPoints();
  std::cout << " and my energy points are " << Arthur.getEnergyPoints();
  std::cout << " and my attack damage are " << Arthur.getAttackDamage() << std::endl;
  std::cout << std::endl;

  FragTrap Frag("dupond");
  Frag.highFivesGuys();
  std::cout << "My name is " << Frag.getName();
  std::cout << " and my hit points are " << Frag.getHitPoints();
  std::cout << " and my energy points are " << Frag.getEnergyPoints();
  std::cout << " and my attack damage are " << Frag.getAttackDamage() << std::endl;
  std::cout << std::endl;

  DiamondTrap Diamond("bonjour");
  Diamond.whoAmI();
  std::cout << "My name is " << Diamond.getName();
  std::cout << " and my hit points are " << Diamond.getHitPoints();
  std::cout << " and my energy points are " << Diamond.getEnergyPoints();
  std::cout << " and my attack damage are " << Diamond.getAttackDamage() << std::endl;
  Diamond.attack("Barry");
  Diamond.highFivesGuys();
  Diamond.takeDamage(2020);
  Diamond.whoAmI();
  Diamond.attack("Barry");
  Diamond.highFivesGuys();
  std::cout << std::endl;

  return 0;
}
