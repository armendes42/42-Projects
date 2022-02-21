/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_into_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:21 by armendes          #+#    #+#             */
/*   Updated: 2022/02/21 18:44:51 by armendes         ###   ########.fr       */
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

static void	trim_space_in_word_start(t_token **words)
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

static int	trim_space_in_word_end(t_token **words)
{
	t_token	*tmp;
	char	*str;
	int		i;
	int		j;

	tmp = *words;
	while (tmp)
	{
		if (search_space_end(tmp->word) && tmp->type == ARG)
		{
			i = ft_strlen(tmp->word) - 1;
			while (tmp->word[i] == ' ')
				i--;
			str = malloc(sizeof(char) * (i + 2));
			if (!str)
				return (-1);
			j = -1;
			while (tmp->word[++j] && j <= i)
				str[j] = tmp->word[j];
			str[j] = '\0';
			free(tmp->word);
			tmp->word = str;
		}
		tmp = tmp->next;
	}
	return (0);
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
		if (search_error_redirection(tmp->cmd))
			return (-1);
		if (cut_redirection(&tmp->words))
			return (-1);
		if (get_var_env(&tmp->words))
			return (-1);
		if (skip_empty_words(&tmp->words))
			return (-1);
		detect_concat(&tmp->words);
		trim_space_in_word_start(&tmp->words);
		if (concat_words_prev(&tmp->words))
			return (-1);
		skip_space_words(&tmp->words);
		trim_space_in_word_end(&tmp->words);
		get_infile_outfile(&tmp->words);
		tmp = tmp->next;
	}
	return (0);
}
