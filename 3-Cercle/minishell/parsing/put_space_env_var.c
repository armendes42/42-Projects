/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_space_env_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:03:09 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 16:26:50 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		error_and_exit(get_info(), 1);
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
		error_and_exit(get_info(), 1);
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

void	cut_arg_nothing(t_token **words)
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
			free(tmp_word);
			tmp->next->next = tmp_next;
			if (tmp_next != NULL)
				tmp_next->prev = tmp->next;
			tmp->next->prev = tmp;
		}
		tmp = tmp->next;
	}
}
