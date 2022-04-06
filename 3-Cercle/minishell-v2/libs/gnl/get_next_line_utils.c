/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:17:48 by armendes          #+#    #+#             */
/*   Updated: 2022/01/25 17:48:19 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char		*result;
	size_t		len;
	int			i;
	int			j;

	if (!s1 && !s2)
		return (0);
	len = gnl_strlen(s1) + gnl_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	j = -1;
	if (s1)
	{
		i = -1;
		while (s1[++i])
			result[++j] = s1[i];
		free((char *)s1);
	}
	i = -1;
	while (s2[++i])
		result[++j] = s2[i];
	result[++j] = '\0';
	return (result);
}

int	has_return(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
