/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote_and_braces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:12:19 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 18:58:36 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_quote	update_quote_status(char c, t_quote quote)
{
	t_quote	new_quote;

	new_quote = quote;
	if (quote == NOTHING && c == '\'')
		new_quote = SIMPLE;
	else if (quote == NOTHING && c == '"')
		new_quote = DOUBLE;
	else if (quote == SIMPLE && c == '\'')
		new_quote = NOTHING;
	else if (quote == DOUBLE && c == '"')
		new_quote = NOTHING;
	return (new_quote);
}

int	check_quote(char *line)
{
	int		i;
	t_quote	quote;

	i = 0;
	quote = NOTHING;
	while (line[i])
	{
		quote = update_quote_status(line[i], quote);
		i++;
	}
	if (quote != NOTHING)
	{
		if (quote == SIMPLE)
			return (error(NULL, QUOTE_SIMPLE_ERR, 2));
		else if (quote == DOUBLE)
			return (error(NULL, QUOTE_DOUBLE_ERR, 2));
	}
	return (0);
}

int	check_braces(char *line)
{
	int		i;
	t_quote	quote;
	t_quote	prev_quote;

	i = -1;
	quote = NOTHING;
	while (line[++i])
	{
		quote = update_quote_status(line[i], quote);
		if (line[i] == '$' && line[i + 1] == '{' && quote != SIMPLE)
		{
			prev_quote = quote;
			while (line[++i] && line[i] != '}')
			{
				quote = update_quote_status(line[i], quote);
				if (quote != NOTHING && prev_quote == NOTHING)
					return (error(NULL, BRACES_ERR, 2));
				else if (quote != DOUBLE && prev_quote == DOUBLE)
					return (error(NULL, QUOTE_DOUBLE_ERR, 2));
			}
			if (!line[i] && prev_quote == NOTHING)
				return (error(NULL, BRACES_ERR, 2));
		}
	}
	return (0);
}
