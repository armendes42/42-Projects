/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:40:36 by armendes          #+#    #+#             */
/*   Updated: 2022/03/24 18:59:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cut_for_input(t_token **words, t_token **tmp)
{
	char	*new_word;

	if ((*tmp)->word[0] == '<')
	{
		if (cut_redirection_first_char(words, tmp, "<", RED_IN))
			return (-1);
		new_word = cut_one_char((*tmp)->word);
		free((*tmp)->word);
		(*tmp)->word = new_word;
	}
	else
		if (cut_redirection_other_char(words, tmp, "<", RED_IN))
			return (-1);
	return (0);
}

static int	cut_for_output(t_token **words, t_token **tmp)
{
	char	*new_word;

	if ((*tmp)->word[0] == '>')
	{
		if (cut_redirection_first_char(words, tmp, ">", RED_OUT))
			return (-1);
		new_word = cut_one_char((*tmp)->word);
		free((*tmp)->word);
		(*tmp)->word = new_word;
	}
	else
		if (cut_redirection_other_char(words, tmp, ">", RED_OUT))
			return (-1);
	return (0);
}

static int	cut_for_delimiter(t_token **words, t_token **tmp)
{
	char	*new_word;

	if ((*tmp)->word[0] == '<')
	{
		if (cut_redirection_first_char(words, tmp, "<<", HERE_DOC))
			return (-1);
		new_word = cut_two_char((*tmp)->word);
		free((*tmp)->word);
		(*tmp)->word = new_word;
	}
	else
		if (cut_redirection_other_char(words, tmp, "<<", HERE_DOC))
			return (-1);
	return (0);
}

static int	cut_for_append(t_token **words, t_token **tmp)
{
	char	*new_word;

	if ((*tmp)->word[0] == '>')
	{
		if (cut_redirection_first_char(words, tmp, ">>", RED_OUT_APPEND))
			return (-1);
		new_word = cut_two_char((*tmp)->word);
		free((*tmp)->word);
		(*tmp)->word = new_word;
	}
	else
		if (cut_redirection_other_char(words, tmp, ">>", RED_OUT_APPEND))
			return (-1);
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
			if (search_redirection(tmp->word) == 0)
				tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (0);
}
