/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_dollar_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:08:04 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 18:05:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cut_before_only_space(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) != 0 || str[i + 1] == '_'))
			i++;
		if (str[i] == '$' && (str[i + 1] == ' ' || str[i + 1] == '\0'
				|| str[i + 1] == '$'
				|| (ft_isalnum(str[i + 1]) == 0 && str[i] != '_')))
			break ;
		i++;
	}
	result = cut_before_only_space_two(str, i);
	return (result);
}

static void	count_i_and_j_for_only_space(char *str, int *i, int *j)
{
	*i = 0;
	*j = 1;
	while (str[*i])
	{
		if (str[*i] == '$')
		{
			if (str[*i + 1] == '\0' || str[*i + 1] == '$')
				break ;
			if (str[*i + 1] == ' ')
			{
				(*i)++;
				while (str[*i] && str[*i] == ' ')
				{
					(*j)++;
					(*i)++;
				}
				break ;
			}
		}
		(*i)++;
	}
}

char	*cut_only_space(char *str)
{
	int		i;
	int		j;
	char	*result;

	count_i_and_j_for_only_space(str, &i, &j);
	result = malloc(sizeof(char) * (j + 1));
	if (!result)
		error_and_exit(get_info(), 1);
	i -= j;
	i++;
	result[0] = '$';
	j = 1;
	while (str[i] && str[i] == ' ')
	{
		result[j] = str[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

static void	count_i_for_after_only_space(char *str, int *i)
{
	*i = 0;
	while (str[*i])
	{
		if (str[*i] == '$')
		{
			if (str[*i + 1] == '\0')
				break ;
			else if (ft_isalnum(str[*i + 1]) != 0 || str[*i + 1] == '_')
				(*i)++;
			else if (str[*i + 1] == '$' || str[*i + 1] == ' '
				|| ft_isalnum(str[*i + 1]) == 0)
			{
				(*i)++;
				break ;
			}
		}
		(*i)++;
	}
}

char	*cut_after_only_space(char *str)
{
	int		i;
	int		j;
	char	*result;

	count_i_for_after_only_space(str, &i);
	result = malloc(sizeof(char) * (ft_strlen(str) - i + 2));
	if (!result)
		error_and_exit(get_info(), 1);
	j = 0;
	while (str[i])
	{
		result[j] = str[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
