/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:53:12 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/22 18:35:33 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab[i]);
	free(tab);
	tab = NULL;
}

void	_free(void **to_free)
{
	if (to_free && *to_free)
		free(*to_free);
	*to_free = NULL;
}

void	free_tex(t_cub3d *cub, int i)
{
	i = 0;
	while (i < TEXTURE_MAX)
	{
		if (cub->tex_img[i].img_ptr)
			mlx_destroy_image(cub->mlx, cub->tex_img[i].img_ptr);
		i++;
	}
}

void	free_config(t_cub3d *cub, int i)
{
	if (cub->config)
	{
		i = 0;
		while (cub->config[i])
		{
			free((char *)cub->config[i]);
			cub->config[i] = NULL;
			++i;
		}
		free(cub->config[i]);
		free(cub->config);
		cub->config = NULL;
	}
}

void	free_mapinfo(t_cub3d *cub, int i)
{
	i = 0;
	while (i < TEXTURE_MAX)
	{
		if (cub->mapinfo.texture[i])
			_free((void **)&cub->mapinfo.texture[i]);
		i++;
	}
	if (cub->mapinfo.map)
	{
		free(cub->mapinfo.map);
		cub->mapinfo.map = NULL;
	}
}
