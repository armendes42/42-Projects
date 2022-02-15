/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:14:50 by armendes          #+#    #+#             */
/*   Updated: 2022/02/15 19:32:22 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cut_one_char(char *str)
{
	int	i;

	i = 1;
	return (&str[i]);
}

char	*cut_two_char(char *str)
{
	int	i;

	i = 2;
	return (&str[i]);
}

char	*before_redirection(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] && str[i] != '<' && str[i] != '>')
		i++;
	new = ft_strdup_size(str, i);
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
	return (new);
}
