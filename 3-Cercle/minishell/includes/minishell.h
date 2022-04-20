/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:34:18 by armendes          #+#    #+#             */
/*   Updated: 2022/04/20 22:32:15 by armendes         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>

# define QUOTE_SIMPLE_ERR "$: unexpected EOF while looking for matching '''\n$:\
 syntax error: unexpected end of file\n"
# define QUOTE_DOUBLE_ERR "$: unexpected EOF while looking for matching '\"'\n$:\
 syntax error: unexpected end of file\n"
# define BRACES_ERR "$: unexpected EOF while looking for matching '{'\n$: syntax \
error: unexpected end of file\n"
# define PIPE_ERR "syntax error near unexpected token '|'\n"
# define NEWLINE_ERR "syntax error near unexpected token 'newline'\n"
# define INPUT_ERR "syntax error near unexpected token '<'\n"
# define OUTPUT_ERR "syntax error near unexpected token '>'\n"
# define OUTPUT_APPEND_ERR "syntax error near unexpected token '>>'\n"
# define HERE_DOC_ERR "syntax error near unexpected token '<<'\n"
# define ACCOLADE_ERR ": bad substitution\n"
# define MALLOC_ERR "Error during a memory allocation\n"
# define DIRECTORY_ERR "$: /: Is a directory\n"
# define PWD_ERR "pwd: error retrieving current directory: getcwd: cannot access\
 parent directories: "
# define SUCCESS 0
# define ERROR -1

extern int	g_exit_status;

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
	LIMITER,
	OUTFILE,
	OUTFILE_APPEND,
	JUST_DOLLAR,
	JUST_DOLLAR_DOUBLE,
}			t_type;

typedef enum quote
{
	NOTHING,
	SIMPLE,
	DOUBLE,
}			t_quote;

typedef struct s_token
{
	char			*word;
	t_type			type;
	int				need_to_concat;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

typedef struct s_cmd
{
	int				range;
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

// first checks
int		parsing(char *line, t_info *info);
t_quote	update_quote_status(char c, t_quote quote);
int		check_quote(char *line);
int		check_braces(char *line);
int		check_redir_before_pipe(char *str);

// linked list cmd
int		add_cmd(t_cmd **cmd, int start, int end, char *line);

// linked list words
t_token	*create_word(char *str, t_type type);
int		cut_into_words(t_info *info);
int		add_word(t_token **words, char *str, t_quote quote);

// error and free
int		error(t_info *info, char *err_msg, int exit_status);
void	error_and_exit(t_info *info, int exit_status);
void	free_cmd(t_cmd *cmd);
void	free_info(t_info *info);
void	free_env(char **env);

// redirection
int		search_redirection(char *str);
void	cut_redirection(t_token **words);
int		search_error_redirection(char *str);
int		search_error_redirection_two(char *str, int i);
char	*get_next_char(char *str);
char	*cut_one_char(char *str);
char	*cut_two_char(char *str);
char	*before_redirection(char *str);
char	*after_redirection(char *str);
void	cut_redirection_first_char(t_token **words, t_token **tmp, char *sign,
			t_type type);
void	cut_redirection_other_char(t_token **words, t_token **tmp, char *sign,
			t_type type);
void	get_infile_outfile(t_token **words);
int		type_is_redirection(t_type type);
void	cut_for_input(t_token **words, t_token **tmp);
void	cut_for_output(t_token **words, t_token **tmp);
void	cut_for_delimiter(t_token **words, t_token **tmp);
void	cut_for_append(t_token **words, t_token **tmp);
void	cut_for_redirection(t_token **words, t_token **tmp, int i);
int		detect_here_doc(t_token *tmp);

// environment
int		search_dollar(char *str);
void	get_var_env(t_token **words, char **env);
int		keep_going_till_dollar(char *str);
int		keep_going_till_end_of_var(char *str);
void	cut_arg_nothing(t_token **words);
char	*ft_getenv(char *var, char **env);
char	**copy_env(char **envp, char *arg);
void	get_just_dollar(t_token **words);
void	change_just_dollar_to_arg(t_token **words);
int		search_error_var_env(char *str);
char	*ft_getenv_var(char *str);
int		ft_len_env(char **env);
void	get_var_env_files(t_token **words, char **env);
char	*search_env_var(char *str);
char	*replace_env_var_by_nothing(char *str);
char	*replace_env_var_by_content(char *str, char *inside_var);
char	*cut_before_only_space(char *str);
char	*cut_before_only_space_two(char *str, int i);
char	*cut_only_space(char *str);
char	*cut_after_only_space(char *str);
void	cut_cell_for_dollar_first_char(t_token **words, t_token **cell);
void	cut_cell_for_dollar_other_char(t_token **words, t_token **cell);
void	cut_dollars_from_env(t_token **words);
int		braces_non_conform(char *str);
int		braces_empty(char *str);
int		search_dollar_groups(char *str);
int		count_group_of_dollar(char *str);
void	print_env_export(char **env);
char	**update_shlvl(char **env, int len);

// concatenate words
int		search_space_start(char *str);
int		search_space_end(char *str);
t_token	*last_cell(t_token **words);
void	concat_words_prev(t_token **words);
void	detect_concat(t_token **words);

// deal with unnecessary space
int		is_empty(char *str);
int		skip_empty_words(t_token **words);
void	skip_space_words(t_token **words);
void	trim_space_in_word_start(t_token **words);
void	trim_space_in_word_end(t_token **words);
int		search_space(char *str);

// deal with info
char	*format_str(char *line, int start, int end);
t_cmd	*find_pipe(char *line);
void	make_args(t_cmd **cmd);
void	get_exit_status(t_token **words, int exit_status);
t_info	*get_info(void);

// execution
int		execution(t_info *info);
void	pipe_odd_or_even(t_cmd *cmd, int (*pipefd)[2]);
void	close_pipe(t_cmd *cmd, int (*pipefd)[2]);

	// pipe n redirection	
int		dup2_first_cmd(t_info *info, int (*pipefd)[2], int *red);
int		dup2_odd_cmd(t_info *info, t_cmd *cmd, int (*pipefd)[2], int *red);
int		dup2_even_cmd(t_info *info, t_cmd *cmd, int (*pipefd)[2], int *red);
int		dup2_n_redirect(t_info *info, t_cmd *cmd, int (*pipefd)[2], int pid);
int		redirect_in(t_token *words);
t_token	*find_last_infile(t_token *word);
int		redirect_out(t_token *words, int child);
int		check_file_n_create(t_token *token);
int		fill_here_doc_file(int *pipefd, char *limiter);
int		manage_here_doc(t_token *word, int pid);
int		check_if_red_in(t_token *token);
int		check_if_red_out(t_token *token);

	//builtin
int		check_if_builtin(t_cmd *cmd, int fd);
int		builtin_cd(char **args, char **env, int *pid);
void	builtin_echo(char **args, int fd);
int		builtin_pwd(int fd, int *pid);
int		builtin_export(t_info *info, t_cmd *cmd);
char	**update_env_export(char **env, char **args, int control);
char	**update_env_two(char **args, char **new_env, int j);
int		check_format_of_var_export(char *str);
int		builtin_unset(t_info *info, t_cmd *cmd);
void	builtin_env(char **env, int fd);
int		builtin_exit(t_info *info, t_cmd *cmd);
void	builtin_exit_if_cmd_alone(t_info *info, t_cmd *cmd);
void	builtin_exit_if_multiple_cmd(t_cmd *cmd);
int		is_arg_numeric(char *str);
void	my_exit(t_info *info);
void	error_for_export_and_unset(char *str, int i);
int		exec_builtin(t_info *info, t_cmd *cmd, int *pid, int fd);

	//binary
void	exec_binary_n_exec(t_info *info, t_cmd *cmd, int *pid);
char	*parse_path(t_info *info, t_cmd *cmd);
void	manage_error_in_child(void);

	// executable
int		exec_executable(t_cmd *cmd, int *pipefd);
char	*recover_cmd_path(char **tab_path, char *word);
char	*format_path(char *path_to_test, char *word);
char	**get_var_env_path(char **ev);

	//general
void	free_tab_char(char **tab);
void	set_up_range(t_info *info);
int		count_nb_cmd(t_info *info);
int		check_if_executable(t_cmd *cmd);
int		check_error(int error, char *message);
char	*new_get_next_line(int fd);

	//signal
void	ctrl_c(int sig);
void	ctrl_backslash_child(int sig);
void	set_up_signals_here_doc(int sig);
void	set_up_signals_parent(void);
void	set_up_signals_child(void);
void	ignore_signals_parent(void);

#endif