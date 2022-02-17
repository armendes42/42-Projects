/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile_and_outfile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:01:58 by armendes          #+#    #+#             */
/*   Updated: 2022/02/17 16:05:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    get_infile_outfile(t_token **words)
{
    t_token *tmp;

    tmp = *words;
    while (tmp)
    {
        if (tmp->type == RED_IN && tmp->next != NULL)
            tmp->next->type = INFILE;
        else if (tmp->type == RED_OUT && tmp->next != NULL)
            tmp->next->type == OUTFILE;
        else if (tmp->type == RED_OUT_APPEND && tmp->next != NULL)
            tmp->next->type == OUTFILE_APPEND;
        else if (tmp->type == HERE_DOC && tmp->next != NULL)
            tmp->next->type == LIMITOR;
        tmp = tmp->next;
    }
}