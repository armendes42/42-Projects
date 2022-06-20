/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:02:43 by xuwang            #+#    #+#             */
/*   Updated: 2022/06/20 22:31:47 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_after_parser(t_cub3d *cub3d)
{
	int	len;
	int	i;
	int	j;

	j = 0;
	i = 0;
	len = 0;
	while (cub3d->config[i])
	{
		if (cub3d->config[i][0] != '\0')
			len++;
		i++;
	}
	cub3d->mapinfo.map = ft_calloc(sizeof(char *), len + 1);
	if (!cub3d->mapinfo.map)
		return ;
	i = 0;
	while (cub3d->config[i])
	{
		if (cub3d->config[i][0] == '\0')
			i++;
		else
			cub3d->mapinfo.map[j++] = cub3d->config[i++];
	}
	cub3d->mapinfo.map[j] = NULL;
}

void	set_text_path(t_cub3d *cub3d, char *str1, char *str2)
{
	static int	i;

	i = 0;
	if (i < TEXTURE_MAX && ft_strncmp(str2, "NO", 3) == 0)
		cub3d->mapinfo.texture[0] = str1;
	else if (i < TEXTURE_MAX && ft_strncmp(str2, "SO", 3) == 0)
		cub3d->mapinfo.texture[1] = str1;
	else if (i < TEXTURE_MAX && ft_strncmp(str2, "WE", 3) == 0)
		cub3d->mapinfo.texture[2] = str1;
	else if (i < TEXTURE_MAX && ft_strncmp(str2, "EA", 3) == 0)
		cub3d->mapinfo.texture[3] = str1;
}

void	set_couleur(t_cub3d *cub3d, char *str)
{
	t_setclr	setclr;

	ft_bzero(&setclr, sizeof(t_setclr));
	while (str[setclr.i] && str[setclr.i] == ' ' )
		setclr.i++;
	if (str[setclr.i] == 'F')
	{
		setclr.tab = ft_split((str + setclr.i + 1), ',');
		while (setclr.tab && setclr.tab[setclr.j] && setclr.k < 3)
		{
			setclr.nbr = ft_atoi(setclr.tab[setclr.j++]);
			cub3d->mapinfo.f_couleur[setclr.k++] = setclr.nbr;
		}
		free_tab(setclr.tab);
	}
	if (str[setclr.i] == 'C')
	{
		setclr.tab = ft_split((str + setclr.i + 1), ',');
		while (setclr.tab && setclr.tab[setclr.j] && setclr.k < 3)
		{
			setclr.nbr = ft_atoi(setclr.tab[setclr.j++]);
			cub3d->mapinfo.c_couleur[setclr.k++] = setclr.nbr;
		}
		free_tab(setclr.tab);
	}
}
