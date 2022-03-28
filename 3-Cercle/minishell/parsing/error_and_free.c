/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:11:15 by armendes          #+#    #+#             */
/*   Updated: 2022/03/28 17:23:54 by armendes         ###   ########.fr       */
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
				if (tmp_w->word)
				{
					ft_putstr_fd(tmp_w->word, 1);
					ft_putstr_fd("\n", 1);
					free(tmp_w->word);
				}
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

// static void	free_env(char **env)
// {
// 	int	i;

// 	i = 0;
// 	while (env[i])
// 	{
// 		free(env);
// 		i++;
// 	}
// }

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
