/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:37:17 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 16:28:30 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

private:	
	std::string	name;

public:
	Zombie(std::string name);
	~Zombie(void);

	void		setName(std::string name);
	std::string	getName(void);
	void		announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif