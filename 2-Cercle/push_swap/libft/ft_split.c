/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:39:54 by armendes          #+#    #+#             */
/*   Updated: 2022/01/10 19:13:19 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		nb_mall(char *str, char *charset)
{
	int result;
	int	is_true;

	result = 0;
	is_true = 0;
	while (*str)
	{
		if (check_charset(*str, charset))
			is_true = 0;
		else if (is_true == 0)
		{
			is_true = 1;
			result++;
		}
		str++;
	}
	return (result);
}

int		len_str(char *str, char *charset, int nb)
{
	int i;

	i = 0;
	while (str[nb])
	{
		if (!check_charset(str[nb], charset))
			i++;
		nb++;
	}
	return (i);
}

void	split(char **result, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (str[++i])
	{
		if (!check_charset(str[i], charset))
		{
			if (k == 0)
				if (!(result[j] = malloc(sizeof(char) *
								(len_str(str, charset, i) + 1))))
					return ;
			result[j][k] = str[i];
			result[j][k + 1] = '\0';
			k++;
		}
		if ((check_charset(str[i], charset) &&
				!check_charset(str[i + 1], charset) && k > 0) &&
				(k = 0) == 0)
			j++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	if (!(result = (char **)malloc(sizeof(char *) *
					(nb_mall(str, charset) + 1))))
		return (NULL);
	split(result, str, charset);
	result[nb_mall(str, charset)] = NULL;
	return (result);
}
