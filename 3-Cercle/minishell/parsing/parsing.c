/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:51:03 by armendes          #+#    #+#             */
/*   Updated: 2022/02/07 17:43:07 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_cmd_args(char *cmd)
{
	int	i;
	int	control_simple;
	int	control_double;

	i = 0;
	control_simple = 0;
	control_double = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' && (i > 0 && cmd[i - 1] != '\\')
			&& control_simple == 0)
		{
			write(0, &cmd[i], ft_strlen(&cmd[i]));
			if (simple_quote(&cmd[i]) == 1)
				control_simple = 1;
		}
		if (cmd[i] == '\'' && (i > 0 && cmd[i - 1] != '\\')
			&& control_simple == 1)
			control_simple = 0;
		if (cmd[i] == '"' && control_double == 0)
		{
			//if (double_quote(&cmd[i]) == 1)
				control_double = 1;
		}
		i++;
	}
	return (0);
}

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
	while (cmd_line)
	{
		if (get_cmd_args(cmd_line->cmd))
			return (-1);
		cmd_line = cmd_line->next;
	}
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
