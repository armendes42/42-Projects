/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:23:37 by armendes          #+#    #+#             */
/*   Updated: 2022/06/13 17:41:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	sidedist_init(t_ray *ray, t_win *win)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (win->player.x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - win->player.x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (win->player.y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - win->player.y) * ray->deltadist_y;
	}
}

static void	hit_wall(t_ray *ray, t_win *win)
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
		if (win->map.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static void	set_perpwalldist(t_ray *ray, t_win *win)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perpwalldist = (ray->map_x - win->player.x
				+ (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - win->player.y
				+ (1 - ray->step_y) / 2) / ray->raydir_y;
}

static void	set_lineheight(t_ray *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perpwalldist);
}

static void	set_drawinfo(t_ray *ray, t_win *win)
{
	ray->draw_start = (-ray->line_height / 2 + ((WIN_HEIGHT / 2)
				* win->player.cam_height));
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2 + ((WIN_HEIGHT / 2)
				* win->player.cam_height));
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT;
}

static void	raycasting_init(t_ray *ray, t_win *win)
{
	ray->camera = 2 * ray->pixel / (double)WIN_WIDTH - 1;
	ray->raydir_x = win->player.dir_x + (win->player.plane_x * ray->camera);
	ray->raydir_y = win->player.dir_y + (win->player.plane_y * ray->camera);
	ray->map_x = (int)win->player.x;
	ray->map_y = (int)win->player.y;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->hit = 0;
}

static void	raycasting(t_ray *ray, t_win *win)
{
	raycasting_init(ray, win);
	sidedist_init(ray, win);
	hit_wall(ray, win);
	set_perpwalldist(ray, win);
	set_lineheight(ray);
	set_drawinfo(ray, win);
	drawing(ray, win);
}

void	raycast(t_win *win)
{
	t_ray	ray;

	ft_bzero(&ray, sizeof(t_ray));
	while (ray.pixel < WIN_WIDTH)
	{
		raycasting(&ray, win);
		ray.pixel++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img, 0, 0);
}
