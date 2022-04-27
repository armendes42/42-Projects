/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:48:41 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 16:29:44 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	Foo("Foo");
	Zombie	*Bar = newZombie("Bar");

	Foo.announce();
	Bar->announce();
	randomChump("FooBar");
	delete Bar;
}