/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:50:50 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/06 17:53:36 by armendes         ###   ########.fr       */
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

int	exec_first_binary(t_info *info, t_cmd *cmd, int (*pipefd)[2])
{
	char	*path;
	int		error;

	error = SUCCESS;
	// if (pipe(pipefd[0]) == -1)
	// 	error = ERROR;
	close(pipefd[0][0]);
	if (dup2(pipefd[0][1], STDOUT_FILENO) == -1)
		error = ERROR;
	close(pipefd[0][1]);
	path = parse_path(info, cmd);
	if (execve(path, cmd->args, info->env) == -1)
		error = ERROR;
	free(path);
	if (check_error(error, "exec_first_binary") == true)
		exit (2);
	return (0);
}

int	exec_odd_binary(t_info *info, t_cmd *cmd, int (*pipefd)[2])
{
	char	*path;
	int		error;

	error = SUCCESS;
	if (dup2(pipefd[0][0], STDIN_FILENO) == -1)
		error = ERROR;
	close(pipefd[0][0]);
	// if (pipe(pipefd[1]) == -1)
	// 	error = ERROR;
	close(pipefd[1][0]);
	if (cmd->next != NULL)
	{	
		if (dup2(pipefd[1][1], STDOUT_FILENO) == -1)
			error = ERROR;
		close(pipefd[1][1]);
	}
	path = parse_path(info, cmd);
	if (execve(path, cmd->args, info->env) == -1)
		error = ERROR;
	free(path);
	if (check_error(error, "exec_odd_binary") == true)
		exit(2);
	return (0);
}

int	exec_even_binary(t_info *info, t_cmd *cmd, int (*pipefd)[2])
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
	if (execve(path, cmd->args, info->env) == -1)
		error = ERROR;
	free(path);
	if (check_error(error, "exec_even_binary") == -1)
		exit(2);
	return (0);
}

int	exec_binary(t_info *info, t_cmd *cmd, int (*pipefd)[2])
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
			return (-1);
	}
	return (0);
}

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
			perror("pipe");
			return (-1);
		}
		if (pid == 0)
		{
			// if (check_if_executable(cmd) == 0)
			// 	exec_executable(cmd, NULL); //pas oublier d'exit() si ca foire
			path = parse_path(info, cmd);
			if (execve(path, cmd->args, info->env) == -1)
			{	
				free(path);
				perror("execve single argument");
				exit(2);
			}
		}
		waitpid(pid, NULL, 0);
	}
	return (0);
}

void	pipe_odd_or_even(t_cmd *cmd, int(*pipefd)[2])
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

int	execution(t_info *info)
{
	int		pipefd[2][2];
	t_cmd	*yet;
	int		*pid;
	int		i;

	if (count_nb_cmd(info) == 1)
		exec_single_cmd(info); // fork si c'est pas un builtin
	i = 0;
	pid = malloc(sizeof(int) * count_nb_cmd(info)); // comment alouer proprement ces deux pipe ?
	if (!pid)
		perror("malloc");
	yet = info->cmd;
	set_up_range(info);
	// 3. parcourir les pipe -> est ce vraiment necessaire ?
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
				
			// else if (check_if_executable(yet) == 0)
			// 	exec_executable(yet, pipefd); //  quel est la difference dans l'utilisation d'execve?
			else
				exec_binary(info, yet, pipefd);
			printf("error in exec loop");
			exit (2); //dois je mettre une ret 0?
		}
		if (waitpid(pid[i], NULL, 0) == -1)
			perror("waitpid");
		close_pipe(yet, pipefd);
		yet = yet->next;
		i++;
	}
	free(pid);
	return (0);
}
// ATTENTION: les heredocs sont a exec en premier !!