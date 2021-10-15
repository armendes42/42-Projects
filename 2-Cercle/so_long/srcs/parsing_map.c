/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:14:04 by armendes          #+#    #+#             */
/*   Updated: 2021/10/15 18:45:09 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_map(char *filename, char ***map)
{
	char	*line;
	char	*line2;
	int		i;
	int		fd;

	i = 0;
	fd = openfile(filename);
	if (fd == -1)
		return (1);
	while (get_next_line(fd, &line) != 0)
		i++;
	printf("%d\n", i);
	map = malloc(sizeof(char *) * (i + 1));
	printf("bonjour\n");
	if (!map)
		return (1);
	printf("au revoir\n");
	if (close(fd) == -1)
		return (1);
	printf("afterclose\n");
	fd = openfile(filename);
	if (fd == -1)
		return (1);
	i = 0;
	printf("after open\n");
	while (get_next_line(fd, &line2) != 0)
	{
		printf("%s\n", line2);
		printf("map[i]\n");
		*map[i] = malloc(sizeof(char) * (ft_strlen(line2) + 2));
		printf("map[o]\n");
		if (!*map[i])
		{
			printf("00\n");
			return (1);
		}
		*map[i] = line2;
		i++;
	}
	*map[i] = NULL;
	if (close(fd) == -1)
		return (1);
	return (0);
}
