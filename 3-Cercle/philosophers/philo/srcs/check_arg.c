/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:47:22 by armendes          #+#    #+#             */
/*   Updated: 2022/01/24 19:28:05 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_int(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

static int	check_overflow(char *str)
{
	int		after_atoi;
	char	*after_itoa;

	after_atoi = ft_atoi(str);
	after_itoa = ft_itoa(after_atoi);
	if (ft_strncmp(str, after_itoa, ft_strlen(str)))
	{
		free(after_itoa);
		return (1);
	}
	free(after_itoa);
	return (0);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("%s", ARGC_ERROR);
		return (-1);
	}
	i = 0;
	while (++i < argc)
	{
		if (check_int(argv[i]) == -1)
		{
			printf("%s", INT_ERROR);
			return (-1);
		}
		if (check_overflow(argv[i]) == -1)
		{
			printf("%s", OVERFLOW_ERROR);
			return (-1);
		}
	}
	return (0);
}
