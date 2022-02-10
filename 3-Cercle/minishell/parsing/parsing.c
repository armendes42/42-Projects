/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:36 by armendes          #+#    #+#             */
/*   Updated: 2022/02/10 16:10:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parsing(char *line)
{
	t_cmd	*cmd;
	
	if (check_quote(line))
		error(QUOTE_ERR);
	cmd = find_pipe(line);
	if (!cmd)
		error(CMD_ERR);
		
	t_cmd	*tmp = cmd;
	while (tmp)
	{
		write(0, tmp->cmd, ft_strlen(tmp->cmd));
		write(0, "\n", 1);
		tmp = tmp->next;
	}

	if (cut_into_words(&cmd))
		error(WORD_ERR);

	t_cmd	*tmp2 = cmd;
	while (tmp2)
	{
		while (tmp2->words)
		{
			write(0, tmp2->words->word, ft_strlen(tmp2->words->word));
			write(0, "\n", 1);
			tmp2->words = tmp2->words->next;
		}
		tmp2 = tmp2->next;
	}
}

int	main(void)
{
	char *line;

	line = "";
	while (line)
	{
		line = readline("~>");
		parsing(line);
	}
	free(line);
	return (0);
}