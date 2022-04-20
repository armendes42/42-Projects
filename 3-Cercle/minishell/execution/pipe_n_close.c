/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_n_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:35:32 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/20 17:36:08 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_odd_or_even(t_cmd *cmd, int (*pipefd)[2])
{
	if (cmd->next == NULL)
		return ;
	else if (cmd->range % 2 == 0)
		pipe(pipefd[0]);
	else if (cmd->range % 2 != 0)
		pipe(pipefd[1]);
}

void	close_pipe(t_cmd *cmd, int (*pipefd)[2])
{
	if (cmd->range == 0)
		close(pipefd[0][1]);
	else if (cmd->range % 2 == 1 && cmd->next != NULL)
	{
		close(pipefd[0][0]);
		close(pipefd[1][1]);
	}
	else if (cmd->range % 2 == 0 && cmd->next != NULL)
	{
		close(pipefd[0][1]);
		close(pipefd[1][0]);
	}
	else if (cmd->range % 2 == 1 && cmd->next == NULL)
		close(pipefd[0][0]);
	else if (cmd->range % 2 == 0 && cmd->next == NULL)
		close(pipefd[1][0]);
}
