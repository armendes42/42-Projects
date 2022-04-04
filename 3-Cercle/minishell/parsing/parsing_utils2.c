/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:01:02 by armendes          #+#    #+#             */
/*   Updated: 2022/04/04 18:34:21 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	search_space_end(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == ' ')
		return (1);
	return (0);
}

int	search_space_start(char *str)
{
	if (str[0] == ' ')
		return (1);
	return (0);
}
