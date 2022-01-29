/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:29:06 by armendes          #+#    #+#             */
/*   Updated: 2022/01/29 17:46:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_all(t_win *win)
{
	int	i;

	render_map(win);
	render_collectibles(win);
	render_exit(win);
	render_player(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img, 0, 0);
	render_move_counter(win);
	i = 0;
	while (i < win->nb_exit)
	{
		if (win->exit[i].x == win->player->x
			&& win->exit[i].y == win->player->y && win->nb_coll == 0)
		{
			free_all(win);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	return (0);
}
