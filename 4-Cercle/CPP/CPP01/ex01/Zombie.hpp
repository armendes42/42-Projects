/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:37:17 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 17:12:57 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

private:	
	std::string	name;

public:
	Zombie(void);
	~Zombie(void);

	void		setName(std::string name);
	std::string	getName(void);
	void		announce(void);
};

Zombie*		zombieHorde(int N, std::string name);

#endif