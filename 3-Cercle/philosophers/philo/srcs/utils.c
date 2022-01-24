/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:59:35 by armendes          #+#    #+#             */
/*   Updated: 2022/01/24 19:24:28 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static void	itoa(char *result, unsigned int nb, int i)
{
	int	len;

	len = len_nb(nb) - 1;
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
	unsigned int	nb;

	if (n >= 0)
	{
		nb = n;
		result = malloc(sizeof(char) * (len_nb(nb) + 1));
		if (!result)
			return (NULL);
		i = 0;
		result[len_nb(nb)] = '\0';
	}
	if (n < 0)
	{
		nb = -n;
		result = malloc(sizeof(char) * (len_nb(nb) + 2));
		if (!result)
			return (NULL);
		result[0] = '-';
		result[len_nb(nb) + 1] = '\0';
		i = 1;
	}
	itoa(result, nb, i);
	return (result);
}

int	ft_atoi(char *str)
{
	int	result;
	int	neg;
	int	i;

	result = 0;
	neg = 1;
	i = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * neg);
}
