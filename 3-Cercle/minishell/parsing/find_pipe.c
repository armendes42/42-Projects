/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:20:59 by armendes          #+#    #+#             */
/*   Updated: 2022/02/10 16:55:33 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*find_pipe(char *line)
{
	int		i;
	e_quote	quote;
	int		start_for_pipe;
	t_cmd	*cmd;

	i = 0;
	quote = NOTHING;
	start_for_pipe = 0;
	cmd = NULL;
	while (line[i])
	{
		quote = update_quote_status(line[i], quote);
		if (line[i] == '|' && quote == NOTHING)
		{
			if (add_cmd(&cmd, start_for_pipe, i, line))
				return (NULL);
			start_for_pipe = i + 1;
		}
		i++;
	}
	add_cmd(&cmd, start_for_pipe, i, line);
	return (cmd);
}
