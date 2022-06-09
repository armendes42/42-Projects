/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:32:47 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 16:29:35 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render(t_win *win)
{

}

int	main(int ac, char **av)
{
	t_win	*win;

	win = NULL;
	if (ac != 2)
		error(win, ARGNB_ERR);
	win = initialize_window(av);
	// setup();
	loops(win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
