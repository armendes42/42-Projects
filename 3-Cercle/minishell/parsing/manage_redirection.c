/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:40:36 by armendes          #+#    #+#             */
/*   Updated: 2022/02/15 19:48:19 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cut_for_input(t_token **words, t_token **tmp)
{
	if ((*tmp)->word[0] == '<')
	{
		cut_redirection_first_cell(words, tmp, "<", RED_IN);
		(*tmp)->word = cut_one_char((*tmp)->word);
	}
	else
		cut_redirection_other_cell(words, tmp, "<", RED_IN);
	return (0);
}

static int	cut_for_output(t_token **words, t_token **tmp)
{
	if ((*tmp)->word[0] == '>')
	{
		cut_redirection_first_cell(words, tmp, ">", RED_OUT);
		(*tmp)->word = cut_one_char((*tmp)->word);
	}
	else
		cut_redirection_other_cell(words, tmp, ">", RED_OUT);
	return (0);
}

static int	cut_for_delimiter(t_token **words, t_token **tmp)
{
	if ((*tmp)->word[0] == '<')
	{
		cut_redirection_first_cell(words, tmp, "<<", HERE_DOC);
		(*tmp)->word = cut_two_char((*tmp)->word);
	}
	else
		cut_redirection_other_cell(words, tmp, "<<", HERE_DOC);
	return (0);
}

static int	cut_for_append(t_token **words, t_token **tmp)
{
	if ((*tmp)->word[0] == '>')
	{
		cut_redirection_first_cell(words, tmp, ">>", RED_OUT_APPEND);
		(*tmp)->word = cut_two_char((*tmp)->word);
	}
	else
		cut_redirection_other_cell(words, tmp, ">>", RED_OUT_APPEND);
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