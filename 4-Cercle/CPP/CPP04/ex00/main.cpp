/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:15:22 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:17:30 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  const WrongAnimal* a = new WrongAnimal();
  const WrongAnimal* b = new WrongCat();
  const WrongCat* c = new WrongCat();

  std::cout << a->getType() << " " << std::endl;
  std::cout << b->getType() << " " << std::endl;
  std::cout << c->getType() << " " << std::endl;
  a->makeSound();
  b->makeSound();
  c->makeSound();

  delete a;
  delete b;
  delete c;

  return 0;
}
