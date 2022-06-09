/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:41:47 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 16:29:30 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "macro.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_key
{
	int	key;
	int	pressed;
	int	delay;
}				t_key;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_key	*key;
}								t_win;

void	error(t_win *win, char *err_msg);
t_win	*initialize_window(char **av);
void	loops(t_win *win);

#endif
