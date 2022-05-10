/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:15:22 by armendes          #+#    #+#             */
/*   Updated: 2022/05/10 16:29:02 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
  Animal* animalTab[10];
  for (int i = 0; i < 10; i++)
  {
    if (i % 2)
      animalTab[i] = new Dog();
    else
      animalTab[i] = new Cat();
  }

  for (int i = 0; i < 10; i++)
  {
    std::cout << "Animal 0: idea " << i << ": ";
    std::cout << animalTab[0]->getBrain()->ideas[i] << " / ";
    std::cout << "Animal 1: idea " << i << ": ";
    std::cout << animalTab[1]->getBrain()->ideas[i] << std::endl;
  }
  std::cout << std::endl;

  *(animalTab[1]) = *(animalTab[0]);

  for (int i = 0; i < 10; i++)
  {
    std::cout << "Animal 0: idea " << i << ": ";
    std::cout << animalTab[0]->getBrain()->ideas[i] << " / ";
    std::cout << "Animal 1: idea " << i << ": ";
    std::cout << animalTab[1]->getBrain()->ideas[i] << std::endl;
  }
  std::cout << std::endl;

  for (int i = 0; i < 10; i++)
  {
    delete animalTab[i];
  }

  return 0;
}
