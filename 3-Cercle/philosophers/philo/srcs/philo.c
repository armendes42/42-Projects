/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:20:29 by armendes          #+#    #+#             */
/*   Updated: 2022/01/31 19:25:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(void)
{
	/*if (check_arg(argc, argv))
		return (-1);
	if (create_philo(argc, argv))
		return (-1);*/
	long n = get_time();
	printf("%ld\n", n);
	usleep(200 * 1000);
	n = get_time();
	printf("%ld\n", n);
	usleep(100 * 1000);
	n = get_time();
	
	printf("%ld\n", n);
	return (0);
}
