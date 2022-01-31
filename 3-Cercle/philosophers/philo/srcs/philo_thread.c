/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:50:04 by armendes          #+#    #+#             */
/*   Updated: 2022/01/31 18:07:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo, int nb_of_philo)
{
	pthread_mutex_lock(&philo->mutex_forks[nb_of_philo- 1]);
	if (philo->forks[nb_of_philo - 1] == 0)
	{
		philo->forks[nb_of_philo - 1]++;
		pthread_mutex_unlock(&philo->mutex_forks[nb_of_philo - 1]);
	}
	pthread_mutex_unlock(&philo->mutex_forks[nb_of_philo - 1]);
}

static void	philo_eat(t_philo *philo)
{
	while (take_fork(philo, philo->philo_nb) && pas mort());
	while (take_fork(philo, philo->philo_nb + 1));
}

void	release_fork(t_philo *philo)
{

}

void	philo_sleep(t_philo *philo)
{
	
}

static void	*philo_loop(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		philo_eat(philo);
		release_fork(philo);
		philo_sleep(philo);
		print_message();
	}
}

int	create_philo(int argc, char **argv)
{
	t_philo	*philos;
	int		i;

	philos = NULL;
	init_philo(&philos, argc, argv);
	if (!philos)
		return (-1);
	i = -1;
	while (++i < philos->info.nb_of_philos)
	{
		if (pthread_create(&philos[i].philo_thread, NULL, &philo_loop, &philos[i]) != 0)
			return (-1);
	}
	i = -1;
	while (++i < philos->info.nb_of_philos)
	{
		if (pthread_join(philos[i].philo_thread, NULL) != 0)
			return (-1);
	}
	return (0);
}
