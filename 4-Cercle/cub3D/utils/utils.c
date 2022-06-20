/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:26:07 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 15:43:02 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	tab_size(char **src)
{
	int	i;

	i = 0;
	while (src != NULL && src[i] != NULL)
		++i;
	return (i);
}

char	**lst_to_tab(t_list *list)
{
	char	**map;
	int		len;
	int		i;
	t_list	*tmp;

	len = ft_lstsize(list);
	map = ft_calloc(sizeof(char *), len + 1);
	if (!map)
		return (NULL);
	tmp = list;
	i = 0;
	while (tmp && i < len)
	{
		map[i] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	check_c(char c)
{
	if (c != '0' && c != '1' && c != ' ' && c != 'N'
		&& c != 'S' && c != 'W' && c != 'E')
		return (0);
	return (1);
}

void	mlx_img_clean(t_cub3d *cub3d)
{
	if (cub3d->mlx_img.img_ptr != NULL)
		mlx_destroy_image(cub3d->mlx, cub3d->mlx_img.img_ptr);
}

void	tex_img_clean(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < TEXTURE_MAX)
	{
		if (cub3d->tex_img[i].img_ptr != NULL)
			mlx_destroy_image(cub3d->mlx, cub3d->tex_img[i].img_ptr);
		i++;
	}
}
