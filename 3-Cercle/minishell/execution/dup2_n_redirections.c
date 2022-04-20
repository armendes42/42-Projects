/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_n_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:33:14 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/20 17:51:06 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dup2_first_cmd(t_info *info, int (*pipefd)[2], int *red)
{
	close(pipefd[0][0]);
	if (red[1] == -1)
	{
		if (dup2(pipefd[0][1], STDOUT_FILENO) == -1)
		{	
			perror("dup2");
			error_and_exit(info, 1);
		}
	}
	close(pipefd[0][1]);
	return (0);
}

int	dup2_odd_cmd(t_info *info, t_cmd *cmd, int (*pipefd)[2], int *red)
{
	if (red[0] == -1)
	{
		if (dup2(pipefd[0][0], STDIN_FILENO) == -1)
		{
			perror("dup2");
			error_and_exit(info, 1);
		}
	}
	close(pipefd[0][0]);
	if (cmd->next != NULL)
	{	
		close(pipefd[1][0]);
		if (red[1] == -1)
		{
			if (dup2(pipefd[1][1], STDOUT_FILENO) == -1)
			{
				perror("dup2");
				error_and_exit(info, 1);
			}
		}
		close(pipefd[1][1]);
	}
	return (0);
}

int	dup2_even_cmd(t_info *info, t_cmd *cmd, int (*pipefd)[2], int *red)
{
	if (red[0] == -1)
	{
		if (dup2(pipefd[1][0], STDIN_FILENO) == -1)
		{
			perror("dup2");
			error_and_exit(info, 1);
		}
	}
	close(pipefd[1][0]);
	if (cmd->next != NULL)
	{
		close(pipefd[0][0]);
		if (red[1] == -1)
		{
			if (dup2(pipefd[0][1], STDOUT_FILENO) == -1)
			{
				perror("dup2");
				error_and_exit(info, 1);
			}
		}
		close(pipefd[0][1]);
	}
	return (0);
}

int	dup2_n_redirect(t_info *info, t_cmd *cmd, int (*pipefd)[2], int pid)
{
	int	red[2];

	red[0] = -1;
	red[1] = -1;
	if (check_file_n_create(cmd->words) == -1)
		return (-2);
	red[0] = redirect_in(cmd->words);
	red[1] = redirect_out(cmd->words, pid);
	if (red[0] == -2 || red[1] == -2)
		return (-2);
	if (cmd->range == 0)
		dup2_first_cmd(info, pipefd, red);
	else if (cmd->range % 2 == 1)
		dup2_odd_cmd(info, cmd, pipefd, red);
	else
		dup2_even_cmd(info, cmd, pipefd, red);
	return (red[1]);
}
