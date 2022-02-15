/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_into_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:21 by armendes          #+#    #+#             */
/*   Updated: 2022/02/15 16:40:09 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*cut_cmd(char *str)
{
	int		i;
	int		diff;
	t_token	*words;
	e_quote	quote;

	i = 0;
	diff = 0;
	words = NULL;
	quote = NOTHING;
	while (str[i])
	{
		quote = update_quote_status(str[i], quote);
		if (quote == SIMPLE || quote == DOUBLE || (quote == NOTHING
				&& (str[i] == '\'' || str[i] == '"')))
			diff = add_word(&words, &str[i + 1], quote) + 1;
		else
			diff = add_word(&words, &str[i], quote);
		if (diff == -1)
			return (NULL);
		else if (diff == 0)
			i++;
		else
			i += diff;
	}
	return (words);
}

// static void	trim_space_in_word(t_token **words)
// {
// 	t_token	*tmp;

// 	tmp = *words;
// 	while (tmp)
// 	{
// 		if (tmp->word[0] == ' ' && tmp->type == ARG && !is_empty(tmp->word))
// 			tmp->word = format_str(tmp->word, 0, ft_strlen(tmp->word));
// 		tmp = tmp->next;
// 	}
// }

int	cut_into_words(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		tmp->words = cut_cmd(tmp->cmd);
		if (tmp->words == NULL)
			return (-1);
		if (search_error_redirection(tmp->cmd))
			return (-1);
		if (cut_redirection(&tmp->words))
			return (-1);
		detect_concat(&tmp->words);
		//skip_empty_words(&tmp->words);
		//skip_space_words(&tmp->words);
		//if (concat_words_prev(&tmp->words))
		//	return (-1);
		//trim_space_in_word(&tmp->words);
		//attach_words(&tmp->words);
		tmp = tmp->next;
	}
	return (0);
}
