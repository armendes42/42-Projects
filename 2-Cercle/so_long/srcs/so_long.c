/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:33:47 by armendes          #+#    #+#             */
/*   Updated: 2021/10/13 16:09:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	(void)argc;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, argv[0]);
	if (win_ptr == NULL)
		return (1);
	mlx_loop(mlx_ptr);
	return (0);
}
