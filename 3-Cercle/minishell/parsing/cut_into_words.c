/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_into_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:21 by armendes          #+#    #+#             */
/*   Updated: 2022/04/20 17:34:36 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*cut_cmd(char *str)
{
	int		i;
	int		diff;
	t_token	*words;
	t_quote	quote;

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
		if (diff == 0)
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
	get_just_dollar(&tmp->words);
	cut_dollars_from_env(&tmp->words);
	get_var_env(&tmp->words, info->env);
	cut_arg_nothing(&tmp->words);
	if (skip_empty_words(&tmp->words))
		return (-1);
	detect_concat(&tmp->words);
	get_var_env_files(&tmp->words, info->env);
	change_just_dollar_to_arg(&tmp->words);
	trim_space_in_word_start(&tmp->words);
	concat_words_prev(&tmp->words);
	skip_space_words(&tmp->words);
	if (skip_empty_words(&tmp->words))
		return (-1);
	trim_space_in_word_end(&tmp->words);
	get_infile_outfile(&tmp->words);
	return (0);
}

static int	check_empty_first_word(char *str)
{
	if (ft_strlen(str) == 0)
	{
		ft_putstr_fd(": command not found\n", 2);
		return (-1);
	}
	return (0);
}

int	cut_into_words(t_info *info)
{
	t_cmd	*tmp;
	int		control;

	tmp = info->cmd;
	while (tmp)
	{
		tmp->words = cut_cmd(tmp->cmd);
		if (check_empty_first_word(tmp->words->word))
			return (-1);
		if (search_error_redirection(tmp->cmd))
			return (-1);
		control = search_error_var_env(tmp->cmd);
		if (control == -1)
			return (braces_empty(tmp->cmd));
		if (control == -2)
			return (braces_non_conform(tmp->cmd));
		cut_redirection(&tmp->words);
		get_exit_status(&tmp->words, g_exit_status);
		control = cut_into_words_two(info, &tmp);
		if (control == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
