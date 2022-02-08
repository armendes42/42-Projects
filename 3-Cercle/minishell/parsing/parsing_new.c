/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:36 by armendes          #+#    #+#             */
/*   Updated: 2022/02/08 20:32:23 by armendes         ###   ########.fr       */
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

static char	*get_var(char *str)
{
	int		i;
	char	*var;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	var = malloc(sizeof(char) * (i + 1));
	if (!var)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		var[i] = str[i];
		i++;
	}
	return (var);
}

static char	*change_env_var(char *line)
{
	int		i;
	char	*tmp;
	char	*cmd;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			while (line[i] != '\'')
				i++;
		else if (line[i] == '"')
		{
			while (line[i] != '"')
			{
				if (line[i] == '$')
				{
					tmp = get_var(&cmd[i]);
					if (!tmp)
						return (NULL);
					tmp = getenv(tmp);
				}
				i++;
			}
		}
		i++;
	}
}

static void	parsing(char *line)
{
	char	*cmd;

	if (check_quote(line))
		error(QUOTE_ERR);
	cmd = change_env_var(line);
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