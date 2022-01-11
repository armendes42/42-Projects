/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:05:18 by armendes          #+#    #+#             */
/*   Updated: 2022/01/11 17:17:13 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_empty(char *str)
{
	if (!str)
		return (1);
	if (ft_strlen(str) == 0)
		return (1);
	return (0);
}

static int	check_int(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || (i == 0 && str[i] == '-' && ft_isdigit(str[i + 1]))
			|| (i > 0 && str[i] == '-' && str[i - 1] == ' '
			&& ft_isdigit(str[i + 1])) || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

static int	check_int_overflow(char *str)
{
	int		i;
	char	**tab;
	int		after_atoi;
	char	*after_itoa;

	tab = ft_split(str, WHITE_SPACE);
	i = 0;
	while (tab[i])
	{
		after_atoi = ft_atoi(tab[i]);
		after_itoa = ft_itoa(after_atoi);
		if (ft_strncmp(tab[i], after_itoa, ft_strlen(tab[i])))
		{
			free(after_itoa);
			free_tab(tab);
			return (1);
		}
		free(after_itoa);
		i++;
	}
	free_tab(tab);
	return (0);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (check_empty(argv[i]))
			error(EMPTY_ERR);
		if (check_int(argv[i]))
			error(NOT_INT_ERR);
		if (check_int_overflow(argv[i]))
			error(OVERFLOW_ERR);
		i++;
	}
	return (0);
}