/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:41:16 by armendes          #+#    #+#             */
/*   Updated: 2022/01/10 19:44:03 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	free_elem(int content)
{
	(void)content;
}

void	error(t_list *input, char *err_msg)
{
	ft_lstclear(&input, &free_elem);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}