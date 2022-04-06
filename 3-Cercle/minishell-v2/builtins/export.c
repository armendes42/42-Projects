/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:59 by armendes          #+#    #+#             */
/*   Updated: 2022/04/05 17:08:35 by imaalem          ###   ########.fr       */
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

	i = -1;
	j = -1;
	new_env = malloc(sizeof(char *) * (ft_len_env(env) + control + 1));
	if (!new_env)
		return (NULL);
	while (env[++i] != NULL)
	{
		if (!is_in_args(args, env[i]))
			new_env[++j] = ft_strdup(env[i]);
		free(env[i]);
	}
	free(env);
	i = 0;
	while (args[++i])
	{
		if (check_format_of_var(args[i]))
			new_env[++j] = ft_strdup(args[i]);
	}
	new_env[++j] = NULL;
	return (new_env);
}

static int	update_control(char *arg, char **env)
{
	char	*env_var;
	char	*var;

	env_var = ft_getenv_var(arg);
	if (!env_var)
		return (-1);
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
		return (-1);
	while (cmd->args[++i])
	{
		if (check_format_of_var(cmd->args[i]))
		{
			control++;
			control -= update_control(cmd->args[i], info->env);
		}
	}
	info->env = update_env(info->env, cmd->args, control);
	if (!info->env)
		return (-1);
	return (0);
}
