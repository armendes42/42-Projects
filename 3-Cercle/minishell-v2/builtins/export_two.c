/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:59:04 by armendes          #+#    #+#             */
/*   Updated: 2022/04/07 19:01:55 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
				error_and_exit(get_info());
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}
