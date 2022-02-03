/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:32:31 by armendes          #+#    #+#             */
/*   Updated: 2022/02/03 21:07:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_cmd(t_command **cmd_line, char *cmd)
{
	t_command	*elem;
	t_command	*tmp;

	elem = malloc(sizeof(t_command));
	if (!elem)
		return (-1);
	elem->cmd = cmd;
	elem->cmd_pipe = NULL;
	elem->prev = NULL;
	elem->next = NULL;
	if (*cmd_line == NULL)
		*cmd_line = elem;
	else
	{
		tmp = *cmd_line;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->prev = tmp;
	}
	return (0);
}

t_command	*cut_cmd_line(char *line)
{
	int			i;
	int			j;
	char		**tmp;
	t_command	*cmd_line;

	tmp = ft_split(line, ';');
	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i])
		i++;
	j = 0;
	cmd_line = NULL;
	while (j < i)
	{
		if (add_cmd(&cmd_line, tmp[j]))
			return (NULL);
		j++;
	}
	return (cmd_line);
}