/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:39:38 by armendes          #+#    #+#             */
/*   Updated: 2021/07/05 21:39:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_printf(char *format, ...)
{
	va_list		vargs;
	int			c_disp;

	if (format == NULL)
		return (-1);
	else if (ft_strlen(format) == 0)
		return (0);
	va_start(vargs, format);
	c_disp = print_format(format, &vargs);
	va_end(vargs);
	return (c_disp);
}
