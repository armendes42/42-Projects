/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:56 by armendes          #+#    #+#             */
/*   Updated: 2022/04/21 19:37:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	builtin_env(char **env, int fd)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (has_equal(env[i]))
		{
			ft_putstr_fd(env[i], fd);
			ft_putchar_fd('\n', fd);
		}
		i++;
	}
}
