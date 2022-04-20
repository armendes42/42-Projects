/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:50:50 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/19 19:01:28 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_for_the_child(t_info *info, int *pid)
{
	int		i;

	i = 0;
	while (i < count_nb_cmd(info))
	{	
		waitpid(pid[i], &g_exit_status, 0);
		i++;
	}
	manage_error_in_child();
	if (pid != NULL)
		free(pid);
}

int	exec_single_cmd_in_child(t_info *info, t_cmd *cmd)
{
	int	pid;

	ignore_signals_parent();
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		set_up_signals_child();
		redirect_in(cmd->words);
		redirect_out(cmd->words, pid);
		exec_binary_n_exec(info, cmd, NULL);
	}
	waitpid(pid, &g_exit_status, 0);
	manage_error_in_child();
	set_up_signals_parent();
	return (0);
}

int	exec_single_cmd(t_info *info, t_cmd *cmd)
{
	int		pid;
	int		fd;

	if (check_file_n_create(cmd->words) == -1)
		return (-1);
	if (check_if_builtin(cmd, -1) == 0)
	{
		pid = STDOUT_FILENO;
		manage_here_doc(cmd->words, pid);
		fd = redirect_out(cmd->words, pid);
		exec_builtin(info, cmd, NULL, fd);
		if (fd != -1)
			close(fd);
		return (0);
	}
	exec_single_cmd_in_child(info, cmd);
	return (0);
}

void	exec_cmd_one_by_one(t_cmd *yet, int *pid, int (*pipefd)[2], int i)
{
	int		fd;

	pipe_odd_or_even(yet, pipefd);
	pid[i] = fork();
	if (pid[i] == 0)
	{
		set_up_signals_child();
		fd = dup2_n_redirect(get_info(), yet, pipefd, pid[i]);
		if (fd == -2)
			exit(2);
		if (check_if_builtin(yet, fd) == 0)
		{
			exec_builtin(get_info(), yet, pid, fd);
			if (fd != -1)
				close(fd);
			exit(0);
		}
		else
			exec_binary_n_exec(get_info(), yet, pid);
	}
	close_pipe(yet, pipefd);
}

int	execution(t_info *info)
{
	int		pipefd[2][2];
	int		*pid;
	t_cmd	*yet;
	int		i;

	i = 0;
	yet = info->cmd;
	if (count_nb_cmd(info) == 1)
	{
		exec_single_cmd(info, info->cmd);
		return (0);
	}
	pid = malloc(sizeof(int) * (count_nb_cmd(info) + 1));
	if (!pid)
		error_and_exit(info, 1);
	set_up_range(info);
	ignore_signals_parent();
	while (yet != NULL)
	{
		exec_cmd_one_by_one(yet, pid, pipefd, i++);
		yet = yet->next;
	}
	wait_for_the_child(info, pid);
	set_up_signals_parent();
	return (0);
}
