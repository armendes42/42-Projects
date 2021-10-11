/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:40:53 by armendes          #+#    #+#             */
/*   Updated: 2021/07/05 21:41:08 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	print_spec(char **format, int *c_disp, va_list *vargs)
{
	t_format		f_info;
	t_printer		*printers;
	int				index;

	get_format_info(format, &f_info, vargs);
	if (f_info.spec == '?')
		return (-1);
	printers = init_printers();
	if (printers == NULL)
		return (0);
	index = 0;
	while (SPECS[index])
	{
		if (SPECS[index] == f_info.spec)
			printers[index](&f_info, c_disp);
		++index;
	}
	free(printers);
	if (f_info.value != NULL)
		free(f_info.value);
	free(f_info.conv_format);
	return (0);
}

int	print_format(char *format, va_list *vargs)
{
	int		c_disp;

	c_disp = 0;
	while (*format)
	{
		if (*format != '%')
		{
			++c_disp;
			write(1, format, 1);
		}
		else if (print_spec(&format, &c_disp, vargs) == -1)
			return (-1);
		++format;
	}
	return (c_disp);
}
