/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:48:59 by imaalem           #+#    #+#             */
/*   Updated: 2022/04/14 16:49:55 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_red_in(t_token *token)
{
	while (token != NULL)
	{
		if (token->type == INFILE || token->type == HERE_DOC)
			return (0);
		token = token->next;
	}
	return (-1);
}

int	check_if_red_out(t_token *token)
{
	while (token != NULL)
	{
		if (token->type == OUTFILE || token->type == OUTFILE_APPEND)
			return (0);
		token = token->next;
	}
	return (-1);
}

t_token	*find_last_infile(t_token *word)
{
	t_token	*last;

	while (word != NULL)
	{
		if (word->type == INFILE || word->type == HERE_DOC)
			last = word;
		word = word->next;
	}
	return (last);
}
