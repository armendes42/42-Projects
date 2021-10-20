/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:44:21 by armendes          #+#    #+#             */
/*   Updated: 2021/10/20 17:32:01 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**parsing_paths(char **envp);
int		dup_in_out(int fd_in, int fd_out);
int		openfile(int fd_infile, int fd_outfile, char **argv, char **envp);
void	error_command(char *arg);
void	all_cmd_empty(int fd_infile, int fd_outfile, char **envp);
void	cmd1_empty(int fd_infile, int fd_outfile, char *cmd2, char **envp);
void	cmd2_empty(int fd_infile, int fd_outfile, char *cmd1, char **envp);
void	free_tab(char **tab);
void	fill_second_file(int fd_outfile, char *cmd2, char **envp);

#endif
