/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:10:59 by armendes          #+#    #+#             */
/*   Updated: 2022/03/15 20:49:52 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	keep_going_till_dollar(char *str)
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

int	keep_going_till_end_of_var(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$' && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

int	search_error_var_env(char *str)
{
	e_quote	quote;
	int		i;

	quote = NOTHING;
	i = 0;
	while (str[i])
	{
		quote = update_quote_status(str[i], quote);
		if (quote == NOTHING || quote == DOUBLE)
		{
			if (str[i] == '$' && str[i + 1] == '{')
			{
				if (str[i + 2] == '}')
					return (-1);
				i += 2;
				while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
					i++;
				if (str[i] != '}')
					return (-1);
			}
		}
		i++;
	}
	return (0);
}
