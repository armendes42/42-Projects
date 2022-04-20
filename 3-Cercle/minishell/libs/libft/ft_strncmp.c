/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:43:55 by armendes          #+#    #+#             */
/*   Updated: 2022/04/19 20:23:37 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			i;

	i = 0;
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (-1);
	while ((s_1[i] || s_2[i]) && i < n)
	{
		if (s_1[i] != s_2[i])
			return (s_1[i] - s_2[i]);
		else
			i++;
	}
	return (0);
}
