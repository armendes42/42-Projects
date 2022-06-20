/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:03:29 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 14:38:22 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sidedist_init(t_raycast *ray, t_player *player)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

void	hit_wall(t_raycast *ray, t_cub3d *cub3d)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = e_NO;
			else if (ray->step_x == -1)
				ray->side = e_SO;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = e_WE;
			else if (ray->step_y == -1)
				ray->side = e_EA;
		}
		if (cub3d->mapinfo.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	set_perpwalldist(t_raycast *ray, t_player *player)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perpwalldist = (ray->map_x - player->pos_x
				+ (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - player->pos_y
				+ (1 - ray->step_y) / 2) / ray->raydir_y;
}

void	set_lineheight(t_raycast *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perpwalldist);
}

void	set_drawinfo(t_raycast *ray, t_player *player)
{
	ray->draw_start = (-ray->line_height / 2 + ((WIN_HEIGHT / 2)
				* player->cam_height));
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2 + ((WIN_HEIGHT / 2)
				* player->cam_height));
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT;
}
