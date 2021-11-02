/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:32:46 by armendes          #+#    #+#             */
/*   Updated: 2021/11/02 16:55:51 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
}				t_window;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		has_return(char *str);
int		get_next_line(int fd, char **line);
char		**parse_map(char *filename);
int		openfile(char *filename);
char		*ft_strdup(char *s);
int		valid_map_rectangle(char **map);

#endif
