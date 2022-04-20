/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:38:17 by armendes          #+#    #+#             */
/*   Updated: 2022/04/19 20:58:53 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_only_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (str[i + 1] == '\0'
				|| (ft_isalnum(str[i + 1]) == 0 && str[i + 1] != '_')))
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

static int	search_just_dollar(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '\0')
			count++;
		else if (str[i + 1] != '\0')
		{
			if (str[i] == '$' && str[i + 1] == '$')
			{
				count++;
			}
			else if (str[i] == '$' && ft_isalnum(str[i + 1]) == 0
				&& str[i + 1] != '_')
			{
				count++;
			}
		}
		i++;
	}
	return (count);
}

void	get_just_dollar(t_token **words)
{
	t_token	*tmp;
	int		nb_of_dollars;

	tmp = *words;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == ARG_IN_DOUBLE)
		{
			if (detect_here_doc(tmp) == 0)
			{
				nb_of_dollars = search_just_dollar(tmp->word);
				while (nb_of_dollars-- > 0)
				{
					if (search_only_dollar(tmp->word) == 0)
						cut_cell_for_dollar_first_char(words, &tmp);
					else if (search_only_dollar(tmp->word) > 0)
						cut_cell_for_dollar_other_char(words, &tmp);
				}
			}
		}
		tmp = tmp->next;
	}
}
