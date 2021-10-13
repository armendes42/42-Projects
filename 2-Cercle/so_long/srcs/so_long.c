/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:33:47 by armendes          #+#    #+#             */
/*   Updated: 2021/10/13 18:05:00 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	deal_key(int key, t_window *win)
{
	if (key == 13)
		printf("%c\n", 'W');
	else if (key == 0)
		printf("%c\n", 'A');
	else if (key == 1)
		printf("%c\n", 'S');
	else if (key == 2)
		printf("%c\n", 'D');
	else if (key == 53)
	{
		printf("%s\n", "ESC");
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_window win;
	
	(void)argc;
	win.size_x = 500;
	win.size_y = 500;
	win.mlx_ptr = mlx_init();
	if (win.mlx_ptr == NULL)
		return (1);
	win.win_ptr = mlx_new_window(win.mlx_ptr, win.size_x, win.size_y, argv[0]);
	if (win.win_ptr == NULL)
		return (1);
	mlx_key_hook(win.win_ptr, deal_key, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
