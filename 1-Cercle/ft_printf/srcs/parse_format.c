/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:40:24 by armendes          #+#    #+#             */
/*   Updated: 2021/07/05 21:40:44 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static void	get_flag(char **format, t_format *f_info, va_list *vargs)
{
	while (**format && (**format == '0' || **format == '-'
			|| ft_isspace(**format)))
	{
		if (**format == '-')
		{
			f_info->flag = '-';
			f_info->ignore_f = 1;
		}
		if (f_info->ignore_f == 0)
			f_info->flag = '0';
		++(*format);
	}
	if (f_info->flag == 0)
		f_info->flag = '0';
	if (**format == '*')
	{
		f_info->width = va_arg(*vargs, int);
		++(*format);
	}
	else if (ft_isdigit(**format))
		f_info->width = get_int(format);
}

static void	get_prec(char **format, t_format *f_info, va_list *vargs)
{
	if (**format == '.')
	{
		++(*format);
		f_info->precision = '.';
		if (**format == '*')
		{
			f_info->length = va_arg(*vargs, int);
			++(*format);
		}
		else if (ft_isdigit(**format))
			f_info->length = get_int(format);
	}
}

static void	get_spec(char const c, t_format *f_info)
{
	size_t		i;

	i = 0;
	while (SPECS[i])
	{
		if (SPECS[i] == c)
			f_info->spec = c;
		i++;
	}
}

void		get_conv(char const c, va_list *vargs, t_format *f_info)
{
	size_t			index;
	t_converter		*converters;

	converters = init_converters();
	if (converters == NULL)
		return ;
	index = 0;
	while (SPECS[index])
	{
		if (SPECS[index] == c)
			if ((converters[index])(vargs, f_info) == -1)
			{
				free(converters);
				return ;
			}
		++index;
	}
	free(converters);
}

void		get_format_info(char **format, t_format *f_info, va_list *vargs)
{
	init_format_info(f_info);
	++(*format);
	get_flag(format, f_info, vargs);
	get_prec(format, f_info, vargs);
	get_spec(**format, f_info);
	get_conv(f_info->spec, vargs, f_info);
	if (f_info->spec == '?')
		free(f_info->conv_format);
}
