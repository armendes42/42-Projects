/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:13:20 by armendes          #+#    #+#             */
/*   Updated: 2022/02/11 15:37:59 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*format_str(char *line, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	if (end - start <= 0)
		return (NULL);
	while (line[start] && line[start] == ' ')
		start++;
	if (end - start <= 0)
		return (NULL);
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = line[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

int	is_empty(char *str)
{
	int	i;

	if (ft_strlen(str) == 0)
		return (1);
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}
