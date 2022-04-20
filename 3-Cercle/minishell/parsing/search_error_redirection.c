/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_error_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:13:57 by armendes          #+#    #+#             */
/*   Updated: 2022/04/19 14:36:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	little_str_error(char *little_str)
{
	if (little_str != NULL)
	{
		if (little_str[0] == '<')
		{
			if (little_str[1] == '<')
				return (error(NULL, HERE_DOC_ERR, 2));
			return (error(NULL, INPUT_ERR, 2));
		}
		else if (little_str[0] == '>')
		{
			if (little_str[1] == '>')
				return (error(NULL, OUTPUT_APPEND_ERR, 2));
			return (error(NULL, OUTPUT_ERR, 2));
		}	
	}
	return (0);
}

static int	error_redirection(char *str, int i)
{
	char	*little_str;

	little_str = NULL;
	if ((str[i] == '<' && str[i + 1] == '>')
		|| (str[i] == '<' && str[i + 1] == '<')
		|| (str[i] == '>' && str[i + 1] == '>'))
		little_str = get_next_char(&str[i + 2]);
	else if ((str[i] == '<' && str[i + 1] != '<')
		|| (str[i] == '<' && str[i + 1] != '>')
		|| (str[i] == '>' && str[i + 1] != '>')
		|| (str[i] == '>' && str[i + 1] != '>'))
		little_str = get_next_char(&str[i + 1]);
	return (little_str_error(little_str));
}

int	search_error_redirection_two(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '<')
		return (error(NULL, INPUT_ERR, 2));
	else if (str[i] == '<' && str[i + 1] == '>' && is_empty(&str[i + 2]))
		return (error(NULL, OUTPUT_ERR, 2));
	else if (str[i] == '<' && str[i + 1] == '<' && is_empty(&str[i + 2]))
		return (error(NULL, NEWLINE_ERR, 2));
	else if (str[i] == '>' && str[i + 1] == '>' && is_empty(&str[i + 2]))
		return (error(NULL, NEWLINE_ERR, 2));
	else if ((str[i] == '<' || str[i] == '>') && is_empty(&str[i + 1]))
		return (error(NULL, NEWLINE_ERR, 2));
	return (error_redirection(str, i));
}
