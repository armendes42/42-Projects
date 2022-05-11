/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:54:00 by armendes          #+#    #+#             */
/*   Updated: 2022/05/11 17:42:53 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include <iostream>
# include <string>

class MateriaSource{

private:
  AMateria *_materiaLearnTab[4];

public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &T);
	~MateriaSource(void);
	MateriaSource &operator=(MateriaSource const &T);

  void learnMateria(AMateria* m);
  AMateria* createMateria(std::string const & type);

};

#endif
