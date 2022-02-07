/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:34:18 by armendes          #+#    #+#             */
/*   Updated: 2022/02/07 17:19:58 by armendes         ###   ########.fr       */
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

typedef struct	s_cmd_pipe
{
	char				*cmd;
	struct s_cmd_pipe	*prev;
	struct s_cmd_pipe	*next;
	
}				t_cmd_pipe;


typedef	struct	s_cmd
{
	char				*cmd;
	struct s_cmd_pipe	*cmd_pipe;
	struct s_cmd		*prev;
	struct s_cmd		*next;
}				t_cmd;

t_cmd	*cut_cmd_line(char *line);
int		check_pipe(t_cmd **cmd_line);
int		simple_quote(char *cmd);

#endif