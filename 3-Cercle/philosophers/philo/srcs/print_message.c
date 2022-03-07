/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:41:27 by armendes          #+#    #+#             */
/*   Updated: 2022/03/07 17:13:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_message(t_philo *philo, int action)
{
	is_philo_dead(philo);
	pthread_mutex_lock(&philo->info->mutex_info);
	if (philo->info->end == 1)
	{
		pthread_mutex_unlock(&philo->info->mutex_info);
		return (-1);
	}
	pthread_mutex_unlock(&philo->info->mutex_info);
	if (action == 0)
		printf("%ld %d has taken a fork\n", get_time(), philo->philo_nb + 1);
	if (action == 1)
		printf("%ld %d is eating\n", get_time(), philo->philo_nb + 1);
	if (action == 2)
		printf("%ld %d is sleeping\n", get_time(), philo->philo_nb + 1);
	if (action == 3)
		printf("%ld %d is thinking\n", get_time(), philo->philo_nb + 1);
	return (0);
}
