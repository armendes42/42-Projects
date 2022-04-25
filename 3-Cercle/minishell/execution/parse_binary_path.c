/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_binary_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:00:45 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/21 19:44:19 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	access_error(char *path, char *cmd, char *msg, int ex)
{
	ft_putstr_fd("$ : ", 2);
	if (cmd != NULL)
		ft_putstr_fd(cmd, 2);
	else
		ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	if (msg != NULL)
		ft_putstr_fd(msg, 2);
	else
		perror("");
	g_exit_status = ex;
	if (path != NULL)
		free(path);
	free_info(get_info());
	exit(g_exit_status);
}

char	*parse_exec_path(t_cmd *cmd)
{
	char	*path;

	path = ft_strdup(cmd->args[0]);
	if (access(path, X_OK) == -1)
		access_error(path, NULL, NULL, 126);
	if (access(path, F_OK) == -1)
		access_error(path, NULL, "No such file or directory", 127);
	return (path);
}

char	*parse_binary_path(t_info *info, t_cmd *cmd)
{
	char	*path;
	char	**tab_path;

	tab_path = get_var_env_path(info->env);
	if (!tab_path && cmd->args[0] != NULL)
		access_error(NULL, cmd->args[0], "No such file or directory\n", 127);
	path = recover_cmd_path(tab_path, cmd->args[0]);
	free_tab_char(tab_path);
	if (!path && cmd->args[0] != NULL)
		access_error(path, cmd->args[0], "command not found\n", 127);
	return (path);
}

char	*parse_path(t_info *info, t_cmd *cmd)
{
	char	*path;

	if (check_if_executable(cmd) == 0)
	{	
		path = parse_exec_path(cmd);
		return (path);
	}
	else
	{
		path = parse_binary_path(info, cmd);
		return (path);
	}
}
