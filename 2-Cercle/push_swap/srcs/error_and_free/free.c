/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:57:57 by armendes          #+#    #+#             */
/*   Updated: 2022/01/26 18:59:27 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*elem;
	t_list	*tmp;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
	{
		free(*stack);
		return ;
	}
	elem = *stack;
	while (elem->next != NULL)
	{
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
	free(elem);
}

void	free_char_tab(char **tab)
{
	int	i;

	if (tab == NULL)
	{
		free(tab);
		return ;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
