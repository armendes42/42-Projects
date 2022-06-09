/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:28:56 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 16:29:16 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_win_to_zero(t_win *win)
{
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
}

t_win	*initialize_window(char **av)
{
	t_win	*win;

	(void)av;
	win = malloc(sizeof(t_win));
	if (!win)
		error(win, MALLOC_ERR);
	set_win_to_zero(win);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		error(win, MALLOC_ERR);
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!win->win_ptr)
		error(win, MALLOC_ERR);
	return (win);
}
