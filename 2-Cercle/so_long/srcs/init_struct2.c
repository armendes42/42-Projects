/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:55:19 by armendes          #+#    #+#             */
/*   Updated: 2022/01/26 16:34:44 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_init(t_win *win)
{
	win->key = malloc(sizeof(t_key));
	if (win->key == NULL)
		error(win, MALLOC_ERR);
	win->key->key = 0;
	win->key->pressed = 0;
	win->key->delay = 0;
}

void	img_init(t_win *win)
{
	win->img = malloc(sizeof(t_img));
	if (win->img == NULL)
		error(win, MALLOC_ERR);
	win->img->img = mlx_new_image(win->mlx_ptr,
			win->map->length * 16,
			win->map->height * 16);
	if (!win->img->img)
		error(win, IMG_ERR);
	win->img->addr = mlx_get_data_addr(win->img->img, &win->img->bpp,
			&win->img->ll, &win->img->endian);
}
