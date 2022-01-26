/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:33:47 by armendes          #+#    #+#             */
/*   Updated: 2022/01/26 20:47:18 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_win	*win;

	win = NULL;
	if (ac != 2)
		error(win, ARGNB_ERR);
	win = win_init(av);
	printf("gate");
	get_collectibles(win);
	get_player_pos(win);
	get_exit(win);
	loops(win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
