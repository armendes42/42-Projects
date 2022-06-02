/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:38:37 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 19:30:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <string>

Span::Span(void) : _size(0)
{
	return;
}

Span::Span(unsigned int N) : _size(N)
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
  this->_size = T._size;
  this->_array = T._array;
	return (*this);
}

Span::~Span(void)
{
	return;
}

std::vector<int> Span::getArray(void) const
{
  return (this->_array);
}

void Span::addNumber(int n)
{
  if (this->_array.size() < this->_size)
    this->_array.push_back(n);
  else
    throw SpanFullException();
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
  if ((end - begin) <= this->_size)
    this->_array.insert(this->_array.end(), begin, end);
  else
    throw NotEnoughSpaceException();
}

unsigned int Span::shortestSpan(void)
{
  if (this->_array.size() <= 1)
    throw LittleSpanException();

  std::sort(this->_array.begin(), this->_array.end());
  int min = 0;
  bool first = true;
  for (size_t i = 0; i < this->_array.size() - 1; i++)
  {
    if (first || this->_array[i + 1] - this->_array[i] < min)
    {
      min = this->_array[i + 1] - this->_array[i];
      first = false;
    }
  }
  return (min);
}

unsigned int Span::longestSpan(void)
{
  if (this->_array.size() <= 1)
    throw LittleSpanException();

  int min = *std::min_element(this->_array.begin(), this->_array.end());
  int max = *std::max_element(this->_array.begin(), this->_array.end());
  return (max - min);
}

std::ostream &	operator<<(std::ostream & stdout, Span const &span)
{
	std::vector<int>	array = span.getArray();

	for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
	{
		stdout << *it;
		if (it != array.end() - 1)
			stdout << " ";
	}
	return (stdout);
}
