/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_into_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:41:21 by armendes          #+#    #+#             */
/*   Updated: 2022/02/14 17:47:19 by armendes         ###   ########.fr       */
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
}*/

static int	search_redirection(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			if (str[i + 1] == '<')
				return (3);
			return (1);
		}
		if (str[i] == '>')
		{
			if (str[i + 1] == '>')
				return (4);
			return (2);
		}
		i++;
	}
	return (0);
}

static int	cut_for_input(t_token **words, t_token *tmp)
{
	int	i;

	i = 0;
}

static int	cut_for_output(t_token **words, t_token *tmp)
{
	
}

static int	cut_for_delimiter(t_token **words, t_token *tmp)
{
	
}

static int	cut_for_append(t_token **words, t_token *tmp)
{
	
}

static int	cut_redirection(t_token **words)
{
	t_token	*tmp;
	int		control;

	tmp = *words;
	control = 0;
	while (tmp)
	{
		if (tmp->type == ARG)
		{
			if (search_redirection(tmp->word) == 1)
				control = cut_for_input();
			else if (search_redirection(tmp->word) == 2)
				control = cut_for_output();
			else if (search_redirection(tmp->word) == 3)
				control = cut_for_delimiter();
			else if (search_redirection(tmp->word) == 4)
				control = cut_for_append();
			if (control != 0)
				return (-1);
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
		if (cut_redirection(&tmp->words))
			return (-1);
		//skip_empty_words(&tmp->words);
		//detect_concat(&tmp->words);
		//skip_space_words(&tmp->words);
		//if (concat_words_prev(&tmp->words))
		//	return (-1);
		//trim_space_in_word(&tmp->words);
		//attach_words(&tmp->words);
		tmp = tmp->next;
	}
	return (0);
}
