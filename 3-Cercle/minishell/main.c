/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:37:36 by armendes          #+#    #+#             */
/*   Updated: 2022/04/21 17:26:50 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

void	set_up_signals_parent(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c);
}

static int	loop(t_info	*info)
{
	char	*line;

	line = "";
	while (1)
	{
		line = readline("$ ");
		if (line == NULL)
		{
			free(line);
			free_env(info->env);
			ft_putstr_fd("exit\n", 1);
			g_exit_status = 0;
			return (-1);
		}
		if (line && *line)
			add_history(line);
		if (parsing(line, info) == 0)
		{
			execution(info);
			free_info(info);
		}
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;

	(void)argc;
	(void)argv;
	info = get_info();
	info->env = copy_env(envp, argv[0]);
	set_up_signals_parent();
	loop(info);
	return (0);
}
