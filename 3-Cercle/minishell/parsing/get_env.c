/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:10:27 by armendes          #+#    #+#             */
/*   Updated: 2022/04/25 16:16:05 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**create_env(char *arg)
{
	char	**env;
	char	**args;
	char	*buff;

	env = malloc(sizeof(char *) * 1);
	if (!env)
		error_and_exit(get_info(), 1);
	env[0] = NULL;
	args = malloc(sizeof(char *) * 5);
	if (!args)
		error_and_exit(get_info(), 1);
	args[0] = "";
	buff = getcwd(NULL, 0);
	args[1] = ft_strjoin("PWD=", buff);
	if (args[1] == NULL)
		error_and_exit(get_info(), 1);
	args[2] = "SHLVL=1";
	args[3] = ft_strjoin("_=", arg);
	args[4] = NULL;
	free(buff);
	env = update_env_export(env, args, 3);
	free(args[1]);
	free(args[3]);
	free(args);
	return (env);
}

char	**copy_env(char **envp, char *arg)
{
	int		i;
	char	**env;

	if (envp[0] == NULL)
	{
		env = create_env(arg);
		return (env);
	}
	i = 0;
	while (envp[i])
		i++;
	env = malloc(sizeof(char *) * (i + 1));
	if (!env)
		error_and_exit(get_info(), 1);
	i = 0;
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		if (!env[i])
			error_and_exit(get_info(), 1);
		i++;
	}
	env[i] = NULL;
	return (env);
}

char	*ft_getenv_var(char *str)
{
	int		i;
	char	*env_var;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	env_var = ft_strdup_size(str, i);
	if (!env_var)
		error_and_exit(get_info(), 1);
	return (env_var);
}

int	ft_len_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		i++;
	}
	i++;
	return (i);
}

char	*ft_getenv(char *var, char **env)
{
	int		i;
	int		j;
	char	*env_var;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (!env[i][j])
			return (NULL);
		env_var = ft_strdup_size(env[i], j);
		if (!env_var)
			error_and_exit(get_info(), 1);
		if (ft_strncmp(var, env_var, 500) == 0)
		{
			free(env_var);
			env_var = ft_strdup_size(&env[i][j + 1], 500);
			if (!env_var)
				error_and_exit(get_info(), 1);
			return (env_var);
		}
		free(env_var);
		i++;
	}
	return (NULL);
}
