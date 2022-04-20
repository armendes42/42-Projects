/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:08:32 by armendes          #+#    #+#             */
/*   Updated: 2022/04/19 19:01:16 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_info *info, t_cmd *cmd, int *pid, int fd)
{
	int	control;

	control = 0;
	if (fd == -1)
		fd = STDOUT_FILENO;
	if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		builtin_echo(cmd->args, fd);
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		control = builtin_cd(cmd->args, info->env, pid);
	else if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		control = builtin_pwd(fd, pid);
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		control = builtin_export(info, cmd);
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		control = builtin_unset(info, cmd);
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		builtin_env(info->env, fd);
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		control = builtin_exit(info, cmd);
	if (pid != NULL)
		free(pid);
	if (control == -1)
		return (-1);
	g_exit_status = 0;
	return (0);
}

int	check_if_builtin(t_cmd *cmd, int fd)
{
	if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		return (0);
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		return (0);
	else if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		return (0);
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		return (0);
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		return (0);
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		return (0);
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		return (0);
	if (fd != -1)
		close(fd);
	return (-1);
}
