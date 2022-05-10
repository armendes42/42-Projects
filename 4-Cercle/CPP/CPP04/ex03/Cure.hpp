/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:41:59 by armendes          #+#    #+#             */
/*   Updated: 2022/05/10 16:52:34 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Cure : public AMateria{

public:
	Cure(void);
	Cure(Cure const &T);
	~Cure(void);
	Cure &operator=(Cure const &T);

  AMateria* clone() const;

};

#endif
