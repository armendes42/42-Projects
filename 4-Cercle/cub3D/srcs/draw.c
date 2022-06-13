/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:35:28 by armendes          #+#    #+#             */
/*   Updated: 2022/06/13 17:38:11 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_side(t_line *line, double wall_x,
		t_ray *ray, t_win *win)
{
	t_img const	tex_view_by_player[TEXTURE_MAX] = {
		win->tex_img[e_EA],
		win->tex_img[e_WE],
		win->tex_img[e_SO],
		win->tex_img[e_NO]
	};
	int			tex_x;
	t_img		tex;
	int			i;

	tex = tex_view_by_player[e_NO];
	i = 0;
	while (++i < TEXTURE_MAX)
		if (i == ray->side)
			tex = tex_view_by_player[i];
	tex_x = (int)(wall_x * (double)tex.width);
	if ((ray->side == 0 || ray->side == 1) && ray->raydir_x > 0)
		tex_x = tex.width - tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->raydir_y < 0)
		tex_x = tex.width - tex_x - 1;
	line->start = ray->draw_start;
	line->end = ray->draw_end;
	line->tex_x = tex_x;
	text_vertic(line, tex, ray, win);
}

uint32_t	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static void	draw_ceiling_floor(t_line *line, t_ray *ray, t_win *win)
{
	unsigned char const	*c = win->map.c_couleur;
	unsigned char const	*f = win->map.f_couleur;

	line->start = 0;
	line->end = ray->draw_start;
	color_vertic(line, create_rgb(c[0], c[1], c[2]), win);
	line->start = ray->draw_end;
	line->end = WIN_HEIGHT;
	color_vertic(line, create_rgb(f[0], f[1], f[2]), win);
}

void	drawing(t_ray *ray, t_win *win)
{
	t_line			line;
	double			wall_x;

	ft_bzero(&line, sizeof(t_line));
	line.line_x = ray->pixel;
	if (ray->side == 0 || ray->side == 1)
		wall_x = win->player.y + ray->perpwalldist * ray->raydir_y;
	else
		wall_x = win->player.x + ray->perpwalldist * ray->raydir_x;
	wall_x -= floor(wall_x);
	if (cub3d->map.map[ray->map_y][ray->map_x] == '1')
		draw_side(&line, wall_x, ray, win);
	draw_ceiling_floor(&line, ray, win);
}
