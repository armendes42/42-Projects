/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:22:15 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:25:04 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Dog : public Animal{

private:
	Brain *_brain;

public:
	Dog(void);
	Dog(Dog const &T);
	virtual ~Dog(void);
	Dog &operator=(Dog const &T);
	virtual Animal &operator=(Animal const &T);

  void makeSound(void) const;

	Brain *getBrain(void) const;

};

#endif
