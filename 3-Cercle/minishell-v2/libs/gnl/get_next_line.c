/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:19:54 by armendes          #+#    #+#             */
/*   Updated: 2022/01/29 19:34:48 by armendes         ###   ########.fr       */
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

static int	gnl_return_and_free(char *save, int return_value)
{
	free(save);
	return (return_value);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*save;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (gnl_return_and_free(save, -1));
	while (!has_return(save) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (gnl_return_and_free(save, -1));
		buff[bytes_read] = '\0';
		save = gnl_strjoin(save, buff);
		if (!save)
			return (gnl_return_and_free(save, -1));
	}
	*line = before_return(save);
	save = after_return(save);
	if (!save)
		free(save);
	if (bytes_read == 0)
		return (gnl_return_and_free(save, 0));
	return (1);
}
