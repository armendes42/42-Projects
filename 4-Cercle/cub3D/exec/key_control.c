/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:13:31 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 13:08:37 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_ESC)
		_exit_(NULL, NULL, SUCCESS, cub3d);
	else if (keycode == KEY_W && cub3d->key.w == 0)
		cub3d->key.w = 1;
	else if (keycode == KEY_A && cub3d->key.a == 0)
		cub3d->key.a = 1;
	else if (keycode == KEY_S && cub3d->key.s == 0)
		cub3d->key.s = 1;
	else if (keycode == KEY_D && cub3d->key.d == 0)
		cub3d->key.d = 1;
	else if (keycode == KEY_LEFT && cub3d->key.left == 0)
		cub3d->key.left = 1;
	else if (keycode == KEY_RIGHT && cub3d->key.right == 0)
		cub3d->key.right = 1;
	return (1);
}

int	key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_ESC)
		_exit_(NULL, NULL, SUCCESS, cub3d);
	else if (keycode == KEY_W && cub3d->key.w == 1)
		cub3d->key.w = 0;
	else if (keycode == KEY_A && cub3d->key.a == 1)
		cub3d->key.a = 0;
	else if (keycode == KEY_S && cub3d->key.s == 1)
		cub3d->key.s = 0;
	else if (keycode == KEY_D && cub3d->key.d == 1)
		cub3d->key.d = 0;
	else if (keycode == KEY_LEFT && cub3d->key.left == 1)
		cub3d->key.left = 0;
	else if (keycode == KEY_RIGHT && cub3d->key.right == 1)
		cub3d->key.right = 0;
	return (1);
}

void	key_control(t_cub3d *cub3d)
{
	if (cub3d->key.w == 1)
		player_move_w(cub3d);
	if (cub3d->key.s == 1)
		player_move_s(cub3d);
	if (cub3d->key.a == 1)
		player_move_a(cub3d);
	if (cub3d->key.d == 1)
		player_move_d(cub3d);
	if (cub3d->key.left == 1)
		player_rotate_left(cub3d);
	if (cub3d->key.right == 1)
		player_rotate_right(cub3d);
}
