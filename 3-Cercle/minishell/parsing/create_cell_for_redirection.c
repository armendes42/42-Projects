/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cell_for_redirection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:45:35 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 19:00:00 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cut_redirection_first_char(t_token **words, t_token **tmp, char *sign,
	t_type type)
{
	t_token	*new;

	new = create_word(sign, type);
	new->next = *tmp;
	if ((*tmp)->prev == NULL)
		*words = new;
	else
	{
		new->prev = (*tmp)->prev;
		(*tmp)->prev->next = new;
	}
	(*tmp)->prev = new;
}

void	cut_redirection_other_char(t_token **words, t_token **tmp, char *sign,
	t_type type)
{
	t_token	*new;
	t_token	*prev;
	char	*new_word;

	new = create_word(sign, type);
	prev = create_word(before_redirection((*tmp)->word), (*tmp)->type);
	prev->next = new;
	new->prev = prev;
	new->next = *tmp;
	if ((*tmp)->prev == NULL)
		*words = prev;
	else
	{
		(*tmp)->prev->next = prev;
		prev->prev = (*tmp)->prev;
	}
	(*tmp)->prev = new;
	new_word = after_redirection((*tmp)->word);
	free((*tmp)->word);
	(*tmp)->word = new_word;
}
