/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:51:03 by armendes          #+#    #+#             */
/*   Updated: 2022/02/04 17:08:06 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parsing(char *line)
{
	char 	**path;
	t_cmd	*cmd_line;

	path = ft_split(getenv("PATH"), ':');
	if (path == NULL) 
	{
		write(0, "PATH n'existe pas", 17);
		return (-1);
	}
	cmd_line = cut_cmd_line(line);
	if (cmd_line == NULL)
		return (-1);
	if (check_pipe(&cmd_line))
		return (-1);
	return (0);
}

int	main(void)
{
	char *line;

	line = "";
	while (line)
	{
		line = readline("~>");
		if (parsing(line) == -1)
			return (-1);
	}
	free(line);
	return (0);
}
