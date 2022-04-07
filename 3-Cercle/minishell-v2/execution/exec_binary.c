/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:44:06 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/07 14:15:40 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	exec_first_binary(t_info *info, t_cmd *cmd, int (*pipefd)[2])
{
	char	*path;
	//int		error;

	//error = SUCCESS;
	close(pipefd[0][0]);
	if (dup2(pipefd[0][1], STDOUT_FILENO) == -1)
		//error = ERROR;
	close(pipefd[0][1]);
	char *str = ft_strjoin("./", cmd->args[0]);
	if (access(cmd->args[0], X_OK) == 0)
	{	
		ft_putstr_fd(cmd->args[0], 1);
		execve(str, cmd->args, info->env);
	}
	else
		ft_putstr_fd("ok\n", 1);
	path = parse_path(info, cmd);
	if (execve(path, cmd->args, info->env) == -1)
		//error = ERROR;
	free(path);
	// if (check_error(error, "exec_first_binary") == true)
	// 	exit (2);
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
	if (cmd->next != NULL)
	{	
		close(pipefd[1][0]);
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
	if (cmd->next != NULL)
	{
		close(pipefd[0][0]);
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
