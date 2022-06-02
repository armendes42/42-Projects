/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:32:49 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 16:43:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <exception>

class NotFoundException : public std::exception
{
  public:
    virtual const char *what() const throw()
    {
      return ("Not found");
    }
}

template <typename T>
typename T::iterator easyfind(T &array, int n)
{
  typename T::iterator result = find(array.begin(), array.end(), n);

  if (result == array.end())
    throw NotFoundException();
  return (result);
}

#endif
