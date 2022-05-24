/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:10:25 by armendes          #+#    #+#             */
/*   Updated: 2022/05/24 19:48:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <string>

class Conversion{

private:


public:
	Conversion(void);
	Conversion(Conversion const &T);
	~Conversion(void);
	Conversion &operator=(Conversion const &T);

};

#endif
