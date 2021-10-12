/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:24:50 by armendes          #+#    #+#             */
/*   Updated: 2021/10/11 17:26:08 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_one(int fd_infile, char *cmd1, int *pipefd, char **envp)
{
	int		i;
	char	**paths;
	char	*cmd;
	char	**cmdargs;

	if (dup_in_out(fd_infile, pipefd[1]) == -1)
		return ;
	close(pipefd[0]);
	close(fd_infile);
	i = -1;
	paths = parsing_paths(envp);
	cmdargs = ft_split(cmd1, ' ');
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], cmdargs[0]);
		execve(cmd, cmdargs, envp);
		free(cmd);
	}
	exit(EXIT_FAILURE);
	return ;
}

void	child_two(int fd_outfile, char *cmd2, int *pipefd, char **envp)
{
	int		i;
	char	**paths;
	char	*cmd;
	char	**cmdargs;

	if (dup_in_out(pipefd[0], fd_outfile) == -1)
		return ;
	close(pipefd[1]);
	close(fd_outfile);
	i = -1;
	paths = parsing_paths(envp);
	cmdargs = ft_split(cmd2, ' ');
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], cmdargs[0]);
		execve(cmd, cmdargs, envp);
		free(cmd);
	}
	exit(EXIT_FAILURE);
	return ;
}

void	pipex(int fd_infile, int fd_outfile, char **argv, char **envp)
{
	int		pipefd[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(pipefd) == -1)
		perror("Pipe");
	child1 = fork();
	if (child1 < 0)
		perror("Fork");
	if (child1 == 0)
		child_one(fd_infile, argv[2], pipefd, envp);
	child2 = fork();
	if (child2 < 0)
		perror("Fork");
	if (child2 == 0)
		child_two(fd_outfile, argv[3], pipefd, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_infile;
	int		fd_outfile;

	if (argc != 5)
	{
		ft_putstr_fd("input should be: ./pipex file1 cmd1 cmd2 file2", 2);
		return (-1);
	}
	fd_infile = open(argv[1], O_RDONLY);
	fd_outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (openfile(fd_infile, fd_outfile, argv[1], argv[4]) == -1)
		return (-1);
	pipex(fd_infile, fd_outfile, argv, envp);
	return (0);
}
