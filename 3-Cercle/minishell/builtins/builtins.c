/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:08:32 by armendes          #+#    #+#             */
/*   Updated: 2022/04/04 15:57:46 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_if_builtin(t_info *info)
{
	int	control;

	control = 0;
	if (ft_strncmp(info->cmd->args[0], "echo", 5) == 0)
		builtin_echo(info->cmd->args);
	else if (ft_strncmp(info->cmd->args[0], "cd", 3) == 0)
		builtin_cd(info->cmd->args);
	else if (ft_strncmp(info->cmd->args[0], "pwd", 4) == 0)
		builtin_pwd();
	else if (ft_strncmp(info->cmd->args[0], "export", 7) == 0)
		control = builtin_export(info);
	else if (ft_strncmp(info->cmd->args[0], "unset", 6) == 0)
		control = builtin_unset(info);
	else if (ft_strncmp(info->cmd->args[0], "env", 4) == 0)
		builtin_env(info->env);
	else if (ft_strncmp(info->cmd->args[0], "exit", 5) == 0)
		builtin_exit(info);
	if (control == -1)
		return ;
}
