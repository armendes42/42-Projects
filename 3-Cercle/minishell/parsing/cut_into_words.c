/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_into_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:21 by armendes          #+#    #+#             */
/*   Updated: 2022/03/09 18:37:11 by armendes         ###   ########.fr       */
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

static char	*cut_before_space(char *str)
{
	char	*result;
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	result = ft_strdup_size(str, i);
	if (!result)
		return (NULL);
	return (result);
}

static char	*cut_after_space(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	result = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (str[i])
	{
		result[j] = str[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

static int	cut_arg_nothing(t_token **words)
{
	t_token	*tmp;
	t_token	*tmp_next;
	char	*tmp_word;

	tmp = *words;
	while (tmp)
	{
		tmp_next = tmp->next;
		if (tmp->type == ARG && search_space(tmp->word))
		{
			tmp_word = tmp->word;
			tmp->word = cut_before_space(tmp_word);
			tmp->next = create_word(cut_after_space(tmp_word), ARG);
			if (tmp->word == NULL || tmp->next->word == NULL)
				return (-1);
			if (tmp_next == NULL)
				tmp->next->next = NULL;
			else
			{
				tmp->next->next = tmp_next;
				tmp_next->prev = tmp->next;
			}
			tmp->next->prev = tmp;
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
		if (cut_arg_nothing(&tmp->words))
			return (-1);
		if (skip_empty_words(&tmp->words))
			return (-2);
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
