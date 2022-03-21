/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:08:32 by armendes          #+#    #+#             */
/*   Updated: 2022/03/21 17:52:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_if_builtin(t_info *info)
{
	int	control;

	// if (info.cmd->args[0] == "echo")
	// 	builtin_echo();
	// else if (info.cmd->args[0] == "cd")
	// 	builtin_cd();
	// else if (info.cmd->args[0] == "pwd")
	// 	builtin_pwd();
	if (ft_strncmp(info->cmd->args[0], "export", 7) == 0)
		control = builtin_export(info);
	// else if (info.cmd->args[0] == "unset")
	// 	builtin_unset();
	else if (ft_strncmp(info->cmd->args[0], "env", 4) == 0)
		builtin_env(info->env);
	// else if (info.cmd->args[0] == "exit")
	// 	builtin_exit();
	if (control == -1)
		return ;
}
