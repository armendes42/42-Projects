/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:11:15 by armendes          #+#    #+#             */
/*   Updated: 2022/02/10 18:07:34 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_words(t_token **words)
{
	t_token	*tmp_w;
	t_token	*tmp_w2;

	if (*words)
	{
		tmp_w = *words;
		while (tmp_w)
		{
			write(0, "salut\n", 6);
			tmp_w2 = tmp_w->next;
			free(tmp_w->word);
			free(tmp_w);
			tmp_w = tmp_w2;
		}
	}
}

void	free_all(t_cmd **cmd)
{
	t_cmd	*tmp_cmd;
	t_cmd	*tmp_cmd2;

	if (*cmd)
	{
		tmp_cmd = *cmd;
		while (tmp_cmd)
		{
			free_words(&tmp_cmd->words);
			tmp_cmd2 = tmp_cmd->next;
			free(tmp_cmd->cmd);
			free(tmp_cmd);
			tmp_cmd = tmp_cmd2;
		}
	}
}

void	error(t_cmd **cmd, char *err_msg)
{
	free_all(cmd);
	write(0, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}
