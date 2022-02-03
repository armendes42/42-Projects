/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:51:03 by armendes          #+#    #+#             */
/*   Updated: 2022/02/03 20:08:43 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parsing(int argc, char **argv)
{
	char *path;

	(void)argc;
	(void)argv;
	path = getenv("PATH");
	if (path == NULL) 
	{
		printf("PATH n'existe pas");
		return (-1);
	}
	write(0, path, ft_strlen(path));
	return (0);
}

int	main(int argc, char **argv)
{
	char *line;

	write(0, "~>", 2);
	while (get_next_line(0, &line) > 0)
	{
		if (parsing(argc, argv) == -1)
			return (-1);
		write(0, "\n", 1);
		write(0, "~>", 2);
	}
	free(line);
	return (0);
}
