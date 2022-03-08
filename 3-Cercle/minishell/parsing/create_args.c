/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:28:17 by armendes          #+#    #+#             */
/*   Updated: 2022/03/08 15:40:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_words(t_token *words)
{
	int		i;
	t_token	*tmp;

	tmp = words;
	i = 0;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == ARG_IN_SIMPLE
			|| tmp->type == ARG_IN_DOUBLE)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static char	**create_args(t_token *words)
{
	t_token	*tmp;
	char	**args;
	int		i;

	i = count_words(words);
	tmp = words;
	args = malloc(sizeof(char *) * (i + 1));
	if (!args)
		return (NULL);
	i = 0;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == ARG_IN_SIMPLE
			|| tmp->type == ARG_IN_DOUBLE)
		{
			args[i] = tmp->word;
			i++;
		}
		tmp = tmp->next;
	}
	args[i] = NULL;
	return (args);
}

int	make_args(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		tmp->args = create_args(tmp->words);
		if (tmp->args == NULL)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
