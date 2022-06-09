/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:41:47 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 19:18:28 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "macro.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
}				t_img;

typedef struct s_key
{
	int	key;
	int	pressed;
	int	delay;
}				t_key;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction; //-1 if left, +1 if right
	int		walk_direction; //-1 if back, +1 if front
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}								t_player;

typedef struct s_map
{
	char	**map;
	int		height;
	int		length;
}								t_map;

typedef struct s_sprite
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		iw;
	int		ih;
}				t_sprite;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	int				tile_size;
	int				num_rays;
	t_img			*img;
	t_key			*key;
	t_player	*player;
	t_map			*map;
	t_sprite	**sprites;
}								t_win;

void			error(t_win *win, char *err_msg);
void			free_all(t_win *win);
t_win			*initialize_window(char **av);
void			loops(t_win *win);
int				game_loop(t_win *win);
void			draw_sprite(t_win *win, int y, int x, int index);
t_sprite	*import_sprite(t_win *win, char *path);

#endif
