/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:11:21 by armendes          #+#    #+#             */
/*   Updated: 2022/03/08 18:12:04 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*result;
	size_t		len;
	int			i;
	int			j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		result[++j] = s1[i];
	i = -1;
	while (s2[++i])
		result[++j] = s2[i];
	result[++j] = '\0';
	return (result);
}
