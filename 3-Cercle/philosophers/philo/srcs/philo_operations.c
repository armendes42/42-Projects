/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:03:40 by armendes          #+#    #+#             */
/*   Updated: 2022/02/14 15:37:36 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_philo_dead(t_philo *philo)
{
	long	time;

	time = get_time();
	pthread_mutex_lock(&philo->info->mutex_info);
	if ((time - philo->last_time_eat) > philo->info->time_to_die
		&& philo->info->end == 0)
	{
		printf("%ld %d died\n", get_time(), philo->philo_nb + 1);
		philo->info->end = 1;
	}
	pthread_mutex_unlock(&philo->info->mutex_info);
}

int	is_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex_info);
	if (philo->info->end == 1)
	{
		pthread_mutex_unlock(&philo->info->mutex_info);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->mutex_info);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	long	time;
	long	time_sleep;

	if (print_message(philo, THINK))
		return (-1);
	take_two_forks(philo, philo->info->nb_of_philos);
	if (print_message(philo, EAT))
		return (-1);
	time = get_time();
	pthread_mutex_lock(&philo->info->mutex_info);
	time_sleep = 1000 * philo->info->time_to_eat;
	pthread_mutex_unlock(&philo->info->mutex_info);
	usleep(time_sleep);
	release_two_forks(philo);
	return (time);
}

void	philo_sleep(t_philo *philo)
{
	long	time;

	if (print_message(philo, SLEEP))
		return (-1);
	pthread_mutex_lock(&philo->info->mutex_info);
	time = 1000 * philo->info->time_to_sleep;
	pthread_mutex_unlock(&philo->info->mutex_info);
	usleep(time);
}
