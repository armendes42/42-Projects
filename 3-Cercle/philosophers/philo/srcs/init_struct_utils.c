/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:47:46 by armendes          #+#    #+#             */
/*   Updated: 2022/02/03 18:50:04 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_each_philo(t_info *info, t_philo **philos, int i)
{
	(*philos)[i].info = info;
	(*philos)[i].philo_nb = i;
	(*philos)[i].meals_needed = info->nb_of_meal;
	(*philos)[i].last_time_eat = 0;
}

void	init_each_philo_2(t_philo **philos, int *forks_tab,
	pthread_mutex_t *mutex_forks_tab, int i)
{
	(*philos)[i].forks = forks_tab;
	(*philos)[i].mutex_forks = mutex_forks_tab;
}
