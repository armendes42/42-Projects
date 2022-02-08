/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:36 by armendes          #+#    #+#             */
/*   Updated: 2022/02/08 19:09:41 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error(char *err_msg)
{
	write(0, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}

static int	check_quote(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			while (line[i + 1] != '\'' && line[i + 1])
				i++;
			if (!line[i + 1])
				return (-1);
			i++;
		}
		else if (line[i] == '"')
		{
			while (line[i + 1] != '"' && line[i + 1])
				i++;
			if (!line[i + 1])
				return (-1);
			i++;
		}
		i++;
	}
	return (0);
}

static void	parsing(char *line)
{
	if (check_quote(line))
		error(QUOTE_ERR);
}

int	main(void)
{
	char *line;

	line = "";
	while (line)
	{
		line = readline("~>");
		parsing(line);
	}
	free(line);
	return (0);
}