/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:26:43 by armendes          #+#    #+#             */
/*   Updated: 2022/03/24 17:39:05 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_exit_status(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
			return (1);
		i++;
	}
	return (0);
}

static char	*replace_env_var_by_exit_status(char *str, int exit_status)
{
	char	*new_word;
	int		i;
	int		j;
	int		k;
	char	*exit;

	exit = ft_itoa(exit_status);
	
	new_word = malloc(sizeof(char)
			* (ft_strlen(str) - 2 + ft_strlen(exit) + 1));
	if (!new_word)
		return (NULL);
	i = -1;
	j = -1;
	while (str[++i] && str[i] != '$')
		new_word[++j] = str[i];
	i += 1;
	k = -1;
	while (exit[++k])
		new_word[++j] = exit[k];
	while (str[i++])
		new_word[++j] = str[i];
	new_word[j] = '\0';
	write(1, new_word, ft_strlen(new_word));
	free(str);
	return (new_word);
}

int	get_exit_status(t_token **words, int exit_status)
{
	t_token	*tmp;

	tmp = *words;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == ARG_IN_DOUBLE)
		{
			if (!(tmp->prev != NULL && tmp->prev->type == HERE_DOC))
			{
				if (search_exit_status(tmp->word))
					tmp->word = replace_env_var_by_exit_status(tmp->word, exit_status);
				if (tmp->word == NULL)
					return (-1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
