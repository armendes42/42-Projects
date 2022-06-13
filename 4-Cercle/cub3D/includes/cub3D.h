/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:41:47 by armendes          #+#    #+#             */
/*   Updated: 2022/06/13 17:43:20 by armendes         ###   ########.fr       */
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
# include <stdbool.h>
# include <math.h>

enum e_path
{
	e_NO,
	e_SO,
	e_WE,
	e_EA,
	e_F,
	e_C
};

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			size;
	int			ll;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	rot_angle;
	double	walk_speed;
	double	rot_speed;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_height;
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

typedef struct s_keys
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_left;
	int	key_right;
}								t_keys;

typedef struct s_ray
{
	int			pixel;
	double	camera;
	double	raydir_x;
	double	raydir_y;
	int			map_x;
	int			map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double	*zbuffer;
}								t_ray;

typedef struct s_line
{
	int		start;
	int		end;
	int		line_x;
	int		line_y;
	int		tex_x;
	int		tex_y;
}							t_line;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				tile_size;
	int				num_rays;
	int				sprite_size;
	t_keys		keys;
	t_img			*img;
	t_player	player;
	t_map			map;
	t_sprite	**sprites;
}								t_win;

void			error(t_win *win, char *err_msg);
void			free_all(t_win *win);
t_win			*initialize_window(char **av);
void			loops(t_win *win);
void			draw_sprite(t_win *win, int y, int x, int index);
t_sprite	*import_sprite(t_win *win, char *path);
void			move_player(t_win *win);
void			rotate_player_left(t_win *win);
void			rotate_player_right(t_win *win);
void			raycast(t_win *win);
void			drawing(t_ray *ray, t_win *win);

#endif
