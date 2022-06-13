/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:05:41 by armendes          #+#    #+#             */
/*   Updated: 2022/06/13 16:16:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player_left(t_win *win)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = win->player.dir_x;
	old_plane_x = win->player.plane_x;
	win->player.dir_x = win->player.dir_x * cos(-win->player.rot_speed)
		- win->player.dir_y * sin(-win->player.rot_speed);
	win->player.dir_y = old_dir_x * sin(-win->player.rot_speed)
		+ win->player.dir_y * cos(-win->player.rot_speed);
	win->player.plane_x = win->player.plane_x
		* cos(-win->player.rot_speed) - win->player.plane_y
		* sin(-win->player.rot_speed);
	win->player.plane_y = old_plane_x * sin(-win->player.rot_speed)
		+ win->player.plane_y * cos(-win->player.rot_speed);
}

void	rotate_player_right(t_win *win)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = win->player.dir_x;
	old_plane_x = win->player.plane_x;
	win->player.dir_x = win->player.dir_x * cos(win->player.rot_speed)
		- win->player.dir_y * sin(win->player.rot_speed);
	win->player.dir_y = old_dir_x * sin(win->player.rot_speed)
		+ win->player.dir_y * cos(win->player.rot_speed);
	win->player.plane_x = win->player.plane_x * cos(win->player.rot_speed)
		- win->player.plane_y * sin(win->player.rot_speed);
	win->player.plane_y = old_plane_x * sin(win->player.rot_speed)
		+ win->player.plane_y * cos(win->player.rot_speed);
}
