/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:22:38 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 16:24:01 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_movement_key(int key)
{
	if (key == K_W || key == K_A || key == K_S || key == K_D)
		return (1);
	return (0);
}

static int	key_press(int key, t_win *win)
{
	if (is_movement_key(key) && key != ESC && win->key->pressed == 0)
	{
		win->key->key = key;
		win->key->pressed = 1;
	}
	else if (key == ESC)
	{
		free_all(win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	key_release(int key, t_win *win)
{
	if (is_movement_key(key) && key != ESC && win->key->pressed == 1)
	{
		win->key->pressed = 0;
		win->key->delay = 0;
	}
	return (0);
}

void	loops(t_win *win)
{
	mlx_hook(win->win_ptr, 17, 1L << 17, mlx_loop_end, win->mlx_ptr);
	mlx_hook(win->win_ptr, 2, 1L << 0, key_press, win);
	mlx_hook(win->win_ptr, 3, 1L << 1, key_release, win);
	mlx_loop_hook(win->mlx_ptr, render_all, win);
}
