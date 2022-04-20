/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_binary_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:00:45 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/19 18:08:25 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_exec_path(t_cmd *cmd)
{
	char	*path;

	path = ft_strdup(cmd->args[0]);
	if (access(path, X_OK) == -1)
	{	
		perror("access");
		g_exit_status = 126;
		exit(g_exit_status);
	}
	if (access(path, F_OK) == -1)
	{	
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory", 2);
		g_exit_status = 127;
		exit(g_exit_status);
	}
	return (path);
}

char	*parse_binary_path(t_info *info, t_cmd *cmd)
{
	char	*path;
	char	**tab_path;

	tab_path = get_var_env_path(info->env);
	if (!tab_path && cmd->args[0] != NULL)
	{
		ft_putstr_fd(cmd->args[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_exit_status = 127;
		exit(g_exit_status);
	}
	path = recover_cmd_path(tab_path, cmd->args[0]);
	free_tab_char(tab_path);
	if (!path && cmd->args[0] != NULL)
	{
		ft_putstr_fd(cmd->args[0], 2);
		ft_putstr_fd(": Command not found\n", 2);
		g_exit_status = 127;
		exit(g_exit_status);
	}
	return (path);
}

char	*parse_path(t_info *info, t_cmd *cmd)
{
	char	*path;

	if (check_if_executable(cmd) == 0)
	{	
		path = parse_exec_path(cmd);
		if (!path)
			return (NULL);
		return (path);
	}
	else
	{
		path = parse_binary_path(info, cmd);
		if (!path)
			return (NULL);
		return (path);
	}
}
