/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:33:53 by armendes          #+#    #+#             */
/*   Updated: 2022/01/29 17:45:04 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_win_to_zero(t_win *win)
{
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->map = NULL;
	win->player = NULL;
	win->sprites = NULL;
	win->collectibles = NULL;
	win->img = NULL;
	win->exit = NULL;
	win->key = NULL;
	win->nb_coll = 0;
	win->nb_exit = 0;
	win->nb_moves = 0;
}

static void	map_init(t_win *win)
{
	win->map = malloc(sizeof(t_map));
	if (win->map == NULL)
		error(win, MALLOC_ERR);
	win->map->map = NULL;
	win->map->height = 0;
	win->map->length = 0;
}

static void	player_init(t_win *win)
{
	win->player = malloc(sizeof(t_player));
	if (win->player == NULL)
		error(win, MALLOC_ERR);
	win->player->x = 0;
	win->player->y = 0;
	win->player->coll = 0;
}

static void	sprite_init(t_win *win)
{
	win->sprites = malloc(sizeof(t_sprite *) * 6);
	if (win->sprites == NULL)
		error(win, MALLOC_ERR);
	win->sprites[0] = import_sprite(win, "images/sol.xpm");
	win->sprites[1] = import_sprite(win, "images/Dirt.xpm");
	win->sprites[2] = import_sprite(win, "images/gold.xpm");
	win->sprites[3] = import_sprite(win, "images/exit.xpm");
	win->sprites[4] = import_sprite(win, "images/player.xpm");
	win->sprites[5] = NULL;
}

t_win	*win_init(char **av)
{
	t_win	*win;

	win = malloc(sizeof(t_win));
	if (win == NULL)
		error(win, MALLOC_ERR);
	set_win_to_zero(win);
	map_init(win);
	get_map_info(av[1], win);
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		error(win, MALLOC_ERR);
	win->win_ptr = mlx_new_window(win->mlx_ptr,
			win->map->length * 16, win->map->height * 16, "so_long");
	if (win->win_ptr == NULL)
		error(win, MALLOC_ERR);
	player_init(win);
	sprite_init(win);
	key_init(win);
	img_init(win);
	return (win);
}
