/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:24:50 by armendes          #+#    #+#             */
/*   Updated: 2021/10/15 16:40:41 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_one(int fd_infile, char *cmd1, int *pipefd, char **envp)
{
	int		i;
	char	**paths;
	char	*cmd;
	char	**cmdargs;

	close(pipefd[0]);
	if (dup_in_out(fd_infile, pipefd[1]) == -1)
		return ;
	close(pipefd[1]);
	close(fd_infile);
	i = -1;
	cmdargs = ft_split(cmd1, ' ');
	if (access(cmdargs[0], F_OK | X_OK) == 0)
		execve(cmdargs[0], cmdargs, envp);
	paths = parsing_paths(envp);
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], cmdargs[0]);
		if (access(cmd, F_OK | X_OK) == 0)
			execve(cmd, cmdargs, envp);
		free(cmd);
		free(paths[i]);
	}
	free(paths[i]);
	free(paths);
	error_command(cmdargs[0]);
	exit(EXIT_FAILURE);
}

void	child_two(int fd_outfile, char *cmd2, int *pipefd, char **envp)
{
	int		i;
	char	**paths;
	char	*cmd;
	char	**cmdargs;

	close(pipefd[1]);
	if (dup_in_out(pipefd[0], fd_outfile) == -1)
		return ;
	close(pipefd[0]);
	close(fd_outfile);
	i = -1;
	cmdargs = ft_split(cmd2, ' ');
	if (access(cmdargs[0], F_OK | X_OK) == 0)
		execve(cmdargs[0], cmdargs, envp);
	paths = parsing_paths(envp);
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], cmdargs[0]);
		if (access(cmd, F_OK | X_OK) == 0)
			execve(cmd, cmdargs, envp);
		free(cmd);
		free(paths[i]);
	}
	free(paths[i]);
	free(paths);
	error_command(cmdargs[0]);
	exit(EXIT_FAILURE);
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

void	all_cmd_empty(int fd_infile, int fd_outfile, char **envp)
{
	char	*cmd;
	char	*cmdargs[2];

	if (dup_in_out(fd_infile, fd_outfile) == -1)
		return ;
	close(fd_infile);
	close(fd_outfile);
	cmd = "/usr/bin/cat";
	cmdargs[0] = cmd;
	cmdargs[1] = NULL;
	if (access(cmd, F_OK | X_OK) == 0)
		execve(cmd, cmdargs, envp);
	cmd = "/bin/cat";
	cmdargs[0] = cmd;
	if (access(cmd, F_OK | X_OK) == 0)
		execve(cmd, cmdargs, envp);
	exit(EXIT_FAILURE);
}

void	cmd1_empty(int fd_infile, int fd_outfile, char *cmd2, char **envp)
{
	int		i;
	char	**paths;
	char	*cmd;
	char	**cmdargs;

	if (dup_in_out(fd_infile, fd_outfile) == -1)
		return ;
	close(fd_infile);
	close(fd_outfile);
	i = -1;
	cmdargs = ft_split(cmd2, ' ');
	if (access(cmdargs[0], F_OK | X_OK) == 0)
		execve(cmdargs[0], cmdargs, envp);
	paths = parsing_paths(envp);
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], cmdargs[0]);
		if (access(cmd, F_OK | X_OK) == 0)
			execve(cmd, cmdargs, envp);
		free(cmd);
		free(paths[i]);
	}
	free(paths[i]);
	free(paths);
	error_command(cmdargs[0]);
	exit(EXIT_FAILURE);
}

void	cmd2_empty(int fd_infile, int fd_outfile, char *cmd1, char **envp)
{
	int		i;
	char	**paths;
	char	*cmd;
	char	**cmdargs;

	if (dup_in_out(fd_infile, fd_outfile) == -1)
		return ;
	close(fd_infile);
	close(fd_outfile);
	i = -1;
	cmdargs = ft_split(cmd1, ' ');
	if (access(cmdargs[0], F_OK | X_OK) == 0)
		execve(cmdargs[0], cmdargs, envp);
	paths = parsing_paths(envp);
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], cmdargs[0]);
		if (access(cmd, F_OK | X_OK) == 0)
			execve(cmd, cmdargs, envp);
		free(cmd);
		free(paths[i]);
	}
	free(paths[i]);
	free(paths);
	error_command(cmdargs[0]);
	exit(EXIT_FAILURE);
}


int	main(int argc, char **argv, char **envp)
{
	int		fd_infile;
	int		fd_outfile;

	if (argc != 5)
	{
		ft_putstr_fd("input should be: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (-1);
	}
	fd_infile = open(argv[1], O_RDONLY);
	fd_outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (openfile(fd_infile, fd_outfile, argv[1], argv[4]) == -1)
		return (-1);
	if (ft_strncmp(argv[2], "", 1) == 0 && ft_strncmp(argv[3], "", 1) == 0)
		all_cmd_empty(fd_infile, fd_outfile, envp);
	else if (ft_strncmp(argv[2], "", 1) == 0)
		cmd1_empty(fd_infile, fd_outfile, argv[3], envp);
	else if (ft_strncmp(argv[3], "", 1) == 0)
		cmd2_empty(fd_infile, fd_outfile, argv[2], envp);
	pipex(fd_infile, fd_outfile, argv, envp);
	return (0);
}
