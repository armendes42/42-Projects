/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:10:59 by armendes          #+#    #+#             */
/*   Updated: 2022/02/21 17:23:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	keep_till_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$')
	{
		i++;
	}
	i++;
	return (i);
}

int	keep_till_end_of_var(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$' && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}
