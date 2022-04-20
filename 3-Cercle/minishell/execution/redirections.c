/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:38:11 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/19 19:03:22 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_in(t_token *yet)
{
	t_token		*last_infile;
	int			fd;

	if (check_if_red_in(yet) == -1)
		return (-1);
	manage_here_doc(yet, 0);
	last_infile = find_last_infile(yet);
	if (last_infile->type == INFILE)
	{
		fd = open(last_infile->word, O_RDONLY);
		if (fd == -1)
		{
			perror(last_infile->word);
			g_exit_status = 127;
			return (-2);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (0);
}

int	redirect_out(t_token *yet, int pid)
{
	t_token	*last;
	int		fd;

	if (check_if_red_out(yet) == -1)
		return (-1);
	while (yet != NULL)
	{
		if (yet->type == OUTFILE || yet->type == OUTFILE_APPEND)
			last = yet;
		yet = yet->next;
	}
	if (last->type == OUTFILE)
		fd = open(last->word, O_WRONLY);
	else
		fd = open(last->word, O_WRONLY | O_APPEND);
	if (pid == 0)
		dup2(fd, STDOUT_FILENO);
	return (fd);
}

int	check_file_n_create(t_token *token)
{
	int	fd;

	fd = -42;
	while (token != NULL)
	{
		if (token->type == INFILE)
			fd = open(token->word, O_RDONLY);
		else if (token->type == OUTFILE)
			fd = open(token->word, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		else if (token->type == OUTFILE_APPEND)
			fd = open(token->word, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (fd == -1)
		{
			perror(token->word);
			g_exit_status = 127;
			return (-1);
		}
		if (fd != -42)
			close(fd);
		token = token->next;
	}
	return (0);
}
