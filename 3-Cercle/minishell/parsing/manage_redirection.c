/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:40:36 by armendes          #+#    #+#             */
/*   Updated: 2022/04/12 19:31:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cut_for_input(t_token **words, t_token **tmp)
{
	char	*new_word;

	if ((*tmp)->word[0] == '<')
	{
		cut_redirection_first_char(words, tmp, "<", RED_IN);
		new_word = cut_one_char((*tmp)->word);
		free((*tmp)->word);
		(*tmp)->word = new_word;
	}
	else
		cut_redirection_other_char(words, tmp, "<", RED_IN);
}

void	cut_for_output(t_token **words, t_token **tmp)
{
	char	*new_word;

	if ((*tmp)->word[0] == '>')
	{
		cut_redirection_first_char(words, tmp, ">", RED_OUT);
		new_word = cut_one_char((*tmp)->word);
		free((*tmp)->word);
		(*tmp)->word = new_word;
	}
	else
		cut_redirection_other_char(words, tmp, ">", RED_OUT);
}

void	cut_for_delimiter(t_token **words, t_token **tmp)
{
	char	*new_word;

	if ((*tmp)->word[0] == '<')
	{
		cut_redirection_first_char(words, tmp, "<<", HERE_DOC);
		new_word = cut_two_char((*tmp)->word);
		free((*tmp)->word);
		(*tmp)->word = new_word;
	}
	else
		cut_redirection_other_char(words, tmp, "<<", HERE_DOC);
}

void	cut_for_append(t_token **words, t_token **tmp)
{
	char	*new_word;

	if ((*tmp)->word[0] == '>')
	{
		cut_redirection_first_char(words, tmp, ">>", RED_OUT_APPEND);
		new_word = cut_two_char((*tmp)->word);
		free((*tmp)->word);
		(*tmp)->word = new_word;
	}
	else
		cut_redirection_other_char(words, tmp, ">>", RED_OUT_APPEND);
}

void	cut_redirection(t_token **words)
{
	t_token	*tmp;

	tmp = *words;
	while (tmp)
	{
		if (tmp->type == ARG)
		{
			if (search_redirection(tmp->word) == 1
				|| search_redirection(tmp->word) == 2
				|| search_redirection(tmp->word) == 3
				|| search_redirection(tmp->word) == 4)
				cut_for_redirection(words, &tmp, search_redirection(tmp->word));
			if (search_redirection(tmp->word) == 0)
				tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
}
