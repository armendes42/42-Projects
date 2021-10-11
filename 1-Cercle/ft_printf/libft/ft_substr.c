/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:22:21 by armendes          #+#    #+#             */
/*   Updated: 2020/12/25 22:15:21 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;
	size_t			j;

	i = 0;
	if (!s)
		return (NULL);
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] && i < start)
		i++;
	j = 0;
	while (s[i] && j < len)
	{
		result[j] = s[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
