/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:56:10 by armendes          #+#    #+#             */
/*   Updated: 2022/06/10 15:07:07 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	update(t_win *win)
// {
// 	(void)win;
// }

static void	render_map(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	while (win->map->map[++i])
	{
		j = -1;
		while (win->map->map[i][++j])
		{
			if (win->map->map[i][j] == '1')
				draw_sprite(win, i * win->sprite_size * MINIMAP_SCALE_FACTOR,
						j * win->sprite_size * MINIMAP_SCALE_FACTOR, 0);
			else
				draw_sprite(win, i * win->sprite_size * MINIMAP_SCALE_FACTOR,
						j * win->sprite_size * MINIMAP_SCALE_FACTOR, 1);
		}
	}
}

// static void	render_rays(t_win *win)
// {
//
// }
//
// static void	render_player(t_win *win)
// {
//
// }

static void	render(t_win *win)
{
	render_map(win);
	// render_rays(win);
	// render_player(win);
}

int	game_loop(t_win *win)
{
	// update(win);
	render(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img, 0, 0);
	return (0);
}
