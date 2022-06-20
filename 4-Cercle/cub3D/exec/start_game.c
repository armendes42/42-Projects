/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:27:25 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/22 18:13:33 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_window(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (NULL == cub3d->mlx)
		_exit_(NULL, NULL, FAILURE, cub3d);
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (NULL == cub3d->win)
		_exit_(NULL, NULL, FAILURE, cub3d);
}

void	_image(t_cub3d *cub3d)
{
	t_img	*img;

	img = &cub3d->mlx_img;
	img->img_ptr = mlx_new_image(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (NULL == img->img_ptr)
		_exit_(NULL, NULL, FAILURE, cub3d);
	cub3d->mlx_img.addr = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->size, &img->endian);
}

int	window_destroy(t_cub3d *cub3d)
{
	_exit_(NULL, NULL, FAILURE, cub3d);
	return (1);
}

int	_game_loop(t_cub3d *cub3d)
{
	do_raycasting(cub3d);
	key_control(cub3d);
	return (1);
}

void	start_game(t_cub3d *cub3d)
{
	_window(cub3d);
	_image(cub3d);
	player_init(cub3d);
	tex_init(cub3d);
	mlx_hook(cub3d->win, 2, 1L << 0, key_press, cub3d);
	mlx_hook(cub3d->win, 3, 1L << 1, key_release, cub3d);
	mlx_hook(cub3d->win, RED_CROSS, 1L << 2, window_destroy, cub3d);
	mlx_loop_hook(cub3d->mlx, _game_loop, cub3d);
	mlx_loop(cub3d->mlx);
}
