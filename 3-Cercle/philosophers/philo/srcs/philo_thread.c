/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:50:04 by armendes          #+#    #+#             */
/*   Updated: 2022/02/03 18:40:27 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_loop(void *arg)
{
	t_philo	*philo;
	long	time;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->info->mutex_info);
	time = 1000 * philo->info->time_to_sleep / 2;
	pthread_mutex_unlock(&philo->info->mutex_info);
	if (philo->philo_nb % 2 == 0)
		usleep(time);
	while (philo->meals_needed && is_end(philo) == 0)
	{
		if (is_end(philo) == 0)
		{
			philo->last_time_eat = philo_eat(philo);
			if (philo->last_time_eat == -1)
				return (NULL);
		}
		if (is_end(philo) == 0 && (philo->meals_needed - 1 != 0))
			philo_sleep(philo);
		if (philo->meals_needed > 0)
			philo->meals_needed--;
	}
	return (NULL);
}

int	create_philo(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->info->nb_of_philos)
	{
		if (pthread_create(&(philos[i].philo_thread), NULL,
				&philo_loop, &philos[i]))
		{
			free(philos);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	end_philo(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->info->nb_of_philos)
	{
		if (pthread_join(philos[i].philo_thread, NULL))
		{
			free(philos);
			return (-1);
		}
		i++;
	}
	return (0);
}
