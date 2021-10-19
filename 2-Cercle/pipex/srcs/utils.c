/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:00:05 by armendes          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**create_tab(int i)
{
	char	**tmp;

	tmp = malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	**parsing_paths(char **envp)
{
	int		i;
	char	**paths;
	char	**tmp;

	i = -1;
	while (envp[++i] != NULL)
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
	paths = ft_split(&envp[i][5], ':');
	i = 0;
	while (paths[i])
		i++;
	tmp = create_tab(i);
	i = -1;
	while (paths[++i])
	{
		tmp[i] = ft_strjoin(paths[i], "/");
		free(paths[i]);
	}
	tmp[i] = NULL;
	free(paths[i]);
	free(paths);
	return (tmp);
}

int	dup_in_out(int fd_in, int fd_out)
{
	int	err_in;
	int	err_out;

	err_in = dup2(fd_in, STDIN_FILENO);
	err_out = dup2(fd_out, STDOUT_FILENO);
	if (err_in == -1 || err_out == -1)
	{
		perror("dup2");
		return (-1);
	}
	return (0);
}

int	openfile(int fd_infile, int fd_outfile, char *infile, char *outfile)
{
	if (fd_infile < 0 && fd_outfile < 0)
	{
		perror(infile);
		perror(outfile);
		return (-1);
	}
	else if (fd_infile < 0)
	{
		perror(infile);
		return (-1);
	}
	else if (fd_outfile < 0)
	{
		perror(outfile);
		return (-1);
	}
	return (0);
}

void	error_command(char *arg)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\n", 2);
}
