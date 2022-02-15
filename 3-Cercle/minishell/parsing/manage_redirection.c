/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:40:36 by armendes          #+#    #+#             */
/*   Updated: 2022/02/15 17:03:16 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cut_for_input(t_token **words, t_token **tmp)
{
	t_token	*new;

	new = create_word("<", RED_IN);
	if (!new)
		return (-1);
	if ((*tmp)->prev == NULL)
	{
		new->next = *tmp;
		(*tmp)->prev = new;
		(*words) = new;
	}
	else
	{
		new->prev = (*tmp)->prev;
		(*tmp)->prev->next = new;
		new->next = *tmp;
		(*tmp)->prev = new;
	}
	(*tmp)->word = cut_one_char((*tmp)->word);
	return (0);
}

static int	cut_for_output(t_token **words, t_token **tmp)
{
	t_token	*new;

	new = create_word(">", RED_IN);
	if (!new)
		return (-1);
	if ((*tmp)->prev == NULL)
	{
		new->next = *tmp;
		(*tmp)->prev = new;
		(*words) = new;
	}
	else
	{
		new->prev = (*tmp)->prev;
		(*tmp)->prev->next = new;
		new->next = *tmp;
		(*tmp)->prev = new;
	}
	(*tmp)->word = cut_one_char((*tmp)->word);
	return (0);
}

static int	cut_for_delimiter(t_token **words, t_token **tmp)
{
	t_token	*new;

	new = create_word("<<", RED_IN);
	if (!new)
		return (-1);
	if ((*tmp)->prev == NULL)
	{
		new->next = *tmp;
		(*tmp)->prev = new;
		(*words) = new;
	}
	else
	{
		new->prev = (*tmp)->prev;
		(*tmp)->prev->next = new;
		new->next = *tmp;
		(*tmp)->prev = new;
	}
	(*tmp)->word = cut_two_char((*tmp)->word);
	return (0);
}

static int	cut_for_append(t_token **words, t_token **tmp)
{
	t_token	*new;

	new = create_word(">>", RED_IN);
	if (!new)
		return (-1);
	if ((*tmp)->prev == NULL)
	{
		new->next = *tmp;
		(*tmp)->prev = new;
		(*words) = new;
	}
	else
	{
		new->prev = (*tmp)->prev;
		(*tmp)->prev->next = new;
		new->next = *tmp;
		(*tmp)->prev = new;
	}
	(*tmp)->word = cut_two_char((*tmp)->word);
	return (0);
}

int	cut_redirection(t_token **words)
{
	t_token	*tmp;
	int		control;

	tmp = *words;
	control = 0;
	while (tmp)
	{
		if (tmp->type == ARG)
		{
			if (search_redirection(tmp->word) == 1)
				control = cut_for_input(words, &tmp);
			else if (search_redirection(tmp->word) == 2)
				control = cut_for_output(words, &tmp);
			else if (search_redirection(tmp->word) == 3)
				control = cut_for_delimiter(words, &tmp);
			else if (search_redirection(tmp->word) == 4)
				control = cut_for_append(words, &tmp);
			if (control != 0)
				return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}
