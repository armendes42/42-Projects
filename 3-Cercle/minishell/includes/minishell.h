/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:34:18 by armendes          #+#    #+#             */
/*   Updated: 2022/04/05 16:32:59 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

# define QUOTE_ERR "A quote is unclosed\n"
# define CMD_ERR "A problem occured during the formation of the struct cmd\n"
# define MALLOC_ERR "Error during a memory allocation\n"
# define WORD_ERR "A problem occured during the formation of the struct word\n"
# define ARG_ERR "A problem occured during the formation of args\n"
# define ENV_ERR "A problem occured during copy of env"

typedef enum type
{
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
	JUST_DOLLAR,
	JUST_DOLLAR_DOUBLE,
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
	char			**args;
	struct s_token	*words;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

typedef struct s_info
{
	int				exit_status;
	char			**env;
	struct s_cmd	*cmd;
}				t_info;

void	read_struct(t_info *info);

int		error(t_info *info, char *err_msg);
void	error_and_exit(t_info *info);
e_quote	update_quote_status(char c, e_quote quote);
int		check_quote(char *line);
char	*format_str(char *line, int start, int end);
int		add_cmd(t_cmd **cmd, int start, int end, char *line);
t_cmd	*find_pipe(char *line);
int		cut_into_words(t_info *info);
void	free_cmd(t_cmd *cmd);
void	free_info(t_info *info);
void	free_env(char **env);
int		is_empty(char *str);
int		add_word(t_token **words, char *str, e_quote quote);
int		skip_empty_words(t_token **words);
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
int		cut_redirection_first_char(t_token **words, t_token **tmp, char *sign,
			e_type type);
int		cut_redirection_other_char(t_token **words, t_token **tmp, char *sign,
			e_type type);
void	get_infile_outfile(t_token **words);
int		search_dollar(char *str);
int		get_var_env(t_token **words, char **env);
int		keep_going_till_dollar(char *str);
int		keep_going_till_end_of_var(char *str);
void	trim_space_in_word_start(t_token **words);
void	trim_space_in_word_end(t_token **words, t_info *info);
int		make_args(t_cmd **cmd);
int		search_space(char *str);
int		is_only_space(char *str);
int		cut_arg_nothing(t_token **words);
char	*ft_getenv(char *var, char **env);
char	**copy_env(char **envp);
int		get_exit_status(t_token **words, int exit_status);
int		get_just_dollar(t_token **words);
void	change_just_dollar_to_arg(t_token **words);
int		search_error_var_env(char *str);
char	*ft_getenv_var(char *str);
int		ft_len_env(char **env);
int		get_var_env_files(t_token **words, char **env);
char	*search_env_var(char *str);
char	*replace_env_var_by_nothing(char *str);
char	*replace_env_var_by_content(char *str, char *inside_var);
int		type_is_redirection(e_type type);
int		cut_for_input(t_token **words, t_token **tmp);
int		cut_for_output(t_token **words, t_token **tmp);
int		cut_for_delimiter(t_token **words, t_token **tmp);
int		cut_for_append(t_token **words, t_token **tmp);
int		cut_for_redirection(t_token **words, t_token **tmp, int i);
char	*cut_before_only_space(char *str);
char	*cut_only_space(char *str);
char	*cut_after_only_space(char *str);
int		cut_cell_for_dollar_first_char(t_token **words, t_token **cell);
int		cut_cell_for_dollar_other_char(t_token **words, t_token **cell);

void	check_if_builtin(t_info *info, t_cmd *cmd);
void	builtin_echo(char **args);
int		builtin_cd(char **args);
int		builtin_pwd(void);
int		builtin_export(t_info *info, t_cmd *cmd);
int		builtin_unset(t_info *info, t_cmd *cmd);
void	builtin_env(char **env);
void	builtin_exit(t_info *info, t_cmd *cmd);

#endif