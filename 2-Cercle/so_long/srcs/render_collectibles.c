/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:12:38 by armendes          #+#    #+#             */
/*   Updated: 2022/01/28 15:44:26 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	set_collectible(t_collectible *coll, int i, int j)
{
	coll->x = j;
	coll->y = i;
	coll->picked = 0;
	coll->last = 0;
}

void	get_collectibles(t_win *win)
{
	int	i;
	int	j;
	int	k;

	win->nb_coll = count_collectibles(win->map->map);
	win->collectibles = malloc(sizeof(t_collectible) * (win->nb_coll + 1));
	if (win->collectibles == NULL)
		error(win, MALLOC_ERR);
	i = -1;
	k = 0;
	while (win->map->map[++i] != NULL)
	{
		j = -1;
		while (win->map->map[i][++j])
		{
			if (win->map->map[i][j] == 'C')
			{
				set_collectible(&win->collectibles[k], i, j);
				k++;
			}
		}
	}
	win->collectibles[k].last = 1;
}

void	render_collectibles(t_win *win)
{
	int	i;

	i = 0;
	while (win->collectibles[i].last < 1)
	{
		if (win->collectibles[i].picked == 0)
			draw_sprite(win, win->collectibles[i].y * 16,
				win->collectibles[i].x * 16, 2);
		i++;
	}
}
