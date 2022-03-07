/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:22:18 by armendes          #+#    #+#             */
/*   Updated: 2022/03/07 15:07:15 by armendes         ###   ########.fr       */
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
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meal;
	pthread_mutex_t	mutex_info;
	int				end;
}				t_info;

typedef struct s_philo
{
	int				last_time_eat;
	pthread_t		philo_thread;
	int				philo_nb;
	int				meals_needed;
	t_info			*info;
	int				*forks;
	pthread_mutex_t	*mutex_forks;
}				t_philo;

int		ft_atoi(char *str);
int		check_arg(int argc, char **argv);
int		create_philo(t_philo *philos);
int		end_philo(t_philo *philos);
int		init_philo(t_philo **philos, int argc, char **argv);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
long	get_time(void);
void	take_two_forks(t_philo *philo, int nb_of_philos);
void	release_two_forks(t_philo *philo);
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		print_message(t_philo *philo, int action);
void	is_philo_dead(t_philo *philo);
int		is_end(t_philo *philo);
void	init_each_philo(t_info *info, t_philo **philos, int i);
void	init_each_philo_2(t_philo **philos, int *forks_tab,
			pthread_mutex_t *mutex_forks_tab, int i);
void	free_all(t_philo **philos);

#endif