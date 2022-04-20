/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:04:52 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/18 21:06:35 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab_char(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab != NULL)
		free(tab);
}

void	set_up_range(t_info *info)
{
	int		i;
	t_cmd	*yet;

	i = 0;
	yet = info->cmd;
	while (yet != NULL)
	{
		yet->range = i;
		i++;
		yet = yet->next;
	}
}

int	count_nb_cmd(t_info *info)
{
	int		i;
	t_cmd	*yet;

	i = 0;
	yet = info->cmd;
	while (yet != NULL)
	{
		i++;
		yet = yet->next;
	}
	return (i);
}

int	check_if_executable(t_cmd *cmd)
{
	if (ft_strncmp(cmd->args[0], "./", 2) == 0)
		return (0);
	if (ft_strncmp(cmd->args[0], "/", 1) == 0)
		return (0);
	return (-1);
}

int	check_error(int error, char *message)
{
	if (error == ERROR)
	{
		perror(message);
		return (ERROR);
	}
	return (SUCCESS);
}
