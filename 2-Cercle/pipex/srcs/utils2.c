#include "../includes/pipex.h"

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
