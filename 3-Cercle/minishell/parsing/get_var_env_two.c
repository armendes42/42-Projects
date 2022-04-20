/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_env_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:35:24 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 19:00:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_env_var(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = keep_going_till_dollar(&str[0]);
	if (str[i] == '{')
		j = keep_going_till_end_of_var(&str[i + 1]);
	else
		j = keep_going_till_end_of_var(&str[i]);
	result = malloc(sizeof(char) * (j + 1));
	if (!result)
		error_and_exit(get_info(), 1);
	j = -1;
	if (str[i] == '{')
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '}'
		&& (ft_isalnum(str[i]) || str[i] == '_'))
	{
		result[++j] = str[i];
		i++;
	}
	result[++j] = '\0';
	return (result);
}

char	*replace_env_var_by_nothing(char *str)
{
	char	*new_word;
	int		i;
	int		j;

	i = keep_going_till_dollar(&str[0]);
	if (str[i] == '{')
		j = keep_going_till_end_of_var(&str[i + 1]) + 1;
	else
		j = keep_going_till_end_of_var(&str[i]);
	new_word = malloc(sizeof(char) * (ft_strlen(str) - j));
	if (!new_word)
		error_and_exit(get_info(), 1);
	i = -1;
	j = -1;
	while (str[++i] && str[i] != '$')
		new_word[++j] = str[i];
	if (str[i + 1] == '{')
		i += keep_going_till_end_of_var(&str[i + 2]) + 2;
	else
		i += keep_going_till_end_of_var(&str[i + 1]);
	while (str[++i])
		new_word[++j] = str[i];
	new_word[++j] = '\0';
	free(str);
	return (new_word);
}

static char	*create_malloc_for_env_content(char *str, char *inside_var)
{
	int		i;
	int		j;
	char	*new_word;

	i = keep_going_till_dollar(&str[0]);
	if (str[i] == '{')
		j = keep_going_till_end_of_var(&str[i + 1]) + 3;
	else
		j = keep_going_till_end_of_var(&str[i]);
	new_word = malloc(sizeof(char)
			* (ft_strlen(str) - j + ft_strlen(inside_var) + 1));
	if (!new_word)
		error_and_exit(get_info(), 1);
	return (new_word);
}

char	*replace_env_var_by_content(char *str, char *inside_var)
{
	char	*new_word;
	int		i;
	int		j;
	int		k;

	new_word = create_malloc_for_env_content(str, inside_var);
	i = -1;
	j = -1;
	while (str[++i] && str[i] != '$')
		new_word[++j] = str[i];
	if (str[i + 1] == '{')
		i += keep_going_till_end_of_var(&str[i + 2]) + 2;
	else
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

int	type_is_redirection(t_type type)
{
	if (type == HERE_DOC || type == RED_IN
		|| type == RED_OUT || type == RED_OUT_APPEND)
		return (1);
	return (0);
}
