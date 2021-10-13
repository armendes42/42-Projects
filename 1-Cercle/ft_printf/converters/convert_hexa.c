/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:26:39 by armendes          #+#    #+#             */
/*   Updated: 2021/10/13 16:28:31 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	convert_hexa(va_list *vargs, t_format *f_info)
{
	unsigned int	*n;

	n = malloc(sizeof(unsigned int));
	if (n == NULL)
		return (-1);
	*n = va_arg(*vargs, unsigned int);
	f_info->value = n;
	f_info->conv_format = ft_itoa_base(*n, BASE_HEXA);
	f_info->len_format = ft_strlen(f_info->conv_format);
	if (f_info->conv_format == NULL)
		return (-1);
	return (0);
}
