/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 23:14:47 by armendes          #+#    #+#             */
/*   Updated: 2020/12/25 21:41:30 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*endd;
	unsigned char	*ends;

	d = dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
		ft_memcpy(d, s, n);
	else
	{
		endd = d + (n - 1);
		ends = s + (n - 1);
		while (n > 0)
		{
			*endd = *ends;
			endd--;
			ends--;
			n--;
		}
	}
	return (d);
}
