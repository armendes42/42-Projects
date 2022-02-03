/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:42:03 by armendes          #+#    #+#             */
/*   Updated: 2022/02/03 18:42:09 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	static int				for_the_first_time;
	static struct timeval	tv1;
	struct timeval			tv2;
	struct timeval			tv3;

	if (for_the_first_time == 0)
	{
		if (gettimeofday(&tv1, NULL))
			return (-1);
		for_the_first_time = 1;
	}
	if (gettimeofday(&tv2, NULL))
		return (-1);
	tv3.tv_sec = tv2.tv_sec - tv1.tv_sec;
	tv3.tv_usec = tv2.tv_usec - tv1.tv_usec;
	if (tv3.tv_usec < 0)
	{
		tv3.tv_sec--;
		tv3.tv_usec += 1000000;
	}
	return (tv3.tv_sec * 1000 +(tv3.tv_usec / 1000));
}
