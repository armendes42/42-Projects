/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:46:42 by armendes          #+#    #+#             */
/*   Updated: 2022/05/25 17:25:31 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed area(Point const a, Point const b, Point const c)
{
  Fixed aX, aY;
  Fixed bX, bY;
  Fixed cX, cY;
  Fixed aCoeff, bCoeff, cCoeff;
  Fixed value;

  aX = a.getX();
  aY = a.getY();
  bX = b.getX();
  bY = b.getY();
  cX = c.getX();
  cY = c.getY();
  aCoeff = aX * (bY - cY);
  bCoeff = bX * (cY - aY);
  cCoeff = cX * (aY - bY);
  value = (aCoeff + bCoeff + cCoeff) / 2;
  if (value < 0)
    return (value * (-1));
  return (value);
}

bool  check_for_summit(Point const a, Point const b, Point const c, Point const point)
{
  Fixed pX, pY;
  Fixed aX, aY;
  Fixed bX, bY;
  Fixed cX, cY;

  aX = a.getX();
  aY = a.getY();
  bX = b.getX();
  bY = b.getY();
  cX = c.getX();
  cY = c.getY();
  pX = point.getX();
  pY = point.getY();
  if (pX == aX && pY == aY)
    return (true);
  if (pX == bX && pY == bY)
    return (true);
  if (pX == cX && pY == cY)
    return (true);
  return (false);
}

bool  bsp(Point const a, Point const b, Point const c, Point const point)
{
  Fixed totalArea, sumArea;
  Fixed aArea, bArea, cArea;

  if (check_for_summit(a, b, c, point))
    return (false);

  totalArea = area(a, b, c);
  aArea = area(point, a, b);
  bArea = area(point, b, c);
  cArea = area(point, c, a);
  sumArea = aArea + bArea + cArea;

  if (totalArea == sumArea)
    return (true);
  return (false);
}
