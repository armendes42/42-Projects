/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:11:29 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 15:10:00 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_horizont_part(char **map, int x, int y)
{
	int	check;
	int	j;

	check = 0;
	j = y;
	while (map[x][j])
	{
		if (map[x][j] == '1')
		{
			check++;
			break ;
		}
		if (map[x][j] == ' ')
			break ;
		j++;
	}
	return (check);
}

int	check_horizont(char **map, int x, int y)
{
	int	j;
	int	check;

	check = check_horizont_part(map, x, y);
	j = y;
	while (map[x][j])
	{
		if (map[x][j] == '1' )
		{
			check++;
			break ;
		}
		if (map[x][j] == ' ')
			break ;
		j--;
	}
	if (check == 2)
		return (1);
	return (0);
}

int	check_vertic_part(char **map, int x, int y)
{
	int	check;
	int	i;

	i = x;
	check = 0;
	while (map[i])
	{
		if ((size_t)y < ft_strlen(map[i]) && map[i][y] == '1')
		{
			check++;
			break ;
		}
		if ((size_t)y < ft_strlen(map[i]) && map[i][y] == ' ' )
			break ;
		i++;
	}
	return (check);
}

int	check_vertic(char **map, int x, int y)
{
	int	check;
	int	i;

	check = check_vertic_part(map, x, y);
	i = x;
	while (map && map[i] && map[i][0] != '\0')
	{
		if ((size_t)y < ft_strlen(map[i]) && map[i][y] == '1' )
		{
			check++;
			break ;
		}
		if ((size_t)y < ft_strlen(map[i]) && map[i][y] == ' ' )
			break ;
		i--;
	}
	if (check == 2)
		return (1);
	return (0);
}

int	first_last_line(char **map)
{
	size_t	i;
	int		j;

	j = 0;
	i = tab_size(map) - 1;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			return (0);
		j++;
	}
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}
