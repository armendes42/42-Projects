/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:47:09 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 19:44:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA {

private:
	Weapon		&_weapon;
	std::string	_name;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	attack(void);
};

#endif