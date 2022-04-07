/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_binary_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:00:45 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/07 17:35:51 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_var_env_path(char **ev)
{
	char 	**tab_path;
	char	*tmp;

	tmp = ft_getenv("PATH", ev);
	if (!tmp)
	{
		perror("ft_getenv");
		return (NULL);
	}
	tab_path = ft_split(tmp, ':');
	free(tmp);
	return (tab_path);
}

char *format_path(char *path_to_test, char *word)
{
	char	*tmp1;
	char	*tmp2;

	if (!path_to_test)
		return (NULL);
	tmp1 = ft_strjoin(path_to_test, "/");
	tmp2 = ft_strjoin(tmp1, word);
	free(tmp1);
	return (tmp2);
}

char *recover_cmd_path(char **tab_path, char *word)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab_path[i])
	{
		// verifier en amont qu'on a bien le droit d'acceder au path avec F_OK
		tmp = format_path(tab_path[i], word);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		else
			i++;
		free(tmp);
	}
	return (NULL);
}

char	*check_right_executable(t_cmd *cmd)
{
	char *path;

	path = malloc(sizeof(char) * (ft_strlen(cmd->args[0]) + 1));
	path = cmd->args[0];
	if (access(path, F_OK | X_OK) == -1)
		return (NULL);
	else
		return (path);
}

char	*parse_path(t_info *info, t_cmd *cmd)
{
	char	**tab_path;
	char	*path;

	if (check_if_executable(cmd) == 0)
	{
		path = check_right_executable(cmd);
		return (path);
	}
	tab_path = get_var_env_path(info->env);
	if (!tab_path)
		perror("error in get path in env\n");
	path = recover_cmd_path(tab_path, cmd->args[0]);
	if (!path)
		perror("path of the cmd not found");
	free_tab_char(tab_path);
	return (path);
}