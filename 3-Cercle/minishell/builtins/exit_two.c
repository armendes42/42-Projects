/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:03:02 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 17:36:39 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit_if_cmd_alone(t_info *info, t_cmd *cmd)
{
	ft_putstr_fd("exit\n", 1);
	if (cmd->args[1] == NULL)
	{
		g_exit_status = 0;
		my_exit(info);
		return ;
	}
	else if (is_arg_numeric(cmd->args[1]) == 1)
	{
		g_exit_status = 2;
		ft_putstr_fd("$: exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		my_exit(info);
		return ;
	}
	else if (cmd->args[2] != NULL)
	{
		g_exit_status = 1;
		ft_putstr_fd("$: exit: too many arguments\n", 2);
		return ;
	}
	g_exit_status = ft_atoi(cmd->args[1]) % 256;
	g_exit_status = (256 + g_exit_status) % 256;
	my_exit(info);
}

void	builtin_exit_if_multiple_cmd(t_cmd *cmd)
{
	if (cmd->args[1] == NULL)
	{
		g_exit_status = 0;
		return ;
	}
	else if (is_arg_numeric(cmd->args[1]) == 1)
	{
		g_exit_status = 2;
		ft_putstr_fd("$: exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return ;
	}
	else if (cmd->args[2] != NULL)
	{
		g_exit_status = 1;
		ft_putstr_fd("$: exit: too many arguments\n", 2);
		return ;
	}
	g_exit_status = ft_atoi(cmd->args[1]) % 256;
	g_exit_status = (256 + g_exit_status) % 256;
}
