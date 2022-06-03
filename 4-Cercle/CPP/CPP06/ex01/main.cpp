/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:57:35 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 16:35:49 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

typedef struct Data
{
  int i;
  float f;
} Data;

uintptr_t serialize(Data* ptr)
{
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
  Data ptr;
  ptr.i = 23;
  ptr.f = 42.5;

  std::cout << "I = " << ptr.i << std::endl;
  std::cout << "F = " << ptr.f << std::endl;

  uintptr_t raw = serialize(&ptr);
  Data * tmp = deserialize(raw);

  std::cout << "I = " << tmp->i << std::endl;
  std::cout << "F = " << tmp->f << std::endl;

  std::cout << tmp->i + 4 << std::endl;
  std::cout << tmp->f + 4 << std::endl;
}
