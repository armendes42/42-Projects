/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:42:13 by armendes          #+#    #+#             */
/*   Updated: 2022/03/22 16:40:57 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_arg_format(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	builtin_echo(char **args)
{
	int	i;
	int	new_line;
	int	control;

	i = 1;
	new_line = 0;
	control = 0;
	while (check_arg_format(args[i]) == 0)
	{
		new_line++;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1] != NULL)
			ft_putchar_fd(' ', STDIN_FILENO);
		i++;
	}
	if (new_line == 0)
		ft_putchar_fd('\n', STDIN_FILENO);
}