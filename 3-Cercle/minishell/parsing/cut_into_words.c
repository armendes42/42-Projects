/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_into_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:21 by armendes          #+#    #+#             */
/*   Updated: 2022/02/10 18:30:22 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*create_word(char *str, e_type type)
{
	t_token	*elem;

	elem = malloc(sizeof(t_token));
	if (!elem)
		return (NULL);
	elem->word = str;
	elem->type = type;
	elem->next = NULL;
	return (elem);
}

static void	add_word_to_struct(t_token **words, char *str, e_type type)
{
	t_token	*tmp;

	if (*words == NULL)
		*words = create_word(str, type);
	else
	{
		tmp = *words;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_word(str, type);
	}
}

static int	add_word_when_no_quote(t_token **words, char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (i);
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
		i++;
	new_str = ft_strdup_size(str, i);
	if (!new_str)
		return (-1);
	add_word_to_struct(words, new_str, ARG);
	return (i);
}

static int	add_word(t_token **words, char *str, e_quote quote)
{
	int		i;
	char	*new_str;

	i = 0;
	if (quote == NOTHING)
		i = add_word_when_no_quote(words, str);
	else if (quote == SIMPLE || quote == DOUBLE)
	{
		if (quote == SIMPLE)
			while (str[i] && str[i] != '\'')
				i++;
		if (quote == DOUBLE)
			while (str[i] && str[i] != '"')
				i++;
		new_str = ft_strdup_size(str, i);
		if (!new_str)
		{
			return (-1);
		}
		if (quote == SIMPLE)
			add_word_to_struct(words, new_str, ARG_IN_SIMPLE);
		else
			add_word_to_struct(words, new_str, ARG_IN_DOUBLE);
	}
	return (i);
}

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

static void	skip_empty_words(t_token **words)
{
	t_token	*tmp;
	t_token	*tmp_prev;

	tmp = *words;
	while (tmp)
	{
		if (is_empty(tmp->word))
		{

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
		tmp = tmp->next;
	}
	return (0);
}
