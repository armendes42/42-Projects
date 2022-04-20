/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:36 by armendes          #+#    #+#             */
/*   Updated: 2022/04/20 22:33:35 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parsing(char *line, t_info *info)
{
	if (is_empty(line))
		return (error(NULL, NULL, -1));
	if (check_quote(line) || check_braces(line)
		|| check_redir_before_pipe(line))
		return (-1);
	info->cmd = find_pipe(line);
	if (!(info->cmd))
		return (error(info, PIPE_ERR, 2));
	if (cut_into_words(info))
		return (error(info, NULL, 1));
	make_args(&info->cmd);
	return (0);
}

t_info	*get_info(void)
{
	static t_info	info;

	return (&info);
}
