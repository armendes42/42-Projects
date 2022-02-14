/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:20:36 by armendes          #+#    #+#             */
/*   Updated: 2022/02/14 17:21:34 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	concat_words_prev(t_token **words)
{
	t_token	*tmp;
	t_token	*tmp_next;

	tmp = last_cell(words);
	while (tmp->prev)
	{
		if (tmp->need_to_concat == 1)
		{
			if (tmp->next->next == NULL)
			{
				tmp_next = tmp->next;
				tmp->word = ft_strjoin(tmp->word, tmp->next->word);
				if (tmp->word == NULL)
					return (-1);
				tmp->next = NULL;
				tmp->need_to_concat = 0;
				free_word(tmp_next);
			}
			else
			{
				tmp_next = tmp->next;
				tmp->word = ft_strjoin(tmp->word, tmp->next->word);
				if (tmp->word == NULL)
					return (-1);
				tmp->next->next->prev = tmp;
				tmp->next = tmp->next->next;
				tmp->need_to_concat = 0;
				free_word(tmp_next);		
			}
		}
		tmp = tmp->prev;
	}
	return (0);
}

void	detect_concat(t_token **words)
{
	t_token	*tmp;

	tmp = *words;
	while (tmp->next)
	{
		if (tmp->type != ARG || tmp->next->type != ARG)
		{
			if (tmp->type == ARG)
			{
				if (search_space_end(tmp->word) == 0)
					tmp->need_to_concat = 1;
			}
			else if (tmp->next->type == ARG)
			{
				if (search_space_start(tmp->next->word) == 0)
					tmp->need_to_concat = 1;
			}
			else
			{
				if (!is_empty(tmp->next->word))
					tmp->need_to_concat = 1;
			}
		}
		tmp = tmp->next;
	}
}
