#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av, char **env)
{
	char	**dup;
	int	line;
	int	i;
	int	j;

	i = 0;
	j = 0;
	line = 0;
	if (!env)
		return (-1);
	while (env[line] != NULL)
		line++;
	// dans le programme, il faudra avoir un dup pour faire des manipulations
	dup = malloc(sizeof(char *) * line);
	if (!dup)
		return (-1);
	while (i < line)
	{
		dup[i] = malloc(sizeof(char) * (ft_strlen(env[i] + 1)));
		if (!dup)
			return (-1);
		while (env[i][j])
		{
			dup[i][j] = env[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	if (ac > 1)
		if (execve(av[1], av + 1, env) == -1)
			return (-1);
	// s'il reussi execve() quitte le programme, ce qui vient apres ne sera pas affiche
	printf("My pid id  %d\n", getpid());
	return (0);
}
