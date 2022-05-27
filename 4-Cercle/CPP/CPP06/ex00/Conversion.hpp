/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:21:03 by armendes          #+#    #+#             */
/*   Updated: 2022/05/27 17:00:20 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <string>

class Conversion{

private:

  char _c;
  int _i;
  float _f;
  double _d;

public:
	Conversion(std::string str);
	Conversion(Conversion const &T);
	~Conversion(void);
	Conversion &operator=(Conversion const &T);

  char getChar(void) const;
  int getInt(void) const;
  float getFloat(void) const;
  double getDouble(void) const;

  bool isChar(std::string str);
  bool isInt(std::string str);
  bool isFloat(std::string str);
  bool isDouble(std::string str);

};

std::ostream	&operator<<(std::ostream &stdout, Conversion const &conv);

#endif
