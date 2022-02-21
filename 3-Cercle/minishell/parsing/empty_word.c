/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:15:03 by armendes          #+#    #+#             */
/*   Updated: 2022/02/21 18:47:39 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	word_is_empty(t_token **words, t_token **tmp)
{
	t_token	*tmp_prev;

	if ((*tmp)->prev == NULL && (*tmp)->next == NULL)
	{
		free((*tmp)->word);
		free(*tmp);
		*words = NULL;
		return (-1);
	}
	else if ((*tmp)->prev == NULL)
	{
		*words = (*tmp)->next;
		(*words)->prev = NULL;
		*tmp = *words;
	}
	else if ((*tmp)->next == NULL)
	{
		(*tmp)->prev->next = NULL;
		*tmp = NULL;
	}
	else
	{
		tmp_prev = (*tmp)->prev;
		(*tmp)->next->prev = tmp_prev;
		tmp_prev->next = (*tmp)->next;
		*tmp = tmp_prev->next;
	}
	return (0);
}

int	skip_empty_words(t_token **words)
{
	t_token	*tmp;

	if (*words)
	{
		tmp = *words;
		while (tmp)
		{
			if (ft_strlen(tmp->word) == 0 && tmp->type == ARG)
			{
				if (word_is_empty(words, &tmp))
					return (-1);
			}
			else
				tmp = tmp->next;
		}
	}
	return (0);
}

void	skip_space_words(t_token **words)
{
	t_token	*tmp;

	tmp = *words;
	while (tmp)
	{
		if (is_empty(tmp->word) && tmp->type == ARG)
			word_is_empty(words, &tmp);
		else
			tmp = tmp->next;
	}
}
