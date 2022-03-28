/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:11:15 by armendes          #+#    #+#             */
/*   Updated: 2022/03/28 18:56:23 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	free_words(t_token *words)
// {
// 	t_token	*tmp_w;
// 	t_token	*tmp_w2;

// 	tmp_w = words;
// 	while (tmp_w)
// 	{
// 		tmp_w2 = tmp_w->next;
// 		free(tmp_w->word);
// 		free(tmp_w);
// 		tmp_w = tmp_w2;
// 	}
// }

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp_cmd;
	t_cmd	*tmp_cmd2;
	t_token	*tmp_w;
	t_token	*tmp_w2;

	tmp_cmd = cmd;
	while (tmp_cmd)
	{
		if (tmp_cmd->words)
		{
			tmp_w = tmp_cmd->words;
			while (tmp_w)
			{
				tmp_w2 = tmp_w->next;
				if (tmp_w->word && tmp_w->type != RED_IN
					&& tmp_w->type != RED_OUT && tmp_w->type != RED_OUT_APPEND
					&& tmp_w->type != HERE_DOC)
					free(tmp_w->word);
				free(tmp_w);
				tmp_w = tmp_w2;
			}
		}
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
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

void	free_info(t_info *info)
{
	if (info)
	{
		// if (info->env)
		// 	free_env(info->env);
		if (info->cmd)
			free_cmd(info->cmd);
	}
}

int	error(t_info *info, char *err_msg)
{
	free_info(info);
	write(1, err_msg, ft_strlen(err_msg));
	// exit(EXIT_FAILURE);
	return (1);
}
