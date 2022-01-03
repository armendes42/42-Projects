/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 23:56:16 by armendes          #+#    #+#             */
/*   Updated: 2021/10/13 16:23:31 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;
	size_t	size;

	size = nelem * elsize;
	p = malloc(size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, size);
	return (p);
}
