/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:58 by armendes          #+#    #+#             */
/*   Updated: 2022/04/19 15:46:06 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned long long	ft_atoll(char *nptr, int *neg)
{
	unsigned long long	result;
	int					i;

	result = 0;
	i = 0;
	while (nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		*neg = 1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result);
}

static int	check_long_long(char *str)
{
	unsigned long long	result;
	int					neg;
	unsigned long long	high_value;

	neg = 0;
	result = ft_atoll(str, &neg);
	high_value = 9223372036854775808u;
	if (neg == 1 && result > high_value)
		return (1);
	high_value = 9223372036854775807u;
	if (neg == 0 && result > high_value)
		return (1);
	return (0);
}

int	is_arg_numeric(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		len++;
		i++;
	}
	if (len == 19)
		return (check_long_long(str));
	if (len > 19)
		return (1);
	return (0);
}

void	my_exit(t_info *info)
{
	free_env(info->env);
	free_info(info);
	exit(g_exit_status);
}

int	builtin_exit(t_info *info, t_cmd *cmd)
{
	int	i;

	i = count_nb_cmd(info);
	if (i == 1)
		builtin_exit_if_cmd_alone(info, cmd);
	else
		builtin_exit_if_multiple_cmd(cmd);
	return (-1);
}
