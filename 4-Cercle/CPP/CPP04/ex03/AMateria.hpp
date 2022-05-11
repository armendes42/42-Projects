/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:36:08 by armendes          #+#    #+#             */
/*   Updated: 2022/05/11 18:17:49 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class ICharacter;

class AMateria{

protected:
  std::string const _type;

public:
	AMateria(std::string const & type);
  AMateria(AMateria const &T);
  AMateria &operator=(AMateria const &T);
	virtual ~AMateria(void);

  std::string const & getType() const; //Returns the materia type

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target) = 0;

};

#endif
