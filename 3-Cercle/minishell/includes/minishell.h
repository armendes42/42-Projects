/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:34:18 by armendes          #+#    #+#             */
/*   Updated: 2022/02/17 16:05:31 by armendes         ###   ########.fr       */
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
	int				need_to_concat;
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
void	skip_space_words(t_token **words);
int		search_space_start(char *str);
int		search_space_end(char *str);
t_token	*last_cell(t_token **words);
int		concat_words_prev(t_token **words);
void	detect_concat(t_token **words);
int		search_redirection(char *str);
int		cut_redirection(t_token **words);
int		search_error_redirection(char *str);
char	get_next_char(char *str);
t_token	*create_word(char *str, e_type type);
char	*cut_one_char(char *str);
char	*cut_two_char(char *str);
char	*before_redirection(char *str);
char	*after_redirection(char *str);
int		cut_redirection_first_cell(t_token **words, t_token **tmp, char *sign,
			e_type type);
int		cut_redirection_other_cell(t_token **words, t_token **tmp, char *sign,
			e_type type);
void    get_infile_outfile(t_token **words);

#endif