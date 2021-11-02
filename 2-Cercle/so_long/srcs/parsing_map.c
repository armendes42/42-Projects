/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:14:04 by armendes          #+#    #+#             */
/*   Updated: 2021/10/25 16:15:03 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**parse_map(char *filename)
{
	char	*line;
	int		i;
	int		fd;
	char	**map;

	i = 0;
	fd = openfile(filename);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) != 0)
	{
		free(line);
		i++;
	}
	free(line);
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	fd = openfile(filename);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	free(line);
	map[i] = NULL;
	if (close(fd) == -1)
		return (NULL);
	return (map);
}

int	valid_map_rectangle(char **map)
{
	int	i;
	int	length;
	int	tmp;

	i = 0;
	length = ft_strlen(map[i]);
	tmp = length;
	while (map[++i])
	{
		if (tmp != length)
			return (-1);
		tmp = length;
		length = ft_strlen(map[i]);
	}
	return (0);
}
