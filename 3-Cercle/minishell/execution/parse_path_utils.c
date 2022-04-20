/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:43:47 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/18 21:36:27 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_var_env_path(char **ev)
{
	char	**tab_path;
	char	*tmp;

	tmp = ft_getenv("PATH", ev);
	if (!tmp)
		return (NULL);
	tab_path = ft_split(tmp, ':');
	if (tmp != NULL)
		free(tmp);
	if (!tab_path)
		error_and_exit(get_info(), 1);
	return (tab_path);
}

char	*format_path(char *path_to_test, char *word)
{
	char	*tmp1;
	char	*tmp2;

	if (!path_to_test)
		return (NULL);
	tmp1 = ft_strjoin(path_to_test, "/");
	tmp2 = ft_strjoin(tmp1, word);
	if (tmp1 != NULL)
		free(tmp1);
	return (tmp2);
}

char	*recover_cmd_path(char **tab_path, char *word)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab_path[i])
	{
		tmp = format_path(tab_path[i], word);
		if (access(tmp, X_OK | F_OK) == 0)
			return (tmp);
		else
			i++;
		if (tmp != NULL)
			free(tmp);
	}
	return (NULL);
}
