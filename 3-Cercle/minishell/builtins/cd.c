/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:49:53 by armendes          #+#    #+#             */
/*   Updated: 2022/04/20 15:44:10 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error_cd(char *err_msg, char *path)
{
	ft_putstr_fd("$: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd("\n", 2);
}

static char	**create_args_for_cd(void)
{
	char	**args;
	char	*pwd_var;
	t_info	*info;

	info = get_info();
	args = malloc(sizeof(char *) * 3);
	if (!args)
		error_and_exit(info, 1);
	args[0] = "";
	pwd_var = ft_getenv("PWD", info->env);
	if (!pwd_var)
		return (NULL);
	args[1] = ft_strjoin("OLDPWD=", pwd_var);
	if (!args[1])
		error_and_exit(info, 1);
	free(pwd_var);
	args[2] = NULL;
	return (args);
}

static int	update_pwd_and_oldpwd(int *pid)
{
	char	**args;
	char	*pwd_var;
	t_info	*info;

	info = get_info();
	args = create_args_for_cd();
	if (!args)
		return (-1);
	info->env = update_env_export(info->env, args, 0);
	free(args[1]);
	pwd_var = getcwd(NULL, 0);
	args[1] = ft_strjoin("PWD=", pwd_var);
	if (args[1] == NULL)
	{
		g_exit_status = 2;
		if (pid != NULL)
			exit(2);
		return (-1);
	}
	free(pwd_var);
	info->env = update_env_export(info->env, args, 0);
	free(args[1]);
	free(args);
	return (0);
}

static int	cd_home(char **env, int *pid)
{
	char	*home_var;

	home_var = ft_getenv("HOME", env);
	if (!home_var)
	{
		ft_putstr_fd("$: cd: HOME not set\n", 2);
		g_exit_status = 2;
		if (pid != NULL)
			exit(2);
		return (-1);
	}
	if (chdir(home_var) == -1)
	{
		free(home_var);
		g_exit_status = 2;
		print_error_cd(strerror(errno), "HOME");
		if (pid != NULL)
			exit(2);
		return (-1);
	}
	free(home_var);
	return (update_pwd_and_oldpwd(pid));
}

int	builtin_cd(char **args, char **env, int *pid)
{
	(void)pid;
	if (args[1] == NULL)
		return (cd_home(env, pid));
	else if (args[2] == NULL)
	{
		if (chdir(args[1]) == -1)
		{
			g_exit_status = 2;
			print_error_cd(strerror(errno), args[1]);
			if (pid != NULL)
				exit(2);
			return (-1);
		}
		return (update_pwd_and_oldpwd(pid));
	}
	else
	{
		ft_putstr_fd("$: cd: too many arguments\n", 2);
		g_exit_status = 2;
		if (pid != NULL)
			exit(2);
	}
	return (0);
}
