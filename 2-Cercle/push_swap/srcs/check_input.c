/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:50:20 by armendes          #+#    #+#             */
/*   Updated: 2022/01/10 19:47:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_arg(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if (str[i] != '-' && str[i] == '+' && ft_isdigit(str[i]) == 0)
			error(NULL, ARG_ERR);
		i++;
	}
}

static void	check_int(char *str)
{
	long	nb;

	nb = ft_atoi(str);
	if (nb < -2147483648 || nb > 2147483647)
		error(NULL, INT_ERR);
}

static void	check_duplicate(int *tab_input, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab_input[i] == tab_input[j])
				error(NULL, DUP_ERR);
			j++;
		}
		i++;
	}
}

static int	*check_input2(char **tab)
{
	int	i;
	int	*tab_input;

	i = 0;
	while (tab[i])
		i++;
	tab_input = malloc(sizeof(int) * i);
	if (!tab_input)
		error(NULL, MALLOC_ERR);
	i = 0;
	while (tab[i])
	{
		check_arg(tab[i]);
		check_int(tab[i]);
		tab_input[i] = (int)ft_atoi(tab[i]);
		i++;
	}
	check_duplicate(tab_input, i);
	return (tab_input);
}

int	*check_input(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**tab;
	int		*tab_input;

	i = 2;
	str = ft_strjoin(argv[1], " ");
	while (i < argc)
	{
		tmp = ft_strjoin(argv[i], " ");
		str = ft_strjoin(str, tmp);
		free(tmp);
		i++;
	}
	tab = ft_split(str, WHITE_SPACE);
	free(str);
	tab_input = check_input2(tab);
	free_tab(tab);
	return (tab_input);
}
