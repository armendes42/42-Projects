/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:04:21 by armendes          #+#    #+#             */
/*   Updated: 2022/02/10 15:20:20 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_size(const char *s, int size)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (size <= 0)
		return (NULL);
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (s[i] && size)
	{
		dest[j] = s[i];
		i++;
		j++;
		size--;
	}
	dest[j] = '\0';
	return (dest);
}
