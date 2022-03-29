/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:18:38 by armendes          #+#    #+#             */
/*   Updated: 2022/03/29 19:27:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (std::islower(argv[i][j]))
					std::cout << std::toupper(argv[i][j]) + 48;
				else
					std::cout << argv[i][j];
				j++;
			}
			std::cout << std::endl;
			i++;
		}
	}
	return 0;
}