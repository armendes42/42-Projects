/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:40:02 by armendes          #+#    #+#             */
/*   Updated: 2021/07/05 21:40:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_converter	*init_converters(void)
{
	t_converter		*converters;

	converters = malloc(sizeof(t_converter) * 9);
	if (converters == NULL)
	{
		return (NULL);
	}
	converters[0] = convert_char;
	converters[1] = convert_string;
	converters[2] = convert_pointer;
	converters[3] = convert_integer;
	converters[4] = convert_integer;
	converters[5] = convert_uinteger;
	converters[6] = convert_hexa;
	converters[7] = convert_cap_hexa;
	converters[8] = convert_percent;
	return (converters);
}

void		init_format_info(t_format *f_info)
{
	f_info->width = 0;
	f_info->length = 0;
	f_info->ignore_f = 0;
	f_info->ignore_p = 0;
	f_info->len_format = 0;
	f_info->flag = '?';
	f_info->precision = '?';
	f_info->spec = '?';
	f_info->conv_format = NULL;
	f_info->value = NULL;
}

t_printer	*init_printers(void)
{
	t_printer		*printers;

	printers = malloc(sizeof(t_printer) * 9);
	if (printers == NULL)
	{
		return (NULL);
	}
	printers[0] = print_char;
	printers[1] = print_string;
	printers[2] = print_pointer;
	printers[3] = print_integer;
	printers[4] = print_integer;
	printers[5] = print_uinteger;
	printers[6] = print_hexa;
	printers[7] = print_cap_hexa;
	printers[8] = print_percent;
	return (printers);
}
