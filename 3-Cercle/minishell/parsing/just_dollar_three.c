/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_dollar_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:08:38 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 18:03:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cut_cell_for_dollar_first_char(t_token **words, t_token **cell)
{
	t_token	*new;
	char	*new_word;

	new = NULL;
	if ((*cell)->type == ARG)
		new = create_word(cut_only_space((*cell)->word), JUST_DOLLAR);
	else if ((*cell)->type == ARG_IN_DOUBLE)
		new = create_word(cut_only_space((*cell)->word), JUST_DOLLAR_DOUBLE);
	new_word = cut_after_only_space((*cell)->word);
	free((*cell)->word);
	(*cell)->word = new_word;
	new->next = (*cell);
	if ((*cell)->prev == NULL)
		*words = new;
	else
	{
		new->prev = (*cell)->prev;
		(*cell)->prev->next = new;
	}
	(*cell)->prev = new;
}

static void	change_links_for_dollar_other_char(t_token **words, t_token **cell,
	t_token **prev, t_token **new)
{
	(*prev)->next = *new;
	(*new)->prev = *prev;
	(*new)->next = *cell;
	if ((*cell)->prev == NULL)
		*words = *prev;
	else
	{
		(*prev)->prev = (*cell)->prev;
		(*cell)->prev->next = *prev;
	}
	(*cell)->prev = *new;
}

void	cut_cell_for_dollar_other_char(t_token **words, t_token **cell)
{
	t_token	*new;
	t_token	*prev;
	char	*new_word;

	new = NULL;
	if ((*cell)->type == ARG)
		new = create_word(cut_only_space((*cell)->word), JUST_DOLLAR);
	else if ((*cell)->type == ARG_IN_DOUBLE)
		new = create_word(cut_only_space((*cell)->word), JUST_DOLLAR_DOUBLE);
	prev = create_word(cut_before_only_space((*cell)->word), (*cell)->type);
	new_word = cut_after_only_space((*cell)->word);
	free((*cell)->word);
	(*cell)->word = new_word;
	change_links_for_dollar_other_char(words, cell, &prev, &new);
}

char	*cut_before_only_space_two(char *str, int i)
{
	char	*result;

	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		error_and_exit(get_info(), 1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) != 0 || str[i + 1] == '_'))
		{
			result[i] = str[i];
			i++;
			continue ;
		}
		if (str[i] == '$' && (str[i + 1] == ' ' || str[i + 1] == '\0'
				|| str[i + 1] == '$'
				|| (ft_isalnum(str[i + 1]) == 0 && str[i] != '_')))
			break ;
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
