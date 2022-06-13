/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:28:56 by armendes          #+#    #+#             */
/*   Updated: 2022/06/13 16:27:46 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_win_to_zero(t_win *win)
{
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->img = NULL;
	win->sprites = NULL;
}

static void	map_init(t_win *win)
{
	win->map.map = malloc(sizeof(char *) * 5);
	if (!win->map.map)
		error(win, MALLOC_ERR);
	win->map.map[0] = "1111111111111";
	win->map.map[1] = "1000000100001";
	win->map.map[2] = "100100000P001";
	win->map.map[3] = "1111111111111";
	win->map.map[4] = 0;
	win->map.height = 4;
	win->map.length = 13;
}

static void	win_last_init(t_win *win)
{
	win->tile_size = 16;
	win->sprite_size = 16;
	win->num_rays = WIN_WIDTH;
}

static void	player_init(t_win *win)
{
	win->player.x = 0.0;
	win->player.y = 0.0;
	win->player.rot_speed = 0.0;
	win->player.rot_angle = M_PI / 2;
	win->player.walk_speed = 0.10;
	win->player.rot_speed = 45 * (M_PI / 180);
	win->player.dir_x = 0.0;
	win->player.dir_y = -1.0;
	win->player.plane_x = 0.66;
	win->player.plane_y = 0.0;
}

static void	sprite_init(t_win *win)
{
	win->sprites = malloc(sizeof(t_sprite *) * 4);
	if (!win->sprites)
		error(win, MALLOC_ERR);
	win->sprites[0] = import_sprite(win, "img/MinimapWall.xpm");
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
			win->map.length * win->tile_size,
			win->map.height * win->tile_size);
	if (!win->img->img)
		error(win, IMG_ERR);
	win->img->addr = mlx_get_data_addr(win->img->img, &win->img->bpp,
			&win->img->ll, &win->img->endian);
}

static void	keys_init(t_win *win)
{
	win->keys.key_w = 0;
	win->keys.key_a = 0;
	win->keys.key_s = 0;
	win->keys.key_d = 0;
	win->keys.key_left = 0;
	win->keys.key_right = 0;
}

static void	get_player_pos(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	while (win->map.map[++i])
	{
		j = -1;
		while (win->map.map[i][++j])
		{
			if (win->map.map[i][j] == 'P')
			{
				win->player.x = j;
				win->player.y = i;
				printf("\nx=%d y=%d\n", i, j);
			}
		}
	}
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
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!win->win_ptr)
		error(win, MALLOC_ERR);
	keys_init(win);
	player_init(win);
	get_player_pos(win);
	sprite_init(win);
	img_init(win);
	return (win);
}
