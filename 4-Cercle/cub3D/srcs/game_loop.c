/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:56:10 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 19:05:34 by armendes         ###   ########.fr       */
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
				draw_sprite(win, i * win->tile_size, j * win->tile_size, 0);
			else
				draw_sprite(win, i * win->tile_size, j * win->tile_size, 1);
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
	return (0);
}
