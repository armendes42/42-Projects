/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:26:12 by armendes          #+#    #+#             */
/*   Updated: 2022/01/25 17:48:30 by armendes         ###   ########.fr       */
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
		printf("gate 11\n");
		mlx_destroy_image(win->mlx_ptr, sprite[min]->img);
		printf("gate 12\n");
		// Check if need to free addr
		free(sprite[min]);
	}
	free(sprite);
}

static void	free_map(t_map *map)
{
	char	**tmp;

	tmp = map->map;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(map->map);
	free(map);
}

void	free_all(t_win *win)
{
	if (win->collectibles)
		free(win->collectibles);
	if (win->map)
		free_map(win->map);
	if (win->exit)
		free(exit);
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
	// mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	free(win);
}


void	error(t_win *win, char *err_msg)
{
	free_all(win);
	printf("Error : %s", err_msg);
	exit(EXIT_FAILURE);
}
