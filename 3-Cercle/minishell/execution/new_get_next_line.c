/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:02:19 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/14 16:37:44 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_errors_gnl(int fd, char *buf, char **str)
{
	int	ret;

	ret = read(fd, buf, 0);
	if (fd < 0 || fd >= FOPEN_MAX || 0 >= BUFFER_SIZE || ret < 0)
		return (0);
	if (!str[fd])
		str[fd] = ft_strdup("\0");
	if (!str[fd])
		return (0);
	return (1);
}

static void	free_it(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

static char	*separate_lines(char **str, int fd)
{
	int		i;
	char	*leak;
	char	*line;

	i = 0;
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	line = ft_substr(str[fd], 0, i + 1);
	if (!line)
	{
		free_it(&str[fd]);
		return (NULL);
	}
	if (str[fd][i])
	{
		leak = str[fd];
		str[fd] = ft_substr(str[fd], i + 1, ft_strlen(str[fd]) - (i + 1));
		free(leak);
		if (!str[fd])
			free_it(&str[fd]);
		return (line);
	}
	free_it(&str[fd]);
	return (line);
}

char	*new_get_next_line(int fd)
{
	static char	*str[FOPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			i;
	char		*tmp;

	if (!check_errors_gnl(fd, buf, str))
		return (NULL);
	while (!ft_strchr(str[fd], '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			break ;
		if (i == 0 && str[fd][0] == '\0')
		{
			free_it(&str[fd]);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buf);
		free (tmp);
		if (i == 0 && str[fd])
			return (separate_lines(str, fd));
	}
	return (separate_lines(str, fd));
}
