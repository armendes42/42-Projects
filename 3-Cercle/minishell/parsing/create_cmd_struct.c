/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:14:01 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 16:26:25 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*create_elem(char *line, int start, int end)
{
	t_cmd	*elem;
	char	*str;

	elem = malloc(sizeof(t_cmd));
	if (!elem)
		error_and_exit(get_info(), 1);
	elem->next = NULL;
	elem->prev = NULL;
	elem->words = NULL;
	elem->args = NULL;
	str = format_str(line, start, end);
	if (!str)
		error_and_exit(get_info(), 1);
	elem->cmd = str;
	return (elem);
}

int	add_cmd(t_cmd **cmd, int start, int end, char *line)
{
	t_cmd	*elem;
	t_cmd	*tmp;

	if (cmd == NULL)
		return (-1);
	elem = create_elem(line, start, end);
	if (*cmd == NULL)
		*cmd = elem;
	else
	{
		tmp = *cmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->prev = tmp;
	}
	return (0);
}
