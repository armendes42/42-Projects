/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_dollars_from_env_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:57:58 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 17:59:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_dollar_groups(char *str)
{
	int	nb_of_groups;
	int	i;

	i = 0;
	nb_of_groups = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '$')
		{
			nb_of_groups++;
			while (str[i] == '$')
				i++;
		}
		i++;
	}
	return (nb_of_groups);
}

int	count_group_of_dollar(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '$')
		{
			while (str[i] == '$')
			{
				i++;
				j++;
			}
			break ;
		}
		i++;
	}
	return (j);
}
