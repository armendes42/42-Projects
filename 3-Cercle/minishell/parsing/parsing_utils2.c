/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:56:13 by armendes          #+#    #+#             */
/*   Updated: 2022/02/15 16:58:01 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cut_one_char(char *str)
{
	int	i;

	i = 1;
	return (&str[i]);
}

char	*cut_two_char(char *str)
{
	int	i;

	i = 2;
	return (&str[i]);
}
