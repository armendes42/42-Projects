/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:14:12 by armendes          #+#    #+#             */
/*   Updated: 2022/05/09 16:36:28 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : virtual public ClapTrap{

public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &T);
	~ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &T);

	void attack(const std::string &target);
	void guardGate(void);

};

#endif
