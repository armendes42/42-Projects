/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:05:55 by armendes          #+#    #+#             */
/*   Updated: 2022/01/25 15:45:33 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_info(t_info *info, int argc, char **argv)
{
	info = malloc(sizeof(t_info));
	if (!info)
		return (-1);
	if (argc == 6)
		info->nb_of_meal = ft_atoi(argv[5]);
	else
		info->nb_of_meal = -1;
	info->nb_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	return (0);
}

static int	init_mutex_tab(pthread_mutex_tab **mutex_tab, int nb_philo)
{
	int	i;

	*mutex_tab = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!*mutex_tab)
		return (-1);
	i = -1;	
	while (++i < nb_philo)
		if (pthread_mutex_init(&(*mutex_tab)[i], NULL))
		{
			free(*mutex_tab);
			return (-1);

	return (mutex_tab);
}

static int	*init_fork_tab(int nb_philos)
{
	int	*fork_tab;
	int	i;

	fork_tab = malloc(sizeof(int) * nb_philos);
	if (!fork_tab)
		return (NULL);
	i = -1;
	while (++i < nb_philos)
		fork_tab[i] = 0;
	return (fork_tab);
}

int	init_philo(t_philo **philos, int argc, char **argv)
{
	t_info			info;
	int				*forks_tab;
	pthread_mutex_t	*mutex_forks_tab;
	int				i;

	if (init_info(&info, argc, argv))
		return (-1);
	*philos = malloc(sizeof(t_philo) * info.nb_of_philos);
	if (init_mutex_tab(&mutex_forks_tab, info.nb_of_philos))
		return (-1);
	forks_tab = init_fork_tab(info.nb_of_philos);
	if (!*philos || !forks_tab)
		return (-1);
	i = -1;
	while (++i < info.nb_of_philos)
	{
		philos[i]->info = info;
		philos[i]->philo_nb = i;
		philos[i]->times_eaten = 0;
		philos[i]->forks = forks_tab;
		philos[i]->mutex_forks = mutex_forks_tab;
		philos[i]->last_time_eat = 0;
	}
	return (0);
}
