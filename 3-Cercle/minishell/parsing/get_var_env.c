/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:53:12 by armendes          #+#    #+#             */
/*   Updated: 2022/03/14 20:32:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*search_env_var(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = keep_going_till_dollar(&str[0]);
	j = keep_going_till_end_of_var(&str[i]);
	i += j;
	result = malloc(sizeof(char) * (j + 1));
	if (!result)
		return (NULL);
	i -= j;
	j = 0;
	while (str[i] && str[i] != ' ' && str[i] != '$'
		&& (ft_isalnum(str[i]) || str[i] == '_'))
	{
		result[j] = str[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

static char	*replace_env_var_by_nothing(char *str)
{
	char	*new_word;
	int		i;
	int		j;

	i = keep_going_till_dollar(&str[0]);
	j = keep_going_till_end_of_var(&str[i]);
	i += j;
	new_word = malloc(sizeof(char) * (ft_strlen(str) - j));
	if (!new_word)
		return (NULL);
	i = -1;
	j = -1;
	while (str[++i] && str[i] != '$')
		new_word[++j] = str[i];
	i += keep_going_till_end_of_var(&str[i + 1]);
	while (str[++i])
		new_word[++j] = str[i];
	new_word[++j] = '\0';
	free(str);
	return (new_word);
}

static char	*replace_env_var_by_content(char *str, char *inside_var)
{
	char	*new_word;
	int		i;
	int		j;
	int		k;

	i = keep_going_till_dollar(&str[0]);
	j = keep_going_till_end_of_var(&str[i]);
	i += j;
	new_word = malloc(sizeof(char)
			* (ft_strlen(str) - j + ft_strlen(inside_var) + 1));
	if (!new_word)
		return (NULL);
	i = -1;
	j = -1;
	while (str[++i] && str[i] != '$')
		new_word[++j] = str[i];
	i += keep_going_till_end_of_var(&str[i + 1]);
	k = -1;
	while (inside_var[++k])
		new_word[++j] = inside_var[k];
	while (str[i++])
		new_word[++j] = str[i];
	new_word[j] = '\0';
	free(str);
	return (new_word);
}

int	get_var_env(t_token **words, char **env)
{
	t_token	*tmp;
	char	*var;
	char	*inside_var;
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
					var = search_env_var(tmp->word);
					if (var == NULL)
						return (-1);
					inside_var = ft_getenv(var, env);
					free(var);
					if (inside_var == NULL)
						tmp->word = replace_env_var_by_nothing(tmp->word);
					else
						tmp->word = replace_env_var_by_content(tmp->word,
								inside_var);
					if (tmp->word == NULL)
						return (-1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
