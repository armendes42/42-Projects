/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:26:45 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 19:39:16 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array{

private:
  T * _array;
  unsigned int _size;

public:
	Array(void);
  Array(unsigned int n);
	Array(Array const &A);
	~Array(void);
	Array<T> &operator=(Array const &A);
  T &operator[](unsigned int const n) const;

  unsigned int size(void) const;

  class OutOfRangeException : public std::exception{

  public:
    virtual const char *what() const throw()
    {
      return ("Out of Range");
    }

  };

};

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
  return;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
  for (unsigned int i = 0; i < n; i++)
    this->_array[i] = T();
  return;
}

template <typename T>
Array<T>::Array(Array const &A) : _array(NULL), _size(0)
{
  *this = A;
  return;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &A)
{
  if (this == &A)
    return (*this);
  else
  {
    if (this->_size != 0 && this->_array != NULL && this->_size != A._size)
      delete[] this->_array;
    this->_size = A._size;
    this->_array = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++)
      this->_array[i] = A._array[i];
  }
  return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
  if (this->_array != NULL)
    delete[] this->_array;
}

template <typename T>
T &Array<T>::operator[](unsigned int n) const
{
  if (n >= this->_size)
    throw OutOfRangeException();
  return (this->_array[n]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
  return (this->_size);
}

#endif
