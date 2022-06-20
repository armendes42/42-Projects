/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:21:11 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 14:18:54 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move_w(t_cub3d *cub3d)
{
	if (cub3d->mapinfo.map[(int)cub3d->player.pos_y]
		[(int)(cub3d->player.pos_x + cub3d->player.dir_x
			* cub3d->player.speed * 2)] == '0')
		cub3d->player.pos_x += cub3d->player.dir_x * cub3d->player.speed;
	if (cub3d->mapinfo.map[(int)(cub3d->player.pos_y + cub3d->player.dir_y
			* cub3d->player.speed * 2)][(int)cub3d->player.pos_x] == '0')
		cub3d->player.pos_y += cub3d->player.dir_y * cub3d->player.speed;
}

void	player_move_s(t_cub3d *cub3d)
{
	if (cub3d->mapinfo.map[(int)cub3d->player.pos_y]
		[(int)(cub3d->player.pos_x - cub3d->player.dir_x
			* cub3d->player.speed * 2)] == '0')
		cub3d->player.pos_x -= cub3d->player.dir_x * cub3d->player.speed;
	if (cub3d->mapinfo.map[(int)(cub3d->player.pos_y - cub3d->player.dir_y
			* cub3d->player.speed * 2)][(int)cub3d->player.pos_x] == '0')
		cub3d->player.pos_y -= cub3d->player.dir_y * cub3d->player.speed;
}

void	player_move_a(t_cub3d *cub3d)
{
	if (cub3d->mapinfo.map[(int)cub3d->player.pos_y]
		[(int)(cub3d->player.pos_x - cub3d->player.plane_x
			* cub3d->player.speed * 2)] == '0')
		cub3d->player.pos_x -= cub3d->player.plane_x
			* cub3d->player.speed;
	if (cub3d->mapinfo.map[(int)(cub3d->player.pos_y - cub3d->player.plane_y
			* cub3d->player.speed * 2)][(int)cub3d->player.pos_x] == '0')
		cub3d->player.pos_y -= cub3d->player.plane_y * cub3d->player.speed;
}

void	player_move_d(t_cub3d *cub3d)
{
	if (cub3d->mapinfo.map[(int)cub3d->player.pos_y]
		[(int)(cub3d->player.pos_x + cub3d->player.plane_x
			* cub3d->player.speed * 2)] == '0')
		cub3d->player.pos_x += cub3d->player.plane_x * cub3d->player.speed;
	if (cub3d->mapinfo.map[(int)(cub3d->player.pos_y + cub3d->player.plane_y
			* cub3d->player.speed * 2)]
			[(int)cub3d->player.pos_x] == '0')
		cub3d->player.pos_y += cub3d->player.plane_y * cub3d->player.speed;
}
