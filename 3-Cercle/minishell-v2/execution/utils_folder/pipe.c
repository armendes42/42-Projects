#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int ac, char **av, char **ev)
{
	int 		pipefd[2];
	// pourquoi avoir mis un tableau de string?
	char		*cmd1[] = {"/bin/ls", "-l", "-a", NULL};
	char		*cmd2[] = {"/bin/cat", "-e", NULL};
	int			pid1;
	int			pid2;

	if (pipe(pipefd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (write(1, "1 fork failed\n", 14), 1);
	else if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execve(cmd1[0], cmd1, ev);
		return (2);
	}
	else
	{
		close(pipefd[1]);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (2);
	else if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		execve(cmd2[0], cmd2, ev);
	}
	else
	{
		close(pipefd[0]);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}