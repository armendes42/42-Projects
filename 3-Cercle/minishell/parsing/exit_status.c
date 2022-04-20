/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:26:43 by armendes          #+#    #+#             */
/*   Updated: 2022/04/20 17:25:01 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_exit_status(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			result++;
			i++;
		}
		i++;
	}
	return (result);
}

static char	*create_malloc_for_exit_status(char *str, char *exit)
{
	char	*new_word;

	new_word = malloc(sizeof(char)
			* (ft_strlen(str) - 2 + ft_strlen(exit) + 1));
	if (!new_word)
		error_and_exit(get_info(), 1);
	return (new_word);
}

static char	*replace_env_var_by_exit_status(char *str, int exit_status)
{
	char	*new_word;
	int		i;
	int		j;
	int		k;
	char	*exit;

	exit = ft_itoa(exit_status);
	if (!exit)
		error_and_exit(get_info(), 1);
	new_word = create_malloc_for_exit_status(str, exit);
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
	free(str);
	free(exit);
	return (new_word);
}

void	get_exit_status(t_token **words, int exit_status)
{
	t_token	*tmp;
	int		nb_exit_status;

	tmp = *words;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == ARG_IN_DOUBLE)
		{
			if (detect_here_doc(tmp) == 0)
			{
				nb_exit_status = search_exit_status(tmp->word);
				while (nb_exit_status-- > 0)
					tmp->word = replace_env_var_by_exit_status(tmp->word,
							exit_status);
			}
		}
		tmp = tmp->next;
	}
}
