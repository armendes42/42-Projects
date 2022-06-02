/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:23:12 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 19:27:09 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Span{

private:
  std::vector<int> _array;
  unsigned int _size;

public:
	Span(void);
  Span(unsigned int N);
	Span(Span const &T);
	~Span(void);
	Span &operator=(Span const &T);

  std::vector<int> getArray(void) const;

  void addNumber(int n);
  void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
  unsigned int shortestSpan(void);
  unsigned int longestSpan(void);

  class SpanFullException : public std::exception
  {
    public:
      virtual const char *what() const throw()
      {
        return ("The Span is full!");
      }
  };

  class LittleSpanException : public std::exception
  {
    public:
      virtual const char *what() const throw()
      {
        return ("The Span is empty or to little!");
      }
  };

  class NotEnoughSpaceException : public std::exception
  {
    public:
      virtual const char *what() const throw()
      {
        return ("The Span is to little to store the range!");
      }
  };

};

std::ostream &	operator<<(std::ostream & stdout, Span const &span);

#endif
