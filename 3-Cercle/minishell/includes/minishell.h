/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:34:18 by armendes          #+#    #+#             */
/*   Updated: 2022/02/11 17:32:00 by armendes         ###   ########.fr       */
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
# define WORD_ERR "A problem occured during the formation of the struct word"

typedef enum type
{
	NONE,
	ARG,
	ARG_IN_SIMPLE,
	ARG_IN_DOUBLE,
	RED_IN,
	HERE_DOC,
	RED_OUT,
	RED_OUT_APPEND,
	INFILE,
	LIMITOR,
	OUTFILE,
	OUTFILE_APPEND,
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
	struct s_token	*prev;
}				t_token;

typedef struct s_cmd
{
	char			*cmd;
	struct s_token	*words;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

void	error(t_cmd **cmd, char *err_msg);
e_quote	update_quote_status(char c, e_quote quote);
int		check_quote(char *line);
char	*format_str(char *line, int start, int end);
int		add_cmd(t_cmd **cmd, int start, int end, char *line);
t_cmd	*find_pipe(char *line);
int		cut_into_words(t_cmd **cmd);
void	free_all(t_cmd **cmd);
int		is_empty(char *str);
int		add_word(t_token **words, char *str, e_quote quote);
void	free_word(t_token *tmp);
void	skip_empty_words(t_token **words);

#endif