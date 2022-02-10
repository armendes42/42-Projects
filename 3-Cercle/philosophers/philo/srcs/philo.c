/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:20:29 by armendes          #+#    #+#             */
/*   Updated: 2022/02/10 14:23:37 by armendes         ###   ########.fr       */
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
	{
		free_all(&philos);
		return (-1);
	}
	if (!philos)
		return (-1);
	get_time();
	if (create_philo(philos))
		return (-1);
	if (end_philo(philos))
		return (-1);
	free_all(&philos);
	return (0);
}
