/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:05:18 by armendes          #+#    #+#             */
/*   Updated: 2022/01/29 17:12:46 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_empty(char *str)
{
	if (!str)
		return (-1);
	if (ft_strlen(str) == 0)
		return (-1);
	return (0);
}

static int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_int(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' && !ft_isdigit(str[i + 1]))
			|| (i > 0 && str[i] == '-' && str[i - 1] != ' '))
			return (-1);
		i++;
	}
	return (0);
}

static int	check_int_overflow(char *str)
{
	int		i;
	char	**tab;
	int		after_atoi;
	char	*after_itoa;

	tab = ft_split(str, ' ');
	if (tab == NULL)
		free_stack_and_tab_and_error(NULL, tab);
	i = 0;
	while (tab[i])
	{
		after_atoi = ft_atoi(tab[i]);
		after_itoa = ft_itoa(after_atoi);
		if (!after_itoa || ft_strncmp(tab[i], after_itoa, ft_strlen(tab[i])))
		{
			free(after_itoa);
			free_char_tab(tab);
			return (-1);
		}
		free(after_itoa);
		i++;
	}
	free_char_tab(tab);
	return (0);
}

void	check_arg(int argc, char **argv)
{
	int	i;
	int	control;

	i = 0;
	control = 0;
	while (++i < argc)
	{
		if (check_empty(argv[i]))
			control++;
	}
	if (control == (argc - 1))
		exit(EXIT_SUCCESS);
	i = 0;
	while (++i < argc)
	{
		if (check_empty(argv[i]))
			error();
		if (check_digit(argv[i]))
			error();
		if (check_int(argv[i]))
			error();
		if (check_int_overflow(argv[i]))
			error();
	}
}
