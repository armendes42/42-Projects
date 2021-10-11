/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:32:12 by armendes          #+#    #+#             */
/*   Updated: 2021/07/05 21:32:33 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** INCLUDES
*/
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

/*
** FORMAT SPECIFIER LIST AND BASES
*/

# define SPECS "cspdiuxX%"
# define BASE_DEC "0123456789"
# define BASE_HEXA "0123456789abcdef"
# define CAP_BASE_HEXA "0123456789ABCDEF"

/*
** STRUCTURE TO STORE FORMAT SPECIFIER, FLAG AND PRECISION INFO
*/

typedef struct	s_format
{
	int			width;
	int			length;
	int			ignore_f;
	int			ignore_p;
	int			len_format;
	char		flag;
	char		precision;
	char		spec;
	char		*conv_format;
	void		*value;
}				t_format;

/*
** TYPEDEF ARRAY OF FUNCTIONS
*/

typedef int		(*t_converter)();
typedef void	(*t_printer)();

/*
**	FT_PRINTF
*/

int				ft_printf(char *format, ...);

/*
** USEFULL FUNCTIONS
*/

unsigned int	get_int(char **format);
void			get_format_info(char **format, t_format *f_info
								, va_list *vargs);
t_converter		*init_converters(void);
t_printer		*init_printers(void);
void			init_format_info(t_format *f_info);
int				print_format(char *format, va_list *vargs);
void			print_nchar(int n, char c);

/*
** CONVERTER FOR EACH FORMAT SPECIFIER
*/

int				convert_char(va_list *vargs, t_format *f_info);
int				convert_string(va_list *vargs, t_format *f_info);
int				convert_percent(va_list *vargs, t_format *f_info);
int				convert_pointer(va_list *vargs, t_format *f_info);
int				convert_integer(va_list *vargs, t_format *f_info);
int				convert_uinteger(va_list *vargs, t_format *f_info);
int				convert_hexa(va_list *vargs, t_format *f_info);
int				convert_cap_hexa(va_list *vargs, t_format *f_info);

/*
**	PRINTER FOR EACH FORMAT SPECIFIER
*/

void			print_pointer(t_format *f_info, int *c_disp);
void			print_string(t_format *f_info, int *c_disp);
void			print_char(t_format *f_info, int *c_disp);
void			print_percent(t_format *f_info, int *c_disp);
void			print_integer(t_format *f_info, int *c_disp);
void			print_uinteger(t_format *f_info, int *c_disp);
void			print_hexa(t_format *f_info, int *c_disp);
void			print_cap_hexa(t_format *f_info, int *c_disp);

#endif
