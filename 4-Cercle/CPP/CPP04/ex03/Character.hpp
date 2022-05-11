/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:19:09 by armendes          #+#    #+#             */
/*   Updated: 2022/05/11 17:52:22 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <string>

class Character : public ICharacter{

private:
  std::string _name;
  AMateria *_materiaTab[4];

public:
	Character(std::string name);
	Character(Character const &T);
	Character &operator=(Character const &T);
  ~Character();

  std::string const & getName() const;
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);

};

#endif
