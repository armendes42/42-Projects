/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:06:27 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:22:06 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal{

protected:
  std::string type;

public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &T);
	virtual ~WrongAnimal(void);
	WrongAnimal &operator=(WrongAnimal const &T);

  void makeSound(void) const;

  std::string getType(void) const;

};

#endif
