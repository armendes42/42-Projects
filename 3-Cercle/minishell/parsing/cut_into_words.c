/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_into_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:21 by armendes          #+#    #+#             */
/*   Updated: 2022/02/09 19:54:33 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cut_cmd(t_cmd *cmd)
{
	t_token	*words;
	int		i;
	e_quote	quote;
	int		start;

	words = NULL;
	i = 0;
	quote = NOTHING;
	start = 0;
	while (cmd->cmd[i])
	{
		if (cmd->cmd[i] == '\'')
			quote = update_quote_status(cmd->cmd[i], quote);
		if (cmd->cmd[i] == '"')
			quote = update_quote_status(cmd->cmd[i], quote);
		i++;
	}
}

void	cut_into_words(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while(tmp)
	{
		cut_cmd(&tmp);
		tmp = tmp->next;
	}
}