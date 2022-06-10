/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:56:10 by armendes          #+#    #+#             */
/*   Updated: 2022/06/10 17:59:58 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	update(t_win *win)
// {
//
// }

static void	render_map(t_win *win)
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
				draw_sprite(win, i * win->sprite_size, j * win->sprite_size, 0);
			else
				draw_sprite(win, i * win->sprite_size, j * win->sprite_size, 1);
		}
	}
}

static bool	has_wall_at(t_win *win, float x, float y)
{
	int map_index_x;
	int map_index_y;

	if (x < 0 || x > win->map->length * win->sprite_size || y < 0 || y > win->map->height * win->sprite_size)
		return (true);
	printf("0");
	map_index_x = floor(x);
	map_index_y = floor(y);
	printf("\nx=%d y=%d\n", map_index_x, map_index_y);
	printf("\nx=%f y=%f\n", x, y);
	if (win->map->map[map_index_y][map_index_x] == '1')
		return (true);
	return (false);
}

void	get_player_pos(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	while (win->map->map[++i])
	{
		j = -1;
		while (win->map->map[i][++j])
		{
			if (win->map->map[i][j] == 'P')
			{
				win->player->x = j;
				win->player->y = i;
			}
		}
	}
}

static void	update_for_player(t_win *win)
{
	if (win->key->key == K_W)
		win->player->walk_direction = +1;
	if (win->key->key == ARR_LT)
		win->player->turn_direction = -1;
	if (win->key->key == K_S)
		win->player->walk_direction = -1;
	if (win->key->key == ARR_RT)
		win->player->turn_direction = +1;
}

static void	move_player(t_win *win)
{
	float	move_step;
	float	new_player_x;
	float	new_player_y;

	printf("b");
	update_for_player(win);
	win->player->rotation_angle += win->player->turn_direction
			* win->player->turn_speed;
	move_step = win->player->walk_direction * win->player->walk_speed;
	new_player_x = win->player->x * cos(win->player->rotation_angle) * move_step;
	new_player_y = win->player->y * sin(win->player->rotation_angle) * move_step;
	printf("a");
	if (!has_wall_at(win, win->player->x, win->player->y))
	{
		win->player->x += new_player_x;
		printf("%f", win->player->x);
		win->player->y += new_player_y;
		printf("%f", win->player->y);
	}
}

static void	render_player(t_win *win)
{
	if (win->key->pressed && win->key->delay == 0)
	{
		printf("c");
		move_player(win);
		win->key->delay = 250;
	}
	if (win->key->pressed)
		win->key->delay--;
	// draw_sprite(win, win->player->y * win->sprite_size,
	// 	win->player->x * win->sprite_size, 2);
}

// static void	render_rays(t_win *win)
// {
//
// }

static void	render(t_win *win)
{
	render_map(win);
	// render_rays(win);
	render_player(win);
}

int	game_loop(t_win *win)
{
	// update(win);
	render(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img, 0, 0);
	return (0);
}
