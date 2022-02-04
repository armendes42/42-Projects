/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:32:31 by armendes          #+#    #+#             */
/*   Updated: 2022/02/04 16:39:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_cmd(t_cmd **cmd_line, char *cmd)
{
	t_cmd	*elem;
	t_cmd	*tmp;

	elem = malloc(sizeof(t_cmd));
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

t_cmd	*cut_cmd_line(char *line)
{
	int			i;
	char		**tmp;
	t_cmd	*cmd_line;

	tmp = ft_split(line, ';');
	if (!tmp)
		return (NULL);
	i = 0;
	cmd_line = NULL;
	while (tmp[i])
	{
		if (add_cmd(&cmd_line, tmp[i]))
			return (NULL);
		i++;
	}
	return (cmd_line);
}

static int	add_cmd_pipe(t_cmd_pipe **cmd_pipe, char *cmd)
{
	t_cmd_pipe	*elem;
	t_cmd_pipe	*tmp;

	elem = malloc(sizeof(t_cmd_pipe));
	if (!elem)
		return (-1);
	elem->cmd = cmd;
	elem->prev = NULL;
	elem->next = NULL;
	if (*cmd_pipe == NULL)
		*cmd_pipe = elem;
	else
	{
		tmp = *cmd_pipe;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->prev = tmp;
	}
	return (0);
}

static t_cmd_pipe	*cut_cmd_pipe(char *cmd_str)
{
	int			i;
	char		**tmp;
	t_cmd_pipe	*cmd_pipe;

	tmp = ft_split(cmd_str, '|');
	if (!tmp)
		return (NULL);
	i = 0;
	cmd_pipe = NULL;
	while (tmp[i])
	{
		if (add_cmd_pipe(&cmd_pipe, tmp[i]))
			return (NULL);
		i++;
	}
	return (cmd_pipe);
}

int	check_pipe(t_cmd **cmd_line)
{
	t_cmd	*tmp;

	if (!*cmd_line)
		return (-1);
	tmp = *cmd_line;
	while (tmp)
	{
		if (ft_strchr(tmp->cmd, '|'))
		{
			tmp->cmd_pipe = cut_cmd_pipe(tmp->cmd);
			if (tmp->cmd_pipe == NULL)
				return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}
