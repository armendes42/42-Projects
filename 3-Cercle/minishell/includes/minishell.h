/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:34:18 by armendes          #+#    #+#             */
/*   Updated: 2022/02/09 18:23:00 by armendes         ###   ########.fr       */
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

# define QUOTE_ERR "A quote is unclosed"
# define CMD_ERR "A problem occured during the formation of the struct cmd"
# define MALLOC_ERR "Error during a memory allocation"

typedef enum type
{
	NONE,
	ARG,
	FILE_IN,
	HERE_DOC,
	FILE_OUT,
	FILE_OUT_SUR,
	OPEN_FILE,
	LIMITOR,
	EXIT_FILE,
	EXIT_FILE_RET,
}			e_type;

typedef enum quote
{
	NOTHING,
	SIMPLE,
	DOUBLE,
}			e_quote;

typedef struct s_token
{
	char			*word;
	e_type			type;
	struct s_token	*next;
}				t_token;

typedef struct s_cmd
{
	char			*cmd;
	struct s_token	*words;
	struct s_cmd	*next;
}				t_cmd;

void	error(char *err_msg);
e_quote	update_quote_status(char c, e_quote quote);
int		check_quote(char *line);
char	*format_str(char *line, int start, int end);
int		add_cmd(t_cmd **cmd, int start, int end, char *line);
t_cmd	*find_pipe(char *line);

#endif