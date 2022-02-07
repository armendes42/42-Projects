/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:25:33 by armendes          #+#    #+#             */
/*   Updated: 2022/02/07 17:34:59 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	simple_quote(char *cmd)
{
	int i;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i] == '\'' && cmd[i - 1] != '\\')
			return (1);
		i++;
	}
	//quote_error();
	return (0);
}
