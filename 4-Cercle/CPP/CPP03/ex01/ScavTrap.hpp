/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:14:12 by armendes          #+#    #+#             */
/*   Updated: 2022/05/06 18:55:39 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

class ScavTrap : public ClapTrap{

private:
	

public:
	ScavTrap(void);
	ScavTrap(ScavTrap const &T);
	~ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &T);

	void attack() {
		/* code */
	}

};

#endif
