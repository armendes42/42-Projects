/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uinteger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:30:30 by armendes          #+#    #+#             */
/*   Updated: 2021/07/05 21:30:39 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int		convert_uinteger(va_list *vargs, t_format *f_info)
{
	unsigned int		*n;

	n = malloc(sizeof(unsigned int));
	if (n == NULL)
		return (-1);
	*n = va_arg(*vargs, int);
	f_info->value = n;
	f_info->conv_format = ft_itoa_base(*n, BASE_DEC);
	f_info->len_format = ft_strlen(f_info->conv_format);
	if (f_info->conv_format == NULL)
		return (-1);
	return (0);
}
