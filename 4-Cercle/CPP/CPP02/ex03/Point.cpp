/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:46:39 by armendes          #+#    #+#             */
/*   Updated: 2022/05/05 20:04:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
{
  this->_x = 0;
  this->_y = 0;
  return ;
}

Point::Point(const float x, const float y)
{
  this->_x = x;
  this->_y = y;
  return ;
}

Point::Point(const Point &T)
{
  *this = T;
  return ;
}

Point &Point::operator=(const Point &T)
{
  if (this == &T)
    return (*this);
  this->_x = T.getX();
  this->_y = T.getY();
  return (*this);
}

Point::~Point(void)
{
  return ;
}

Fixed Point::getX(void) const
{
  return (this->_x);
}

Fixed Point::getY(void) const
{
  return (this->_y);
}
