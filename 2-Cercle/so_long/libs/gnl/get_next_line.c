/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:19:54 by armendes          #+#    #+#             */
/*   Updated: 2022/01/25 17:48:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*after_return(char *save)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * ((gnl_strlen(save) - i) + 1));
	if (!tmp)
		return (NULL);
	i++;
	while (save[i])
		tmp[j++] = save[i++];
	tmp[j] = '\0';
	free(save);
	return (tmp);
}

char	*before_return(char *save)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		tmp[i] = save[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*save;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!has_return(save) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (-1);
		buff[bytes_read] = '\0';
		save = gnl_strjoin(save, buff);
		if (!save)
		{
			free(save);
			return (-1);
		}
	}
	*line = before_return(save);
	if (!*line)
	{
		free(save);
		return (-1);
	}
	save = after_return(save);
	if (!save)
	{
		free(save);
		return (-1);
	}
	if (bytes_read == 0)
		return (0);
	return (1);
}
