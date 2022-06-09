/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:28:56 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 17:58:37 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_win_to_zero(t_win *win)
{
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->key = NULL;
	win->player = NULL;
	win->map = NULL;
}

static void	key_init(t_win *win)
{
	win->key = malloc(sizeof(t_key));
	if (win->key == NULL)
		error(win, MALLOC_ERR);
	win->key->key = 0;
	win->key->pressed = 0;
	win->key->delay = 0;
}

static void	player_init(t_win *win)
{
	win->player = malloc(sizeof(t_player));
	if (win->player == NULL)
		error(win, MALLOC_ERR);
	win->player->x = 0;
	win->player->y = 0;
	win->player->width = 0;
	win->player->height = 0;
	win->player->turn_direction = 0;
	win->player->turn_speed = 0;
	win->player->rotation_angle = 0;
	win->player->walk_speed = 0;
	win->player->turn_speed = 0;
}

static void	map_init(t_win *win)
{
	win->map = malloc(sizeof(t_map));
	if (!win->map)
		error(win, MALLOC_ERR);
	win->map->map = malloc(sizeof(char *) * 4);
	if (!win->map->map)
		error(win, MALLOC_ERR);
	win->map->map[0] = "1111";
	win->map->map[1] = "1001";
	win->map->map[2] = "1001";
	win->map->map[3] = "1111";
	win->map->height = 4;
	win->map->length = 4;
}

static void	win_last_init(t_win *win)
{
	win->tile_size = 64;
	win->win_width = win->map->length * win->tile_size;
	win->win_height = win->map->height * win->tile_size;
	win->num_rays = win->win_width;
}

t_win	*initialize_window(char **av)
{
	t_win	*win;

	(void)av;
	win = malloc(sizeof(t_win));
	if (!win)
		error(win, MALLOC_ERR);
	set_win_to_zero(win);
	//parsing of map

	map_init(win);

	//end of false parsing
	win_last_init(win);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		error(win, MALLOC_ERR);
	win->win_ptr = mlx_new_window(win->mlx_ptr,
			win->win_width, win->win_height, "cub3D");
	if (!win->win_ptr)
		error(win, MALLOC_ERR);
	key_init(win);
	player_init(win);
	return (win);
}
