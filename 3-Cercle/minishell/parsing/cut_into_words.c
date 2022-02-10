/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_into_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:21 by armendes          #+#    #+#             */
/*   Updated: 2022/02/10 16:12:29 by armendes         ###   ########.fr       */
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

static int	add_word(t_token **words, char *str, e_quote quote)
{
	int		i;
	char	*new_str;

	i = 0;
	if (quote == NOTHING)
	{
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
	}
	else if (quote == DOUBLE)
	{
		while (str[i] && str[i] != '"')
			i++;
		new_str = ft_strdup_size(str, i);
		if (!new_str)
			return (-1);
		add_word_to_struct(words, new_str, ARG);
	}
	else if (quote == SIMPLE)
	{
		while (str[i] && str[i] != '\'')
			i++;
		new_str = ft_strdup_size(str, i);
		if (!new_str)
			return (-1);
		add_word_to_struct(words, new_str, ARG_IN_SIMPLE);	
	}
	return (i);
}

static int	cut_cmd(t_cmd *cmd, char *str)
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
		if (str[i] == '\'')
			quote = update_quote_status(str[i], quote);
		if (str[i] == '"')
			quote = update_quote_status(str[i], quote);
		diff = add_word(&words, &str[i], quote);
		if (diff == -1)
			return (-1);
		else if (diff == 0)
			i++;
		else
			i += diff;
	}
	cmd->words = words;
	return (0);
}

int	cut_into_words(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while(tmp)
	{
		if (cut_cmd(tmp, tmp->cmd))
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}