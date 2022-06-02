/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:38:37 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 17:42:46 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <string>

Span::Span(void) : _array(NULL), _size(0)
{
	return;
}

Span::Span(unsigned int N) : _array(new int[N]), _size(N)
{
	return;
}

Span::Span(Span const &T)
{
	*this = T;
	return;
}

Span &Span::operator=(Span const &T)
{
	if (this == &T)
		return (*this);
  if (this->_size != 0 && this->_array != NULL && this->_size != T._size)
    delete[] this->_array;
  this->_size = T._size;
  this->_array = new int[this->_size];
  for (unsigned int i = 0; i < this->_size; i++)
    this->_array[i] = T._array[i];
	return (*this);
}

Span::~Span(void)
{
  if (this->_array != NULL)
    delete[] this->_array;
	return;
}
