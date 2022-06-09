/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:56:10 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 17:50:49 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	update(t_win *win)
{
	(void)win;
}

int	game_loop(t_win *win)
{
	update(win);
	// render(win);
	return (0);
}
