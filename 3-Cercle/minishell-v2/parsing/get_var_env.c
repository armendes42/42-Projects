/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:53:12 by armendes          #+#    #+#             */
/*   Updated: 2022/04/06 18:41:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_var_env_two(char **word, char **env)
{
	char	*var;
	char	*inside_var;

	var = search_env_var(*word);
	inside_var = ft_getenv(var, env);
	free(var);
	if (inside_var == NULL)
		*word = replace_env_var_by_nothing(*word);
	else
		*word = replace_env_var_by_content(*word, inside_var);
	free(inside_var);
}

void	get_var_env(t_token **words, char **env)
{
	t_token	*tmp;
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
					get_var_env_two(&tmp->word, env);
			}
		}
		tmp = tmp->next;
	}
}

static void	get_var_env_files_two(char **word, char **env)
{
	char	*var;
	char	*inside_var;

	var = search_env_var(*word);
	inside_var = ft_getenv(var, env);
	free(var);
	if (inside_var == NULL)
	{
		free(inside_var);
		ft_putstr_fd(*word, STDERR_FILENO);
		ft_putstr_fd(": ambiguous redirect\n", STDERR_FILENO);
		return ;
	}
	else
		*word = replace_env_var_by_content(*word, inside_var);
	free(inside_var);
}

void	get_var_env_files(t_token **words, char **env)
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
					get_var_env_files_two(&tmp->word, env);
			}
		}
		tmp = tmp->next;
	}
}
