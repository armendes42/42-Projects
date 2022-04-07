/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:36 by armendes          #+#    #+#             */
/*   Updated: 2022/04/07 19:14:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parsing(char *line, t_info *info)
{
	if (check_quote(line))
		return (error(NULL, QUOTE_ERR));
	info->cmd = find_pipe(line);
	if (!(info->cmd))
		return (error(info, CMD_ERR));
	if (cut_into_words(info))
		return (error(info, WORD_ERR));
	if (make_args(&info->cmd))
		return (error(info, ARG_ERR));
	// read_struct(info);
	return (0);
}

t_info	*get_info(void)
{
	static t_info	info;

	return (&info);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_info	*info;

	(void)argc;
	(void)argv;
	line = "";
	info = get_info();
	info->env = copy_env(envp);
	info->exit_status = 127;
	while (line)
	{
		line = readline("~>");
		if (line == NULL)
		{
			free(line);
			return (-1);
		}
		if (line && *line)
			add_history(line);
		// if (parsing(line, &info) == 0)
		// {
		// 	check_if_builtin(&info, info.cmd);
		// 	free_info(&info);
		// }
		parsing(line, info);
		// exec_builtin(info, info->cmd);
		execution(info);
		// exec_binary(&info);
		free_info(info);
	}
	free_env(info->env);
	free(line);
	return (0);
}
