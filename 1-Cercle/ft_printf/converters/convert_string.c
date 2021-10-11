/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:29:57 by armendes          #+#    #+#             */
/*   Updated: 2021/07/05 21:30:05 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int		convert_string(va_list *vargs, t_format *f_info)
{
	char		*str;

	str = va_arg(*vargs, char *);
	if (str != NULL)
		f_info->conv_format = ft_strdup(str);
	else
		f_info->conv_format = ft_strdup("(null)");
	f_info->len_format = ft_strlen(f_info->conv_format);
	return (0);
}
