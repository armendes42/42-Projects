/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_word_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:44:26 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 19:00:06 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_word(char *str, t_type type)
{
	t_token	*elem;

	elem = malloc(sizeof(t_token));
	if (!elem)
		error_and_exit(get_info(), 1);
	elem->word = str;
	elem->type = type;
	elem->need_to_concat = 0;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

static void	add_word_to_struct(t_token **words, char *str, t_type type)
{
	t_token	*tmp;
	t_token	*elem;

	elem = create_word(str, type);
	if (*words == NULL)
		*words = elem;
	else
	{
		tmp = *words;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->prev = tmp;
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
	while (str[i] && str[i] == ' ')
		i++;
	new_str = ft_strdup_size(str, i);
	if (!new_str)
		error_and_exit(get_info(), 1);
	add_word_to_struct(words, new_str, ARG);
	return (i);
}

int	add_word(t_token **words, char *str, t_quote quote)
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
			error_and_exit(get_info(), 1);
		if (quote == SIMPLE)
			add_word_to_struct(words, new_str, ARG_IN_SIMPLE);
		else
			add_word_to_struct(words, new_str, ARG_IN_DOUBLE);
	}
	return (i);
}
