/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:03:51 by armendes          #+#    #+#             */
/*   Updated: 2021/12/23 19:55:32 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_required(char c, int check)
{
	static int	chars[3];

	if (c == 'P')
		chars[0]++;
	else if (c == 'C')
		chars[1]++;
	else if (c == 'E')
		chars[2]++;
	if (check == 1)
		if (chars[0] != 1 || chars[1] == 0 || chars[2] == 0)
			return (1);
	return (0);
}

void	check_required(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->map->map[i])
	{
		j = 0;
		while (win->map->map[i][j])
		{
			count_required(win->map->map[i][j], 0);
			j++;
		}
		i++;
	}
	if (count_required(0, 1))
		error(win, PARSE_ERR);
}
