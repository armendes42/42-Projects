/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:22:09 by armendes          #+#    #+#             */
/*   Updated: 2022/06/13 16:16:08 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move_player_w(t_win *win)
{
	if (win->map.map[(int)win->player.y]
		[(int)(win->player.x + win->player.dir_x
			* win->player.walk_speed * 2)] == '0')
		win->player.x += win->player.dir_x * win->player.walk_speed;
	if (win->map.map[(int)(win->player.y + win->player.dir_y
			* win->player.walk_speed * 2)][(int)win->player.x] == '0')
		win->player.y += win->player.dir_y * win->player.walk_speed;
}

static void	move_player_a(t_win *win)
{
	if (win->map.map[(int)win->player.y]
		[(int)(win->player.x - win->player.plane_x
			* win->player.walk_speed * 2)] == '0')
		win->player.x -= win->player.plane_x * win->player.walk_speed;
	if (win->map.map[(int)(win->player.y - win->player.plane_y
			* win->player.walk_speed * 2)][(int)win->player.x] == '0')
		win->player.y -= win->player.plane_y * win->player.walk_speed;
}

static void	move_player_s(t_win *win)
{
	if (win->map.map[(int)win->player.y]
		[(int)(win->player.x - win->player.dir_x
			* win->player.walk_speed * 2)] == '0')
		win->player.x -= win->player.dir_x * win->player.walk_speed;
	if (win->map.map[(int)(win->player.y - win->player.dir_y
			* win->player.walk_speed * 2)][(int)win->player.x] == '0')
		win->player.y -= win->player.dir_y * win->player.walk_speed;
}

static void	move_player_d(t_win *win)
{
	if (win->map.map[(int)win->player.y]
		[(int)(win->player.x + win->player.plane_x
			* win->player.walk_speed * 2)] == '0')
		win->player.x += win->player.plane_x * win->player.walk_speed;
	if (win->map.map[(int)(win->player.y + win->player.plane_y
			* win->player.walk_speed * 2)]
			[(int)win->player.x] == '0')
		win->player.y += win->player.plane_y * win->player.walk_speed;
}

void	move_player(t_win *win)
{
	if (win->keys.key_w == 1)
		move_player_w(win);
	if (win->keys.key_a == 1)
		move_player_a(win);
	if (win->keys.key_s == 1)
		move_player_s(win);
	if (win->keys.key_d == 1)
		move_player_d(win);
	if (win->keys.key_left == 1)
		rotate_player_left(win);
	if (win->keys.key_right == 1)
		rotate_player_right(win);
}
