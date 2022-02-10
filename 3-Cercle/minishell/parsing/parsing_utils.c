/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:13:20 by armendes          #+#    #+#             */
/*   Updated: 2022/02/10 18:06:14 by armendes         ###   ########.fr       */
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
