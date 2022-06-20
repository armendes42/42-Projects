/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:11:25 by xuwang            #+#    #+#             */
/*   Updated: 2022/06/20 22:26:45 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* mlx_destroy_display() does not exist on macOS */
#if defined(__APPLE__) && defined(__MACH__)

void	exit_clean(t_cub3d *cub)
{
	int	i;

	i = 0;
	if (cub)
	{
		free_tex(cub, i);
		if (cub->mlx_img.img_ptr)
			mlx_destroy_image(cub->mlx, cub->mlx_img.img_ptr);
		if (cub->mlx)
			mlx_destroy_window(cub->mlx, cub->win);
		_free((void **)&cub->mlx);
		if (cub->datamap)
			ft_lstclear(&cub->datamap, free);
		free_config(cub, i);
		free_mapinfo(cub, i);
		_free((void **)&cub);
	}
}

#else

void	exit_clean(t_cub3d *cub)
{
	int	i;

	i = 0;
	if (cub)
	{
		free_tex(cub, i);
		if (cub->mlx_img.img_ptr)
			mlx_destroy_image(cub->mlx, cub->mlx_img.img_ptr);
		if (cub->mlx)
		{
			mlx_destroy_window(cub->mlx, cub->win);
			mlx_destroy_display(cub->mlx);
		}
		_free((void **)&cub->mlx);
		if (cub->datamap)
			ft_lstclear(&cub->datamap, free);
		free_mapinfo(cub, i);
		free_config(cub, i);
		free(cub);
		cub = NULL;
	}
}

#endif

void	_exit_(char *s1, char *s2, int ret, t_cub3d *cub)
{
	if (s1)
		ft_putstr_fd(s1, 2);
	if (s2)
		ft_putstr_fd(s2, 2);
	exit_clean(cub);
	exit(ret);
}
