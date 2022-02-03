/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:51:03 by armendes          #+#    #+#             */
/*   Updated: 2022/02/03 17:57:34 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char *path;
	char *line;

	(void)argc;
	(void)argv;
	while (get_next_line(0, &line) > 0)
	{
		write(0, line, strlen(line));
		write(0, "\n", 1);
		write(0, "~>", 2);
	}
	free(line);
	path = getenv("PATH");
	if (path == NULL) 
	{
		printf("PATH n'existe pas");
		return (-1);
	}
	printf("%s\n", path);
	return (0);
}