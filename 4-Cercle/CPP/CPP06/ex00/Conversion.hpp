/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:21:03 by armendes          #+#    #+#             */
/*   Updated: 2022/05/31 15:29:16 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <string>

class Conversion{

private:

  char _c;
  long _i;
  float _f;
  double _d;
  std::string _special;
  bool _b;
  bool _flow_int;
  bool _flow_float;
  bool _flow_double;

public:
	Conversion(std::string str);
	Conversion(Conversion const &T);
	~Conversion(void);
	Conversion &operator=(Conversion const &T);

  char getChar(void) const;
  long getInt(void) const;
  float getFloat(void) const;
  double getDouble(void) const;
  std::string getSpecial(void) const;
  bool getBool(void) const;
  bool getFlowInt(void) const;
  bool getFlowFloat(void) const;
  bool getFlowDouble(void) const;

  void setFlowInt(bool b);

  bool isSpecial(std::string str);
  bool isInf(std::string str);
  bool isMinusInf(std::string str);
  bool isNan(std::string str);
  bool isChar(std::string str);
  bool isInt(std::string str);
  bool isFloat(std::string str);
  bool isDouble(std::string str);

  char toChar(std::string str);
  long toInt(std::string str);
  float toFloat(std::string str);
  double toDouble(std::string str);

};

std::ostream	&operator<<(std::ostream &stdout, Conversion const &conv);

#endif
