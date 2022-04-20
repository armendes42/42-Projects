/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:16:34 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/19 19:34:07 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*find_last_here_doc(t_token *word)
{
	t_token	*last;

	last = NULL;
	while (word != NULL)
	{
		if (word->type == HERE_DOC)
			last = word;
		word = word->next;
	}
	return (last);
}

int	manage_here_doc(t_token *word, int pid)
{
	int		pipefd[2];
	t_token	*last_here_doc;

	last_here_doc = find_last_here_doc(word);
	if (!last_here_doc)
		return (-1);
	while (word != NULL)
	{
		if (word->type == HERE_DOC)
		{
			pipe(pipefd);
			fill_here_doc_file(pipefd, word->next->word);
			close(pipefd[1]);
			if (word == last_here_doc && pid != 1)
				dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
		}
		word = word->next;
	}
	return (0);
}

int	fill_here_doc_file(int *pipefd, char *limiter)
{
	char	*line;

	signal(SIGINT, set_up_signals_here_doc);
	line = new_get_next_line(STDIN_FILENO);
	if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0
		&& line[ft_strlen(limiter)] == '\n')
	{
		if (line != NULL)
			free(line);
		return (0);
	}
	while (line != NULL)
	{
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
			break ;
		else
			ft_putstr_fd(line, pipefd[1]);
		if (line != NULL)
			free(line);
		line = new_get_next_line(STDIN_FILENO);
	}
	set_up_signals_parent();
	return (0);
}
