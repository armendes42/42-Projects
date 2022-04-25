/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:01:02 by armendes          #+#    #+#             */
/*   Updated: 2022/04/21 17:03:23 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_space_end(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == ' ')
		return (1);
	return (0);
}

int	search_space_start(char *str)
{
	if (str[0] == ' ')
		return (1);
	return (0);
}

int	detect_here_doc(t_token *tmp)
{
	if (tmp != NULL)
	{
		if (tmp->prev != NULL)
		{
			if (tmp->prev->prev != NULL)
			{
				if (tmp->prev->prev->type == HERE_DOC)
					return (1);
			}
		}
	}
	return (0);
}

int	check_redir_before_pipe(char *str)
{
	int		i;
	t_quote	quote;
	char	*tmp;

	i = 0;
	quote = NOTHING;
	while (str[i])
	{
		quote = update_quote_status(str[i], quote);
		if ((str[i] == '<' || str[i] == '>') && quote == NOTHING)
		{
			if (str[i + 1])
			{
				tmp = get_next_char(&str[i + 1]);
				if (!tmp)
					return (error(NULL, NEWLINE_ERR, 2));
				if (tmp[0] == '|')
					return (error(NULL, PIPE_ERR, 2));
			}
		}
		i++;
	}
	return (0);
}
