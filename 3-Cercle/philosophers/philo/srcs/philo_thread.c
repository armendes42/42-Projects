/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:50:04 by armendes          #+#    #+#             */
/*   Updated: 2022/01/24 19:30:19 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void	take_fork(t_philo philo)
{
	while(pthread_mutex_lock());
}

void	eat(t_philo philo)
{

}

void	release_fork(t_philo philo)
{

}*/

static void	philo_loop(void *philo)
{
	while (1)
	{
		take_fork(philo);
		philo_eat(philo);
		release_fork(philo);
		philo_sleep(philo);
	}
}

int	create_philo(int argc, char **argv)
{
	t_philo	*philos;
	int		i;

	philos = init_philo(argc, argv);
	if (!philos)
		return (-1);
	i = -1;
	while (++i < philos->info.nb_of_philos)
	{
		if (pthread_create(philos[i].philo_thread, NULL, &philo_loop, philos[i]) != 0);
	}
}
