/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:41:55 by armendes          #+#    #+#             */
/*   Updated: 2022/05/11 16:48:15 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Ice : public AMateria{

public:
	Ice(void);
	Ice(Ice const &T);
	~Ice(void);
	Ice &operator=(Ice const &T);

  AMateria* clone() const;
  void use(ICharacter& target);

};

#endif
