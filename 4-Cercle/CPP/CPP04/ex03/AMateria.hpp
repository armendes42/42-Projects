/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:36:08 by armendes          #+#    #+#             */
/*   Updated: 2022/05/10 16:52:18 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class AMateria{

protected:
  std::string const _type;

public:
	AMateria(std::string const & type);
	AMateria(AMateria const &T);
	virtual ~AMateria(void);
	virtual AMateria &operator=(AMateria const &T);

  std::string const & getType() const; //Returns the materia type

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

};

#endif
