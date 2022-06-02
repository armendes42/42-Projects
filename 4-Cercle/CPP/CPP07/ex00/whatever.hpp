/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:02:21 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 15:10:46 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T>
void swap(T &a, T &b)
{
  T tmp = a;
  a = b;
  b = tmp;
};

template <typename T>
T &min(const T &a, const T &b)
{
  if (a < b)
   return (const_cast<T &>(a));
  return (const_cast<T &>(b));
}

template <typename T>
T &max(const T &a, const T &b)
{
  if (a > b)
   return (const_cast<T &>(a));
  return (const_cast<T &>(b));
}

#endif
