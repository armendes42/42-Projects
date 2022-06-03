/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:39:40 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 16:36:43 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
  Base *ptr;
  srand(time(NULL));
  int i = rand() % 3;
  if (i == 0)
    ptr = new A();
  if (i == 1)
    ptr = new B();
  if (i == 2)
    ptr = new C();
  return (ptr);
}

void identify(Base *p)
{
  if (p == NULL)
    std::cout << "It's NULL" << std::endl;
  else if (dynamic_cast<A *>(p))
    std::cout << "It's an A!" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "It's a B!" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "It's a C!" << std::endl;
}

void identify(Base &p)
{
  try
  {
    (void)dynamic_cast<A &>(p);
    std::cout << "It's an A!" << std::endl;
  }
  catch (std::exception &e)
  {}
  try
  {
    (void)dynamic_cast<B &>(p);
    std::cout << "It's a B!" << std::endl;
  }
  catch (std::exception &e)
  {}
  try
  {
    (void)dynamic_cast<C &>(p);
    std::cout << "It's a C!" << std::endl;
  }
  catch (std::exception &e)
  {}
}

int main(void)
{
  Base *ptr = generate();
  Base *ptr1 = NULL;
  Base *ptr2 = new A();
  Base *ptr3 = new B();
  Base *ptr4 = new C();

  identify(ptr);
  identify(ptr1);
  identify(ptr2);
  identify(ptr3);
  identify(ptr4);

  std::cout << std::endl;

  Base &tmp = *ptr;
  Base &tmp2 = *ptr2;
  Base &tmp3 = *ptr3;
  Base &tmp4 = *ptr4;

  identify(tmp);
  identify(tmp2);
  identify(tmp3);
  identify(tmp4);
}
