/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:50:04 by armendes          #+#    #+#             */
/*   Updated: 2022/01/31 20:54:01 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo, int philo_nb)
{
	if (philo_nb > philo->info.nb_of_philos)
		philo_nb = 1;
	pthread_mutex_lock(&philo->mutex_forks[philo_nb - 1]);
	if (philo->forks[philo_nb - 1] == 0)
	{
		philo->forks[philo_nb - 1]++;
		pthread_mutex_unlock(&philo->mutex_forks[philo_nb - 1]);
	}
	pthread_mutex_unlock(&philo->mutex_forks[philo_nb - 1]);
}

static void	philo_eat(t_philo *philo)
{
	take_fork(philo, philo->philo_nb));
	take_fork(philo, philo->philo_nb + 1));
}

void	philo_sleep(t_philo *philo)
{
	
}

static void	*philo_loop(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->times_eaten < philo->info.nb_of_meal && !is_end(philo))
	{
		philo->last_time_eat = philo_eat(philo);
		if (philo->last_time_eat == -1)
			return (-1);
		philo->times_eaten++;
		philo_sleep(philo);
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
		if (pthread_create(&philos[i].philo_thread, NULL, &philo_loop, &philos[i]))
			return (-1);
	}
	return (0);
}
