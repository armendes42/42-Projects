/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:50:04 by armendes          #+#    #+#             */
/*   Updated: 2022/01/25 15:39:26 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void	take_fork(t_philo philo, int nb_of_philo)
{
	pthread_mutex_lock(&philo.mutex_forks[nb_of_philo- 1]);
	if (philo.forks[nb_of_philo - 1] != 0)
	{
		philo.forks[nb_of_philo - 1]++;
		printf("%d %d %s",timestamp ,nb_of_philo, FORK);
		pthread_mutex_unlock(&philo.mutex_forks[nb_of_philo - 1]);
	}
	pthread_mutex_unlock(&philo.mutex_forks[nb_of_philo - 1]);
}

static void	philo_eat(t_philo philo)
{
	take_fork(philo, philo.philo_nb);
	take_fork(philo, philo.philo_nb + 1);
}

void	release_fork(t_philo philo)
{

}

void	philo_sleep(t_philo philo)
{
	
}

static void	*philo_loop(void *philo)
{

	while (1)
	{
		philo_eat(philo);
		release_fork(philo);
		philo_sleep(philo);
	}
}*/

int	create_philo(int argc, char **argv)
{
	t_philo	*philos;
	int		i;

	philos = NULL;
	init_philo(&philos, argc, argv);
	if (!philos)
		return (-1);
	i = -1;
	/*while (++i < philos->info.nb_of_philos)
	{
		if (pthread_create(&philos[i].philo_thread, NULL, &philo_loop, &philos[i]) != 0)
			return (-1);
	}
	i = -1;
	while (++i < philos->info.nb_of_philos)
	{
		if (pthread_join(philos[i].philo_thread, NULL) != 0)
			return (-1);
	}*/

	printf("nb of philo :%d\n time_to_die :%d\n time_to_eat :%d\n time_to_sleep :%d", philos->info.nb_of_philos, philos->info.time_to_die, philos->info.time_to_eat, philos->info.time_to_sleep);


	return (0);
}
