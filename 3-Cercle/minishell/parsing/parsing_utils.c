/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:13:20 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 16:26:47 by imaalem          ###   ########.fr       */
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
		error_and_exit(get_info(), 1);
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

t_token	*last_cell(t_token **words)
{
	t_token	*tmp;

	tmp = *words;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

char	*get_next_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (NULL);
	return (&str[i]);
}

int	search_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
