/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:29:39 by armendes          #+#    #+#             */
/*   Updated: 2022/05/05 16:30:27 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

private:
	int	_value;
	static const int	_nb_of_bytes;

public:
	Fixed(void);
	Fixed(int const value);
	Fixed(float const value);
	Fixed(const Fixed &T);

	Fixed &operator=(const Fixed &T);

	bool operator>(const Fixed &T) const;
	bool operator<(const Fixed &T) const;
	bool operator>=(const Fixed &T) const;
	bool operator<=(const Fixed &T) const;
	bool operator==(const Fixed &T) const;
	bool operator!=(const Fixed &T) const;

	Fixed operator+(const Fixed &T);
	Fixed operator-(const Fixed &T);
	Fixed operator*(const Fixed &T);
	Fixed operator/(const Fixed &T);

	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	~Fixed(void);

	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed &min(Fixed &T1, Fixed &T2);
	static Fixed &max(Fixed &T1, Fixed &T2);
	static Fixed const &min(Fixed const &T1, Fixed const &T2);
	static Fixed const &max(Fixed const &T1, Fixed const &T2);

};

std::ostream &operator<<(std::ostream &stdout, Fixed const &value);

#endif
