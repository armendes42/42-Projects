/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:36:33 by armendes          #+#    #+#             */
/*   Updated: 2021/12/23 19:53:23 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    get_map_size(int fd, t_win *win)
{
    int     tmp;
    char    *line;

    tmp = 1;
    while (tmp > 0)
    {
        tmp = get_next_line(fd, &line);
        if (tmp < 0)
            error(win, MALLOC_ERR);
        if (tmp != 0)
            win->map->length = ft_strlen(line);
        win->map->height++;
        free(line);
        line = NULL;
    }
}

static void    get_map(int fd, t_win *win)
{
    int     tmp;
    char    *line;
    int     i;

    tmp = 1;
    i = 0;
    win->map->map = malloc(sizeof(char *) * (win->map->height + 1));
    if (win->map->map == NULL)
        error(win, MALLOC_ERR);
    while (tmp > 0)
    {
        tmp = get_next_line(fd, &line);
        if (tmp < 0 || (((int)ft_strlen(line) != win->map->length) && tmp != 0))
            error(win, PARSE_ERR);
        win->map->map[i] = line;
        i++;
    }
    win->map->length = ft_strlen(win->map->map[0]);
    win->map->map[i] = NULL;
}

static void    check_closed(t_win *win)
{
    int i;

    i = -1;
    while (win->map->map[0][++i])
        if (win->map->map[0][i] != '1')
            error(win, PARSE_ERR);
    i = -1;
    while (win->map->map[win->map->height - 1][++i])
        if (win->map->map[win->map->height - 1][i] != '1')
            error(win, PARSE_ERR);
    i = -1;
    while (win->map->map[++i])
        if (win->map->map[i][0] != '1' ||
        win->map->map[i][win->map->length - 1] != '1')
            error(win, PARSE_ERR);
}

void    get_map_info(char *filename, t_win *win)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error(win, OPEN_ERR);
    get_map_size(fd, win);
    close(fd);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error(win, OPEN_ERR);
    get_map(fd, win);
    check_closed(win);
    check_required(win);
}