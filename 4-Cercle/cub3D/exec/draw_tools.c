/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:02:17 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 12:56:47 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_vertic(t_line *line, unsigned int const color, t_cub3d *cub3d)
{
	line->line_y = line->start;
	if (line->line_y >= 0)
	{
		while (line->line_y < line->end)
		{
			ft_memcpy(cub3d->mlx_img.addr + line->line_y * cub3d->mlx_img.size
				+ line->line_x * (cub3d->mlx_img.bpp / 8), &color,
				sizeof(unsigned int));
			++line->line_y;
		}
	}
}

void	text_vertic(t_line *line, t_img text, t_raycast *ray, t_cub3d *cub3d)
{
	double	step;
	double	tex_pos;

	line->line_y = line->start;
	step = (double)text.height / (double)ray->line_height;
	tex_pos = (line->line_y - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	if (line->line_y >= 0)
	{
		while (line->line_y < line->end)
		{
			line->tex_y = (int)tex_pos;
			tex_pos += step;
			ft_memcpy(cub3d->mlx_img.addr + (line->line_y * cub3d->mlx_img.size)
				+ (line->line_x * (cub3d->mlx_img.bpp / 8)),
				text.addr + (line->tex_y * text.size)
				+ (line->tex_x * (text.bpp / 8)),
				sizeof(unsigned int));
			++line->line_y;
		}
	}
}
