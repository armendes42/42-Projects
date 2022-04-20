/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:59:04 by armendes          #+#    #+#             */
/*   Updated: 2022/04/20 17:01:49 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_export(char **env)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		tmp = ft_getenv_var(env[i]);
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd("=\"", 1);
		tmp2 = ft_getenv(tmp, env);
		free(tmp);
		ft_putstr_fd(tmp2, 1);
		free(tmp2);
		ft_putstr_fd("\"\n", 1);
		i++;
	}
}

void	error_for_export_and_unset(char *str, int i)
{
	ft_putstr_fd("$: ", 2);
	if (i == 0)
		ft_putstr_fd("export: '", 2);
	else if (i == 1)
		ft_putstr_fd("unset: '", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

char	**update_env_two(char **args, char **new_env, int j)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (check_format_of_var_export(args[i]))
		{
			new_env[j] = ft_strdup(args[i]);
			if (!new_env[j])
				error_and_exit(get_info(), 1);
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}
