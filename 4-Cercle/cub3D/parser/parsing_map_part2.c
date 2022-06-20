/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:25:58 by xuwang            #+#    #+#             */
/*   Updated: 2022/03/22 19:46:52 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_zeroinfo(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (!first_last_line(map))
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_c(map[i][j]) == 0)
				return (0);
			if (map[i][j] == '0')
			{
				if ((size_t)j > (ft_strlen(map[i - 1]))
					|| (size_t)j > (ft_strlen(map[i + 1]))
					|| (!check_horizont(map, i, j) || !check_vertic(map, i, j)))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_hor_ver(char **map, int x, int y)
{
	if (check_horizont(map, x, y) && check_vertic(map, x, y) == 1)
		return (1);
	return (0);
}

void	get_player_pos(t_cub3d *cub3d, t_idx pos, int i, char direction)
{
	cub3d->player.pos_x = (double)pos.j + 0.5;
	cub3d->player.pos_y = (double)pos.i - i + 1 + 0.5;
	cub3d->player.direction = direction;
}

int	init_i(t_idx *idx, char **map)
{
	while (map[idx->i])
	{
		if (!line_is_empty(map[idx->i++]))
			break ;
	}
	return (idx->i);
}
