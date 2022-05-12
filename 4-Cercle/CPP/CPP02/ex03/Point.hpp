/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:44:28 by armendes          #+#    #+#             */
/*   Updated: 2022/05/12 17:39:07 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

private:
  Fixed const _x;
  Fixed const _y;

public:
  Point(void);
  Point(const float x, const float y);
  Point(const Point &T);
  Point &operator=(const Point &T);
  ~Point(void);

  Fixed getX(void) const;
  Fixed getY(void) const;
};

#endif
