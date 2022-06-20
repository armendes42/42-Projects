/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:41:47 by armendes          #+#    #+#             */
/*   Updated: 2022/06/20 22:24:41 by armendes         ###   ########.fr       */
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

# define FAILURE 1
# define SUCCESS 0

# define TEXTURE_MAX 4
# define COLOR_MAX 3

# define NAME "Cub3D"
# define WIN_HEIGHT 800
# define WIN_WIDTH  800
# define PLY_DIR 4
# define KEYMAX 6

# if defined (__APPLE__) && (__MACH__)
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define RED_CROSS 17
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define RED_CROSS 33
# endif

enum e_path
{
	e_NO = 0,
	e_SO,
	e_WE,
	e_EA,
	e_F,
	e_C
};

typedef struct s_parsing
{
	int		fd;
	int		read;
	char	*line;
}	t_parsing;

typedef struct s_idx
{
	int	i;
	int	j;
	int	k;
	int	player;
}	t_idx;

typedef struct s_setclr
{
	int		i;
	char	**tab;
	int		nbr;
	int		j;
	int		k;
}	t_setclr;

typedef struct s_player
{
	char	direction;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_height;
	double	speed;
	double	rot_speed;
}	t_player;

typedef struct s_parsing_map
{
	int		i;
	t_list	*tmp;
	char	*str;
	int		tab[6];
}	t_parsing_map;

typedef struct s_map
{
	char			**map;
	char			*texture[TEXTURE_MAX];
	unsigned char	f_couleur[COLOR_MAX];
	unsigned char	c_couleur[COLOR_MAX];
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_key
{
	int	a;
	int	w;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_key;

typedef struct s_raycast
{
	int			pix;
	double		camerax;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		*zbuffer;
}	t_raycast;

typedef struct s_line
{
	int		start;
	int		end;
	int		line_x;
	int		line_y;
	int		tex_x;
	int		tex_y;
}	t_line;

typedef struct s_cub3d
{
	t_setclr	setclr;
	t_list		*datamap;
	char		**config;
	t_map		mapinfo;
	void		*win;
	void		*mlx;
	t_img		mlx_img;
	t_img		tex_img[TEXTURE_MAX];
	t_player	player;
	t_key		key;
}	t_cub3d;

void	_free(void **to_free);
void	free_tab(char **tab);
void	free_tex(t_cub3d *cub, int i);
void	free_config(t_cub3d *cub, int i);
void	free_mapinfo(t_cub3d *cub, int i);
int		main(int ac, char **av);
/* parsing */
void	parsing_texinfo(t_cub3d *cub3d);
int		first_last_line(char **map);
void	ft_parsing(int ac, char *av, t_cub3d *cub3d);
int		tab_size(char **src);
t_list	*sepa_map(t_list *list);
void	parsing_map(t_cub3d *cub3d);
int		check_horizont(char **map, int x, int y);
int		check_vertic(char **map, int x, int y);
int		first_last_line(char **map);
void	text_count(t_parsing_map *map);
int		check_dup(t_list *list);
int		check_text(char *str, t_cub3d *cub3d);
void	map_after_parser(t_cub3d *cub3d);
void	set_couleur(t_cub3d *cub3d, char *str);
void	set_text_path(t_cub3d *cub3d, char *str1, char *str2);
char	**lst_to_tab(t_list *list);
int		check_c(char c);
void	mlx_img_clean(t_cub3d *cub3d);
void	tex_img_clean(t_cub3d *cub3d);
int		check_zeroinfo(char **map);
int		check_hor_ver(char **map, int x, int y);
void	get_player_pos(t_cub3d *cub3d, t_idx pos, int i, char direction);
int		init_i(t_idx *idx, char **map);
int		line_is_empty(char *line);

/* exec */
void	start_game(t_cub3d *cub3d);
void	player_init(t_cub3d *cub3d);
void	sidedist_init(t_raycast *ray, t_player *player);
void	hit_wall(t_raycast *ray, t_cub3d *cub3d);
void	set_perpwalldist(t_raycast *ray, t_player *player);
void	set_lineheight(t_raycast *ray);
void	set_drawinfo(t_raycast *ray, t_player *player);
void	color_vertic(t_line *line, unsigned int const color, t_cub3d *cub3d);
void	text_vertic(t_line *line, t_img text, t_raycast *ray, t_cub3d *cub3d);
void	player_move_w(t_cub3d *cub3d);
void	player_move_a(t_cub3d *cub3d);
void	player_move_s(t_cub3d *cub3d);
void	player_move_d(t_cub3d *cub3d);
void	player_rotate_left(t_cub3d *cub3d);
void	player_rotate_right(t_cub3d *cub3d);
void	do_raycasting(t_cub3d *cub3d);
void	drawing(t_raycast *ray, t_cub3d *cub3d);
int		key_press(int keycode, t_cub3d *cub3d);
int		key_release(int keycode, t_cub3d *cub3d);
void	key_control(t_cub3d *cub3d);
void	tex_init(t_cub3d *cub3d);
void	drawing(t_raycast *ray, t_cub3d *cub3d);

/*exit*/
void	free_tab(char **tab);
void	_exit_(char *s1, char *s2, int ret, t_cub3d *cub3d);

#endif
