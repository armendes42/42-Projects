/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:29:26 by armendes          #+#    #+#             */
/*   Updated: 2021/07/05 21:29:42 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	convert_pointer(va_list *vargs, t_format *f_info)
{
	char			*str;
	unsigned long	*n;

	n = malloc(sizeof(unsigned long));
	if (n == NULL)
		return (-1);
	*n = (unsigned long)va_arg(*vargs, void *);
	f_info->value = n;
	str = ft_itoa_base(*n, BASE_HEXA);
	if (str == NULL)
		return (-1);
	f_info->conv_format = ft_strjoin("0x", str);
	free(str);
	if (f_info->conv_format == NULL)
		return (-1);
	f_info->len_format = ft_strlen(f_info->conv_format);
	return (0);
}
