/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:19:17 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 16:46:30 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_all(t_win *win)
{
	if (win)
	{
		if (win->win_ptr)
			mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		if (win->mlx_ptr)
		{
			mlx_destroy_display(win->mlx_ptr);
			free(win->mlx_ptr);
		}
		free(win);
	}
}

void	error(t_win *win, char *err_msg)
{
	free_all(win);
	printf("Error : %s", err_msg);
	exit(EXIT_FAILURE);
}
