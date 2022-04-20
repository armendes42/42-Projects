/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:59 by armendes          #+#    #+#             */
/*   Updated: 2022/04/20 16:54:39 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_format_of_var_export(char *str)
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
		if (check_format_of_var_export(args[i]))
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

char	**update_env_export(char **env, char **args, int control)
{
	int		i;
	int		j;
	char	**new_env;

	i = -1;
	j = 0;
	new_env = malloc(sizeof(char *) * (ft_len_env(env) + control + 1));
	if (!new_env)
		error_and_exit(get_info(), 1);
	while (env[++i] != NULL)
	{
		if (!is_in_args(args, env[i]))
		{
			new_env[j] = ft_strdup(env[i]);
			if (!new_env[j])
				error_and_exit(get_info(), 1);
			j++;
		}
		free(env[i]);
	}
	free(env);
	new_env = update_env_two(args, new_env, j);
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

int	builtin_export(t_info *info, t_cmd *cmd)
{
	int		i;
	int		control;

	i = 0;
	control = 0;
	if (cmd->args[1] == NULL)
	{
		print_env_export(info->env);
		return (0);
	}
	while (cmd->args[++i])
	{
		if (check_format_of_var_export(cmd->args[i]))
		{
			control++;
			control -= update_control(cmd->args[i], info->env);
		}
		else
			error_for_export_and_unset(cmd->args[i], 0);
	}
	info->env = update_env_export(info->env, cmd->args, control);
	return (0);
}
