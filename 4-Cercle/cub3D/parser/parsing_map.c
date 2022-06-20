/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:10 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/22 19:45:03 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char const	g_ply[] = {
	'N',
	'S',
	'E',
	'W',
	'\0'
};

int	_ply(char **map, int x, int y, int i)
{
	i = 0;
	while (g_ply[i] != '\0')
	{
		if (g_ply[i] == map[x][y] && check_hor_ver(map, x, y))
			return (1);
		i++;
	}
	return (0);
}

int	line_is_empty(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0')
		return (1);
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		++i;
	}
	return (1);
}

int	find_player(t_cub3d *cub3d, char **map)
{
	t_idx	idx;
	int		i;

	ft_bzero(&idx, sizeof(t_idx));
	i = init_i(&idx, map);
	while (map[idx.i])
	{
		idx.j = 0;
		while (map[idx.i][idx.j])
		{
			if (_ply(map, idx.i, idx.j, idx.k))
			{
				get_player_pos(cub3d, idx, i, map[idx.i][idx.j]);
				map[idx.i][idx.j] = '0';
				idx.player++;
			}
			idx.j++;
		}
		idx.i++;
	}
	if (idx.player == 1)
		return (1);
	return (0);
}

void	parsing_map(t_cub3d *cub3d)
{
	t_list	*tmp1;

	tmp1 = NULL;
	tmp1 = sepa_map(cub3d->datamap);
	tmp1 = tmp1->next;
	cub3d->config = lst_to_tab(tmp1);
	if (!check_zeroinfo(cub3d->config))
		_exit_("Error\n", "map config is wrong!\n", FAILURE, cub3d);
	if (!find_player(cub3d, cub3d->config))
		_exit_("Error\n", "player config is wrong!\n", FAILURE, cub3d);
}
