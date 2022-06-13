/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:38:34 by armendes          #+#    #+#             */
/*   Updated: 2022/06/13 17:39:37 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	color_vertic(t_line *line, unsigned int const color, t_win *win)
{
	line->line_y = line->start;
	if (line->line_y >= 0)
	{
		while (line->line_y < line->end)
		{
			ft_memcpy(win->mlx_img.addr + line->line_y * win->mlx_img.size
				+ line->line_x * (win->mlx_img.bpp / 8), &color,
				sizeof(unsigned int));
			++line->line_y;
		}
	}
}

void	text_vertic(t_line *line, t_img text, t_ray *ray, t_win *win)
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
			ft_memcpy(win->mlx_img.addr + (line->line_y * win->mlx_img.size)
				+ (line->line_x * (win->mlx_img.bpp / 8)),
				text.addr + (line->tex_y * text.size)
				+ (line->tex_x * (text.bpp / 8)),
				sizeof(unsigned int));
			++line->line_y;
		}
	}
}
