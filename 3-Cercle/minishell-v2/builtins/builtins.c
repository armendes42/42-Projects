/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:08:32 by armendes          #+#    #+#             */
/*   Updated: 2022/04/07 16:57:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_info *info, t_cmd *cmd) // est ce que tu peux  le refaire avec ce prototype ?
{
	int	control;

	if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		builtin_echo(cmd->args);
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		builtin_cd(cmd->args, info->env);
	else if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		builtin_pwd();
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		control = builtin_export(info, cmd);
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		control = builtin_unset(info, cmd);
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		builtin_env(info->env);
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		builtin_exit(info, cmd);
	if (control == -1)
		return ;
}

int	check_if_builtin(t_cmd *cmd)
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
	return (-1);
}
