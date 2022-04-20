/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   braces_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:58:53 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 18:45:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	braces_empty_two(char *str, int i, t_quote quote)
{
	int	start;

	while (i > 0)
	{
		quote = update_quote_status(str[i], quote);
		if (str[i] == ' ' && quote == NOTHING)
		{
			start = i;
			break ;
		}
		i--;
	}
	if (i == 0)
		start = i;
	start++;
	while (str[start])
	{
		quote = update_quote_status(str[start], quote);
		if (quote == NOTHING && str[start] == ' ')
			return ;
		ft_putchar_fd(str[start], 2);
		start++;
	}
}

int	braces_empty(char *str)
{
	int		i;
	t_quote	quote;

	i = 0;
	quote = NOTHING;
	while (str[i])
	{
		quote = update_quote_status(str[i], quote);
		if (str[i] == '$' && str[i + 1] == '{' && str[i + 2] == '}')
		{
			ft_putstr_fd("$: ", 2);
			braces_empty_two(str, i, quote);
			return (error(NULL, ACCOLADE_ERR, 1));
		}
		i++;
	}
	return (0);
}

static void	braces_non_conform_two(char *str, int i, t_quote quote)
{
	int	start;

	while (i > 0)
	{
		quote = update_quote_status(str[i], quote);
		if (str[i] == ' ' && quote == NOTHING)
		{
			start = i;
			break ;
		}
		i--;
	}
	if (i == 0)
		start = i;
	start++;
	while (str[start])
	{
		quote = update_quote_status(str[start], quote);
		if (str[start - 1] == '}')
			return ;
		ft_putchar_fd(str[start], 2);
		start++;
	}
}

int	braces_non_conform(char *str)
{
	int		i;
	t_quote	quote;

	i = 0;
	quote = NOTHING;
	while (str[i])
	{
		quote = update_quote_status(str[i], quote);
		if (str[i] == '$' && str[i + 1] == '{')
		{
			ft_putstr_fd("$: ", 2);
			braces_non_conform_two(str, i, quote);
			return (error(NULL, ACCOLADE_ERR, 1));
		}
		i++;
	}
	return (0);
}
