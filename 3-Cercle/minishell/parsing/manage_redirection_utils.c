/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirection_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:40:32 by armendes          #+#    #+#             */
/*   Updated: 2022/04/04 16:47:03 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cut_for_redirection(t_token **words, t_token **tmp, int i)
{
	int	control;

	if (i == 1)
		control = cut_for_input(words, tmp);
	else if (i == 2)
		control = cut_for_output(words, tmp);
	else if (i == 3)
		control = cut_for_delimiter(words, tmp);
	else if (i == 4)
		control = cut_for_append(words, tmp);
	return (control);
}
