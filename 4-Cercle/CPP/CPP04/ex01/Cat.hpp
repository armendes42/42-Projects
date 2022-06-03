/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:21:31 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:22:25 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Cat : public Animal{

private:
	Brain *_brain;

public:
	Cat(void);
	Cat(Cat const &T);
	virtual ~Cat(void);
	Cat &operator=(Cat const &T);
	virtual Animal &operator=(Animal const &T);

  void makeSound(void) const;

	Brain *getBrain(void) const;
};

#endif
