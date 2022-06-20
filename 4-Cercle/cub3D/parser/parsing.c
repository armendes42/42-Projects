/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:18:13 by xuwang            #+#    #+#             */
/*   Updated: 2022/06/20 22:31:13 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_filename(char *av, t_cub3d *cub3d)
{
	int	i;

	if (ft_strrchr(av, '.') == NULL)
		_exit_("Error\n", "File Name is Wrong!\n", FAILURE, cub3d);
	i = ft_strlen(av);
	while (av[i - 1] != '.')
		i--;
	if (i <= 0 || ft_strncmp(av + i - 1, ".cub", 4) != 0)
		_exit_("Error\n", "File Name is Wrong!\n", FAILURE, cub3d);
}

void	parsing_file(char *av, t_cub3d *cub3d, t_parsing parsing)
{
	parsing.read = 1;
	parsing.fd = -1;
	parsing_filename(av, cub3d);
	parsing.fd = open(av, O_RDWR | __O_NOFOLLOW);
	if (parsing.fd < 0)
		_exit_("Error\n", "Cannot open file!\n", FAILURE, cub3d);
	while (parsing.read > 0)
	{
		parsing.read = get_next_line(parsing.fd, &parsing.line);
		ft_lstadd_back(&cub3d->datamap, ft_lstnew(ft_strdup(parsing.line)));
		_free((void **)&parsing.line);
	}
	close(parsing.fd);
}

void	text_count(t_parsing_map *map)
{
	while (map->str[map->i] && map->str[map->i] == ' ')
		map->i++;
	if (ft_strncmp(map->str + map->i, "NO", 2) == 0)
		map->tab[0] += 1;
	else if (ft_strncmp(map->str + map->i, "SO", 2) == 0)
		map->tab[1] += 1;
	else if (ft_strncmp(map->str + map->i, "WE", 2) == 0)
		map->tab[2] += 1;
	else if (ft_strncmp(map->str + map->i, "EA", 2) == 0)
		map->tab[3] += 1;
	else if (ft_strncmp(map->str + map->i, "F", 1) == 0)
		map->tab[4] += 1;
	else if (ft_strncmp(map->str + map->i, "C", 1) == 0)
		map->tab[5] += 1;
}

t_list	*sepa_map(t_list *list)
{
	t_parsing_map	map;

	ft_bzero(&map, sizeof(t_parsing_map));
	map.tmp = list;
	while (map.tmp && map.tmp->content)
	{
		map.i = 0;
		map.str = (char *)map.tmp->content;
		text_count(&map);
		if (map.tab[0] == 1 && map.tab[2] == 1 && map.tab[3] == 1
			&& map.tab[4] == 1 && map.tab[5] == 1)
			break ;
		map.tmp = map.tmp->next;
	}
	return (map.tmp);
}

void	ft_parsing(int ac, char *av, t_cub3d *cub3d)
{
	t_parsing	parsing;

	ft_bzero(&parsing, sizeof(t_parsing));
	if (ac != 2)
		_exit_("Error\n", "bad args\n", FAILURE, cub3d);
	parsing_file(av, cub3d, parsing);
	parsing_texinfo(cub3d);
	parsing_map(cub3d);
	map_after_parser(cub3d);
}
