/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:50:02 by armendes          #+#    #+#             */
/*   Updated: 2022/04/06 17:53:13 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_format_of_var(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
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
	new_env = malloc(sizeof(char *) * (ft_len_env(env) - control));
	if (!new_env)
		error_and_exit(get_info());
	while (env[i] != NULL)
	{
		if (!is_in_args(args, env[i]))
			new_env[++j] = ft_strdup(env[i]);
		free(env[i]);
		i++;
	}
	free(env);
	new_env[++j] = NULL;
	return (new_env);
}

static int	update_control(char *arg, char **env)
{
	char	*env_var;
	char	*var;

	env_var = ft_getenv_var(arg);
	var = ft_getenv(env_var, env);
	if (var != NULL)
	{
		free(var);
		free(env_var);
		return (1);
	}
	free(env_var);
	return (0);
}

int	builtin_unset(t_info *info, t_cmd *cmd)
{
	int		i;
	int		control;

	i = 1;
	control = 0;
	while (cmd->args[i])
	{
		if (check_format_of_var(cmd->args[i]))
			control += update_control(cmd->args[i], info->env);
		i++;
	}
	info->env = update_env(info->env, cmd->args, control);
	return (0);
}
