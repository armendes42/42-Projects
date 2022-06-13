/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:22:38 by armendes          #+#    #+#             */
/*   Updated: 2022/06/13 16:16:47 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	key_press(int key, t_win *win)
{
	if (key == K_W && win->keys.key_w == 0)
		win->keys.key_w = 1;
	else if (key == K_A && win->keys.key_a == 0)
		win->keys.key_a = 1;
	else if (key == K_S && win->keys.key_s == 0)
		win->keys.key_s = 1;
	else if (key == K_D && win->keys.key_d == 0)
		win->keys.key_d = 1;
	else if (key == ARR_LT && win->keys.key_left == 0)
		win->keys.key_left = 1;
	else if (key == ARR_RT && win->keys.key_right == 0)
		win->keys.key_right = 1;
	else if (key == ESC)
	{
		free_all(win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	key_release(int key, t_win *win)
{
	if (key == K_W && win->keys.key_w == 1)
		win->keys.key_w = 0;
	else if (key == K_A && win->keys.key_a == 1)
		win->keys.key_a = 0;
	else if (key == K_S && win->keys.key_s == 1)
		win->keys.key_s = 0;
	else if (key == K_D && win->keys.key_d == 1)
		win->keys.key_d = 0;
	else if (key == ARR_LT && win->keys.key_left == 1)
		win->keys.key_left = 0;
	else if (key == ARR_RT && win->keys.key_right == 1)
		win->keys.key_right = 0;
	else if (key == ESC)
	{
		free_all(win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	game_loop(t_win *win)
{
	raycast(win);
	move_player(win);
	// printf("player x = %f\nplayer y = %f\n", win->player.x, win->player.y);
	// printf("player dir_x = %f\nplayer dir_y = %f\n", win->player.dir_x, win->player.dir_y);
	return (0);
}

void	loops(t_win *win)
{
	mlx_hook(win->win_ptr, 17, 1L << 17, mlx_loop_end, win->mlx_ptr);
	mlx_hook(win->win_ptr, 2, 1L << 0, key_press, win);
	mlx_hook(win->win_ptr, 3, 1L << 1, key_release, win);
	mlx_loop_hook(win->mlx_ptr, game_loop, win);
	mlx_loop(win->mlx_ptr);
}
