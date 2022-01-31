/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:03:40 by armendes          #+#    #+#             */
/*   Updated: 2022/01/31 19:11:32 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_philo *philo)
{
	long	time;

	time = get_time();
	pthread_mutex_lock(&philo->info.mutex_info);
	if (time - philo->last_time_eat >= philo->info.time_to_eat)
	{
		print_message(philo->philo_nb, DIE);
		pthread_mutex_unlock(&philo->info.mutex_info);
		return (1);
	}
	pthread_mutex_unlock(&philo->info.mutex_info);
	return (0);
}