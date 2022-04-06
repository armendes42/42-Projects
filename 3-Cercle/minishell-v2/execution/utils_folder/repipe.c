#include <unistd.h>

int	main(int ac, char **av, char **ev)
{
	int		pipefd[2];
	char	*cmd1 = "/bin/ls -l";
	char	*cmd2 = "/bin/wc"
	int		pid1;
	int		pid2;

	if (pipe(pipefd) == -1)
		perror("pipe");
	
	pid = fork();
	if (pid = -1)
		perror("fork");
	else if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipe[1], STDOUT_FILENO);
		if (execve(cmd1, "ls -l", NULL) == -1)
			perror("execve");
	}
	fork();
	if (pid == 0)
	{
		dup2(STDIN_FILENO, pipefd[1]);
		close(pipefd[1]);
		if (execve(cmd2, "wc", NULL) == -1)
			perror("execve");
	}
	close(pipefd[0]);
	return (0);
}