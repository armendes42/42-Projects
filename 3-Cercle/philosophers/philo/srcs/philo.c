/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:20:29 by armendes          #+#    #+#             */
/*   Updated: 2022/02/01 20:25:24 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;

	if (check_arg(argc, argv))
		return (-1);
	philos = NULL;
	if (init_philo(&philos, argc, argv))
		return (-1);
	if (!philos)
		return (-1);
	get_time();
	if (create_philo(philos))
		return (-1);
	if (end_philo(philos))
		return (-1);
	return (0);
}
