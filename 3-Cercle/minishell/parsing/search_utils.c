/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:41:20 by armendes          #+#    #+#             */
/*   Updated: 2022/02/18 16:10:50 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_redirection(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			if (str[i + 1] == '<')
				return (3);
			return (1);
		}
		if (str[i] == '>')
		{
			if (str[i + 1] == '>')
				return (4);
			return (2);
		}
		i++;
	}
	return (0);
}

int	search_error_redirection(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '>' && str[i + 1] == '<')
			return (-1);
		else if (str[i] == '<' && str[i + 1] == '<' && is_empty(&str[i + 2]))
			return (-1);
		else if (str[i] == '>' && str[i + 1] == '>' && is_empty(&str[i + 2]))
			return (-1);
		else if ((str[i] == '<' || str[i] == '>') && is_empty(&str[i + 1]))
			return (-1);
		else if (str[i] == '<' && str[i + 1] == '<'
			&& (get_next_char(&str[i + 2]) == '<'
				|| get_next_char(&str[i + 2]) == '>'))
			return (-1);
		else if (str[i] == '>' && str[i + 1] == '>'
			&& (get_next_char(&str[i + 2]) == '<'
				|| get_next_char(&str[i + 2]) == '>'))
			return (-1);
	}
	return (0);
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

int	search_dollar(char *str)
{
	int	i;
	int	nb_of_dollars;

	i = 0;
	nb_of_dollars = 0;
	while (str[i])
	{
		if (str[i] == '$')
			nb_of_dollars++;
		i++;
	}
	return (nb_of_dollars);
}
