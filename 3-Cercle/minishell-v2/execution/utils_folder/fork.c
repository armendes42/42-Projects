/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:41:22 by imaalem           #+#    #+#             */
/*   Updated: 2022/03/25 16:51:46 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int ac, char **av, char **env)
{
	int	pid;
	int statut;

	statut = 0;
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid != 0)
		printf("je suis le pere mon pid est %d et le pid de mon fils est %d\n", getpid(), pid);
	if (pid == 0)
	{
		printf("je suis le fils mon pid est %d\n", getpid());
		if (execve(av[1], av + 1, env) == -1)
			perror("execve");
		return (1);
	}
	// waitpid(pid, &statut, 0);
	// if (WIFEXITED(statut) == 1)
	// {

	// }
	wait(&statut);
	return (0);
}
