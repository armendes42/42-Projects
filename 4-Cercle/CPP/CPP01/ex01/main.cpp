/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:00:13 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 18:26:13 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *Horde = zombieHorde(5, "Foo");
	
	for (int i = 0; i < 5; i++)
		Horde[i].announce();
	
	delete[] Horde;

	Zombie *Horde2 = zombieHorde(10, "Bar");
	
	for (int i = 0; i < 10; i++)
		Horde2[i].announce();
	
	delete[] Horde2;
}