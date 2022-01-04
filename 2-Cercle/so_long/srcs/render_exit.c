/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:48:59 by armendes          #+#    #+#             */
/*   Updated: 2021/12/23 19:27:56 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_exit(char **map)
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
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	set_exit(t_exit *exit, int i, int j)
{
	exit->x = j;
	exit->y = i;
	exit->open = 0;
}

void	get_exit(t_win *win)
{
	int	i;
	int	j;
	int	k;

	win->nb_exit = count_exit(win->map->map);
	win->exit = malloc(sizeof(t_exit) * (win->nb_exit));
	if (win->exit == NULL)
		error(win, MALLOC_ERR);
	i = -1;
	k = 0;
	while (win->map->map[++i])
	{
		j = -1;
		while (win->map->map[i][++j])
		{
			if (win->map->map[i][j] == 'E')
			{
				set_exit(&(win->exit[k]), i, j);
				k++;
			}
		}
	}
}

void	render_exit(t_win *win)
{
	int	i;

	i = 0;
	if (win->nb_coll == 0)
	{
		while (i < win->nb_exit)
		{
			win->exit[i].open = 1;
			i++;
		}
	}
	i = 0;
	while (i < win->nb_exit)
	{
		draw_sprite(win, win->exit[i].y * 16, win->exit[i].x * 16, 3);
		i++;
	}
}
