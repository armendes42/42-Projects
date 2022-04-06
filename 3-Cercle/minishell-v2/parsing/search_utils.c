/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:41:20 by armendes          #+#    #+#             */
/*   Updated: 2022/04/04 18:34:26 by armendes         ###   ########.fr       */
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

static int	search_error_redirection_two(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '<')
		return (-1);
	else if (str[i] == '<' && str[i + 1] == '>')
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
	return (0);
}

int	search_error_redirection(char *str)
{
	int		i;
	e_quote	quote;
	int		control;

	i = -1;
	quote = NOTHING;
	while (str[++i])
	{
		quote = update_quote_status(str[i], quote);
		if (quote == NOTHING)
		{
			control = search_error_redirection_two(str, i);
			if (control == -1)
				return (-1);
		}
	}
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
