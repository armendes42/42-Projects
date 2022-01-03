/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:55:19 by armendes          #+#    #+#             */
/*   Updated: 2021/12/23 21:56:12 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	exit_init(t_win *win)
{
	win->exit = malloc(sizeof(t_exit *));
	if (win->exit == NULL)
		error(win, MALLOC_ERR);
	win->exit->open = 0;
	win->exit->x = 0;
	win->exit->y = 0;
}*/

void    key_init(t_win *win)
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
	win->img->addr = mlx_get_data_addr(win->img->img, &win->img->bpp,
			&win->img->ll, &win->img->endian);
}