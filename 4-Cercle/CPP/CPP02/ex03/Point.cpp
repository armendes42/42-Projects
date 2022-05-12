/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:46:39 by armendes          #+#    #+#             */
/*   Updated: 2022/05/12 17:39:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
  return ;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
  return ;
}

Point::Point(const Point &T) : _x(T._x), _y(T._y)
{
  *this = T;
  return ;
}

Point &Point::operator=(const Point &T)
{
  if (this == &T)
    return (*this);
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
