/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:34:00 by armendes          #+#    #+#             */
/*   Updated: 2021/10/13 16:45:32 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static void	print_flag(t_format f_info, int *c_disp)
{
	if (f_info.width < 0)
		f_info.width *= -1;
	print_nchar(f_info.width - 1, ' ');
	if (f_info.width - 1 > 0)
		(*c_disp) += f_info.width - 1;
}

void	print_char(t_format *f_info, int *c_disp)
{
	if (f_info->flag == '?' && f_info->width > 0)
		print_flag(*f_info, c_disp);
	write(1, f_info->conv_format, f_info->len_format);
	(*c_disp) += f_info->len_format;
	if (f_info->flag == '-' || f_info->width < 0)
		print_flag(*f_info, c_disp);
}
