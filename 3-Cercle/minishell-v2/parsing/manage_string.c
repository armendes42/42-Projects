/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:14:50 by armendes          #+#    #+#             */
/*   Updated: 2022/04/06 17:35:46 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//#define malloc(x) NULL

char	*cut_one_char(char *str)
{
	int		i;
	int		j;
	char	*new_word;

	i = 0;
	while (str[i])
		i++;
	new_word = malloc(sizeof(char) * i);
	if (!new_word)
		error_and_exit(get_info());
	i = 1;
	j = 0;
	while (str[i])
	{
		new_word[j] = str[i];
		i++;
		j++;
	}
	new_word[j] = '\0';
	return (new_word);
}

char	*cut_two_char(char *str)
{
	int		i;
	int		j;
	char	*new_word;

	i = 0;
	while (str[i])
		i++;
	new_word = malloc(sizeof(char) * (i - 1));
	if (!new_word)
		error_and_exit(get_info());
	i = 2;
	j = 0;
	while (str[i])
	{
		new_word[j] = str[i];
		i++;
		j++;
	}
	new_word[j] = '\0';
	return (new_word);
}

char	*before_redirection(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] && str[i] != '<' && str[i] != '>')
		i++;
	new = ft_strdup_size(str, i);
	if (!new)
		error_and_exit(get_info());
	return (new);
}

char	*after_redirection(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] && str[i] != '<' && str[i] != '>')
		i++;
	if (!str[i])
		return (NULL);
	if (str[i + 1] == '<' || str[i + 1] == '>')
		i++;
	new = ft_strdup_size(&str[i + 1], ft_strlen(str) - i);
	if (!new)
		error_and_exit(get_info());
	return (new);
}
