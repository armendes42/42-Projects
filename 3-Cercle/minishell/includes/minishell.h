/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:34:18 by armendes          #+#    #+#             */
/*   Updated: 2022/02/03 21:06:49 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef	struct	s_command
{
	char				*cmd;
	char				*cmd_pipe;
	struct s_command	*prev;
	struct s_command	*next;
}				t_command;

t_command	*cut_cmd_line(char *line);

#endif