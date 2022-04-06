/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:38:17 by armendes          #+#    #+#             */
/*   Updated: 2022/04/04 19:12:49 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_only_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

void	change_just_dollar_to_arg(t_token **words)
{
	t_token	*tmp;

	tmp = *words;
	while (tmp)
	{
		if (tmp->type == JUST_DOLLAR)
			tmp->type = ARG;
		if (tmp->type == JUST_DOLLAR_DOUBLE)
			tmp->type = ARG_IN_DOUBLE;
		tmp = tmp->next;
	}
}

static int	get_just_dollar_two(t_token **words, t_token **tmp)
{
	if (search_only_dollar((*tmp)->word) == 0)
	{
		if (cut_cell_for_dollar_first_char(words, tmp))
			return (-1);
	}
	else if (search_only_dollar((*tmp)->word) > 0)
		if (cut_cell_for_dollar_other_char(words, tmp))
			return (-1);
	return (0);
}

int	get_just_dollar(t_token **words)
{
	t_token	*tmp;
	int		nb_of_dollars;
	int		control;

	tmp = *words;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == ARG_IN_DOUBLE)
		{
			if (!(tmp->prev != NULL && tmp->prev->type == HERE_DOC))
			{
				nb_of_dollars = search_dollar(tmp->word);
				while (nb_of_dollars-- > 0)
				{
					control = get_just_dollar_two(words, &tmp);
					if (control == -1)
						return (-1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
