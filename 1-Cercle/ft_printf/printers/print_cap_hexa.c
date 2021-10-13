/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cap_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:33:21 by armendes          #+#    #+#             */
/*   Updated: 2021/10/13 16:45:13 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static void	get_n(t_format f_info, int *n)
{
	if (f_info.precision == '.' && f_info.length == 0
		&& *(unsigned int *)f_info.value == 0)
		*n = f_info.width;
	else if (f_info.precision != '.' || f_info.length < f_info.len_format)
		*n = f_info.width - f_info.len_format;
	else if (f_info.length > 0)
		*n = f_info.width - f_info.length;
	else
		*n = f_info.width;
}

static void	print_flag(t_format f_info, int *c_disp)
{
	int		n;
	char	c;

	if (f_info.width < 0)
		f_info.width *= -1;
	if ((f_info.flag != '?' || f_info.width != 0)
		&& f_info.precision == '.' && f_info.length > f_info.width)
		return ;
	c = ' ';
	if (f_info.flag == '0' && (f_info.precision != '.'
			|| (f_info.precision == '.' && f_info.length < 0))
		&& f_info.width > 0)
		c = '0';
	get_n(f_info, &n);
	print_nchar(n, c);
	if (n > 0)
		(*c_disp) += n;
}

static void	print_precision(t_format f_info, int *c_disp)
{
	int	n;

	if (f_info.length < f_info.len_format || f_info.length <= 0)
		return ;
	n = f_info.length - f_info.len_format;
	print_nchar(n, '0');
	if (n > 0)
		(*c_disp) += n;
}

void	print_cap_hexa(t_format *f_info, int *c_disp)
{
	if ((f_info->flag == '?' || f_info->flag == '0') && f_info->width > 0)
		print_flag(*f_info, c_disp);
	if (f_info->precision == '.' && f_info->length > 0)
		print_precision(*f_info, c_disp);
	if ((f_info->precision == '.' && f_info->length != 0)
		|| f_info->precision != '.'
		|| *(unsigned int*)f_info->value != 0)
	{
		write(1, f_info->conv_format, f_info->len_format);
		(*c_disp) += f_info->len_format;
	}
	if (f_info->flag == '-' || f_info->width < 0)
		print_flag(*f_info, c_disp);
}
