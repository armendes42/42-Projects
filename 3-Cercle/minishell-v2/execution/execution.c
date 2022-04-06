/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:50:50 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/05 16:36:52 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_error(int error, char *message)
{
	if (error == ERROR)
	{
		perror(message);
		return (ERROR);
	}
	return (SUCCESS);
}

int	exec_first_binary(t_info *info, t_cmd *cmd, int **pipefd)
{
	char	*path;
	int		error;

	error = SUCCESS;
	if (pipe(pipefd[0]) == -1)
		error = ERROR;
	close(pipefd[0][0]);
	if (dup2(pipefd[0][1], STDOUT_FILENO) == -1)
		error = ERROR;
	close(pipefd[0][1]);
	path = parse_path(info, cmd);
	if (execve(path, cmd->args[0], info->env) == -1)
		error = ERROR;
	free(path);
	if (check_error(error, "exec_first_binary") == true)
		return (-1);
	return (0);
}

int	exec_odd_binary(t_info *info, t_cmd *cmd, int **pipefd)
{
	char	*path;
	int		error;

	error = SUCCESS;
	if (dup2(pipefd[0][0], STDIN_FILENO) == -1)
		error = ERROR;
	close(pipefd[0][0]);
	if (pipe(pipefd[1]) == -1)
		error = ERROR;
	close(pipefd[1][0]);
	if (cmd->next != NULL)
	{	
		if (dup2(pipefd[1][1], STDOUT_FILENO) == -1)
			error = ERROR;
		close(pipefd[1][1]);
	}
	path = parse_path(info, cmd);
	if (execve(path, cmd->args[0], info->env) == -1)
		error = ERROR;
	free(path);
	if (check_error(error, "exec_odd_binary") == true)
		return (-1);
	return (0);
}

int	exec_even_binary(t_info *info, t_cmd *cmd, int **pipefd)
{
	char	*path;
	bool	error;

	error = SUCCESS;
	if (dup2(pipefd[1][0], STDIN_FILENO) == -1)
		error = ERROR;
	close(pipefd[1][0]);
	if (pipe(pipefd[0]) == -1)
		error = ERROR;
	close(pipefd[0][0]);
	if (cmd->next != NULL)
	{
		if (dup2(pipefd[0][1], STDOUT_FILENO) == -1)
			error = ERROR;
		close(pipefd[0][1]); 
	}
	path = parse_path(info, cmd);
	if (execve(path, cmd->args[0], info->env) == -1)
		error = ERROR;
	free(path);
	if (check_error(error, "exec_even_binary") == -1)
		return (-1);
	return (0);
}

int	exec_binary(t_info *info, t_cmd *cmd, int **pipefd)
{
	if (cmd->range == 0)
	{
		if (exec_first_binary(info, cmd, pipefd) == -1)
			return (-1);
	}
	else if (cmd->range % 2 == 1)
	{
		if (exec_odd_binary(info, cmd, pipefd) == -1)
			return (-1);
	}
	else
	{
		if (exec_even_binary(info, cmd, pipefd) == -1)
			return (-1)
	}
	return (0);
}

int	execution(t_info *info)
{
	int		pipefd[2][2];
	t_cmd	*yet;
	int		*pid;
	int		i;

	// if (count_nb_cmd(info) == 1)
	// 	exec_single_cmd(info->cmd);
	i = 0;
	pid = malloc(sizeof(int) * count_nb_cmd(info));
	if (!pid)
		perror("malloc");
	yet = info->cmd;
	set_up_range(yet);
	// 3. parcourir les pipe -> est ce vraiment necessaire ?
	// 4. parcourir les redirections et changer les pipes en fonction
	while(yet != NULL)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			perror("fork");
		if (pid[i] == 0)
		{	
			if (check_if_builtin(yet) == 0)
				exec_builtin(info, yet);
				//dois je mettre une ret 0?
			else if (check_if_executable(yet) == 0)
				exec_executable(yet, pipefd); //  quel est la difference dans l'utilisation d'execve?
			else
				exec_binary(yet, pipefd, info);
			//comment bien fermer les pipes ?
		}
		if (waitpid(pid[i], NULL, 0) == -1)
			perror("waitpid");
		i++;
		yet = yet->next;
	}
	free_tab(pid);
}

// ATTENTION: les heredocs sont a exec en premier !!