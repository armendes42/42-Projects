/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:35:06 by armendes          #+#    #+#             */
/*   Updated: 2021/10/13 16:47:59 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static void	print_neg(t_format f_info, int *c_disp, int *neg_f, char c)
{
	if (c == '0' && (f_info.precision != '.'
			|| (f_info.precision == '.' && f_info.length < 0))
		&& *(int *)f_info.value < 0
		&& *neg_f == 0)
	{
		*neg_f = 1;
		write(1, "-", 1);
		(*c_disp)++;
	}
}

static void	get_n(t_format f_info, int *n)
{
	if (f_info.precision == '.' && f_info.length == 0
		&& *(int *)f_info.value == 0)
		*n = f_info.width;
	else if (f_info.precision != '.' || f_info.length < f_info.len_format)
		*n = f_info.width - f_info.len_format;
	else if (f_info.length > 0)
		*n = f_info.width - f_info.length;
	else
		*n = f_info.width;
}

static void	print_flag(t_format f_info, int *c_disp, int *neg_f)
{
	int		n;
	char	c;

	c = ' ';
	if (f_info.flag == '0' && (f_info.precision != '.'
			|| (f_info.precision == '.' && f_info.length < 0))
		&& f_info.width > 0)
		c = '0';
	print_neg(f_info, c_disp, neg_f, c);
	if (f_info.width < 0)
		f_info.width *= -1;
	if (*(int *)f_info.value < 0)
		f_info.width--;
	get_n(f_info, &n);
	print_nchar(n, c);
	if (n > 0)
		(*c_disp) += n;
}

static void	print_precision(t_format f_info, int *c_disp, int *neg_f)
{
	int	n;

	if (f_info.length < f_info.len_format || f_info.length <= 0)
		return ;
	if (*(int *)f_info.value < 0)
	{
		*neg_f = 1;
		write(1, "-", 1);
		(*c_disp)++;
	}
	n = f_info.length - f_info.len_format;
	print_nchar(n, '0');
	if (n > 0)
		(*c_disp) += n;
}

void	print_integer(t_format *f_info, int *c_disp)
{
	int	neg_f;

	neg_f = 0;
	if ((f_info->flag == '?' || f_info->flag == '0') && f_info->width > 0)
		print_flag(*f_info, c_disp, &neg_f);
	if (f_info->precision == '.' && f_info->length > 0)
		print_precision(*f_info, c_disp, &neg_f);
	if (neg_f == 0 && *(int *)f_info->value < 0)
	{
		write(1, "-", 1);
		(*c_disp)++;
		neg_f = 1;
	}
	if ((f_info->precision == '.' && f_info->length != 0)
		|| f_info->precision != '.'
		|| *(int *)f_info->value != 0)
	{
		write(1, f_info->conv_format, f_info->len_format);
		(*c_disp) += f_info->len_format;
	}
	if (f_info->flag == '-' || f_info->width < 0)
		print_flag(*f_info, c_disp, &neg_f);
}
