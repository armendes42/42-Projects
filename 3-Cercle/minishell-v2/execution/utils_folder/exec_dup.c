/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:25:51 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/01 15:40:34 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_binary(t_info *info)
{
	printf("\n***** execution_binary *****\n");
	char	*path;
	t_cmd	*yet;
	int		pid1;
	int		pid2;
	int		pid3;
	int		pipefd[2][2];

	yet = info->cmd;
	path = parse_path(info, yet);
	printf("path is %s\n", path);
	if (pipe(pipefd[0]) == -1)
		perror("pipe");
	pid1 = fork();
	if (pid1 == -1)
		perror("fork");
	else if (pid1 == 0)
	{
		close(pipefd[0][0]);
		dup2(pipefd[0][1], STDOUT_FILENO);
		close(pipefd[0][1]);
		execve(path, yet->args, info->env);
	}
	close(pipefd[0][1]);
	free(path);
	yet = yet->next;
	path = parse_path(info, yet);
	if (!path)
		perror("error parse path\n");
	if (pipe(pipefd[1]) == -1)
		perror("pipe"); 
	pid2 = fork();
	if (pid2 == -1)
		perror("fork");
	else if (pid2 == 0)
	{
		dup2(pipefd[0][0], STDIN_FILENO);
		close(pipefd[0][0]);
		close(pipefd[1][0]);
		dup2(pipefd[1][1], STDOUT_FILENO);
		close(pipefd[1][1]);
		execve(path, yet->args, NULL);
	}
	close(pipefd[0][0]);
	close(pipefd[1][1]);
	free(path);
	yet = yet->next;
	path = parse_path(info, yet);
	if (!path)
		perror("error parse path\n");
	pid3 = fork();
	if (pid3 == -1)
		perror("fork");
	else if (pid3 == 0)
	{
		close(pipefd[1][1]);
		dup2(pipefd[1][0], STDIN_FILENO);
		close(pipefd[1][0]);
		execve(path, yet->args, NULL);
	}
	close(pipefd[1][0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
	return (0);
}