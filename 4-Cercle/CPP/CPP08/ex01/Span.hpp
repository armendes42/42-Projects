/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:23:12 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 17:43:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>

class Span{

private:
  int *_array;
  unsigned int _size;

public:
	Span(void);
  Span(unsigned int N);
	Span(Span const &T);
	~Span(void);
	Span &operator=(Span const &T);

  void addNumber

};

#endif
