/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:41:12 by armendes          #+#    #+#             */
/*   Updated: 2021/07/05 21:41:41 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

unsigned int	get_int(char **format)
{
	unsigned short	nbr;

	nbr = 0;
	while (**format && ft_isdigit(**format))
	{
		nbr = nbr * 10 + **format - '0';
		++(*format);
	}
	return (nbr);
}

void			print_nchar(int n, char c)
{
	while (--n >= 0)
		write(1, &c, 1);
}
