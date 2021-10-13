/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:33:47 by armendes          #+#    #+#             */
/*   Updated: 2021/10/13 19:28:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	deal_key(int key, t_window *win)
{
	int	x;
	int	y;

	if (key == 13)
	{
		printf("%c\n", 'W');
		x = 0;
		while (x < 100)
		{
			y = 0;
			while (y < 100)
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0x0000FF00);
				y++;
			}
			x++;
		}
	}
	else if (key == 0)
	{
		printf("%c\n", 'A');
		x = 100;
		while (x < 200)
		{
			y = 100;
			while (y < 200)
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0x000000FF);
				y++;
			}
			x++;
		}
	}
	else if (key == 1)
	{
		printf("%c\n", 'S');
		x = 200;
		while (x < 300)
		{
			y = 200;
			while (y < 300)
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0x00FF0000);
				y++;
			}
			x++;
		}
	}
	else if (key == 2)
	{
		printf("%c\n", 'D');
		x = 0;
		while (x < 100)
		{
			y = 0;
			while (y < 100)
			{
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0x000000FF);
				y++;
			}
			x++;
		}
	}
	else if (key == 53)
	{
		printf("%s\n", "ESC");
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y + data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_window	win;
	//t_data		img;
	void		*img;
	int			img_width;
	int			img_height;
	
	(void)argc;
	win.size_x = 1000;
	win.size_y = 1000;

	win.mlx_ptr = mlx_init();

	win.win_ptr = mlx_new_window(win.mlx_ptr, win.size_x, win.size_y, argv[0]);
	
	//img.img = mlx_new_image(win.mlx_ptr, 250, 250);
	//img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);


	img = mlx_xpm_file_to_image(win.mlx_ptr, "./sample_640x426.xpm", &img_width, &img_height);
	//mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, img, 0, 0);

	mlx_key_hook(win.win_ptr, deal_key, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
