/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:34:18 by armendes          #+#    #+#             */
/*   Updated: 2022/02/08 20:49:58 by armendes         ###   ########.fr       */
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

# define QUOTE_ERR "Erreur de quote"

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
}				t_token;

typedef struct s_token
{
	char			*cmd;
	enum			e_type;
	struct s_token	*next;
}				t_token;

typedef struct s_cmd
{
	char			*cmd;
	struct s_token	*cmd_pipe;
	struct s_cmd	*next;
}				t_token;

t_cmd	*cut_cmd_line(char *line);
int		check_pipe(t_cmd **cmd_line);
int		simple_quote(char *cmd);

#endif