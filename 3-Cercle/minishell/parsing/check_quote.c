/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:12:19 by armendes          #+#    #+#             */
/*   Updated: 2022/02/09 18:13:00 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

e_quote	update_quote_status(char c, e_quote quote)
{
	e_quote	new_quote;

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
	e_quote	quote;

	i = 0;
	quote = NOTHING;
	while (line[i])
	{
		if (line[i] == '\'')
			quote = update_quote_status('\'', quote);
		else if (line[i] == '"')
			quote = update_quote_status('"', quote);
		i++;
	}
	if (quote != NOTHING)
		return (-1);
	return (0);
}