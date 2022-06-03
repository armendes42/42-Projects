/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:07:07 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 15:22:04 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class WrongCat : public WrongAnimal{

public:
	WrongCat(void);
	WrongCat(WrongCat const &T);
	virtual ~WrongCat(void);
	WrongCat &operator=(WrongCat const &T);

  void makeSound(void) const;

};

#endif
