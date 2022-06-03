/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:17:53 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:21:45 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal{

protected:
  std::string type;

public:
	Animal(void);
	Animal(Animal const &T);
	virtual ~Animal(void);
	Animal &operator=(Animal const &T);

  virtual void makeSound(void) const;

  std::string getType(void) const;

};

#endif
