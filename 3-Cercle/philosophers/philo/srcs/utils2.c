/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:23:17 by armendes          #+#    #+#             */
/*   Updated: 2022/01/31 18:11:45 by armendes         ###   ########.fr       */
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

void	print_message(int philo_nb, int action)
{
	if (action == 0)
		printf("%d %d %s",get_time() ,philo_nb, FORK);
}
