/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:39:54 by armendes          #+#    #+#             */
/*   Updated: 2022/01/19 16:53:50 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int	is_true;
	int	result;

	is_true = 0;
	result = 0;
	while (s != NULL && *s)
	{
		if (*s == c)
			is_true = 0;
		else if (is_true == 0)
		{
			is_true = 1;
			result++;
		}
		s++;
	}
	return (result);
}

static size_t	wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	nb_mall;
	size_t	l_word;

	nb_mall = count_words(s, c) + 1;
	str = malloc(sizeof(char **) * nb_mall);
	if (!str)
		return (NULL);
	while (s != NULL && *s)
	{
		if (*s != c)
		{
			l_word = wordlen(s, c) + 1;
			*str = malloc(sizeof(char) * l_word);
			if (!*str)
				return (NULL);
			ft_strlcpy(*str, s, l_word);
			s += l_word - 1;
			str++;
		}
		else
			s++;
	}
	*str = NULL;
	return (str - nb_mall + 1);
}
