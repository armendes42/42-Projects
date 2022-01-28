/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:26:12 by armendes          #+#    #+#             */
/*   Updated: 2022/01/28 15:55:51 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_sprites(t_sprite **sprite, t_win *win)
{
	int		text;
	int		min;

	min = -1;
	text = 5;
	while (++min < text)
	{
		mlx_destroy_image(win->mlx_ptr, sprite[min]->img);
		free(sprite[min]);
	}
	free(sprite);
}

static void	free_map(t_map *map)
{
	char	**tmp;
	int		i;

	tmp = map->map;
	i = 0;
	if (map->map)
	{
		while (i < map->height)
		{
			free(tmp[i]);
			i++;
		}
		free(map->map);
	}
}

static void	free_coll(t_win *win, t_collectible **coll)
{
	int	i;

	i = -1;
	while (++i < win->nb_coll)
	{
		free(coll[i]);
	}
	free(win->collectibles);
}

void	free_all(t_win *win)
{
	if (win->collectibles)
		free_coll(win, &(win->collectibles));
	if (win->map)
	{
		free_map(win->map);
		free(win->map);
	}
	if (win->exit)
		free(win->exit);
	if (win->sprites)
		free_sprites(win->sprites, win);
	if (win->img)
	{
		mlx_destroy_image(win->mlx_ptr, win->img->img);
		free(win->img);
	}
	if (win->player)
		free(win->player);
	if (win->key)
		free(win->key);
	if (win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->mlx_ptr)
		mlx_destroy_display(win->mlx_ptr);
}

void	error(t_win *win, char *err_msg)
{
	if (win)
		free_all(win);
	free(win);
	printf("Error : %s", err_msg);
	exit(EXIT_FAILURE);
}
