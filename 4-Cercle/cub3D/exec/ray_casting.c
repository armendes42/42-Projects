/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:17:34 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 15:14:23 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raycasting_init(t_raycast*ray, t_player *player)
{
	ray->camerax = 2 * ray->pix / (double)WIN_WIDTH - 1;
	ray->raydir_x = player->dir_x + (player->plane_x * ray->camerax);
	ray->raydir_y = player->dir_y + (player->plane_y * ray->camerax);
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->hit = 0;
}

static void	ft_raycasting(t_raycast *ray, t_cub3d *cub3d)
{
	raycasting_init(ray, &cub3d->player);
	sidedist_init(ray, &cub3d->player);
	hit_wall(ray, cub3d);
	set_perpwalldist(ray, &cub3d->player);
	set_lineheight(ray);
	set_drawinfo(ray, &cub3d->player);
	drawing(ray, cub3d);
}

void	do_raycasting(t_cub3d *cub3d)
{
	t_raycast	ray;

	ft_bzero(&ray, sizeof(t_raycast));
	while (ray.pix < WIN_WIDTH)
	{
		ft_raycasting(&ray, cub3d);
		++ray.pix;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win,
		cub3d->mlx_img.img_ptr, 0, 0);
}
