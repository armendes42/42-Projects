/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:42:13 by armendes          #+#    #+#             */
/*   Updated: 2022/04/17 21:52:44 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_arg_format(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (1);
	if (str[1] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	builtin_echo(char **args, int fd)
{
	int	i;
	int	new_line;

	i = 0;
	new_line = 0;
	if (args[1] == NULL)
	{
		ft_putchar_fd('\n', fd);
		return ;
	}
	while (args[++i] && check_arg_format(args[i]) == 0)
		new_line++;
	if (!args[i])
		return ;
	while (args[i])
	{
		ft_putstr_fd(args[i], fd);
		if (args[i + 1] != NULL)
			ft_putchar_fd(' ', fd);
		i++;
	}
	if (new_line == 0)
		ft_putchar_fd('\n', fd);
}
