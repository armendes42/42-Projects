/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:13:36 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 15:09:08 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_dup(t_list *list)
{
	t_parsing_map	dup;

	ft_bzero(&dup, sizeof(t_parsing_map));
	dup.tmp = list;
	while (dup.tmp && dup.tmp->content)
	{
		dup.i = 0;
		dup.str = (char *)dup.tmp->content;
		text_count(&dup);
		dup.tmp = dup.tmp->next;
	}
	if (dup.tab[0] > 1 || dup.tab[2] > 1 || dup.tab[3] > 1
		|| dup.tab[4] > 1 || dup.tab[5] > 1)
		return (0);
	return (1);
}

void	free_texture(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < TEXTURE_MAX)
	{
		if (cub3d->mapinfo.texture[i])
			_free((void **)&cub3d->mapinfo.texture[i]);
		i++;
	}
}

void	parsing_texinfo(t_cub3d *cub3d)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = cub3d->datamap;
	tmp = sepa_map(tmp2);
	if (check_dup(tmp2) == 0)
		_exit_("Error\n", "Texinfo duplicate!\n", FAILURE, cub3d);
	while (tmp2)
	{
		if (check_text((tmp2->content), cub3d) == 1)
			set_couleur(cub3d, tmp2->content);
		else
			_exit_("Error\n", "Texinfo is wrong!\n", FAILURE, cub3d);
		if (tmp == tmp2)
			break ;
		tmp2 = tmp2->next;
	}
}
