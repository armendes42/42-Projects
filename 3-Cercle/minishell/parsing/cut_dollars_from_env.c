/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_dollars_from_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:18:23 by armendes          #+#    #+#             */
/*   Updated: 2022/04/19 21:00:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cut_before_group_of_dollar(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '$')
			break ;
		i++;
	}
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		error_and_exit(get_info(), 1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '$')
			break ;
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*cut_group_of_dollar(char *str)
{
	int		i;
	int		j;
	char	*result;

	j = count_group_of_dollar(str);
	result = malloc(sizeof(char) * j);
	if (!result)
		error_and_exit(get_info(), 1);
	i = 0;
	while (i < (j - 1))
	{
		result[i] = '$';
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*cut_after_group_of_dollar(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '$' && str[i + 2] != '$')
			break ;
		i++;
	}
	result = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!result)
		error_and_exit(get_info(), 1);
	i++;
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

static void	cut_dollars_of_var_env(t_token **words, t_token **tmp)
{
	t_token	*new;
	t_token	*prev;
	char	*new_word;

	if ((*tmp)->type == ARG)
		new = create_word(cut_group_of_dollar((*tmp)->word), JUST_DOLLAR);
	else if ((*tmp)->type == ARG_IN_DOUBLE)
		new = create_word(cut_group_of_dollar((*tmp)->word),
				JUST_DOLLAR_DOUBLE);
	prev = create_word(cut_before_group_of_dollar((*tmp)->word), (*tmp)->type);
	new_word = cut_after_group_of_dollar((*tmp)->word);
	free((*tmp)->word);
	(*tmp)->word = new_word;
	if ((*tmp)->prev == NULL)
		(*words) = prev;
	else
	{
		prev->prev = (*tmp)->prev;
		(*tmp)->prev->next = prev;
	}
	prev->next = new;
	new->prev = prev;
	(*tmp)->prev = new;
	new->next = *tmp;
}

void	cut_dollars_from_env(t_token **words)
{
	t_token	*tmp;
	int		nb_of_groups;

	tmp = *words;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == ARG_IN_DOUBLE)
		{
			if (detect_here_doc(tmp) == 0)
			{
				nb_of_groups = search_dollar_groups(tmp->word);
				while (nb_of_groups-- > 0)
					cut_dollars_of_var_env(words, &tmp);
			}
		}
		tmp = tmp->next;
	}
}
