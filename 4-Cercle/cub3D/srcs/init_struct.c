/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:28:56 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 19:25:30 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_win_to_zero(t_win *win)
{
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->img = NULL;
	win->key = NULL;
	win->player = NULL;
	win->map = NULL;
	win->sprites = NULL;
}

static void	map_init(t_win *win)
{
	win->map = malloc(sizeof(t_map));
	if (!win->map)
		error(win, MALLOC_ERR);
	win->map->map = malloc(sizeof(char *) * 5);
	if (!win->map->map)
		error(win, MALLOC_ERR);
	win->map->map[0] = malloc(sizeof(char) * 5);
	if (!win->map->map[0])
		error(win, MALLOC_ERR);
	win->map->map[1] = malloc(sizeof(char) * 5);
	if (!win->map->map[1])
		error(win, MALLOC_ERR);
	win->map->map[2] = malloc(sizeof(char) * 5);
	if (!win->map->map[2])
		error(win, MALLOC_ERR);
	win->map->map[3] = malloc(sizeof(char) * 5);
	if (!win->map->map[3])
		error(win, MALLOC_ERR);
	win->map->map[0] = "1111";
	win->map->map[1] = "1001";
	win->map->map[2] = "1001";
	win->map->map[3] = "1111";
	win->map->map[4] = NULL;
	win->map->height = 4;
	win->map->length = 4;
}

static void	win_last_init(t_win *win)
{
	win->tile_size = 16;
	win->win_width = win->map->length * win->tile_size;
	win->win_height = win->map->height * win->tile_size;
	win->num_rays = win->win_width;
}

static void	key_init(t_win *win)
{
	win->key = malloc(sizeof(t_key));
	if (!win->key)
		error(win, MALLOC_ERR);
	win->key->key = 0;
	win->key->pressed = 0;
	win->key->delay = 0;
}

static void	player_init(t_win *win)
{
	win->player = malloc(sizeof(t_player));
	if (!win->player)
		error(win, MALLOC_ERR);
	win->player->x = 0;
	win->player->y = 0;
	win->player->width = 5;
	win->player->height = 5;
	win->player->turn_direction = 0;
	win->player->turn_speed = 0;
	win->player->rotation_angle = M_PI / 2;
	win->player->walk_speed = 100;
	win->player->turn_speed = 45 * (M_PI / 180);
}

static void	sprite_init(t_win *win)
{
	win->sprites = malloc(sizeof(t_sprite *) * 4);
	if (!win->sprites)
		error(win, MALLOC_ERR);
	win->sprites[0] = import_sprite(win, "img/Dirt.xpm");
	win->sprites[1] = import_sprite(win, "img/MinimapEmpty.xpm");
	win->sprites[2] = import_sprite(win, "img/MinimapPlayer.xpm");
	win->sprites[3] = NULL;
}

static void	img_init(t_win *win)
{
	win->img = malloc(sizeof(t_img));
	if (!win->img)
		error(win, MALLOC_ERR);
	win->img->img = mlx_new_image(win->mlx_ptr,
			win->map->length * win->tile_size,
			win->map->height * win->tile_size);
	if (!win->img->img)
		error(win, IMG_ERR);
	win->img->addr = mlx_get_data_addr(win->img->img, &win->img->bpp,
			&win->img->ll, &win->img->endian);
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
	sprite_init(win);
	img_init(win);
	return (win);
}
