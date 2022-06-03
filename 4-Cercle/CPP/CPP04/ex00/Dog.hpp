/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:22:15 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:22:00 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Dog : public Animal{

public:
	Dog(void);
	Dog(Dog const &T);
	virtual ~Dog(void);
	Dog &operator=(Dog const &T);

  void makeSound(void) const;

};

#endif
