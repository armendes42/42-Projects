/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:50:00 by armendes          #+#    #+#             */
/*   Updated: 2022/04/20 17:20:00 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(int fd, int *pid)
{
	char	*buff;

	buff = getcwd(NULL, 0);
	if (buff == NULL)
	{
		ft_putstr_fd(PWD_ERR, 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		g_exit_status = 1;
		if (pid != NULL)
			exit(2);
		return (-1);
	}
	ft_putstr_fd(buff, fd);
	ft_putchar_fd('\n', fd);
	free(buff);
	return (0);
}
