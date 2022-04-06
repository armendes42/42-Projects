/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:51:21 by armendes          #+#    #+#             */
/*   Updated: 2021/07/05 21:51:40 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(long long n, int base_len)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long long n, char *base)
{
	char		*str;
	int			n_len;
	int			base_len;
	int			tmp;

	base_len = ft_strlen(base);
	n_len = nbr_len(n, base_len);
	str = malloc(sizeof(char) * n_len + 1);
	if (str == NULL)
		return (NULL);
	str[n_len] = '\0';
	while (--n_len >= 0)
	{
		tmp = (n % base_len);
		if (tmp < 0)
			tmp *= -1;
		str[n_len] = base[tmp];
		n /= base_len;
	}
	return (str);
}
