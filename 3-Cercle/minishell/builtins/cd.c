/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:53 by armendes          #+#    #+#             */
/*   Updated: 2022/03/29 18:34:42 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(char **args)
{
	if (args[1] == NULL)
		return (0);
	else if (args[2] == NULL)
	{
		if (chdir(args[1]))
			return (-1);
	}
	else
		ft_putstr_fd("~>: cd: too many arguments\n", STDERR_FILENO);
	return (0);
}
