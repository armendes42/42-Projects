/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:38:17 by armendes          #+#    #+#             */
/*   Updated: 2022/03/15 18:40:54 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_only_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

static char	*cut_before_only_space(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (str[i + 1] == ' ' || str[i + 1] == '\0'
			|| str[i + 1] == '$'))
			break ;
		i++;
	}
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (str[i + 1] == ' ' || str[i + 1] == '\0'
			|| str[i + 1] == '$'))
			break ;
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*cut_only_space(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '\0' || str[i + 1] == '$')
				break ;
			if (str[i + 1] == ' ')
			{
				i++;
				while (str[i] && str[i] == ' ')
				{
					j++;
					i++;
				}
				break;
			}
		}
		i++;
	}
	result = malloc(sizeof(char) * (j + 1));
	if (!result)
		return (NULL);
	i -= j;
	i++;
	result[0] = '$';
	j = 1;
	while (str[i] && str[i] == ' ')
	{
		result[j] = str[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

static char	*cut_after_only_space(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '\0')
				break ;
			if (str[i + 1] == ' ' || str[i + 1] == '$')
			{
				i++;
				while (str[i] == ' ')
					i++;
				break;
			}
		}
		i++;
	}
	result = malloc(sizeof(char) * (ft_strlen(str) - i + 2));
	if (!result)
		return (NULL);
	j = 0;
	while (str[i])
	{
		result[j] = str[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

static int	cut_cell_for_dollar_first_char(t_token **words, t_token **cell)
{
	t_token	*new;

	if ((*cell)->type == ARG)
		new = create_word(cut_only_space((*cell)->word), JUST_DOLLAR);
	else if ((*cell)->type == ARG_IN_DOUBLE)
		new = create_word(cut_only_space((*cell)->word), JUST_DOLLAR_DOUBLE);
	if (!new)
		return (-1);
	(*cell)->word = cut_after_only_space((*cell)->word);
	new->next = (*cell);
	if ((*cell)->prev == NULL)
		*words = new;
	else
	{
		new->prev = (*cell)->prev;
		(*cell)->prev->next = new;
	}
	(*cell)->prev = new;
	return (0);
}

static int	cut_cell_for_dollar_other_char(t_token **words, t_token **cell)
{
	t_token	*new;
	t_token	*prev;

	if ((*cell)->type == ARG)
		new = create_word(cut_only_space((*cell)->word), JUST_DOLLAR);
	else if ((*cell)->type == ARG_IN_DOUBLE)
		new = create_word(cut_only_space((*cell)->word), JUST_DOLLAR_DOUBLE);
	if (!new)
		return (-1);
	prev = create_word(cut_before_only_space((*cell)->word), (*cell)->type);
	if (!prev)
		return (-1);
	(*cell)->word = cut_after_only_space((*cell)->word);
	prev->next = new;
	new->prev = prev;
	new->next = *cell;
	if ((*cell)->prev == NULL)
		*words = prev;
	else
	{
		prev->prev = (*cell)->prev;
		(*cell)->prev->next = prev;
	}
	(*cell)->prev = new;
	return (0);
}

void	change_just_dollar_to_arg(t_token **words)
{
	t_token	*tmp;

	tmp = *words;
	while (tmp)
	{
		if (tmp->type == JUST_DOLLAR)
			tmp->type = ARG;
		if (tmp->type == JUST_DOLLAR_DOUBLE)
			tmp->type = ARG_IN_DOUBLE;
		tmp = tmp->next;
	}
}

int	get_just_dollar(t_token **words)
{
	t_token	*tmp;
	int		nb_of_dollars;

	tmp = *words;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == ARG_IN_DOUBLE)
		{
			if (!(tmp->prev != NULL && tmp->prev->type == HERE_DOC))
			{
				nb_of_dollars = search_dollar(tmp->word);
				while (nb_of_dollars-- > 0)
				{
					if (search_only_dollar(tmp->word) == 0)
					{
						if (cut_cell_for_dollar_first_char(words, &tmp))
							return (-1);
					}
					else if (search_only_dollar(tmp->word) > 0)
						if (cut_cell_for_dollar_other_char(words, &tmp))
							return (-1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
