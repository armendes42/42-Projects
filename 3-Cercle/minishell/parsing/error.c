/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:56:42 by armendes          #+#    #+#             */
/*   Updated: 2022/04/19 15:47:15 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error(t_info *info, char *err_msg, int exit_status)
{
	if (exit_status != -1)
		g_exit_status = exit_status;
	free_info(info);
	if (err_msg != NULL)
		write(2, err_msg, ft_strlen(err_msg));
	return (1);
}

void	error_and_exit(t_info *info, int exit_status)
{
	g_exit_status = exit_status;
	free_info(info);
	exit(g_exit_status);
}
