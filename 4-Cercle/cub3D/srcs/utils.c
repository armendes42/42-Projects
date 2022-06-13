/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:25:49 by armendes          #+#    #+#             */
/*   Updated: 2022/06/13 17:46:13 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_pixel(t_sprite *sprite, int x, int y)
{
	char	*pixel;

	pixel = sprite->addr + (y * sprite->ll + x * (sprite->bpp / 8));
	return (*(int *)pixel);
}

static void	draw_pixel(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->img->addr + (y * win->img->ll + x * (win->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_sprite(t_win *win, int y, int x, int index)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < win->sprites[index]->ih)
	{
		j = 0;
		while (j < win->sprites[index]->iw)
		{
			color = get_pixel(win->sprites[index], j, i);
			draw_pixel(win, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
