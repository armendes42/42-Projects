/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:24:50 by armendes          #+#    #+#             */
/*   Updated: 2021/10/08 17:38:35 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**parsing_paths(char **envp)
{
	int		i;
	char	**paths;

	i = -1;
	while (envp[++i] != NULL)
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
	paths = ft_split(&envp[i][5], ':');
	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
	return (paths);
}

int	openfile(char *file, int id)
{
	int	fd;

	if (id == 1)
		fd = open(file, O_RDONLY);
	if (id == 2)
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 00644);
	if (fd < 0)
	{
		perror(file);
		strerror(errno);
		return (-1);
	}
	return (fd);
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

void	child_one(char *infile, char *cmd1, int *pipefd, char **envp)
{
	int		err;
	int		f1;
	int		i;
	char	**paths;
	char	*cmd;
	char	**cmdargs;

	f1 = openfile(infile, 1);
	if (f1 == -1)
		return ;
	i = dup_in_out(f1, pipefd[1]);
	if (i == -1)
		return ;
	close(pipefd[0]);
	close(f1);
	i = -1;
	paths = parsing_paths(envp);
	cmdargs = ft_split(cmd1, ' ');
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], cmdargs[0]);
		err = access(cmd, F_OK | X_OK);
		if (err == -1)
		{
			perror("access");
			strerror(errno);
		}
		execve(cmd, cmdargs, envp);
		free(cmd);
	}
	exit(EXIT_FAILURE);
	return ;
}

void	child_two(char *outfile, char *cmd2, int *pipefd, char **envp)
{
	int		err;
	int		f2;
	int		i;
	char	**paths;
	char	*cmd;
	char	**cmdargs;

	f2 = openfile(outfile, 2);
	if (f2 == -1)
		return ;
	i = dup_in_out(pipefd[0], f2);
	if (i == -1)
		return ;
	close(pipefd[1]);
	close(f2);
	i = -1;
	paths = parsing_paths(envp);
	cmdargs = ft_split(cmd2, ' ');
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], cmdargs[0]);
		err = access(cmd, F_OK);
		if (err == -1)
		{
			perror("access");
			strerror(errno);
		}
		execve(cmd, cmdargs, envp);
		free(cmd);
	}
	exit(EXIT_FAILURE);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		err;
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (argc != 5)
	{
		ft_putstr_fd("input should be: ./pipex file1 cmd1 cmd2 file2", 2);
		return (0);
	}
	err = pipe(pipefd);
	if (err == -1)
		perror("Pipe");
	child1 = fork();
	if (child1 < 0)
		perror("Fork");
	if (child1 == 0)
		child_one(argv[1], argv[2], pipefd, envp);
	child2 = fork();
	if (child2 < 0)
		perror("Fork");
	if (child2 == 0)
		child_two(argv[4], argv[3], pipefd, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}
