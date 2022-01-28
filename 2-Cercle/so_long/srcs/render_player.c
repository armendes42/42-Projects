/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:26:59 by armendes          #+#    #+#             */
/*   Updated: 2022/01/28 15:47:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->map->map[i])
	{
		j = 0;
		while (win->map->map[i][j])
		{
			if (win->map->map[i][j] == 'P')
			{
				win->player->x = j;
				win->player->y = i;
				win->player->coll = 0;
			}
			j++;
		}
		i++;
	}
}

static void	pick_collectible(t_win *win)
{
	int	x;
	int	y;
	int	i;

	x = win->player->x;
	y = win->player->y;
	i = 0;
	if (win->map->map[y][x] == 'C')
	{
		while (win->collectibles[i].last < 1)
		{
			if (win->collectibles[i].x == x && win->collectibles[i].y == y
				&& win->collectibles[i].picked == 0)
			{
				win->collectibles[i].picked = 1;
				win->nb_coll -= 1;
			}
			i++;
		}
	}
}

static void	move_player(int key, t_win *win, int x, int y)
{
	if (key == K_W && win->map->map[y - 1][x] != '1')
	{
		win->player->y--;
		win->nb_moves++;
	}
	if (key == K_A && win->map->map[y][x - 1] != '1')
	{
		win->player->x--;
		win->nb_moves++;
	}
	if (key == K_S && win->map->map[y + 1][x] != '1')
	{
		win->player->y++;
		win->nb_moves++;
	}
	if (key == K_D && win->map->map[y][x + 1] != '1')
	{
		win->player->x++;
		win->nb_moves++;
	}
	pick_collectible(win);
}

void	render_player(t_win *win)
{
	if (win->key->pressed && win->key->delay == 0)
	{
		move_player(win->key->key, win, win->player->x, win->player->y);
		win->key->delay = 250;
	}
	if (win->key->pressed)
		win->key->delay--;
	draw_sprite(win, win->player->y * 16, win->player->x * 16, 4);
}

void	render_move_counter(t_win *win)
{
	char	*str_move;
	char	*tmp;

	tmp = ft_itoa(win->nb_moves);
	str_move = ft_strjoin("Moves : ", tmp);
	free(tmp);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 16, 16, trgb(255, 255, 0, 0),
		str_move);
	free(str_move);
}
