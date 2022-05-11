/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:52:56 by armendes          #+#    #+#             */
/*   Updated: 2022/05/11 17:42:59 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"
# include <iostream>
# include <string>

class IMateriaSource{

public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria* m) = 0;
  virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif
