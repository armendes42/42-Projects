/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:50:50 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/07 18:43:39 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_single_cmd(t_info *info)
{
	int		pid;
	t_cmd	*cmd;
	char	*path;

	cmd = info->cmd;
	if (check_if_builtin(cmd) == 0)
		exec_builtin(info, cmd); // attendre qu'arthur m'envoit un message d'erreur
	else 
	{
		pid = fork();
		if (pid == -1)
		{	
			perror("pid");
			return (-1);
		}
		if (pid == 0)
		{
			path = parse_path(info, cmd);
			if (execve(path, cmd->args, info->env) == -1)
			{	
				free(path);
				perror("execve single argument");
				exit(2);
			}
			printf("chelou\n");
		}
		waitpid(pid, NULL, 0);
		printf("je suis sorti\n");
	}
	return (0);
}

int	execution(t_info *info)
{
	int		pipefd[2][2];
	t_cmd	*yet;
	int		*pid;
	int		i;

	i = 0;
	if (count_nb_cmd(info) == 1)
	{	
		exec_single_cmd(info); // fork si c'est pas un builtin
		return (0);
	}
	pid = malloc(sizeof(int) * (count_nb_cmd(info))); //+1
	if (!pid)
		perror("malloc");
	yet = info->cmd;
	set_up_range(info);
	// 4. parcourir les redirections et changer les pipes en fonction
	while(yet != NULL)
	{
		pipe_odd_or_even(yet, pipefd);
		pid[i] = fork();
		if (pid[i] == -1)
			perror("fork");
		if (pid[i] == 0)
		{	
			if (check_if_builtin(yet) == 0)
				exec_builtin(info, yet);
			else
			{
				exec_binary(info, yet, pipefd);
				perror("error in exec loop");
				exit (2);
			}
		}
		close_pipe(yet, pipefd);
		yet = yet->next;
		i++;
	}
	i = 0;
	while (pid[i])
	{	
		printf("cmd %i has ended\n", i);
		waitpid(pid[i], NULL, 0);
		i++;
	}
	free(pid);
	return (0);
}
// ATTENTION: les heredocs sont a exec en premier !!