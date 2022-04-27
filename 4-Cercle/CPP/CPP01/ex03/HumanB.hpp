/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:47:11 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 19:44:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB {

private:
	Weapon		*_weapon;
	std::string	_name;

public:
	HumanB(std::string name);
	~HumanB(void);

	void	setWeapon(Weapon &weapon);
	void	attack(void);
};

#endif