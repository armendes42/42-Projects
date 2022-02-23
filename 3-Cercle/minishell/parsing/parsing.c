/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:36 by armendes          #+#    #+#             */
/*   Updated: 2022/02/23 18:51:27 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parsing(char *line)
{
	t_cmd	*cmd;

	if (check_quote(line))
		error(NULL, QUOTE_ERR);
	cmd = find_pipe(line);
	if (!cmd)
		error(cmd, CMD_ERR);
	if (cut_into_words(&cmd))
		error(cmd, WORD_ERR);
	free_all(cmd);
}

int	main(void)
{
	char	*line;

	line = "";
	while (line)
	{
		line = readline("~>");
		parsing(line);
	}
	free(line);
	return (0);
}
