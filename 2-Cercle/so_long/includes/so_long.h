/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:32:46 by armendes          #+#    #+#             */
/*   Updated: 2022/01/28 15:52:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "keys.h"
# include "errors.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

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

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
}				t_img;

typedef struct s_map
{
	char	**map;
	int		height;
	int		length;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		coll;
}				t_player;

typedef struct s_collectible
{
	int	x;
	int	y;
	int	picked;
	int	last;
}				t_collectible;

typedef struct s_exit
{
	int	x;
	int	y;
	int	open;
}				t_exit;

typedef struct s_key
{
	int	key;
	int	pressed;
	int	delay;
}				t_key;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				nb_coll;
	int				nb_exit;
	int				nb_moves;
	t_map			*map;
	t_player		*player;
	t_sprite		**sprites;
	t_collectible	*collectibles;
	t_exit			*exit;
	t_key			*key;
	t_img			*img;
}				t_win;

void		error(t_win *win, char *err_msg);
void		free_all(t_win *win);
t_win		*win_init(char **av);
void		key_init(t_win *win);
void		img_init(t_win *win);
void		get_collectibles(t_win *win);
void		get_player_pos(t_win *win);
void		get_exit(t_win *win);
void		loops(t_win *win);
void		draw_sprite(t_win *win, int y, int x, int index);
int			trgb(int t, int r, int g, int b);
t_sprite	*import_sprite(t_win *win, char *path);
void		get_map_info(char *filename, t_win *win);
void		check_required(t_win *win);
int			render_all(t_win *win);
void		render_collectibles(t_win *win);
void		render_exit(t_win *win);
void		render_map(t_win *win);
void		render_player(t_win *win);
void		render_move_counter(t_win *win);

#endif
