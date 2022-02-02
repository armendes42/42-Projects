/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:05:55 by armendes          #+#    #+#             */
/*   Updated: 2022/02/02 18:29:58 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_info(t_info *info, int argc, char **argv)
{
	if (argc == 6)
		info->nb_of_meal = ft_atoi(argv[5]);
	else
		info->nb_of_meal = -1;
	info->nb_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->end = 0;
	if (info->time_to_die < 0 || info->time_to_eat < 0
		|| info->time_to_sleep < 0 || info->nb_of_philos <= 0
		|| (info->nb_of_meal < 0 && argc == 6))
		return (-1);
	if (pthread_mutex_init(&info->mutex_info, NULL))
		return (-1);
	return (0);
}

static int	init_mutex_tab(pthread_mutex_t **mutex_tab, int nb_philo)
{
	int	i;

	*mutex_tab = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!*mutex_tab)
		return (-1);
	i = 0;	
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&(*mutex_tab)[i], NULL))
		{
			free(*mutex_tab);
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	*init_fork_tab(int nb_philos)
{
	int	*fork_tab;
	int	i;

	fork_tab = malloc(sizeof(int) * nb_philos);
	if (!fork_tab)
		return (NULL);
	i = 0;
	while (i < nb_philos)
	{
		fork_tab[i] = 0;
		i++;
	}
	return (fork_tab);
}

static void	init_each_philo(t_info *info, t_philo **philos, int *forks_tab,
	pthread_mutex_t *mutex_forks_tab, int i)
{
	(*philos)[i].info = info;
	(*philos)[i].philo_nb = i;
	(*philos)[i].meals_needed = info->nb_of_meal;
	(*philos)[i].forks = forks_tab;
	(*philos)[i].mutex_forks = mutex_forks_tab;
	(*philos)[i].last_time_eat = 0;
}

int	init_philo(t_philo **philos, int argc, char **argv)
{
	t_info			*info;
	int				*forks_tab;
	pthread_mutex_t	*mutex_forks_tab;
	int				i;

	info = malloc(sizeof(t_info));
	if (!info)
		return (-1);
	if (init_info(info, argc, argv))
		return (-1);
	*philos = malloc(sizeof(t_philo) * info->nb_of_philos);
	if (init_mutex_tab(&mutex_forks_tab, info->nb_of_philos))
		return (-1);
	forks_tab = init_fork_tab(info->nb_of_philos);
	if (!*philos || !forks_tab)
		return (-1);
	i = 0;
	while (i < info->nb_of_philos)
	{
		init_each_philo(info, philos, forks_tab, mutex_forks_tab, i);
		i++;
	}
	return (0);
}
