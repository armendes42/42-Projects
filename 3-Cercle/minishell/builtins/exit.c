/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:58 by armendes          #+#    #+#             */
/*   Updated: 2022/03/22 17:09:51 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_long_long(char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (str[0] == '-')
	{
		i++;
		neg = 1;
	}
	i++;
	if (str[i] > '2')
		return (1);
	else if (str[i] == '2')
	{
		i++;
		if (str[i] > '2')
			return (1);
		else if (str[i] == '2')
		{
			i++;
			if (str[i] > '3')
				return (1);
			else if (str[i] == '3')
			{
				i++;
				if (str[i] > '3')
					return (1);
				else if (str[i] == '3')
				{
					i++;
					if (str[i] > '7')
						return (1);
					else if (str[i] == '7')
					{
						i++;
						if (str[i] > '2')
							return (1);
						else if (str[i] == '2')
						{
							i++;
							if (str[i] > '0')
								return (1);
							else if (str[i] == '0')
							{
								i++;
								if (str[i] > '3')
									return (1);
								else if (str[i] == '3')
								{
									i++;
									if (str[i] > '6')
										return (1);
									else if (str[i] == '6')
									{
										i++;
										if (str[i] > '8')
											return (1);
										else if (str[i] == '8')
										{
											i++;
											if (str[i] > '5')
												return (1);
											else if (str[i] == '5')
											{
												i++;
												if (str[i] > '4')
													return (1);
												else if (str[i] == '4')
												{
													i++;
													if (str[i] > '7')
														return (1);
													else if (str[i] == '7')
													{
														i++;
														if (str[i] > '7')
															return (1);
														else if (str[i] == '7')
														{
															i++;
															if (str[i] > '5')
																return (1);
															else if (str[i] == '5')
															{
																i++;
																if (str[i] > '8')
																	return (1);
																else if (str[i] == '8')
																{
																	i++;
																	if (str[i] > '0')
																		return (1);
																	else if (str[i] == '0')
																	{
																		i++;
																		if ((str[i] > '7' && neg == 0) || (str[i] > '8' && neg == 1))
																			return (1);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

static int	is_arg_numeric(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[0] == '-')
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

void	builtin_exit(t_info *info)
{
	if (info->cmd->args[1] == NULL)
		info->exit_status = 0;
	if (is_arg_numeric(info->cmd->args[1]) == 0)
		ft_putstr_fd("bonjour\n", 1);
	else if (is_arg_numeric(info->cmd->args[1]) == 1)
		ft_putstr_fd("bonsoir\n", 1);
}
