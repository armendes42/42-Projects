/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_into_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:21 by armendes          #+#    #+#             */
/*   Updated: 2022/02/14 16:41:47 by armendes         ###   ########.fr       */
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

/*static void	trim_space_in_word(t_token **words)
{
	t_token	*tmp;

	tmp = *words;
	while (tmp)
	{
		if (tmp->word[0] == ' ' && tmp->type == ARG && !is_empty(tmp->word))
			tmp->word = format_str(tmp->word, 0, ft_strlen(tmp->word));
		tmp = tmp->next;
	}
}

static int	concat_two_words(t_token **words, int index)
{
	t_token	*tmp;

	tmp = *words;
	while (index-- && tmp)
		tmp = tmp->next;
	
}

static void	attach_words(t_token **words)
{
	t_token	*tmp;
	int		i;

	tmp = *words;
	i = 0;
	while (tmp->next)
	{
		if (tmp->type != ARG || tmp->next->type != ARG)
		{
			if (search_space_end(tmp->word) == 0 || is_empty(tmp->next->word))
			{
				concat_two_words(words, i);
			}
		}
		tmp = tmp->next;
		i++;
	}
}*/

static int	search_space_end(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == ' ')
		return (1);
	return (0);
}

static int	search_space_start(char *str)
{
	if (str[0] == ' ')
		return (1);
	return (0);
}

static void	detect_concat(t_token **words)
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

int	cut_into_words(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		tmp->words = cut_cmd(tmp->cmd);
		if (tmp->words == NULL)
			return (-1);
		skip_empty_words(&tmp->words);
		//trim_space_in_word(&tmp->words);
		//attach_words(&tmp->words);
		detect_concat(&tmp->words);
		tmp = tmp->next;
	}
	return (0);
}
