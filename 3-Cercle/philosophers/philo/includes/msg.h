/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:10:09 by armendes          #+#    #+#             */
/*   Updated: 2022/01/24 20:56:40 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define ARGC_ERROR "The input should be : nb_of_philo time_to_die time_to_eat\
 time_to_sleep\nor nb_of_philo time_to_die time_to_eat time_to_sleep\
 nb_of_times_philo_must_eat\n"
# define INT_ERROR "One of the arguments is not an int\n"
# define OVERFLOW_ERROR "One of the arguments is too big for an integer\n"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

#endif