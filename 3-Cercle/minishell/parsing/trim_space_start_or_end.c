/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_space_start_or_end.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:56:22 by armendes          #+#    #+#             */
/*   Updated: 2022/04/18 16:26:53 by imaalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	trim_space_in_word_start(t_token **words)
{
	t_token	*tmp;
	char	*new_word;

	tmp = *words;
	while (tmp)
	{
		if (tmp->word[0] == ' ' && tmp->type == ARG && !is_empty(tmp->word))
		{
			new_word = format_str(tmp->word, 0, ft_strlen(tmp->word));
			if (!new_word)
				error_and_exit(get_info(), 1);
			free(tmp->word);
			tmp->word = new_word;
		}
		tmp = tmp->next;
	}
}

void	trim_space_in_word_end(t_token **words)
{
	t_token	*tmp;
	char	*str;
	int		i;
	int		j;

	tmp = *words;
	while (tmp)
	{
		if (search_space_end(tmp->word) && tmp->type == ARG)
		{
			i = ft_strlen(tmp->word) - 1;
			while (tmp->word[i] == ' ')
				i--;
			str = malloc(sizeof(char) * (i + 2));
			if (!str)
				error_and_exit(get_info(), 1);
			j = -1;
			while (tmp->word[++j] && j <= i)
				str[j] = tmp->word[j];
			str[j] = '\0';
			free(tmp->word);
			tmp->word = str;
		}
		tmp = tmp->next;
	}
}
