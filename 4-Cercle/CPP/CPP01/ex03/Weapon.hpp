/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:47:06 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 19:44:16 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {

private:
	std::string	_type;

public:
	Weapon(std::string type);
	~Weapon(void);

	const std::string&	getType(void) const;
	void				setType(std::string type);
};

#endif