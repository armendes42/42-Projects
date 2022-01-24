/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:22:18 by armendes          #+#    #+#             */
/*   Updated: 2022/01/24 19:27:07 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "msg.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	int	nb_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_of_meal;
}				t_info;

typedef struct s_philo
{
	pthread_t		philo_thread;
	int				philo_nb;
	int				times_eaten;
	t_info			info;
	int				*forks;
	pthread_mutex_t *mutex_forks;
}				t_philo;

int		ft_atoi(char *str);
int		check_arg(int argc, char **argv);
int		create_philo(int argc, char **argv);
t_philo	*init_philo(int argc, char **argv);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

#endif