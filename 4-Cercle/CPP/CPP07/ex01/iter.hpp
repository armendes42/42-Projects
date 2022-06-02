/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:12:24 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 15:17:21 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void iter(T const *tab, size_t length, void(*f)(T const & arg))
{
  for (size_t i = 0; i < length; i++)
    f(tab[i]);
}

#endif
