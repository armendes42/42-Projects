/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:38:48 by armendes          #+#    #+#             */
/*   Updated: 2022/02/02 19:02:44 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_fork(t_philo *philo, int philo_nb)
{
	is_philo_dead(philo);
	pthread_mutex_lock(&philo->mutex_forks[philo_nb]);
	if (philo->forks[philo_nb] == 0)
	{
		philo->forks[philo_nb]++;
		print_message(philo, FORK);
		pthread_mutex_unlock(&philo->mutex_forks[philo_nb]);
		return (1);	
	}
	pthread_mutex_unlock(&philo->mutex_forks[philo_nb]);
	return (0);
}

void	take_two_forks(t_philo *philo, int nb_of_philos)
{
	/*if (philo->philo_nb % 2 == 0)
	{
		while (take_fork(philo, philo->philo_nb) == 0 && is_end(philo) == 0);
		while (take_fork(philo,
			(philo->philo_nb + 1) % nb_of_philos) == 0
			&& is_end(philo) == 0);
	}
	else
	{
		while (take_fork(philo,
			(philo->philo_nb + 1) % nb_of_philos) == 0
			&& is_end(philo) == 0);
		while (take_fork(philo, philo->philo_nb) == 0 && is_end(philo) == 0);
	}*/
	while (take_fork(philo, philo->philo_nb) == 0 && is_end(philo) == 0);
	while (take_fork(philo,
			(philo->philo_nb + 1) % nb_of_philos) == 0
			&& is_end(philo) == 0);
}

void	release_two_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_forks[philo->philo_nb]);
	if (philo->forks[philo->philo_nb] == 1)
		philo->forks[philo->philo_nb]--;
	pthread_mutex_unlock(&philo->mutex_forks[philo->philo_nb]);
	pthread_mutex_lock(&philo->mutex_forks[(philo->philo_nb + 1)
		% philo->info->nb_of_philos]);
	if (philo->forks[(philo->philo_nb + 1) % philo->info->nb_of_philos] == 1)
		philo->forks[(philo->philo_nb + 1) % philo->info->nb_of_philos]--;
	pthread_mutex_unlock(&philo->mutex_forks[(philo->philo_nb + 1)
		% philo->info->nb_of_philos]);
}
