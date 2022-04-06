/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_into_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:21 by armendes          #+#    #+#             */
/*   Updated: 2022/04/04 19:36:26 by armendes         ###   ########.fr       */
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

static int	cut_into_words_two(t_info *info, t_cmd **cell)
{
	t_cmd	*tmp;

	tmp = *cell;
	if (get_just_dollar(&tmp->words))
		return (-1);
	if (get_var_env(&tmp->words, info->env))
		return (-1);
	if (cut_arg_nothing(&tmp->words))
		return (-1);
	if (skip_empty_words(&tmp->words))
		return (-1);
	detect_concat(&tmp->words);
	if (get_var_env_files(&tmp->words, info->env))
		return (-1);
	change_just_dollar_to_arg(&tmp->words);
	trim_space_in_word_start(&tmp->words);
	if (concat_words_prev(&tmp->words))
		return (-1);
	skip_space_words(&tmp->words);
	if (skip_empty_words(&tmp->words))
		return (-1);
	trim_space_in_word_end(&tmp->words, info);
	get_infile_outfile(&tmp->words);
	return (0);
}

int	cut_into_words(t_info *info)
{
	t_cmd	*tmp;
	int		control;

	tmp = info->cmd;
	control = 0;
	while (tmp)
	{
		tmp->words = cut_cmd(tmp->cmd);
		if (tmp->words == NULL)
			return (-1);
		if (search_error_redirection(tmp->cmd))
			return (-1);
		if (search_error_var_env(tmp->cmd))
			return (-1);
		if (cut_redirection(&tmp->words))
			return (-1);
		// skip_space_words(&tmp->words);
		if (get_exit_status(&tmp->words, info->exit_status))
			return (-1);
		control = cut_into_words_two(info, &tmp);
		if (control == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
