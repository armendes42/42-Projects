/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:05:55 by armendes          #+#    #+#             */
/*   Updated: 2022/01/25 15:00:24 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_info(t_info *info, int argc, char **argv)
{
	if (argc == 6)
		info->nb_of_meal = ft_atoi(argv[5]);
	else
		info->nb_of_meal = -1;
	info->nb_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
}

static pthread_mutex_t	*init_mutex_tab(int nb_philo)
{
	pthread_mutex_t	*mutex_tab;
	int				i;

	mutex_tab = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!mutex_tab)
		return (NULL);
	i = -1;	
	while (++i < nb_philo)
		pthread_mutex_init(&mutex_tab[i], NULL);
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

t_philo	*init_philo(int argc, char **argv)
{
	t_philo			*philos;
	t_info			info;
	int				*forks_tab;
	pthread_mutex_t	*mutex_forks_tab;
	int				i;

	init_info(&info, argc, argv);
	philos = malloc(sizeof(t_philo *) * (ft_atoi(argv[1])));
	mutex_forks_tab = init_mutex_tab(info.nb_of_philos);
	forks_tab = init_fork_tab(info.nb_of_philos);
	if (!mutex_forks_tab || !forks_tab || !philos)
		return (NULL);
	i = 0;
	while (++i <= info.nb_of_philos)

	{
		philos[i].info = info;
		philos[i].philo_nb = i;
		philos[i].times_eaten = 0;
		philos[i].forks = forks_tab;
		philos[i].mutex_forks = mutex_forks_tab;
		philos[i].last_time_eat = 0;
	}
	return (philos);
}
