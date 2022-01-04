/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:30:56 by armendes          #+#    #+#             */
/*   Updated: 2021/12/23 19:28:12 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_win *win)
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
				draw_sprite(win, i * 16, j * 16, 1);
			else
				draw_sprite(win, i * 16, j * 16, 0);
		}
	}
}
