/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:18:13 by armendes          #+#    #+#             */
/*   Updated: 2022/01/11 16:52:08 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power_ten(int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= 10;
		power--;
	}
	return (result);
}

static int	len_nb(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	itoa(char *result, int len, unsigned int nb, int i)
{
	while (len >= 0)
	{
		result[i] = (nb / power_ten(len) % 10) + 48;
		len--;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char			*result;
	int				i;
	int				len;
	unsigned int	nb;

	if (n >= 0)
	{
		nb = n;
		if (!(result = malloc(sizeof(char) * (len_nb(nb) + 1))))
			return (NULL);
		i = 0;
		result[len_nb(nb)] = '\0';
	}
	if (n < 0)
	{
		nb = -n;
		if (!(result = malloc(sizeof(char) * (len_nb(nb) + 2))))
			return (NULL);
		result[0] = '-';
		result[len_nb(nb) + 1] = '\0';
		i = 1;
	}
	len = len_nb(nb) - 1;
	itoa(result, len, nb, i);
	return (result);
}
