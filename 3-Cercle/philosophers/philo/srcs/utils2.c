/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:23:17 by armendes          #+#    #+#             */
/*   Updated: 2022/02/10 14:28:04 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			i;

	i = 0;
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	while ((s_1[i] || s_2[i]) && i < n)
	{
		if (s_1[i] != s_2[i])
			return (s_1[i] - s_2[i]);
		else
			i++;
	}
	return (0);
}

static void	free_mutex_tab(pthread_mutex_t *mutex_tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&mutex_tab[i]);
		i++;
	}
	free(mutex_tab);
}

void	free_all(t_philo **philos)
{
	int	nb_of_philo;

	nb_of_philo = philos[0]->info->nb_of_philos;
	if (philos)
	{
		if (philos[0]->info)
		{
			pthread_mutex_destroy(&philos[0]->info->mutex_info);
			free(philos[0]->info);
		}
		if (philos[0]->mutex_forks)
			free_mutex_tab(philos[0]->mutex_forks, nb_of_philo);
		if (philos[0]->forks)
			free(philos[0]->forks);
		free(*philos);
	}
}
