/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:59 by armendes          #+#    #+#             */
/*   Updated: 2022/03/28 19:23:46 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_format_of_var(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (!str[i])
		return (0);
	return (1);
}

static int	is_in_args(char **args, char *str_env)
{
	int		i;
	char	*env_var;
	char	*env_arg;

	i = 1;
	env_var = ft_getenv_var(str_env);
	while (args[i])
	{
		if (check_format_of_var(args[i]))
		{
			env_arg = ft_getenv_var(args[i]);
			if (ft_strncmp(env_arg, env_var, 500) == 0)
			{
				free(env_var);
				free(env_arg);
				return (1);
			}
			free(env_arg);
		}
		i++;
	}
	free(env_var);
	return (0);
}

static char	**update_env(char **env, char **args, int control)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = -1;
	new_env = malloc(sizeof(char *) * (ft_len_env(env) + control + 1));
	if (!new_env)
		return (NULL);
	while (env[i] != NULL)
	{
		if (!is_in_args(args, env[i]))
			new_env[++j] = ft_strdup(env[i]);
		free(env[i]);
		i++;
	}
	i = 1;
	while (args[i])
	{
		if (check_format_of_var(args[i]))
			new_env[++j] = ft_strdup(args[i]);
		i++;
	}
	new_env[++j] = NULL;
	return (new_env);
}

int	builtin_export(t_info *info)
{
	int		i;
	int		control;
	char	*env_var;

	i = 1;
	control = 0;
	while (info->cmd->args[++i])
	{
		if (check_format_of_var(info->cmd->args[i]))
		{
			control++;
			env_var = ft_getenv_var(info->cmd->args[i]);
			if (!env_var)
				return (-1);
			if (ft_getenv(env_var, info->env))
				control--;
		}
	}
	info->env = update_env(info->env, info->cmd->args, control);
	if (!info->env)
		return (-1);
	//free l'ancien env
	return (0);
}
