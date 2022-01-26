/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:57:57 by armendes          #+#    #+#             */
/*   Updated: 2022/01/26 19:49:51 by armendes         ###   ########.fr       */
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

void	free_stack_and_tab_and_error(t_list **stack, char **tab)
{
	free_char_tab(tab);
	free_stack(stack);
	error();
}
