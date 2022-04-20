/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary_n_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:44:06 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/20 15:07:23 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_binary_n_exec(t_info *info, t_cmd *cmd, int *pid)
{
	char	*path;

	path = parse_path(info, cmd);
	if (cmd->args[0] != NULL)
	{
		if (execve(path, cmd->args, info->env) == -1)
		{
			if (path != NULL)
				free(path);
			if (pid != NULL)
				free(pid);
			error_and_exit(get_info(), 1);
		}
	}
	exit(1);
}

void	manage_error_in_child(void)
{
	if (WIFEXITED(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status);
	else if (WIFSIGNALED(g_exit_status))
	{
		g_exit_status = WTERMSIG(g_exit_status);
		g_exit_status += 128;
		if (g_exit_status == 130)
			write(1, "\n", 1);
		if (g_exit_status == 131)
			ft_putstr_fd("quit (core dumped)\n", 2);
	}
}
