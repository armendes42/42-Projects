/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:34:51 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:55:03 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <string>

int main(void)
{
  MateriaSource* source = new MateriaSource();
  source->learnMateria(new Ice());
  source->learnMateria(new Cure());
  source->learnMateria(new Ice());
  source->learnMateria(new Cure());
  AMateria* ice = new Ice();
  source->learnMateria(ice);
  delete ice;

  ICharacter* me = new Character("me");

  AMateria* temp;
  temp = source->createMateria("ice");
  me->equip(temp);
  temp = source->createMateria("cure");
  me->equip(temp);
  temp = source->createMateria("cur");

  ICharacter* BOB = new Character("BOB");

  me->use(0, *BOB);
  me->use(1, *BOB);

  delete BOB;
  delete me;
  delete source;

  MateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* moi = new Character("moi");

  AMateria* tmp = NULL;
  AMateria* tmp2 = NULL;
  tmp = src->createMateria("ice");
  moi->equip(tmp);
  std::cout << "[+] ICE = " << tmp->getType() << std::endl;

  tmp2 = src->createMateria("cure");
  moi->equip(tmp2);
  std::cout << "[+] CURE = " << tmp2->getType() << std::endl;

  ICharacter* bob = new Character("bob");

  moi->use(0, *bob);
  moi->use(1, *bob);
  std::cout << "[+] " << tmp->getType() << std::endl;
  std::cout << "[+] " << tmp2->getType() << std::endl;


  moi->use(0, *bob);
  std::cout << "[+] " << tmp->getType() << std::endl;
  std::cout << "[+] " << tmp2->getType() << std::endl;

  delete bob;
  delete moi;
  delete src;

  return 0;
}
