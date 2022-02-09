/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:36 by armendes          #+#    #+#             */
/*   Updated: 2022/02/09 19:41:01 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parsing(char *line)
{
	t_cmd	*cmd;
	

	if (check_quote(line))
		error(QUOTE_ERR);
	cmd = find_pipe(line);
	if (!cmd)
		error(CMD_ERR);
	cut_into_words(&cmd);
	while (cmd)
	{
		write(0, cmd->cmd, ft_strlen(cmd->cmd));
		write(0, "\n", 1);
		cmd = cmd->next;
	}
}

int	main(void)
{
	char *line;

	line = "";
	while (line)
	{
		line = readline("~>");
		parsing(line);
	}
	free(line);
	return (0);
}