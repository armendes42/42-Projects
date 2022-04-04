/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:53:12 by armendes          #+#    #+#             */
/*   Updated: 2022/04/04 16:36:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_var_env_two(char **word, char **env)
{
	char	*var;
	char	*inside_var;

	var = search_env_var(*word);
	if (var == NULL)
		return (-1);
	inside_var = ft_getenv(var, env);
	free(var);
	if (inside_var == NULL)
		*word = replace_env_var_by_nothing(*word);
	else
		*word = replace_env_var_by_content(*word, inside_var);
	free(inside_var);
	if (*word == NULL)
		return (-1);
	return (0);
}

int	get_var_env(t_token **words, char **env)
{
	t_token	*tmp;
	int		control;
	int		nb_of_dollars;

	tmp = *words;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == ARG_IN_DOUBLE)
		{
			if (!(tmp->prev != NULL && type_is_redirection(tmp->prev->type)))
			{
				nb_of_dollars = search_dollar(tmp->word);
				while (nb_of_dollars-- > 0)
				{
					control = get_var_env_two(&tmp->word, env);
					if (control == -1)
						return (-1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	get_var_env_files_two(char **word, char **env)
{
	char	*var;
	char	*inside_var;

	var = search_env_var(*word);
	if (var == NULL)
		return (-1);
	inside_var = ft_getenv(var, env);
	free(var);
	if (inside_var == NULL)
	{
		free(inside_var);
		ft_putstr_fd(*word, STDERR_FILENO);
		ft_putstr_fd(": ambiguous redirect\n", STDERR_FILENO);
		return (0);
	}
	else
		*word = replace_env_var_by_content(*word, inside_var);
	free(inside_var);
	if (*word == NULL)
		return (-1);
	return (0);
}

int	get_var_env_files(t_token **words, char **env)
{
	t_token	*tmp;
	int		nb_of_dollars;
	int		control;

	tmp = *words;
	control = 0;
	while (tmp)
	{
		if (tmp->type == ARG || tmp->type == ARG_IN_DOUBLE)
		{
			if (!(tmp->prev != NULL && tmp->prev->type == HERE_DOC))
			{
				nb_of_dollars = search_dollar(tmp->word);
				while (nb_of_dollars-- > 0)
				{
					control = get_var_env_files_two(&tmp->word, env);
					if (control == -1)
						return (-1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
