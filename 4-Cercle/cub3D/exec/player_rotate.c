/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:56:51 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 14:23:59 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_rotate_left(t_cub3d *cub3d)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = cub3d->player.dir_x;
	old_plane_x = cub3d->player.plane_x;
	cub3d->player.dir_x = cub3d->player.dir_x * cos(-cub3d->player.rot_speed)
		- cub3d->player.dir_y * sin(-cub3d->player.rot_speed);
	cub3d->player.dir_y = old_dir_x * sin(-cub3d->player.rot_speed)
		+ cub3d->player.dir_y * cos(-cub3d->player.rot_speed);
	cub3d->player.plane_x = cub3d->player.plane_x
		* cos(-cub3d->player.rot_speed) - cub3d->player.plane_y
		* sin(-cub3d->player.rot_speed);
	cub3d->player.plane_y = old_plane_x * sin(-cub3d->player.rot_speed)
		+ cub3d->player.plane_y * cos(-cub3d->player.rot_speed);
}

void	player_rotate_right(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->player.dir_x;
	old_plane_x = cub3d->player.plane_x;
	cub3d->player.dir_x = cub3d->player.dir_x * cos(cub3d->player.rot_speed)
		- cub3d->player.dir_y * sin(cub3d->player.rot_speed);
	cub3d->player.dir_y = old_dir_x * sin(cub3d->player.rot_speed)
		+ cub3d->player.dir_y * cos(cub3d->player.rot_speed);
	cub3d->player.plane_x = cub3d->player.plane_x * cos(cub3d->player.rot_speed)
		- cub3d->player.plane_y * sin(cub3d->player.rot_speed);
	cub3d->player.plane_y = old_plane_x * sin(cub3d->player.rot_speed)
		+ cub3d->player.plane_y * cos(cub3d->player.rot_speed);
}
