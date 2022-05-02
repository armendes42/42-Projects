/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:29:39 by armendes          #+#    #+#             */
/*   Updated: 2022/05/02 20:48:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

private:
	int	_nb;
	static const int	_nb_of_bytes;

public:
	Fixed(void);
	Fixed(const Fixed &T);
	Fixed &operator=(const Fixed &T);
	~Fixed(void);

	int	getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif