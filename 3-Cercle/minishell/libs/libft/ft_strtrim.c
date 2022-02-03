/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:20:05 by armendes          #+#    #+#             */
/*   Updated: 2022/02/03 19:52:50 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	compute_len_and_i(int *len, int *i, char const *s1, char const *set)
{
	int	len_tmp;
	int	i_tmp;

	len_tmp = ft_strlen(s1) - 1;
	while (len_tmp > 0 && check_set(set, s1[len_tmp]))
		len_tmp--;
	i_tmp = 0;
	while (s1[i_tmp] && check_set(set, s1[i_tmp]))
		i_tmp++;
	*len = len_tmp;
	*i = i_tmp;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		j;
	int		len;

	if (!s1)
		return (NULL);
	compute_len_and_i(&len, &i, s1, set);
	if (len - i > 0)
	{
		result = malloc(sizeof(char) * len - i + 2);
		if (!result)
			return (NULL);
		j = 0;
		while ((len - i + 1) > 0)
			result[j++] = s1[i++];
		result[j] = '\0';
	}
	else
	{
		result = malloc(sizeof(char));
		if (!result)
			return (NULL);
	}
	return (result);
}
