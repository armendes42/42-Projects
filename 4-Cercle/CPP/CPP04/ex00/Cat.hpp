/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:21:31 by armendes          #+#    #+#             */
/*   Updated: 2022/05/09 19:12:51 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat : public Animal{

public:
	Cat(void);
	Cat(Cat const &T);
	~Cat(void);
	Cat &operator=(Cat const &T);

  void makeSound(void) const;
};

#endif
