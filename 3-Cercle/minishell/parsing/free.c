/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:11:15 by armendes          #+#    #+#             */
/*   Updated: 2022/04/21 17:27:59 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_words(t_token *words)
{
	t_token	*tmp_w;
	t_token	*tmp_w2;

	tmp_w = words;
	while (tmp_w)
	{
		tmp_w2 = tmp_w->next;
		if (!(tmp_w->type == RED_IN || tmp_w->type == RED_OUT
				|| tmp_w->type == RED_OUT_APPEND || tmp_w->type == HERE_DOC))
			if (tmp_w->word != NULL)
				free(tmp_w->word);
		if (tmp_w != NULL)
			free(tmp_w);
		tmp_w = tmp_w2;
	}
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp_cmd;
	t_cmd	*tmp_cmd2;

	tmp_cmd = cmd;
	while (tmp_cmd)
	{
		if (tmp_cmd->words)
			free_words(tmp_cmd->words);
		tmp_cmd2 = tmp_cmd->next;
		free(tmp_cmd->cmd);
		free(tmp_cmd->args);
		free(tmp_cmd);
		tmp_cmd = tmp_cmd2;
	}
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			free(env[i]);
			i++;
		}
		free(env);
	}
}

void	free_info(t_info *info)
{
	if (info)
	{
		if (info->cmd)
			free_cmd(info->cmd);
	}
}
