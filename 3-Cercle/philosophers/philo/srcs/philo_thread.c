/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:50:04 by armendes          #+#    #+#             */
/*   Updated: 2022/01/24 16:43:54 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(char **argv)
{
	t_philo	*philos;
	int		i;
	
	while ()
	return (philos);
}

void	take_fork(t_philo philo)
{
	pthread_mutex_lock();
}

void	eat(t_philo philo)
{

}

void	release_fork(t_philo philo)
{

}

void	philo_loop(t_philo philo)
{
	while (1)
	{
		take_fork(philo);
		philo_eat(philo);
		release_fork(philo);
		philo_sleep(philo);
	}
}

void	create_philo(char **argv)
{
	t_philo	*philos;
	int		i;

	philos = init_philo(argv);
	i = 0;
	while (i < (philos[0])->info->)
}
