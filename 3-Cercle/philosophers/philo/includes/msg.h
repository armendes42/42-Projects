/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:10:09 by armendes          #+#    #+#             */
/*   Updated: 2022/02/10 14:12:32 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define ARGC_ERROR "The input should be : nb_of_philo time_to_die time_to_eat\
 time_to_sleep\nor nb_of_philo time_to_die time_to_eat time_to_sleep\
 nb_of_times_philo_must_eat\n"
# define INT_ERROR "One of the arguments is not an int\n"
# define OVERFLOW_ERROR "One of the arguments is too big for an integer\n"
# define ARG_ERROR "One of the arguments is negative or there is no philo"

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

#endif