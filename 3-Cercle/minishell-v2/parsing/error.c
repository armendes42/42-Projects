/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:56:42 by armendes          #+#    #+#             */
/*   Updated: 2022/04/06 17:21:38 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error(t_info *info, char *err_msg)
{
	free_info(info);
	write(1, err_msg, ft_strlen(err_msg));
	return (1);
}

void	error_and_exit(t_info *info)
{
	ft_putnbr_fd(info->exit_status, 1);
	free_info(info);
	exit(EXIT_FAILURE);
}
