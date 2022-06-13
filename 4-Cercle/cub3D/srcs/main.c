/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:32:47 by armendes          #+#    #+#             */
/*   Updated: 2022/06/13 16:16:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_win	*win;

	win = NULL;
	if (ac != 2)
		error(win, ARGNB_ERR);
	win = initialize_window(av);
	loops(win);
	free_all(win);
	return (0);
}
